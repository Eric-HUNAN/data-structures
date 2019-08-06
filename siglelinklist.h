#pragma once

#include "iostream"
#include "exception"
#include "stdlib.h"
#include "malloc.h"

using namespace std;

//结点类
template<class T>
class Node
{
public:
	T data;
	Node<T>  *next;
	Node()
	{
		this->next = NULL;
	}
	Node(T data, Node<T>* next = NULL)
	{
		this->data = data;
	}
	~Node() {};
};

//定义链表类
template<class T>
class SLinkList
{
public:
	Node<T>	node; //结点
	Node<T>* head; //头指针

	SLinkList();			  //创建链表
	SLinkList(int num, T elem[]);
	SLinkList(int num);
	~SLinkList();

	int LengthSLinkList();	   //表长
	void InsertNode(int i, T elem);	  //插入结点
    void InsertNode(T elem);
	void DeleteNode(int i);	 //删除结点
	void DeleteAllNode();	 //删除表
	T GetElem(int i);		 //按序号查找
	int* GetNum(T elem);		 //按元素查找
	void OutputList();       //输出
};

template<class T>
SLinkList<T>::SLinkList()
{
	Node<T>* p = new Node<T>();
	this->head = p;
	cout << "finish<SLinkList()>!" << endl;
}

template<class T>
SLinkList<T>::SLinkList(int num, T elem[])
{
	try
	{
		if(num < 1)
			throw length_error("输入初始化num参数必须大于1！");
		else
		{
			Node<T>* p = new Node<T>();
			this->head = p;
			Node<T>* temp = this->head;
			for (int i = 0; i < num; i++)
			{
				temp->next = new Node<T>(*(elem + i)); 	//这里犯了一个错，就是把elem[i]直接丢进去，（）里面放的是T类型初始值，实参传进来的是T* elem[]，无法用下标进行访问
				temp = temp->next;
			}
			temp->next = NULL;
			cout << "finish<SL]inkList(int num, T elem[])>!" << endl;
		}
	}
	catch(length_error e)
	{
		cout << "info:" << e.what() << endl;
		exit(1);
	}
}

template<class T>
SLinkList<T>::SLinkList(int num)
{
	try
	{
		if (num < 1)
			throw length_error("输入初始化参数num必须大于1！");
		else
		{
			Node<T>* p = new Node<T>();
			this->head = p;
			Node<T>* temp = this->head;
			for(int i = 1; i <= num; i++)
			{
				temp->next = new Node<T>();
				temp = temp->next;
			}
			temp->next = NULL;
			cout << "finish<SLinkList(int num)>!" << endl;
		}
	}
	catch(length_error e)
	{
		cout << "info:" << e.what() << endl;
		exit(0);
	}
}

//调用函数析构
/*
template<class T>
SLinkList<T>::~SLinkList()
{
	this->DeleteAllNode();
}
*/

template<class T>
SLinkList<T>::~SLinkList()
{
	Node<T>* p = this->head;
	Node<T>* temp = p->next;
	Node<T>* q = NULL;
	while(temp)
	{
		q = temp;
		temp = temp->next;
		delete q;
	}
	delete p;
	delete temp;
	cout << "finish ~SLinkList()" << endl;
}

template<class T>
int SLinkList<T>::LengthSLinkList()
{
	int count = 0;
	Node<T>* p = this->head;
	Node<T>* temp = p->next;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

template<class T>
void SLinkList<T>::InsertNode(int i, T elem)
{
	try
	{
		if(i<1 || i>LengthSLinkList() + 1)
			throw out_of_range("输入的参数i值超出了链表的范围！");
		else
		{
			if (i != LengthSLinkList()+1)	 //1-len之间插入
			{
				Node<T>* Elem = new Node<T>(elem);
				Node<T>* temp = this->head;
				for (int j = 1; j < i; j++)
					temp = temp->next;
				Node<T>* p = temp->next;
				temp->next = Elem;
				Elem->next = p;
			}
			else
				InsertNode(elem);	 //在末尾插入
			cout << "finish<Insert(int i, T elem)>!" << endl;
		}
    }
	catch(out_of_range e)
	{
		cout << "info:" << e.what() << endl;
		exit(0);
	}
}

template<class T>
void SLinkList<T>::InsertNode(T elem)	   //末尾插入
{
	Node<T>* Elem = new Node<T>(elem);
	Node<T>* temp = this->head;
	Node<T>* p = NULL;
	while (temp)
	{
		p = temp;
		temp = temp->next;
	}
	p->next = Elem;
	Elem->next = NULL;
	cout << "finnish<InsertNode(T elem)>!" << endl;
}

template<class T>
void SLinkList<T>::DeleteNode(int i)			 //返回的是被删除的值
{
	try
	{
		if (i<1 || i > LengthSLinkList())
			throw out_of_range("输入的参数i值超出了链表的范围！");
		else
		{
			Node<T>* temp = this->head;
			for (int j = 1; j < i; j++)
				temp = temp->next;
			Node<T> *p = temp->next;
			temp->next = p->next;
			cout << "finish<DeleteNode(int i)>!" << endl;
		}
	}
	catch(out_of_range e)
	{
		cout << "info:" << e.what() << endl;
		exit(1);
	}
}

template<class T>
void SLinkList<T>::DeleteAllNode()
{
	Node<T>* temp = this->head;
	int count = this->LengthSLinkList();
	while(count)
	{
		DeleteNode(count);
		count--;
	}
	delete temp;
	cout << "finish<DeleteAllNode()>!" << endl;
}

template<class T>
T SLinkList<T>::GetElem(int i)
{
	try
	{
		if(i<1 || i > LengthSLinkList())
			throw out_of_range("输入参数i值超出了链表的范围！");
		else
		{
			Node<T>* temp = this->head;
			for(int j = 1; j <=i; j++)
				temp = temp->next;
			cout << "finish!" << endl;
			cout << "finish<GetElem(int i)>! " << endl;
			return temp->data;
		}
	}
	catch(out_of_range e)
	{
		cout << "info:" << e.what() << endl;
		exit(1);
	}
}

template<class T>
int* SLinkList<T>::GetNum(T elem)
{
	Node<T>* p = this->head;
	Node<T>* temp = p->next;
	int* count = new int[LengthSLinkList()];
	int j = 0;
	for(int i = 1; i <= LengthSLinkList(); i++)		 
	{
		if(temp->data == elem)
		{
			count[j] = i;
			j++;
		}
		else
			temp = temp->next;
	}
	cout << "finish<GetNum(T elem)>!" << endl;
	return count;
}

template<class T>
void SLinkList<T>::OutputList()
{
	Node<T>* p = this->head;
	Node<T>*	temp = p->next;
	cout << "output list："  ;

	for(int i = 1; i <= LengthSLinkList(); i++)
	{
		cout << temp->data << "     " ;
		temp = temp->next;
	}
	cout << endl;
}
