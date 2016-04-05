//
// Created by Sean Zhou on 4/5/16.
//

#include "com_rayworks_ndkdemo_jni_MathKit.h"

JNIEXPORT jint JNICALL Java_com_rayworks_ndkdemo_jni_MathKit_square
  (JNIEnv *env, jclass clazz, jint num){
    return num*num;
  }