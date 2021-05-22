#ifndef HSMS_UTIL_H
#define HSMS_UTIL_H

#include "meta.h"

/*!
 * init - 初始化 HSMS
 * @return status
 */
int init();

/*!
 * defer - 执行退出前工作
 * @return status
 */
int defer();

/*!
 * newStudent - 创建一个学生对象
 * @param id
 * @param name
 * @param gender
 * @return Student
 */
Student newStudent(int id, const char *name, int gender);

/*!
 * newStudentArray - 创建一个学生数组
 * @return StudentArray
 */
StudentArray newStudentArray();

/*!
 * appendToArray - 将一个 Student 对象加入 StudentArray
 * @param array
 * @param student
 * @return status
 */
int appendToArray(StudentArray array, Student student);

/*!
 * loadStudentsFromFile - 从文件中读取学生信息
 * @param filename
 * @return StudentArray
 */
StudentArray loadStudentsFromFile(const char *filename);

/*!
 * saveStudentsToFile - 将学生信息保存至文件
 * @param filename
 * @return status
 */
int saveStudentsToFile(const char *filename,StudentArray students);

/*!
 * destroyStudentArray - 销毁一个 StudentArray
 * @param array
 * @return status
 */
int destroyStudentArray(StudentArray array);

/*!
 * 从 STUDENTS 里筛选特定的学生，筛选规则由 func 指定
 * @param func - 比较函数
 * @return StudentArray
 */
StudentArray filter(int(*func)(Student, void *), void *arg,StudentArray students);

/*!
 * nameValidator - 学生名字验证器，检查学生名字是否超过长度，包含空格等
 * @param name
 * @return int 符合规范返回 SUCCESS， 否则返回 FAIL
 */
int nameValidator(const char *name);

#endif //HSMS_UTIL_H
