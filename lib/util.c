#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

int init() {
    STUDENTS = loadStudentsFromFile(DATA_FILE);
    return SUCCESS;
}

int defer() {
    saveStudentsToFile(DATA_FILE);
    destroyStudentArray(STUDENTS);
    return SUCCESS;
}

Student newStudent(int id, const char *name, int gender) {
    if (nameValidator(name)==FAIL) {
        return NULL;
    }
    Student stu = (Student)malloc(sizeof(struct _Student));
    strcpy(stu->name, name);
    stu->id = id;
    stu->gender = gender;
    return stu;
}

StudentItem newStudentItem(Student stu) {
    StudentItem s = (StudentItem)malloc(sizeof(struct _StudentItem));
    s->item = stu;
    s->next = NULL;
    return s;
}

StudentArray newStudentArray() {
    StudentArray a = (StudentArray)malloc(sizeof(struct _StudentArray));
    a->length = 0;
    a->head = NULL;
    a->tail = NULL;
    return a;
}

int appendToArray(StudentArray array, Student student) {
    StudentItem s = newStudentItem(student);
    if (array->length == 0) {
        array->tail = s;
        array->head = s;
        array->length = 1;
        return SUCCESS;
    }
    array->length++;
    s->item = student;
    array->tail->next = s;
    array->tail = s;
    return SUCCESS;
}

int destroyStudentArray(StudentArray array) {
    StudentItem tmp;
    for (StudentItem item=array->head; item!=NULL; item = tmp) {
        tmp = item->next;
        free(item->item);
        free(item);
    }
    return SUCCESS;
}

FILE *openfile(const char *filename, const char *mode) {
    FILE *fp = fopen(filename, mode);
    if (fp == NULL) {
        fprintf(stderr, "failed to open file: %s\n", filename);
        exit(1);
    }
    return fp;
}

StudentArray loadStudentsFromFile(const char *filename) {
    FILE *fp = openfile(filename, "r");
    int id, gender, grade;
    double score;
    char name[MAX_NAME_LENGTH];

    StudentArray array = newStudentArray();

    while (fscanf(fp, "%s %d %d %d %lf", name, &id, &gender, &grade, &score)!=EOF) {
        Student stu = newStudent(id, name, gender);
        stu->grade = grade;
        stu->score = score;
        appendToArray(array, stu);
    }
    fclose(fp);
    return array;
}

int saveStudentsToFile(const char *filename) {
    FILE *fp = openfile(filename, "w");
    for (StudentItem it=STUDENTS->head; it!=NULL; it=it->next) {
        Student stu = it->item;
        fprintf(fp, "%s %d %d %d %lf\n", stu->name, stu->id, stu->gender, stu->grade, stu->score);
    }
    fclose(fp);
    return SUCCESS;
}

StudentArray filter(int(*func)(Student, void*), void *arg) {
    StudentArray array = newStudentArray();

    for (StudentItem it=STUDENTS->head; it!=NULL; it=it->next) {
        if (func(it->item, arg)) {
            appendToArray(array, it->item);
        }
    }
    return array;
}

int nameValidator(const char *name) {
    int length = (int)strlen(name);
    if (length >= MAX_NAME_LENGTH) {
        return 1;
    }
    for (int i=0; i<length; i++) {
        if (name[i] == ' ') {
            return 1;
        }
    }
    return 0;
}