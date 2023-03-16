# Data_Stucture-Link_Stack

数据结构：链栈（链式栈）的相关概念
----------------------------------------------------------------------------------------------------------------------------------
采用链式存储结构实现的栈称为链栈，链栈通常采用单链表来实现，
因此其结构与单链表的结构相同由于栈的插入和删除操作仅限制在栈顶位置进行，所以采用单链表的表头指针作为栈顶指针。

同时，为了操作方便，使用带头节点的单链表来实现链表。
数据入栈或出栈时，使表头节点的指针指向新的表首节点即可，再入栈时，需要为新的数据元素动态的开辟存储单元，并修改头结点的指针域；

而在出栈时，除了改变头结点的指针域，还要释放原栈顶元素所占用的空间。

相比起顺序栈，链栈不依赖连续的内存空间，因此对内存的要求不会很高，但是会牺牲一点读写速度。

