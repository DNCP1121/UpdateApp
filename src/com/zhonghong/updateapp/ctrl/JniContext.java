package com.zhonghong.updateapp.ctrl;
/**
 * 
 * @author Administrator
 *
 */
public class JniContext {
	
	private static final String TAG = "JniContext";
	
	static {
		System.loadLibrary("UpdateCtrl");
	}
	
	public interface ICallBack {
		void HandleCmd(int cmd, String val);
	}
	
	private static ICallBack mCallBack; 
	
	public static void setCallBack(ICallBack callback) {
		mCallBack = callback;
	}	
	
	public static native boolean UpdateCtrl(int cmd, String val);
	
	public static void btCallback(int cmd, String val) {
		if (mCallBack != null) {
			mCallBack.HandleCmd(cmd, val);
		}
	}
}
