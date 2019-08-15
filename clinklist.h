#pragma once

#include "iostream"
#include "stdlib.h"
#include "malloc.h"
#include "exception"

using namespace std;

template<class T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node()
	{
		this->next = NULL;
	}
	Node(T elem)
	{
		this->data = elem;
		this->next = NULL;
	}
	~Node(){};
};

template<class T>
class CLinkList
{
public:
	Node<T>* head;													   //头指针
	Node<T>* p;														   //用于创建Node类指针
	CLinkList();							                           //构造函数
	CLinkList(int num, T elem[]);
	~CLinkList();													   //析构函数

	int Length();													   //长度
	bool Empty();													   //判断是否为空
	void InsertNode(T elem);										   //增
	void InsertNode(int num, T elem);
	void DeNode(int num);										       //删
	void DeNode_1(T elem);
	T GetElem(int num);												   //查
	void GetElem_1(T elem);
	friend ostream& operator<<<>(ostream& output, CLinkList<T>& clink);		   //重载<<
private:
	Node<T> node;
	int link_len;
	int link_size;
};

template<class T>
CLinkList<T>::CLinkList()
{
	this->p = (Node<T>*)malloc(sizeof(Node<T>));
	this->head = this->p;
	this->head->next = this->p;
	this->link_len = 0;
	this->link_size = 1;
	cout << "test CLinkList()" << endl;
}

template<class T>
CLinkList<T>::CLinkList(int num, T elem[])						  //头指针也放数据
{
	this->link_len = 0;
	Node<T>* temp = NULL;
	this->p = (Node<T>*)malloc(sizeof(Node<T>));				  //定义第一个节点（头指针指向的）
	this->p->data = elem[0];									  //赋值第一个元素
	this->head = this->p;										  //使头指针指向第一个节点
	temp = this->head;
	for(int i = 1; i <= num; i++)								  //形成link
	{
		this->p = (Node<T>*)malloc(sizeof(Node<T>));
		this->p->data = *(elem + i);
		temp->next = this->p;
		temp = this->p;
		(this->link_len)++;
	}
	this->p->next = this->head;
	this->link_size = num;
}

template<class T>
CLinkList<T>::~CLinkList()
{
	free(this->p);
}

template<class T>
int CLinkList<T>::Length()
{
	return this->link_len;
}

template<class T>
bool CLinkList<T>::Empty()
{
	if(this->link_len == 0)
		return 1;
	else
		return 0;
}

template<class T>
void CLinkList<T>::InsertNode(T elem)
{
	this->p = this->head;
	int num = 1;
	while(num < Length())
	{
		this->p = this->p->next;
		num++;
	}
	this->p->next = (Node<T>*)malloc(sizeof(Node<T>));
	this->p->next->data = elem;
	this->p->next->next = this->head;
	(this->link_len)++;
	(this->link_size)++;
}

template<class T>
void CLinkList<T>::InsertNode(int num, T elem)
{
	this->p = this->head;
	for(int i = 1; i < num - 1; i++)
		this->p = this->p->next;
	Node<T>* temp = this->p->next;
	this->p->next = (Node<T>*)malloc(sizeof(Node<T>));
	this->p->next->data = elem;
	this->p->next->next = temp;
	(this->link_len)++;
	(this->link_size)++;
}

template<class T>
void CLinkList<T>::DeNode(int num)
{
	this->p = this->head;
	if(num == 1)
	{
		Node<T>* temp = this->head;
		this->head = this->p->next;
		(this->link_len)--;
		(this->link_size)--;
		return;
	}
	for(int i = 1; i < num - 1; i++)
		this->p = this->p->next;
	Node<T>* temp = this->p->next;
	this->p->next = this->p->next->next;
	(this->link_len)--;
	(this->link_size)--;
}

template<class T>
void CLinkList<T>::DeNode_1(T elem)
{																
	this->p = this->head;
	int* temp = new int[this->link_len];		                    //开辟动态数组用于存放元素为elem的下标
	int i = 0, j = 0;
	while (this->p->next != this->head)								//遍历链表找elem的下标
	{
		i++;
		if(this->p->data == elem)
		{
			temp[j] = i;
			j++;
		}
		this->p = this->p->next;
	}
	int len = 0;													//删除一次链表的长度会发生变化，这个参数反馈长度变化，每做一次删除长度减1
	for(int k = 0; k < j; k++)
	{
		DeNode(temp[k] - len);
		len++;
	}
	free(temp);
	
}

template<class T>
T CLinkList<T>::GetElem(int num)
{
	try
	{
		if(num > this->link_len)
			throw out_of_range("输入的num值超出范围！");
		this->p = this->head;
		for(int i =0; i < num - 1; i++)
			this->p = this->p->next;
		T elem;
		elem = this->p->data;
		return elem;
	}
	catch(out_of_range e)
	{
		cout << "info:" << e.what() << endl;
		exit(1);
	}
}

template<class T>
void CLinkList<T>::GetElem_1(T elem)
{
	this->p = this->head;
	int* temp = (int*)malloc((this->link_len) * sizeof(int));		//开辟动态数组用于存放元素为elem的下标
	int i = 0, j = 0;
	while (this->p->next != this->head)								//遍历链表找elem的下标
	{
		i++;
		if(this->p->data == elem)
		{
			temp[j] = i;
			j++;
		}
		this->p = this->p->next;
	}
	if(j == 0)
		cout << "不存在" << elem << "元素" << endl;
	else
	{
		cout << "number:" ;
		for(int k = 0; k < j; k++)
			cout << temp[k] << "  " ;
		cout << endl;
	}
}

template<class T>
ostream& operator<< <>(ostream& output, CLinkList<T>& clink)
{
	output << "输出信息:";
	output << endl;
	clink.p = clink.head;
	int num = 1, i = 0;
	while(i < clink.Length())
	{
		output << "第" << num << "个元素：" << "  ";
		output << clink.p->data << endl;
		num++;
		clink.p = clink.p->next;
		i++;
	}
	return output;
}
