package com.tck.opencvandroidtrain;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.SeekBar;

public class MainActivity extends AppCompatActivity implements SeekBar.OnSeekBarChangeListener {
    private ImageView imageView;
    private Button btnFlip;
    private SeekBar sldSigma;

    private Bitmap srcBitmap;
    private Bitmap dstBitmap;
    private ImageHandlerUtils imageHandlerUtils;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        imageView = (ImageView) findViewById(R.id.imageView);
        btnFlip = (Button) findViewById(R.id.btnFlip);
        sldSigma = (SeekBar) findViewById(R.id.sldSigma);

        srcBitmap = BitmapFactory.decodeResource(getResources(), R.drawable.desk_010);

        if (srcBitmap != null) {
            dstBitmap = srcBitmap.copy(srcBitmap.getConfig(), true);
        }
        imageView.setImageBitmap(dstBitmap);
        imageHandlerUtils = new ImageHandlerUtils();

        sldSigma.setOnSeekBarChangeListener(this);

        btnFlip.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                imageHandlerUtils.flip(srcBitmap, srcBitmap);
                doBlur();
            }
        });
    }

    private void doBlur() {
        float sigma = Math.max(0.1F, sldSigma.getProgress() / 10F);
        imageHandlerUtils.blur(srcBitmap, dstBitmap, sigma);
    }

    @Override
    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
        doBlur();
    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {

    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {

    }
}