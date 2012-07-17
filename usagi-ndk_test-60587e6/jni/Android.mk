LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

# モジュール名
# ここでxxxと定義すればファイル名libxxx.soで生成される
LOCAL_MODULE    := test1

# C++ソースファイル
LOCAL_SRC_FILES := test1.cpp

# 既存の別の.aライブラリーをリンクする場合に定義する
# LOCAL_STATIC_LIBRARIES :=
# LOCAL_LDLIBS := 

# C++のコンパイラーに渡すオプションがあれば定義する
LOCAL_CPPFLAGS := -std=c++0x #-fexceptions -frtti

include $(BUILD_SHARED_LIBRARY)
