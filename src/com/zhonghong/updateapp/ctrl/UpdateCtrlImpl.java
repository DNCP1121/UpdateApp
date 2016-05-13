package com.zhonghong.updateapp.ctrl;

public class UpdateCtrlImpl{

public boolean init() {
		return JniContext.UpdateCtrl(Contants.CTRL_CMD_INIT, "");
	}

}
