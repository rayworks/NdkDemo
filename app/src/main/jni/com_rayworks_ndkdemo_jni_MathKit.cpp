//
// Created by Sean Zhou on 8/12/17
// Inspired from :
// https://www.youtube.com/watch?v=YV0zSPVSL1E&index=10&list=PL7ED2D1C8D7BCF6D9
// https://developer.android.com/training/articles/perf-jni.html
// http://docs.oracle.com/javase/7/docs/technotes/guides/jni/spec/types.html#wp428
//

#include <jni.h>
#include <android/log.h>

namespace com_rayworks_ndkdemo_jni_MathKit {

    static jint square(JNIEnv *env, jclass clazz, jint n) {
        __android_log_print(ANDROID_LOG_INFO, "MathKit#square", ">>> computing for num %d", n);

        return n * n;
    }

    static jlong cube(JNIEnv *env, jclass clazz, jint n) {
        __android_log_print(ANDROID_LOG_INFO, "MathKit#cube", ">>> computing for num %d", n);

        return n * n * n;
    }

    static JNINativeMethod method_table[] = {
            {"square", "(I)I", (void *) square},
            {"cube",   "(I)J", (void *) cube}
    };
}

using namespace com_rayworks_ndkdemo_jni_MathKit;

extern "C" jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }

    jclass clazz = env->FindClass("com/rayworks/ndkdemo/jni/MathKit");
    if (clazz) {
        env->RegisterNatives(clazz, method_table, sizeof(method_table) / sizeof(method_table[0]));
        env->DeleteLocalRef(clazz);

        return JNI_VERSION_1_6;
    }

    return -1;

}