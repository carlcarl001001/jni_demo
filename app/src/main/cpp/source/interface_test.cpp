#include <jni.h>
#include <string>
#include <android/log.h>
#include "include/Student.h"
#include "include/SchoolClass.h"
#include <vector>
#include "include/Java_To_C.h"
#include "include/C_To_Jobj.h"

using namespace std;

//#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_carl_jnidemo_model_JniModel_stringFromJNI(JNIEnv *env, jobject thiz) {
    // TODO: implement stringFromJNI()
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());

}extern "C"
JNIEXPORT void JNICALL
Java_com_example_carl_jnidemo_model_JniModel_cppCallJava(JNIEnv *env, jobject thiz) {
    // TODO: implement cppCallJava()
    LOG_D("into JniModel cppCallJava....\n");
    //1.得到字节码
    jclass clazz = env->FindClass("com/example/carl/jnidemo/model/JavaFunction");
    //2.得到方法(最后一个参数是方法签名)
    jmethodID mid = (*env).GetMethodID(clazz,"printLog", "()V");
    //3.实例化该类
    jobject job=env->AllocObject(clazz);
    //4.调用方法
    env->CallVoidMethod(job,mid);
    LOG_D("finish....\n");
}
extern "C"
JNIEXPORT jobject JNICALL
Java_com_example_carl_jnidemo_model_JniModel_getOneClassFromC(JNIEnv *env, jobject thiz) {
    // TODO: implement getOneClassFromC()
    LOG_D("into JniModel getOneClassFromC....\n");
    Java_To_C::initStaticVariables(env);
    vector<SchoolClass> schoolClasses = Java_To_C::changeClasses(env);
    C_To_Jobj::initStaticVariables(env);
    jobject classes = C_To_Jobj::changeAllClasses(env,schoolClasses);
    return classes;
}