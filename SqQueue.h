#pragma once

#include "iostream"
#include "stdlib.h"
#include "malloc.h"
#include "exception"

using namespace std;

const int MAXSIZE = 5;	         //��̬���鳤��

template<class T>
class SqQueue
{
public:
	SqQueue();					 //���캯��
	SqQueue(int num, T elem[]);
	~SqQueue();					 //��������

	int Length();				 //���г���
	bool Empty();				 //�ն����ж�
	void EnQueue(T elem);		 //���
	T DeQueue();				 //����
	friend ostream& operator<< <>(ostream& output, SqQueue<T>& Q);		//���������<<
private:
	T* base;					 //ָ�����鵥Ԫ
	T* front;					 //����
	T* rear;					 //��β
	int queue_len;				 //�ӳ�
	int queue_size;				 //������󳤶�
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
		if(i <= num - 2)					//ʹrearָ����Զָ�����ӵ�Ԫ��
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
	if(this->front + (MAXSIZE - 1) == this->rear)                                 //����
		this->base = (T*)realloc(this->base, (MAXSIZE + this->queue_size) * sizeof(T));
	if(queue_size != 0 && this->queue_len == 1 && this->rear == this->front)	  //�����ձ��ڶ���Ԫ�����
	{  
		(this->rear)++;
		*(this->rear) = elem;
		(this->queue_len)++;
		return;
	}
	if(this->rear == this->front)                                                  //�����ձ���һ��Ԫ�����
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
			throw length_error("���б��޷����ɾ����");
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
	if (Q.front == Q.rear)				   //ֻ��һ��Ԫ��ʱ�����
	{
		output << Q.DeQueue();
		output << endl;
		return output;
	}
	for(int i = 0; i < num-1; i++)
	{
	    output << Q.DeQueue() << "    ";
	    if(Q.front == Q.rear)			   //������������һ��Ԫ��
		      output << *(Q.front);
	}
	output << endl;
	return output;
}
