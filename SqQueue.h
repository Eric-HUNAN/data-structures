#pragma once

#include "iostream"
#include "stdlib.h"
#include "malloc.h"
#include "exception"

using namespace std;

const int MAXSIZE = 5;	         //动态数组长度

template<class T>
class SqQueue
{
public:
	SqQueue();					 //构造函数
	SqQueue(int num, T elem[]);
	~SqQueue();					 //析构函数

	int Length();				 //队列长度
	bool Empty();				 //空队列判定
	void EnQueue(T elem);		 //入队
	T DeQueue();				 //出队
	friend ostream& operator<< <>(ostream& output, SqQueue<T>& Q);		//重载运算符<<
private:
	T* base;					 //指向数组单元
	T* front;					 //队首
	T* rear;					 //队尾
	int queue_len;				 //队长
	int queue_size;				 //队列最大长度
};

template<class T>
SqQueue<T>::SqQueue()
{
	this->base = new T[MAXSIZE];
	this->front = this->base;
	this->rear = this->base;
	this->queue_len = 0;
	this->queue_size = MAXSIZE;
}

template<class T>
SqQueue<T>::SqQueue(int num, T elem[])
{
	this->base = new T[MAXSIZE];
	this->front = this->base;
	this->rear = this->base;
	for(int i = 0; i < num; i++)
	{
		*(this->rear) = *(elem + i);
		if(i <= num - 2)					//使rear指针永远指向刚入队的元素
		    (this->rear)++;
	}
	this->queue_len = num;
	this->queue_size = MAXSIZE;
}

template<class T>
SqQueue<T>::~SqQueue()
{
	delete this->base;
}

template<class T>
int SqQueue<T>::Length()
{
	return this->queue_len;
}

template<class T>
bool SqQueue<T>::Empty()
{
	if(this->queue_len == 0)
		return 1;
	else
		return 0;
}

template<class T>
void SqQueue<T>::EnQueue(T elem)
{
	if(this->front + (MAXSIZE - 1) == this->rear)                                 //扩容
		this->base = (T*)realloc(this->base, (MAXSIZE + this->queue_size) * sizeof(T));
	if(queue_size != 0 && this->queue_len == 1 && this->rear == this->front)	  //建立空表后第二个元素入队
	{  
		(this->rear)++;
		*(this->rear) = elem;
		(this->queue_len)++;
		return;
	}
	if(this->rear == this->front)                                                  //建立空表后第一个元素入队
	{
		*(this->rear) = elem;
		(this->queue_len)++;
		return;
	}
	(this->rear)++;
	*(this->rear) = elem;
	(this->queue_len)++;
}

template<class T>
T SqQueue<T>::DeQueue()
{
	try
	{
		if(Empty())
			throw length_error("空列表，无法完成删除！");
		T elem;
		elem = *(this->front);
		(this->front)++;
		(this->queue_len)--;
		return elem;
	}
	catch(length_error e)
	{
		cout << "info:" << e.what() << endl;
		exit(1);
	}
}

template<class T>
ostream& operator<< <>(ostream& output, SqQueue<T>& Q)
{
	output << "output:";
	int num = Q.Length();
	if (Q.front == Q.rear)				   //只有一个元素时出输出
	{
		output << Q.DeQueue();
		output << endl;
		return output;
	}
	for(int i = 0; i < num-1; i++)
	{
	    output << Q.DeQueue() << "    ";
	    if(Q.front == Q.rear)			   //输出队列中最后一个元素
		      output << *(Q.front);
	}
	output << endl;
	return output;
}
