//
// Created by Administrator on 2020/5/27.
//

#include <include/Student.h>
#include <include/SchoolClass.h>
#include "../include/C_To_Jobj.h"

jclass C_To_Jobj::student_jcls;
jclass C_To_Jobj::school_class_jcls;
jclass C_To_Jobj::list_jcs;

jfieldID C_To_Jobj::nameId;
jfieldID C_To_Jobj::ageId;
jfieldID C_To_Jobj::class_nameId;
jfieldID C_To_Jobj::studentsId;
jmethodID C_To_Jobj::list_init;
jmethodID C_To_Jobj::list_add;

void C_To_Jobj::initStaticVariables(JNIEnv *env) {
    student_jcls = env->FindClass("com/example/carl/jnidemo/bean/Student");//第一步
    nameId = env->GetFieldID(student_jcls, "name", "Ljava/lang/String;"); //第二步
    ageId = env->GetFieldID(student_jcls, "age", "I");//第二步

    school_class_jcls = env->FindClass("com/example/carl/jnidemo/bean/SchoolClass");
    class_nameId = env->GetFieldID(school_class_jcls, "class_name", "I");
    studentsId = env->GetFieldID(school_class_jcls, "students", "Ljava/util/List;");

    list_jcs = env->FindClass("java/util/ArrayList");
    list_add = env->GetMethodID(list_jcs, "add","(Ljava/lang/Object;)Z");
}

jobject C_To_Jobj::changeStudent(JNIEnv *env,Student student) {
    jobject student_obj = env->AllocObject(student_jcls);//第三步
    jstring jstr = env->NewStringUTF(student.name);
    env->SetObjectField(student_obj, nameId, jstr);//第四步
    env->SetIntField(student_obj, ageId, student.age);//第四步
    return student_obj;
}

jobject C_To_Jobj::changeClass(JNIEnv *env,SchoolClass schoolClass) {
    jobject class_obj = env->AllocObject(school_class_jcls);

    if (list_jcs == NULL) {
        LOG_D("ArrayList no  find!");
        return NULL;
    }
    //获取ArrayList构造函数id
    jmethodID list_init = env->GetMethodID(list_jcs, "<init>", "()V");
    //创建一个ArrayList对象
    jobject list_obj = env->NewObject(list_jcs, list_init, "");
    for (int i=0;i<schoolClass.students.size();i++){
        jobject student_obj = changeStudent(env,schoolClass.students[i]);
        env->CallBooleanMethod(list_obj, list_add, student_obj);
    }
    env->SetIntField(class_obj, class_nameId, schoolClass.name);
    env->SetObjectField(class_obj, studentsId, list_obj);
    return class_obj;
}

jobject C_To_Jobj::changeAllClasses(JNIEnv *env,vector<SchoolClass> allClasses) {
    if (list_jcs == NULL) {
        LOG_D("ArrayList no  find!");
        return NULL;
    }
    //获取ArrayList构造函数id
    jmethodID list_init = env->GetMethodID(list_jcs, "<init>", "()V");
    //创建一个ArrayList对象
    jobject list_obj = env->NewObject(list_jcs, list_init, "");
    //获取ArrayList对象的add()的methodID
    int len = allClasses.size();
    for (int i=0; i<len;i++){
        jobject class_obj = changeClass(env,allClasses[i]);
        env->CallBooleanMethod(list_obj, list_add, class_obj);
    }
    return list_obj;
}
