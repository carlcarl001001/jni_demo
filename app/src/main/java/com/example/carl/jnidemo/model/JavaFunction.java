package com.example.carl.jnidemo.model;

import android.util.Log;

import com.example.carl.jnidemo.Interface.SchoolClassInterface;
import com.example.carl.jnidemo.bean.SchoolClass;

import java.util.List;

public class JavaFunction {
    private static String TAG = "jniTest";
    static SchoolClassInterface schoolClassInterface;
    public void printLog(){
        Log.i(TAG,"this is into printLog........");
    }
    public void setLisener(SchoolClassInterface schoolClassInterface){
        JavaFunction.schoolClassInterface = schoolClassInterface;
    }
    public List<SchoolClass> getOneClassStudents(){
        Log.i(TAG,"this is into getOneClassStudents........");
        List<SchoolClass> schoolClasses = schoolClassInterface.getSchoolClass();
        return schoolClasses;
    }




}
