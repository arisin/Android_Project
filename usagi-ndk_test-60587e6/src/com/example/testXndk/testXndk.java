package com.example.testXndk;

import android.app.Activity;
import android.widget.TextView;
import android.os.Bundle;

public class testXndk extends Activity
{
  @Override
  public void onCreate(Bundle savedInstanceState)
  {
    super.onCreate(savedInstanceState);

    TextView tv = new TextView(this);

    // test1()はJAVAの外の"libtest1.so"に定義された
    // ネイティブコード（マシン語）の関数を評価する。
//    String buffer = test1();
    String buffer = test2();    
    tv.setText(buffer);
    setContentView(tv);
  }

  public native String test1();

  // JNIにより実行時に追加で読み込むネイティブライブラリー
  // "libxxx.so"を読み込みたければloadLibrary("xxx")とする
  // 複数の.soを読み込みたければ複数行書けば良い。
  static
  {
    System.loadLibrary("test1");
  }

  public native String test2();
  static
  {
    System.loadLibrary("test2");
  }
}
