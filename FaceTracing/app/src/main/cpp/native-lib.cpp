#include <jni.h>
#include <string>

extern "C"
JNIEXPORT void JNICALL
Java_com_tck_facetracing_Main2Activity_init(JNIEnv *env, jobject instance, jstring model_) {
    const char *model = env->GetStringUTFChars(model_, 0);




    env->ReleaseStringUTFChars(model_, model);
}extern "C"
JNIEXPORT void JNICALL
Java_com_tck_facetracing_Main2Activity_setSurface(JNIEnv *env, jobject instance, jobject surface) {




}extern "C"
JNIEXPORT void JNICALL
Java_com_tck_facetracing_Main2Activity_postData(JNIEnv *env, jobject instance, jbyteArray data_,
                                                jint w, jint h, jint cameraId) {
    jbyte *data = env->GetByteArrayElements(data_, NULL);




    env->ReleaseByteArrayElements(data_, data, 0);
}extern "C"
JNIEXPORT void JNICALL
Java_com_tck_facetracing_Main2Activity_release(JNIEnv *env, jobject instance) {




}