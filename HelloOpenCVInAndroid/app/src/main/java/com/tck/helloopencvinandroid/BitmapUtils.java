package com.tck.helloopencvinandroid;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.ColorMatrix;
import android.graphics.ColorMatrixColorFilter;
import android.graphics.Paint;

import androidx.annotation.NonNull;

/**
 * <p>description:</p>
 * <p>created on: 2019/5/31 8:04</p>
 *
 * @author tck
 * @version 3.5
 */
class BitmapUtils {

    public static Bitmap gary(Bitmap src) {
//矩阵

        Bitmap dst = Bitmap.createBitmap(src.getWidth(), src.getHeight(), src.getConfig());
        Canvas canvas = new Canvas(dst);
        Paint paint = new Paint();
        paint.setDither(true);
        paint.setAntiAlias(true);
        ColorMatrix colorMatrix = new ColorMatrix();
        colorMatrix.setSaturation(0);
        paint.setColorFilter(new ColorMatrixColorFilter(colorMatrix));
        canvas.drawBitmap(src, 0, 0, paint);

        return dst;

    }

    public static Bitmap gary2(Bitmap src) {
//矩阵

        Bitmap dst = Bitmap.createBitmap(src.getWidth(), src.getHeight(), src.getConfig());
        Canvas canvas = new Canvas(dst);
        Paint paint = new Paint();
        paint.setDither(true);
        paint.setAntiAlias(true);
        //底片效果
//        ColorMatrix colorMatrix = new ColorMatrix(new float[]{
//                -1,0,0,0,255,
//                0,-1,0,0,255,
//                0,0,-1,0,255,
//                0,0,0,1,0,
//        });
        ColorMatrix colorMatrix = new ColorMatrix(new float[]{
                1.2f, 0, 0, 0, 0,
                0, 1.2f, 0, 0, 0,
                0, 0, 1.2f, 0, 0,
                0, 0, 0, 1, 0,
        });
        paint.setColorFilter(new ColorMatrixColorFilter(colorMatrix));
        canvas.drawBitmap(src, 0, 0, paint);

        return dst;

    }

    public static Bitmap gary3(Bitmap src) {

        Bitmap dst = Bitmap.createBitmap(src.getWidth(), src.getHeight(), src.getConfig());
        int[] pixels = new int[src.getWidth() * src.getHeight()];

        src.getPixels(
                pixels,
                0,
                src.getWidth(),
                0,
                0,
                src.getWidth(),
                src.getHeight());

        for (int i = 0; i < pixels.length; i++) {
            int pixel = pixels[i];
                int a = (pixel >> 24) & 0xff;
                int r = (pixel >> 16) & 0xff;
                int g = (pixel >> 8) & 0xff;
                int b = pixel & 0xff;

                int gray = (int) (0.213f * r + 0.715f * g + 0.072f * b);
                //黑白
                //int gray = (a + r + b)/3 > 125 ? 255 : 0;
                pixels[i] = (a << 24) | (gray << 16) | (gray << 8) | gray;

        }

        dst.setPixels(
                pixels,
                0,
                src.getWidth(),
                0,
                0,
                src.getWidth(),
                src.getHeight());

        return dst;
    }

    //内存复用
    public static Bitmap gary4(Bitmap src) {

        int[] pixels = new int[src.getWidth() * src.getHeight()];

        src.getPixels(
                pixels,
                0,
                src.getWidth(),
                0,
                0,
                src.getWidth(),
                src.getHeight());

        for (int i = 0; i < pixels.length; i++) {
            int pixel = pixels[i];
            int a = (pixel >> 24) & 0xff;
            int r = (pixel >> 16) & 0xff;
            int g = (pixel >> 8) & 0xff;
            int b = pixel & 0xff;

            int gray = (int) (0.213f * r + 0.715f * g + 0.072f * b);
            //黑白
            //int gray = (a + r + b)/3 > 125 ? 255 : 0;
            pixels[i] = (a << 24) | (gray << 16) | (gray << 8) | gray;

        }

        src.setPixels(
                pixels,
                0,
                src.getWidth(),
                0,
                0,
                src.getWidth(),
                src.getHeight());

        return src;
    }

    public static  native int garys(Bitmap src);

}


