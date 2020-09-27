package com.tck.opencvandroidtrain;

import android.graphics.Bitmap;

/**
 * <p>description:</p>
 * <p>created on: 2020/9/26 9:44</p>
 *
 * @author tck
 * @version v1.3.0
 */
public class ImageHandlerUtils {

    static {
        System.loadLibrary("native-lib");
    }

    public native void flip(Bitmap bitmapIn, Bitmap bitmapOut);

    public native void blur(Bitmap bitmapIn, Bitmap bitmapOut, float sigma);
}
