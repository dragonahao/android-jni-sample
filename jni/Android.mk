LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := YzTestJni
LOCAL_SRC_FILES := YzTestJni.cpp

include $(BUILD_SHARED_LIBRARY)
