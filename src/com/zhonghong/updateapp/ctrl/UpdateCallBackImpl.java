package com.zhonghong.updateapp.ctrl;

import android.os.Handler;
import android.os.Message;

import com.zhonghong.updateapp.ctrl.JniContext.ICallBack;

/**
 * 
 * @author Administrator
 * call back interface
 */
public class UpdateCallBackImpl {
	Handler mHandler;
	public UpdateCallBackImpl(Handler m) {
		// TODO Auto-generated constructor stub
		mHandler = m;
		JniContext.setCallBack(mCallBack);
	}
	private ICallBack mCallBack = new ICallBack() {

		@Override
		public void HandleCmd(int cmd, String val) {
			// TODO Auto-generated method stub
			Message ms = Message.obtain();
			ms.what = cmd;
			ms.obj = val;
			mHandler.sendMessage(ms);
		}
		
	};
}
