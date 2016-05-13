/*
 * BtCallback.h
 *
 *  Created on: 2016-3-2
 *      Author: guoxs
 */

#ifndef _BT_CALLBACK_H_
#define _BT_CALLBACK_H_

#include <jni.h>
#include "CommDef.h"

/**
 * 该类负责回调Java层接口
 */
class CUpdateCallback {
public:
	CUpdateCallback(JavaVM *vm, jclass cls);
	~CUpdateCallback();

	bool PerformCallback(int cmd, const char *pVal);

private:
	bool InitEnv();		// 线程中调用该接口，初始化m_pEnv

private:
	JavaVM *m_pVM;		// 多线程中可以共用
	JNIEnv *m_pEnv;		// m_pEnv在线程中设置值
	jclass m_cls;		// 构造的时候传进来全局的引用
};

#endif /* _BT_CALLBACK_H_ */
