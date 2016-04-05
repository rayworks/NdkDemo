package com.rayworks.ndkdemo.jni;

/**
 * Created by seanzhou on 4/5/16.
 */
public class MathKit {
    public static native int square(int num);

    static {
        System.loadLibrary("jnidemo");
    }
}
