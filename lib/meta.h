//
// Created by able on 2021/5/17.
//

#ifndef HSMS_META_H
#define HSMS_META_H

#define MAX_NAME_LENGTH 16
#define DATA_FILE "../data/students.dat"
#define SUCCESS 0
#define FAIL 1
#define MALE 0
#define FEMALE 1

struct _Student {
    char name[MAX_NAME_LENGTH];
    int gender;
    int id;
    int grade;
    double score;
};
typedef struct _Student * Student;


struct _StudentItem {
    Student item;
    struct _StudentItem* next;
};

typedef struct _StudentItem * StudentItem;

struct _StudentArray {
    StudentItem head;
    StudentItem tail;
    int length;
};
typedef struct _StudentArray* StudentArray;

///*!
// * 储存全体选学生信息
// */
//StudentArray STUDENTS;

#endif //HSMS_META_H
