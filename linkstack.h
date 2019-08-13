#pragma once

#include "iostream"
#include "stdlib.h"
#include "malloc.h"

using namespace std;


template<class T>		 //定义结点类
class Node
{
public:
	T data;
	Node* next;
	Node()
	{
		this->next = NULL;
	}
	Node(T elem, Node* next = NULL)
	{
		this->data = elem;
	}
	~Node(){};
};

template<class T>
class LinkStack
{
public:
	Node<T>* top;
	Node<T>* base;
	LinkStack();
	LinkStack(int num, T elem[]);
	~LinkStack();

	int Length();
	bool Empty();
	void Push(T elem);
	T Pop();
	friend ostream& operator<<<>(ostream& output, LinkStack<T>& linkstack);
private:
	Node<T> node;
	int stack_len;
};

template<class T>
LinkStack<T>::LinkStack()
{
	this->top = new Node<T>();
	this->base = this->top;
}

template<class T>
LinkStack<T>::LinkStack(int num, T elem[])
{
	stack_len = 0;
	Node<T>* temp = NULL;
	this->top = new Node<T>();
	this->base = this->top;
	for (int i = 0; i < num; i++)
	{
		temp = this->top;
		this->top = new Node<T>(*(elem + i));
		this->top->next = temp;
		this->stack_len++;
	}
}

template<class T>
LinkStack<T>::~LinkStack()
{
	Node<T>* temp = NULL;
	while(this->top->next)
	{
		temp = this->top;
		this->top = this->top->next;
		delete temp;
	}
	delete this->top;
}

template<class T>
int LinkStack<T>::Length()
{ 
	return this->stack_len;
}

template<class T>
bool LinkStack<T>::Empty()
{
	if(this->top == this->base)
		return 1;
	else
		return 0;
}

template<class T>
void LinkStack<T>::Push(T elem)
{
	Node<T>* temp = new Node<T>(elem);
	temp->next = this->top;
	this->top = temp;
	this->stack_len++;
	cout << "finish Push!" << endl;
}

template<class T>
T LinkStack<T>::Pop()
{
	if(Empty())
	{
		cout << "空栈，无法完成出栈" << endl;
		exit(0);
	}
	T elem;
	Node<T>* temp = NULL;
	elem = this->top->data;
	temp = this->top;
	this->top = this->top->next;
	delete temp;
	return elem;
}

template<class T>
ostream& operator<<<>(ostream& output, LinkStack<T>& linkstack)		  //为什么友元函数不用声明
{
	output << "output:";
	while(linkstack.top->next)
	{
		output << linkstack.Pop() << "    "; 
	}
	output << endl;
	return output;
}