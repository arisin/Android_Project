// string.hとjni.hは何れもJNIがC++向けに提供するライブラリー
// （C++の標準ライブラリーではない）
#include <string.h>
#include <jni.h>

// C++標準ライブラリーの文字列型 std::string を読み込む
//#include <string>

// #if〜#endifはCPP(C Pre-Processor)と言うC++が含むCの機能の一部で
// ソースコードをコンパイルする前処理として単純な文字列定義と比較と
// 置き換えをソースコード自体に適用する手法における条件分岐構文。
// definedはCPPにおける「もし定義があればtrue、そうでなければfalse」
// を返す組み込み関数。
// __cplusplusはコンパイラーがC++モードであれば定義され、
// そうでなければ通常は定義されないCPP組み込み的な値。
#if defined(__cplusplus)
// JNIにも関数定義があるよ！と解る様に、
// C++の前方宣言をextern "C"しつつ定義。
// よく解らなければ.soを外から見た時に
// 「この.soにはこんな関数や変数があるからね」
// と教えてあげる機能だと思って措いて問題無い。
extern "C" {
  // jstring型を返す、
  // Java_co（中略）_test1という名前で、
  // JNIEnv*型とjobject型の引値を取る関数
  // がある事を外部にも教えますよ、という宣言（関数本体の定義ではない）。
  jstring Java_com_example_testXndk_testXndk_test1(JNIEnv*, jobject);
  jstring Java_com_example_testXndk_testXndk_test2(JNIEnv*, jobject);
}
#endif

// テスト用、純粋で単純で機能的なC++の（テンプレート）関数
// （実際やっている事は文字列を生成するだけ。）
// （templateもinlineも使う必要は無いがデモ目的で使っている。）
template<class T>
inline T generate()
{
  // テンプレート引数T型のコンストラクターに
  // 処理系依存の文字列を渡して
  // 生成したてのright-valueなオブジェクトをリターン
  return T("ばよえーん");
}

// 先に宣言しておいた関数の実体を定義
// 「jstring型」は「JAVAのString型」
// JNIEnvはJNIを使うにあたってC++からJAVAと連携する為の
// アレコレの環境を保持したオブジェクト、
// jobjectは呼び出し元となるJAVAのオブジェクト
// （C++では使用しない仮引数のシンボル名定義は省略可能なので、
// 　型名のみを関数定義に含めている。）
jstring Java_com_example_testXndk_testXndk_test1
  (JNIEnv* env, jobject)
{
  // C++11のautoによる静的推論型により変数vを宣言と同時に
  // generate()により初期化。
  //auto v = generate<std::string>();
  
  // envのNewStringUTF関数によりC++のネイティブな文字列から
  // JAVAの文字列オブジェクトを生成してリターンする。
  return env->NewStringUTF("test1.cpp");
}

jstring Java_com_example_testXndk_testXndk_test2
  (JNIEnv* env, jobject)
{
 return env->NewStringUTF("ばよえーん");
 }
 
