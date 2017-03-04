//
//  main.c
//  CLinkList
// 0x0000000100202b10 head
// 0x0000000100600200 findedHead
//  Created by 王亓泰 on 16/4/13.
// 
//

// 测试数据
/*
 姓名:zhao 学号:1001 年龄:19 成绩:91
 姓名:qian 学号:1002 年龄:29 成绩:92
 姓名:sun 学号:1003 年龄:39 成绩:93
 姓名:li 学号:1004 年龄:49 成绩:94
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct student {
    char name[20]; // 姓名
    char ID[20];   // 学号
    int age;       // 年龄
    int score;     // 成绩
    struct student * next;
}stu_t;
// 创建节点
stu_t *create_node(void);
// 添加节点
void add_node(stu_t * head, stu_t *student);
// 遍历节点
void travel_list(stu_t * head, void (*func)(stu_t * student));

stu_t * find_node(stu_t * head, stu_t *student);
void find_students(stu_t * head, stu_t *student);
// 打印链表
void print_list(stu_t * head);
// 打印节点
void print_node(stu_t * student);

int main(int argc, const char * argv[]) {
    
    stu_t *head = create_node();
    
    while (1) {
        printf("请选择操作:(1)添加一名学生 (2)打印所有学生信息 (3)通过姓名查找一名学生 (4)通过学号查找一名学生 (5)通过姓名删除学生\n");
    
        int ctrl;
        scanf("%d",&ctrl);
        if (ctrl == 1) {
            printf("请输入学生姓名, 学号, 年龄, 成绩\n");
            // 创建结构体, 存储数据
            stu_t *new_student = create_node();
            scanf("%s%s%d%d",new_student->name, new_student->ID, &new_student->age, &new_student->score);
//            stu_t *h = head;
//            while (h->next) {
//                h = h->next;
//            }
//            h->next = new_student;
//            new_student->next = NULL;
            add_node(head, new_student);
            
            
        } else if (ctrl == 2) {
            print_list(head);
        } else if (ctrl == 3) {
            
            printf("请输入学生的姓名:\n");
            // 创建一个参照数据源
            stu_t *student = create_node();
            scanf("%s",student->name);
            stu_t * p = head;
            // 通过参照数据源, 查找学生
            find_students(p,student);
           
        }
    
    }
    
    return 0;
}
stu_t *create_node(void)
{
    stu_t *p = (stu_t *)malloc(sizeof(stu_t));
    if (!p) {
        perror("malloc");
    }
    p->next = NULL;
    return p;
}

void add_node(stu_t * head, stu_t *student) // fix me
{
    while (head->next) {
        head = head->next;
    }
    
    head->next = student;
    student->next = NULL;
}

void travel_list(stu_t * head, void (*func)(stu_t *))
{
    while (head->next) {
        head = head->next;
        func(head);
    }
}

//void print_list(stu_t * head)
//{
//    while ((head = head->next)) {
//        print_node(head);
//    }
//}


void print_list(stu_t * head)
{
    travel_list(head, print_node);
}


void print_node(stu_t * student)
{
    printf("姓名:%s 学号:%s 年龄:%d 成绩:%d\n",student->name, student->ID, student->age, student->score);
}

stu_t * find_node(stu_t * head, stu_t *student)
{
    // 返回值是一个链表
    stu_t * findedHead = create_node();
    // head 3af0
    // findedHead 0080
    while (head->next) {
        head = head->next;
        if (strcmp(head->name, student->name) == 0) {
            add_node(findedHead, student); // fix me
        }
    }
    return findedHead;
}

void find_students(stu_t * head, stu_t *student)
{
    stu_t *find = find_node(head, student);
    print_list(find);
}
