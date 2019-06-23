#include <jni.h>
#include <string>
#include <android/log.h>
#include "cv_helper.h"

using namespace std;
using namespace cv;


extern "C"
JNIEXPORT jobject JNICALL
Java_com_tck_facebeauty_NDKBitmapUtils_againstWorld(JNIEnv *env, jclass type, jobject bitmap) {


    Mat src;
    cv_helper::bitmap2mat(env, bitmap,src);

    return bitmap;
}