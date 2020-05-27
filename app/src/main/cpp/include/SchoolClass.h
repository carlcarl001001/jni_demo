//
// Created by Administrator on 2020/5/26.
//

#ifndef JNIDEMO_SCHOOLCLASS_H
#define JNIDEMO_SCHOOLCLASS_H

#include "include/Student.h"
#include <vector>
using namespace std;

typedef struct
{
    int name;
    vector<Student> students;
} SchoolClass;

#endif //JNIDEMO_SCHOOLCLASS_H
