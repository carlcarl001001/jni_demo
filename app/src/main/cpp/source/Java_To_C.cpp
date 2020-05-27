//
// Created by Administrator on 2020/5/27.
//

#include "include/Java_To_C.h"
//#include <vector>
//using namespace std;

jclass Java_To_C::list_cls;
jclass Java_To_C::javaFanction_cls;
jclass Java_To_C::school_class_jcls;
jclass Java_To_C::student_jcls;

jobject Java_To_C::javaFanction_obj;
jobject Java_To_C::classes_obj;
jobject Java_To_C::school_class_obj;
jobject Java_To_C::students_obj;

jmethodID Java_To_C::getOneClassStudentsId;
jmethodID Java_To_C::sizeId;
jmethodID Java_To_C::getId;
jmethodID Java_To_C::getClassNameId;
jmethodID Java_To_C::getStudentsId;

jmethodID Java_To_C::getNameID;
jmethodID Java_To_C::getAgeID;
void Java_To_C::initStaticVariables(JNIEnv *env) {
    list_cls = env->FindClass("java/util/ArrayList");
    getId=env->GetMethodID(list_cls,"get","(I)Ljava/lang/Object;");//虽然是红色但是没错照样运行;
    sizeId=env->GetMethodID(list_cls,"size","()I");
    javaFanction_cls = env->FindClass("com/example/carl/jnidemo/model/JavaFunction");
    javaFanction_obj = env->AllocObject(javaFanction_cls);
    getOneClassStudentsId = env->GetMethodID(javaFanction_cls,"getOneClassStudents","()Ljava/util/List;");
    classes_obj = env->CallObjectMethod(javaFanction_obj,getOneClassStudentsId);

    school_class_jcls=env->FindClass("com/example/carl/jnidemo/bean/SchoolClass");
    getClassNameId = env->GetMethodID(school_class_jcls,"getClass_name","()I");
    getStudentsId =  env->GetMethodID(school_class_jcls,"getStudents","()Ljava/util/List;");

    student_jcls = env->FindClass("com/example/carl/jnidemo/bean/Student");//第二步
    getNameID = env->GetMethodID(student_jcls,"getName","()Ljava/lang/String;");//第三步
    getAgeID = env->GetMethodID(student_jcls,"getAge","()I");//第三步


}

vector<SchoolClass> Java_To_C::changeClasses(JNIEnv *env) {
    int len = env->CallIntMethod(classes_obj,sizeId);
    vector<SchoolClass> schoolClasses_v ;
    for (int i=0;i<len;i++){
        SchoolClass schoolClass;
        jobject school_class_obj = env->CallObjectMethod(classes_obj,getId,i);
        int class_name = env->CallIntMethod(school_class_obj,getClassNameId);
        schoolClass.name=class_name;
        jobject students_obj = env->CallObjectMethod(school_class_obj,getStudentsId);
        schoolClass.students = changeStudents(env,students_obj);
        schoolClasses_v.push_back(schoolClass);
    }
    return schoolClasses_v;
}
vector<Student> Java_To_C::changeStudents(JNIEnv *env,jobject students_obj) {
    int len2 = env->CallIntMethod(students_obj,sizeId);
    vector<Student> students_v;
    for (int j=0;j<len2;j++){
        jobject student_obj = env->CallObjectMethod(students_obj,getId,j);//第一步
        Student student;
        student.age = env->CallIntMethod(student_obj,getAgeID);//第四步
        jstring name=(jstring)env->CallObjectMethod(student_obj,getNameID);//第四步
        student.name = (char *)env->GetStringUTFChars(name,0);//第五步
        students_v.push_back(student);
    }
    return students_v;
}


