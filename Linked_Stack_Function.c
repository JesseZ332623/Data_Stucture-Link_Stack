/*Linked_Stack_Function.c*/

/*Create by Jesse_EC on 2023.3.16*/
/*Copyright © 2023 Jesse_EC All rights reserved.*/

/*实现 Linked_Stack_Function.h 头文件中声明的函数*/

#include "Linked_Stack_Function.h"

/*功能01）初始化链栈*/
bool Init_Link_Stack(_Link_Stack_ *link_stack, _Stu_Info_ *stack_data, unsigned int length)
{
    link_stack->length = 0;     /*将栈长度设为0*/
    link_stack->top_ptr = NULL; /*指针指向NULL*/

    for (unsigned int data_index = 0; data_index < length; ++data_index)
    {
        Push_Link_Stack(link_stack, &stack_data[data_index]);
    }

    return true;
}

/*功能02）判断栈是否为空 如果栈元长度为0，就代表这是一个空栈*/
bool Empty_Link_Stack(_Link_Stack_ *link_stack)
{
    if (link_stack->length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*功能03）入栈 将数据插入链栈的顶栈，头节点的指针指向了新的栈顶元素。（不就是头插法嘛。。。）*/
bool Push_Link_Stack(_Link_Stack_ *link_stack, _Stu_Info_ *stack_data)
{
    _Linked_Stack_Node_ *stack_node = (_Linked_Stack_Node_ *)malloc(sizeof(_Linked_Stack_Node_));

    if(stack_node == NULL)
    {
        fprintf(stderr,"Not enough memory to allocate.....\n");
        exit(EXIT_FAILURE);
    }

    stack_node->node_data = stack_data;

    if (link_stack->length == 0)
    {
        stack_node->next = NULL;
    }
    else
    {
        stack_node->next = link_stack->top_ptr;
    }

    link_stack->top_ptr = stack_node;
    link_stack->length++;

    return true;
}

/*功能04）出栈 删除栈顶元素，然后让头节点指针下移指向下一个结点*/
bool Pop_Link_Stack(_Link_Stack_ *link_stack)
{
    if (link_stack->length == 0)
    {
        fprintf(stderr, "This is an empty link stack.\nPop faild...\n");
        return false;
    }

    _Linked_Stack_Node_ *temp_node = (_Linked_Stack_Node_*)malloc(sizeof(_Linked_Stack_Node_));

    if(temp_node == NULL)
    {
        fprintf(stderr,"Not enough memory to allocate.....\n");
        exit(EXIT_FAILURE);
    }

    temp_node->next = link_stack->top_ptr;
    link_stack->top_ptr = link_stack->top_ptr->next;

    free(temp_node);
    link_stack->length--;
    temp_node = NULL;

    return true;
}

/*功能05）读取栈内元素*/
/*使用弹栈算法将结点弹出，然后根据top指针指向的元素，遍历打印节点数据。*/
bool Print_Link_Stack(_Link_Stack_ *link_stack)
{
    if (link_stack->length == 0)                    /*若链栈内的长度为0 则代表空栈*/
    {
        fprintf(stderr,"This is an empty link stack.\n");   /*报错并输出假*/
        return false;
    }
    _Linked_Stack_Node_ *temp_node = (_Linked_Stack_Node_*)malloc(sizeof(_Linked_Stack_Node_)); /*开辟一个“中间数据”*/

    if(temp_node == NULL)       /*内存不够就报错*/
    {
        fprintf(stderr,"Not enough memory to allocate.....\n");
        exit(EXIT_FAILURE);
    }

    temp_node->next = link_stack->top_ptr;  /*指针偏移*/

    for(int data_index = 0;data_index < link_stack->length;++data_index)        /*输出链栈内数据*/
    {
        printf("No.[%d] Student_Name:[%s]\t Score: ",data_index + 1,link_stack->top_ptr->node_data->stu_name);  /*Name*/

        for(int score_index = 0;score_index < SUBJECT_COUNT; ++score_index)                                     /*Score*/
        {
            printf("[%.2lf]\t",link_stack->top_ptr->node_data->stu_score[score_index]);
        }
        putchar('\n');
        link_stack->top_ptr = link_stack->top_ptr->next;
    }
    link_stack->top_ptr = temp_node->next;  /*指针偏移*/

    free(temp_node);    /*释放掉“中间数据”的内存*/
    temp_node = NULL;   /*指针指向空防止野指针*/

    return true;
}

/*功能06）获取栈的长度*/
unsigned int Get_Stack_Length(_Link_Stack_ *link_stack)
{
    return link_stack->length;
}
