LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := YzTestJni
LOCAL_SRC_FILES := YzTestJni.cpp
LOCAL_LDLIBS :=  -L$(SYSROOT)/usr/lib -llog

include $(BUILD_SHARED_LIBRARY)
