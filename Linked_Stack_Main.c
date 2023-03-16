/*Linked_Stack_Main.c*/

/*Create by Jesse_EC on 2023.3.16*/
/*Copyright © 2023 Jesse_EC All rights reserved.*/

/*调用Linked_Stack_Function.c实现的各种函数，完成链栈的各种操作（一个简易的，存储学生信息的数据库）*/

#include "Linked_Stack_Function.h"
#include <windows.h>
#include <time.h>

_Stu_Info_ *Student_Informatin(); /*学生信息存储*/
void Test_Link_Stack();

_Stu_Info_ *Student_Informatin()
{
    static _Stu_Info_ stu_info[STUDENT_COUNT] =
        {
            {"Jesse_EC", 95.00, 80.60, 76.00, 81, 65.50}, {"Mike", 99.00, 85.50, 86.00, 83.00, 55.50}, {"Oriana", 90.00, 85.50, 86.00, 83.00, 55.50}, 
            {"Atwood", 95.20, 85.50, 86.00, 83.00, 65.50}, {"Abner", 92.00, 85.50, 86.00, 83.00, 65.50}, {"Adamson", 94.30, 95.50, 96.00, 93.00, 75.50}, 
            {"Dafydd", 92.00, 85.50, 86.00, 83.00, 55.50}, {"Desmond", 90.00, 85.50, 80.00, 83.00, 75.50}, {"Xavier", 70.50, 85.50, 76.00, 83.00, 55.50}, 
            {"Xenia", 80.00, 75.50, 86.00, 83.00, 75.50}, {"Olga", 80.00, 95.50, 86.00, 83.00, 55.50}, {"Octavia", 90.00, 85.50, 96.00, 83.00, 55.50}, 
            {"Oonagh", 82.00, 85.50, 86.00, 83.00, 95.50}, {"Ora", 65.00, 85.50, 85.00, 73.00, 55.50}, {"Ormonda", 80.00, 75.50, 86.00, 80.50, 65.50}
        };

    return stu_info; /*返回这个结构体数组的首地址*/
}

void Test_Link_Stack()
{

    _Stu_Info_ *stu_info = Student_Informatin();

    _Link_Stack_ *link_stack = (_Link_Stack_ *)malloc(sizeof(_Link_Stack_)); /*开辟一个栈的内存*/

    if (Init_Link_Stack(link_stack, stu_info, STUDENT_COUNT)) /*初始化链栈，并压入学生的数据*/
    {
        puts("Init Stack Finish....");
    }
    puts("------------------------------------------------------------------------------------------------------------------");
    puts("After Push_Stack");
    printf("Now,The length of stack is:[%u].\n", Get_Stack_Length(link_stack)); /*压栈完成后获取栈的长度*/
    puts("------------------------------------------------------------------------------------------------------------------");
    puts("------------------------------------------------------------------------------------------------------------------");
    if (Print_Link_Stack(link_stack)) /*读取栈数据*/
    {
        puts("Print finish....");
    }
    puts("------------------------------------------------------------------------------------------------------------------");
    puts("OUT 5 students to this stack....");
    puts("------------------------------------------------------------------------------------------------------------------");
    for (int stack_index = 0; stack_index < 5; ++stack_index) /*从栈顶开始出栈5位学生的数据*/
    {
        if (Pop_Link_Stack(link_stack))
        {
            printf("The student:[%s] OUT STACK.....\n", link_stack->top_ptr->node_data->stu_name);
        }
    }
    printf("Now,The length of stack is:[%u].\n", Get_Stack_Length(link_stack));
    puts("------------------------------------------------------------------------------------------------------------------");

    if (Print_Link_Stack(link_stack)) /*出栈完成后再次读取栈数据*/
    {
        puts("Print finish....");
    }

    free(link_stack);               /*完成上述操作后释放掉这个链栈*/
    link_stack = NULL;

    puts("Free_Meomry Successe.....");
    
}

int main(int argc, char const *argv[])
{
    system("Color A");

    printf("\n#[%s] [%s]\n\n",__DATE__,__FILE__);

    Test_Link_Stack();

    system("Pause");

    return 0;
}

/*Author:Jesse_EC  ヾ(≧▽≦*)o*/
