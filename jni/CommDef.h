/*
 * CommDef.h
 *
 *  Created on: 2016-2-15
 *      Author: guoxs
 */

#ifndef _COMMDEF_H_
#define _COMMDEF_H_

#include <unistd.h>
#include <asm/termbits.h>


#define JAVA_CTRL_BT_CMD_NULL					-1
#define JAVA_CTRL_BT_CMD_INIT 					0
#define JAVA_CTRL_BT_CMD_ONOFF 					1



#define C_CALL_BACK_CMD_CONNECTING				0
#define C_CALL_BACK_CMD_CONNECTED				1
#define C_CALL_BACK_CMD_DISCONNECT				2




#define Sleep(x)	usleep(1000*x);
#define MIN(x, y)	((x < y)? x: y)

typedef unsigned char	BYTE;
typedef unsigned int	UINT;


#endif /* _COMMDEF_H_ */
