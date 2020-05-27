//
// Created by Administrator on 2020/5/27.
//

#ifndef JNIDEMO_C_TO_JOBJ_H
#define JNIDEMO_C_TO_JOBJ_H
#include <jni.h>
#include <android/log.h>
#include <vector>
using namespace std;
static const char *const LOG_TAG2 = "jniTest";
#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG2, __VA_ARGS__)
class C_To_Jobj {
public:
    static jclass student_jcls;
    static jclass school_class_jcls;
    static jclass list_jcs;

    static jfieldID nameId;
    static jfieldID ageId;
    static jfieldID class_nameId;
    static jfieldID studentsId;
    static jmethodID list_init;
    static jmethodID list_add;
    static void initStaticVariables(JNIEnv *env);
    static jobject changeStudent(JNIEnv *env,Student student);
    static jobject changeClass(JNIEnv *env,SchoolClass schoolClass);
    static jobject changeAllClasses(JNIEnv *env,vector<SchoolClass> allClasses);

};


#endif //JNIDEMO_C_TO_JOBJ_H
