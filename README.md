# HSMS
HDU Student Management System

杭电学生管理系统

## 功能

录入，修改，查看，删除学生信息

## 学生信息

1. 学号
2. 姓名
3. 性别
4. 年级
5. 总评绩点

## 常量

程序运行时的常量定义在了 `meta.h` 中。

```c
// ...
// 学生姓名的最大长度
#define MAX_NAME_LENGTH 16
// 保存文件学生信息的文件
#define DATA_FILE "data/students.dat"
// 函数执行状态
#define SUCCESS 0
#define FAIL 1
// 学生性别
#define MALE 0
#define FEMALE 1
// ...
```

## 初始化与退出前工作

`api.c` 中提供了两个函数来处理初始化与退出前工作：

* `int init()`

  完成读取文件，构建学生对象等操作。返回值表示是否执行成功。

* `int defer()`

  在退出前完成数据写入，内存释放等工作。返回值表示是否执行成功。
  
  ```c
  #include <stdio.h>
  #include "lib/api.h"
  
  int main()
  {
      if (init()==FAIL) {
          printf("初始化失败!\n");
          return 1;
      }
      // your code here
      return 0;
  }
  ```
  
  
## 导入 api

```c
// main.c

// #include xxx.h
#include "lib/api.h"

int main()
{
    init();
    // your code here
    defer();
    return 0;
}
```


## API

* `int saveStudentsToFile(const char *filename)`
  将学生信息保存至文件, 默认文件名定义在了 `meta.h` 中。
  
* `Student getStudentById(int id)`

  获取指定学号的学生。

* `StudentArray getStudentsByName(const char *name)`

  获取指定姓名的学生，以为可能出现重名的情况，返回一个 `StudentArray`,返回学生的个数通过 `length` 属性获取。

  ```c
  StudentArray array = getStudentsByName("卢本伟");
  pritnf("一共有 %d 学生\n", array->length);
  for (StudentItem it=array->head; it!=NULL; it=it->next) {
      Student stu = it->item;
      printf("%s %d %d %d %lf", stu->name, stu->gender, std->grade, stu->id, stu->score);
  }
  ```

* `StudentArray getStudentsByGender(int gender)`
  获取指定性别的所有学生。
  
  ```c
  StudentArray boys = getStudentsByGender(MALE);
  StudentArray girls = getStudentsByGender(FEMALE);
  ```
  
* `Student registerStudent(const char *name, int id, int gender)`

  添加一个学生到管理系统中。

* `int setStudentName(Student stu, const char *name)`

  修改一个学生的姓名

  ```c
  Student stu = getStudentById(20051200);
  setStudentName(stu, "卢本伟");
  ```

* `int setStudentGender(Student stu, int gender)`
  修改学生性别
  
* `int setStudentGrade(Student stu, int grade)`
  修改学生所在年级
  
* `int setStudentScore(Student stu, double score)`
  修改学生综合绩点
  



## 内存管理

`StudentArray` 本质上是一个单链表，使用动态内存分配实现，`api.c` 中实现了完整释放`StudentArray`的方法，用完请手动释放内存。

```c
StudentArray array = getStudentsByGender(MALE);
// your code here
destroyStudentArray(array);
```

