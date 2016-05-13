/*
 * UpdateContext.cpp
 *
 *  Created on: 2016-2-29
 *      Author: guoxs
 */

#include <stdio.h>
#include <string.h>
#include <sys/system_properties.h>

#include "Util/Debug.h"
#include "UpdateContext.h"
#include "UpdateCallback.h"


CUpdateContext::CUpdateContext() {
	
}
CUpdateContext::~CUpdateContext() {

	if (m_pCallback != NULL) {
		delete m_pCallback;
	}
}
void CUpdateContext::RegisterCallback(JavaVM *vm, jclass cls) {
	LOGICTRL(UART_DEBUG, "RegisterCallback.");
	if (m_pCallback != NULL) {
		delete m_pCallback;
	}

	m_pCallback = new CUpdateCallback(vm, cls);
}
void CUpdateContext::calltest() {
	LOGICTRL(UART_DEBUG, "calltest");
	m_pCallback->PerformCallback(C_CALL_BACK_CMD_DISCONNECT, NULL);
}
CUpdateContext* CUpdateContext::GetInstance() {
	static CUpdateContext sUpdateContext;
	return &sUpdateContext;
}
