#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <jni.h>

#include "Util/Debug.h"
#include "UpdateContext.h"
#include "CommDef.h"

#ifdef __cplusplus
extern "C" {
#endif

static jclass g_callbackClsRef = NULL;
CUpdateContext *g_pUpdateContext = NULL;


typedef struct {
	int cmd;
	bool (*ProcCmd)(const char *pVal);
	bool bNeedParam;	// 是否需要参数
} S_BT_CTRL_TAB;
static bool Init(const char *pVal) {
	LOGICTRL(UART_DEBUG, "init");
	g_pUpdateContext->calltest();
	//return g_pUpdateContext->Init();
}
// 后期添加接口只需与Java层订好cmd值和val值，无需添加Jni函数
static S_BT_CTRL_TAB sBtCtrlTab[] = {
	JAVA_CTRL_BT_CMD_INIT, Init, false,
	JAVA_CTRL_BT_CMD_NULL, NULL, false
};

JNIEXPORT jboolean JNICALL Java_com_zhonghong_updateapp_ctrl_JniContext_UpdateCtrl
	(JNIEnv *env, jclass cls, jint cmd, jstring val) {
	const char *pVal = env->GetStringUTFChars(val, NULL);
	bool bResult = false;

	for (int i = 0; i < 100; ++i) {
		if (sBtCtrlTab[i].cmd == JAVA_CTRL_BT_CMD_NULL) {
			break;
		}

		if (sBtCtrlTab[i].cmd == cmd) {
			if (sBtCtrlTab[i].ProcCmd != NULL) {
				if (!sBtCtrlTab[i].bNeedParam || (pVal != NULL)) {
					bResult = sBtCtrlTab[i].ProcCmd(pVal);
				}
			}

			break;
		}
	}

	if (pVal != NULL) {
		env->ReleaseStringUTFChars(val, pVal);
	}

	return bResult;
}


// 加载so时调用
JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
	LOGICTRL(UART_DEBUG, "JNI_OnLoad");

	JNIEnv *env = NULL;
	if (vm->GetEnv((void**)&env, JNI_VERSION_1_6) != JNI_OK) {
		LOGICTRL(UART_DEBUG, "JNI_OnLoad GetEnv err.");
		return JNI_ERR;
	}

	jclass cls = env->FindClass("com/zhonghong/updateapp/ctrl/JniContext");
	if (cls == NULL) {
		LOGICTRL(UART_DEBUG, "FindClass JniContext Fail.");
		return JNI_ERR;
	}

	g_callbackClsRef = (jclass)env->NewWeakGlobalRef(cls);
	env->DeleteLocalRef(cls);

	g_pUpdateContext = CUpdateContext::GetInstance();
	g_pUpdateContext->RegisterCallback(vm, g_callbackClsRef);

	return JNI_VERSION_1_6;
}

// 卸载so时调用
JNIEXPORT void JNI_ONUnLoad(JavaVM *vm, void *reserved) {
	LOGICTRL(UART_DEBUG, "JNI_ONUnLoad");

	JNIEnv *env = NULL;
	if (vm->GetEnv((void**)&env, JNI_VERSION_1_6) != JNI_OK) {
		LOGICTRL(UART_DEBUG, "JNI_ONUnLoad GetEnv err.");
		return;
	}

	env->DeleteWeakGlobalRef(g_callbackClsRef);
	g_pUpdateContext = NULL;
}

#ifdef __cplusplus
}
#endif
