#include <jni.h>
#include <string>
#include "../geometry/draw_geometry.h"
#include "../utils/ALog.h"


#define LOG_TAG "OPenGL-JNI"

extern "C"
JNIEXPORT void JNICALL
Java_com_example_learnopengl_MainActivity_drawTriangle(JNIEnv *env, jobject thiz) {
    // TODO: implement drawTriangle()
    ALOGD("[%s] begin",__FUNCTION__ );
    drawTriangle();
    ALOGD("[%s] end",__FUNCTION__ );
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_learnopengl_MainActivity_initTriangle(JNIEnv *env, jobject thiz) {
    // TODO: implement initTriangle()
    ALOGD("[%s] begin",__FUNCTION__ );
    initTriangle();
    ALOGD("[%s] end",__FUNCTION__ );
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_learnopengl_MainActivity_drawRectangle(JNIEnv *env, jobject thiz) {
    // TODO: implement drawRectangle()
    ALOGD("[%s] begin",__FUNCTION__ );
    drawRectangle();
    ALOGD("[%s] end",__FUNCTION__ );
}