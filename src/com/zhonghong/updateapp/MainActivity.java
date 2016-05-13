package com.zhonghong.updateapp;

import android.app.Activity;
import android.media.AudioManager;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

import com.zhonghong.updateapp.ctrl.Contants;
import com.zhonghong.updateapp.ctrl.UpdateCallBackImpl;
import com.zhonghong.updateapp.ctrl.UpdateCtrlImpl;

public class MainActivity extends Activity implements OnClickListener {

	public static final String TAG = "Update";
	Button button;
	UpdateCtrlImpl mCtrlImpl;
	UpdateCallBackImpl mBackImpl;
	AudioManager manager;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		initview();
		mCtrlImpl = new UpdateCtrlImpl();
		mBackImpl = new UpdateCallBackImpl(mHandler);
		manager = (AudioManager)getSystemService(AUDIO_SERVICE);
	}
	Handler mHandler = new Handler(){
		@Override
		public void handleMessage(Message msg) {
			// TODO Auto-generated method stub
			switch(msg.what){
			case Contants.C_CALL_BACK_CMD_CONNECTING:
				String s = (String)msg.obj;
			}
			super.handleMessage(msg);
		}
	};
	private void initview(){
		button = (Button)findViewById(R.id.button);
		button.setOnClickListener(this);
	}
	@Override
	public void onClick(View v) {
		// TODO Auto-generated method stub
		switch(v.getId()){
		case R.id.button:
			Log.d(TAG,"click button"+manager.getStreamVolume(11));
			break;
		}
	}
	

}
