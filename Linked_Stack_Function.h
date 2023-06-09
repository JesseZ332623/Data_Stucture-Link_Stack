/*Linked_Stack_Function.h*/

/*Create by Jesse_EC on 2023.3.16*/
/*Copyright © 2023 Jesse_EC All rights reserved.*/

/*
采用链式存储结构实现的栈称为链栈，链栈通常采用单链表来实现，因此其结构与单链表的结构相同由于栈的插入和删除操作仅限制在栈顶位置进行，所以采用单链表的表头指针作为栈顶指针。

同时，为了操作方便，使用带头节点的单链表来实现链表。数据入栈或出栈时，使表头节点的指针指向新的表首节点即可，再入栈时，需要为新的数据元素动态的开辟存储单元，并修改头结点的指针域；

而在出栈时，除了改变头结点的指针域，还要释放原栈顶元素所占用的空间。

相比起顺序栈，链栈不依赖连续的内存空间，因此对内存的要求不会很高，但是会牺牲一点读写速度。
*/

#ifndef Linked_Stack_Function
#define Linked_Stack_Function

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STUDENT_COUNT 15       /*学生人数 15 人*/
#define NAME_LAN 10            /*姓名长度 10bytes*/
#define SUBJECT_COUNT 5        /*学科数量 5科*/

typedef double Element_Type; /*栈内的元素为 double类型*/

typedef struct Student_Information /*链栈结点的数据构成如下*/
{
    char stu_name[NAME_LAN]; /*学生姓名 String*/

    Element_Type stu_score[SUBJECT_COUNT]; /*学生成绩 Array*/

} _Stu_Info_;

typedef struct Linked_Stack_Node /*一个链栈的结点构成如下*/
{
    _Stu_Info_ *node_data; /*结点数据*/

    struct Linked_Stack_Node *next; /*结点指针，它指向了下一个结点*/

} _Linked_Stack_Node_; /*结构体别名*/

typedef struct Link_Stack /*一个链栈的结构如下*/
{
    _Linked_Stack_Node_ *top_ptr; /*top指针*/

    unsigned int length; /*链栈的长度*/

} _Link_Stack_;

/*链栈的相关操作和顺序栈并没有太多不同 q(≧▽≦q)  但这次在功能的设计上更加集成*/

/*功能01）初始化链栈*/
bool Init_Link_Stack(_Link_Stack_ *link_stack, _Stu_Info_ *stack_data, unsigned int length);

/*功能02）判断栈是否为空 如果栈元长度为0，就代表这是一个空栈*/
bool Empty_Link_Stack(_Link_Stack_ *link_stack);

/*功能03）入栈 将数据插入链栈的顶栈，头节点的指针指向了新的栈顶元素。（不就是头插法嘛。。。）*/
bool Push_Link_Stack(_Link_Stack_ *link_stack, _Stu_Info_ *stack_data);

/*功能04）出栈 删除栈顶元素，然后让头节点指针下移指向下一个结点*/
bool Pop_Link_Stack(_Link_Stack_ *link_stack);

/*功能05）读取栈内元素*/
/*使用弹栈算法将结点弹出，然后根据top指针指向的元素，遍历打印节点数据。*/
bool Print_Link_Stack(_Link_Stack_ *link_stack);

/*功能06）获取栈的长度*/
unsigned int Get_Stack_Length(_Link_Stack_ *link_stack);

#endif