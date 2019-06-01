package com.tck.helloopencvinandroid;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.util.Log;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private ImageView icon1;
    private ImageView icon2;


    {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        icon1 = (ImageView) findViewById(R.id.icon_1);
        icon2 = (ImageView) findViewById(R.id.icon_2);
        BitmapFactory.Options options = new BitmapFactory.Options();
        //内存复用
        options.inMutable = true;
        options.inPreferredConfig = Bitmap.Config.ARGB_8888;
        Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.mipmap.copy, options);
        Log.d("=====", "onCreate: "+bitmap.getByteCount()/1024);
        //ARGB_8888 1639
        //RGB_565 819
        BitmapUtils.garys(bitmap);
        icon2.setImageBitmap(bitmap);

    }

}
