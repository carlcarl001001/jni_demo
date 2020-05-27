package com.example.carl.jnidemo.model;

import android.util.Log;

import com.example.carl.jnidemo.Interface.SchoolClassInterface;
import com.example.carl.jnidemo.bean.SchoolClass;
import com.example.carl.jnidemo.bean.Student;

import java.util.ArrayList;
import java.util.List;

public class JniModel {

    static {
        System.loadLibrary("interface_test");
    }
    private static String TAG = "jniTest";
    public native String stringFromJNI();

    public native List<SchoolClass> getOneClassFromC();

    public void getOneClass(){
        JavaFunction javaFunction = new JavaFunction();
        javaFunction.setLisener(new SchoolClassInterface() {
            @Override
            public List<SchoolClass> getSchoolClass() {
                Student student1 =new Student("aa1",18);
                Student student2 =new Student("bb1",20);
                Student student3 =new Student("cc1",17);
                List students = new ArrayList();
                students.add(student1);
                students.add(student2);
                students.add(student3);
                SchoolClass schoolClass1 = new SchoolClass(1,students);
                Student student4 =new Student("aa2",4);
                Student student5 =new Student("bb2",1);
                Student student6 =new Student("cc2",5);
                List students2 = new ArrayList();
                students2.add(student4);
                students2.add(student5);
                students2.add(student6);
                SchoolClass schoolClass2 = new SchoolClass(2,students2);
                List<SchoolClass> schoolClasses = new ArrayList<>();
                schoolClasses.add(schoolClass1);
                schoolClasses.add(schoolClass2);
                return schoolClasses;
            }
        });

        List<SchoolClass> schoolClasses = getOneClassFromC();
        printSchoolClasses(schoolClasses);


    }
    private void printSchoolClasses( List<SchoolClass> schoolClasses){
        for (int i=0;i<schoolClasses.size();i++){
            Log.i(TAG,"class name:"+schoolClasses.get(i).getClass_name());
            Log.i(TAG,"students:"+schoolClasses.get(i).getStudents().toString());
        }

    }


}
