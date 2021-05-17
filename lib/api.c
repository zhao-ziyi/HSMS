#include <string.h>
#include "api.h"

int getStudentByIdFilter(Student stu, void *arg) {
    return stu->id == *((int *)arg);
}
Student getStudentById(int id) {
    StudentArray array = filter(getStudentByIdFilter, (void *)&id);
    if (array->length == 0) {
        return NULL;
    }
    Student stu = array->head->item;
    destroyStudentArray(array);
    return stu;
}

int getStudentsByNameFilter(Student stu, void *arg) {
    return strcmp(stu->name, (char *)arg) == 0;
}
StudentArray getStudentsByName(const char *name) {
    return filter(getStudentsByNameFilter, (void *)name);
}

int getStudentsByGenderFilter(Student stu, void *arg) {
    return stu->gender == *((int *)arg);
}
StudentArray getStudentsByGender(int gender) {
    return filter(getStudentsByGenderFilter, (void *)&gender);
}

Student registerStudent(const char *name, int id, int gender) {
    Student stu = newStudent(id, name, gender);
    appendToArray(STUDENTS, stu);
    saveStudentsToFile(DATA_FILE);
}

int setStudentName(Student stu, const char *name) {
    if (stu == NULL)
        return FAIL;
    int length = (int)strlen(name);
    if (!nameValidator(name)) {
        strncpy(stu->name, name, length);
        saveStudentsToFile(DATA_FILE);
        return SUCCESS;
    }
    return FAIL;
}

int setStudentGender(Student stu, int gender) {
    if (stu == NULL) return FAIL;
    if (stu->gender != MALE && stu->gender != FEMALE) return FAIL;
    stu->gender = gender;
    saveStudentsToFile(DATA_FILE);
    return SUCCESS;
}

int setStudentGrade(Student stu, int grade) {
    if (stu == NULL)
        return FAIL;
    if (grade > 4 || grade < 1)
        return FAIL;
    stu->grade = grade;
    saveStudentsToFile(DATA_FILE);
    return SUCCESS;
}

int setStudentScore(Student stu, double score) {
    if (stu == NULL)
        return FAIL;
    if (score > 5.0 || score < 0)
        return FAIL;
    stu->score = score;
    saveStudentsToFile(DATA_FILE);
    return SUCCESS;
}