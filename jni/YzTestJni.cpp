#include <jni.h>
#include <string>
#include <cctype>
#include "vehicle_DSP_YZ_VehicleTransit_CVS.h"
#include <android/log.h>
#include <cstdio>
#include <cstdarg>

using namespace std;

#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,DEBUG_TAG,__VA_ARGS__)
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,DEBUG_TAG,__VA_ARGS__)
//helper

char log_temp[1024];
void logcatf(const char* fmt, ...){
	va_list args;
	va_start(args, fmt);
	vsnprintf(&log_temp[0], 1024, fmt, args);
	va_end(args);
	__android_log_write(ANDROID_LOG_DEBUG, "logcatf", log_temp);
}

string jstring2string(JNIEnv* env, jstring jstr){
	const char *cptr = env->GetStringUTFChars(jstr, 0);
	jsize len = env->GetStringUTFLength(jstr);
	string str = "";
	str.append(cptr, len);
	env->ReleaseStringUTFChars(jstr, cptr);
	return str;
}

//char* to jstring
jstring string2jstring(JNIEnv* env, const string str){
	jclass strClass = env->FindClass( "java/lang/String");
	jmethodID ctorID = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
	jbyteArray bytes = env->NewByteArray(str.size());
	env->SetByteArrayRegion(bytes, 0, str.size(), (jbyte*)&str.c_str()[0]);
	jstring encoding = env->NewStringUTF("utf-8");
	return (jstring)env->NewObject(strClass, ctorID, bytes, encoding);
}
JNIEXPORT jstring JNICALL Java_vehicle_1DSP_YZ_1VehicleTransit_1CVS_capitalize
  (JNIEnv *env, jclass cls, jstring words){
	string lowercase = jstring2string(env, words);
	string uppercase = "";
	logcatf("lowercase size = %d, %s", lowercase.size(), lowercase.c_str());
	for (string::iterator it = lowercase.begin(); it != lowercase.end(); ++it){
		uppercase += *it;
	}
	logcatf("uppercase size = %d %s", uppercase.size(), uppercase.c_str());
	jstring jstr;
	jstr = string2jstring(env, uppercase);
	return jstr;
//	return words;
}
