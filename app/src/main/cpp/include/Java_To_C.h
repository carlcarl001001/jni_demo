//
// Created by Administrator on 2020/5/27.
//

#ifndef JNIDEMO_JAVA_TO_C_H
#define JNIDEMO_JAVA_TO_C_H
#include <jni.h>
#include <android/log.h>
#include "SchoolClass.h"
#include <vector>
using namespace std;


static const char *const LOG_TAG = "jniTest";
#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
class Java_To_C {
public:
    static jclass list_cls;
    static jclass javaFanction_cls;
    static jclass school_class_jcls;
    static jclass student_jcls;

    static jobject javaFanction_obj;
    static jobject classes_obj;
    static jobject school_class_obj;
    static jobject students_obj;

    static jmethodID getOneClassStudentsId;
    static jmethodID sizeId;
    static jmethodID getId;
    static jmethodID getClassNameId;
    static jmethodID getStudentsId;

    static jmethodID getNameID;
    static jmethodID getAgeID;

    static void initStaticVariables(JNIEnv *env);
    static vector<Student> changeStudents(JNIEnv *env,jobject students_obj);
    static vector<SchoolClass> changeClasses(JNIEnv *env);

};


#endif //JNIDEMO_JAVA_TO_C_H
