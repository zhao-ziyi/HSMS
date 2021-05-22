#ifndef HSMS_API_H
#define HSMS_API_H

#include "meta.h"
#include "util.h"
#include <stdlib.h>

/*!
 * getStudentById - 通过学号查找学生
 *
 * @param id
 * @return Student
 */
Student getStudentById(int id,StudentArray students);

/*!
 * getStudentsByName - 通过姓名查找学生
 *
 * @param name
 * @return StudentArray
 */
StudentArray getStudentsByName(const char *name,StudentArray students);

/*!
 * getStudentsByGender - 返回特定性别的学生
 * @param gender
 * @return
 */
StudentArray getStudentsByGender(int gender,StudentArray students);

/*!
 * registerStudent - 注册一个学生
 * @param name
 * @param id
 * @param gender
 * @return Student
 */
Student registerStudent(const char *name, int id, int gender,StudentArray students);

/*!
 * setStudentName - 修改学生姓名
 * @param stu
 * @param name
 * @return status
 */
int setStudentName(Student stu, const char *name);

/*!
 * setStudentGender - 修改学生性别
 * @param stu
 * @param gender
 * @return status
 */
int setStudentGender(Student stu, int gender);

/*!
 * setStudentGrade - 修改学生所在年级
 * @param stu
 * @param grade
 * @return
 */
int setStudentGrade(Student stu, int grade);

/*!
 * setStudentScore - 修改学生综合绩点
 * @param stu
 * @param score
 * @return status
 */
int setStudentScore(Student stu, double score);

int deleteStudent(Student stu,StudentArray);

#endif //HSMS_API_H
