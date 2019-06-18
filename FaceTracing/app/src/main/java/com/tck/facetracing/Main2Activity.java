package com.tck.facetracing;

import android.hardware.Camera;
import android.os.Bundle;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class Main2Activity extends AppCompatActivity  implements SurfaceHolder.Callback, Camera
        .PreviewCallback {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
    private SurfaceView surfaceView;
    private CameraHelper cameraHelper;
    int cameraId = Camera.CameraInfo.CAMERA_FACING_FRONT;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        surfaceView = (SurfaceView) findViewById(R.id.surfaceView);

        surfaceView.getHolder().addCallback(this);
        cameraHelper = new CameraHelper(cameraId);
        cameraHelper.setPreviewCallback(this);

        Utils.copyAssets(this, "lbpcascade_frontalface.xml");
    }

    @Override
    protected void onResume() {
        super.onResume();
        //初始化跟踪器
        init("/sdcard/lbpcascade_frontalface.xml");
        cameraHelper.startPreview();
    }

    @Override
    protected void onStop() {
        super.onStop();
        //释放跟踪器
        release();
        cameraHelper.stopPreview();
    }


    @Override
    public void onPreviewFrame(byte[] bytes, Camera camera) {

    }

    @Override
    public void surfaceCreated(SurfaceHolder surfaceHolder) {

    }

    @Override
    public void surfaceChanged(SurfaceHolder surfaceHolder, int i, int i1, int i2) {

    }

    @Override
    public void surfaceDestroyed(SurfaceHolder surfaceHolder) {

    }

    /**
     * 初始化 追踪器
     * @param model
     */
    native void init(String model);

    /**
     * 设置画布
     *  ANativeWindow
     * @param surface
     */
    native void setSurface(Surface surface);

    /**
     * 处理摄像头数据
     * @param data
     * @param w
     * @param h
     * @param cameraId
     */
    native void postData(byte[] data, int w, int h, int cameraId);

    /**
     * 释放
     */
    native void release();
}
