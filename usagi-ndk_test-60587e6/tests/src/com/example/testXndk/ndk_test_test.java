package com.example.testXndk;

import android.test.ActivityInstrumentationTestCase;

/**
 * This is a simple framework for a test of an Application.  See
 * {@link android.test.ApplicationTestCase ApplicationTestCase} for more information on
 * how to write and extend Application tests.
 * <p/>
 * To run this test, you can type:
 * adb shell am instrument -w \
 * -e class com.example.testXndk.testXndkTest \
 * com.example.testXndk.tests/android.test.InstrumentationTestRunner
 */
public class testXndkTest extends ActivityInstrumentationTestCase<testXndk> {

    public testXndkTest() {
        super("com.example.testXndk", testXndk.class);
    }

}
