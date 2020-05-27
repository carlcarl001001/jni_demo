package com.example.carl.jnidemo.bean;

import java.util.List;

public class SchoolClass {
    private int class_name;
    private List<Student> students;

    public SchoolClass(int class_name, List<Student> students) {
        this.class_name = class_name;
        this.students = students;
    }

    public int getClass_name() {
        return class_name;
    }

    public List<Student> getStudents() {
        return students;
    }
}
