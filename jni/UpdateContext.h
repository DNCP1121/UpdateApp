/*
 * BtContext.h
 *
 *  Created on: 2016-2-29
 *      Author: guoxs
 */

#ifndef _BT_CONTEXT_H_
#define _BT_CONTEXT_H_

#include <jni.h>
#include "CommDef.h"


class CUpdateCallback;

class CUpdateContext {
public:
	~CUpdateContext();

	void RegisterCallback(JavaVM *vm, jclass cls);
	void calltest();

	static CUpdateContext* GetInstance();
	
private:
	CUpdateContext();

private:
	CUpdateCallback *m_pCallback;

};

#endif /* _BT_CONTEXT_H_ */
