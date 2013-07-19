#include <jni.h>
#include <string>
#include <cctype>
#include "vehicle_DSP_YZ_VehicleTransit_CVS.h"

using namespace std;
//helper
string jstring2string(JNIEnv* env, jstring jstr){
	const char *cptr = env->GetStringUTFChars(jstr, 0);
	jsize len = env->GetStringLength(jstr);
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
	for (string::iterator it = lowercase.begin(); it != lowercase.end(); ++it){
		uppercase += toupper(*it);
	}
	jstring jstr;
	jstr = string2jstring(env, uppercase);
	return jstr;
//	return words;
}
