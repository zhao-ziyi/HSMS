#include <string.h>
#include "api.h"

//extern StudentArray STUDENTS;

int getStudentByIdFilter(Student stu, void *arg) {
    return stu->id == *((int *)arg);
}
Student getStudentById(int id,StudentArray students ) {
    StudentArray array = filter(getStudentByIdFilter, (void *)&id,students);
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
StudentArray getStudentsByName(const char *name,StudentArray students) {
    return filter(getStudentsByNameFilter, (void *)name,students);
}

int getStudentsByGenderFilter(Student stu, void *arg) {
    return stu->gender == *((int *)arg);
}
StudentArray getStudentsByGender(int gender,StudentArray students) {
    return filter(getStudentsByGenderFilter, (void *)&gender,students);
}

Student registerStudent(const char *name, int id, int gender,StudentArray STUDENTS) {
    Student stu = newStudent(id, name, gender);
    appendToArray(STUDENTS, stu);
    return stu;
//    saveStudentsToFile(DATA_FILE);
}

int setStudentName(Student stu, const char *name) {
    if (stu == NULL)
        return FAIL;
    int length = (int)strlen(name);
    if (!nameValidator(name)) {
        memset(stu->name,'\0',sizeof(char[MAX_NAME_LENGTH]));
        strncpy(stu->name, name, length);
//        saveStudentsToFile(DATA_FILE);
        return SUCCESS;
    }
    return FAIL;
}

int setStudentGender(Student stu, int gender) {
    if (stu == NULL) return FAIL;
    if (stu->gender != MALE && stu->gender != FEMALE) return FAIL;
    stu->gender = gender;
//    saveStudentsToFile(DATA_FILE);
    return SUCCESS;
}

int setStudentGrade(Student stu, int grade) {
    if (stu == NULL)
        return FAIL;
    if (grade > 4 || grade < 1)
        return FAIL;
    stu->grade = grade;
//    saveStudentsToFile(DATA_FILE);
    return SUCCESS;
}

int setStudentScore(Student stu, double score) {
    if (stu == NULL)
        return FAIL;
    if (score > 5.0 || score < 0)
        return FAIL;
    stu->score = score;
 //   saveStudentsToFile(DATA_FILE);
    return SUCCESS;
}

int deleteStudent(Student stu,StudentArray STUDENTS) {
    if(stu==STUDENTS->head->item)
    {
//        StudentItem target=STUDENTS->head;
        STUDENTS->head=STUDENTS->head->next;
//        free(target->item);
//        free(target);
        STUDENTS->length--;
    }
     for (StudentItem it=STUDENTS->head; it!=NULL&&it->next!=NULL; it=it->next) {
         if (it->next->item == stu) {
             StudentItem target = it->next;
             StudentItem child = target->next;
             it->next = child;
//             free(target->item);
 //            free(target);
             STUDENTS->length--;
         }
     }
     return SUCCESS;
 }
