/*
 * BtCallback.cpp
 *
 *  Created on: 2016-3-2
 *      Author: guoxs
 */

#include "Util/Debug.h"
#include "UpdateCallback.h"


CUpdateCallback::CUpdateCallback(JavaVM *vm, jclass cls):
	m_pVM(vm), m_pEnv(NULL), m_cls(cls) {
}

CUpdateCallback::~CUpdateCallback() {
	if (m_pEnv != NULL) {
		m_pVM->DetachCurrentThread();
	}
}

bool CUpdateCallback::PerformCallback(int cmd, const char *pVal) {
	if (!InitEnv()) {
		return false;
	}

	static jmethodID methodID = NULL;
	if (methodID == NULL) {
		methodID = m_pEnv->GetStaticMethodID(m_cls, "btCallback", "(ILjava/lang/String;)V");
		if (methodID == NULL) {
			LOGICTRL(UART_DEBUG, "GetMethodID btCallback Fail.");
			return false;
		}
	}

	jstring val = m_pEnv->NewStringUTF(pVal);
	m_pEnv->CallStaticVoidMethod(m_cls, methodID, cmd, val);

	m_pEnv->DeleteLocalRef(val);

	return true;
}

bool CUpdateCallback::InitEnv() {
	if (m_pEnv != NULL) {
		return true;
	}

	if (m_pVM->AttachCurrentThread(&m_pEnv, NULL) == JNI_OK) {
		return true;
	}

	return false;
}
