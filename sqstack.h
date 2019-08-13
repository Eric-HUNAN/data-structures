#pragma  once
#include "iostream"
#include "stdlib.h"
#include "malloc.h"
#include "exception"

using namespace std;

const int MAXSIZE = 5;

template<class T>
class SqStack
{
public:
	SqStack();
	SqStack(int num, T elem[]);
	~SqStack();

	int GetLength();
	bool Empty();
	void pushSqStack(T elem);  //入栈
	T popSqStack();  //出栈
	void DeleteSqStack();
	friend ostream& operator<<<>(ostream& out, SqStack<T>& sqstack); //重载运算符<<
private:
	T* base;
	T* top;
	int stack_size;
	int stack_len;
};

template<class T>
SqStack<T>::SqStack()
{
	this->base = new T[MAXSIZE];  
	this->stack_size = MAXSIZE;
	this->top = this->base;
	this->stack_len = 0;
}

template<class T>
SqStack<T>::SqStack(int num, T elem[])
{
	this->stack_len = 0;
	this->base = new T[MAXSIZE];
	this->top = this->base;
	for (int i = 0; i < num; i++)
	{
		*(this->top) = *(elem + i);
		this->top++;
		this->stack_len++;
	}
	this->stack_size = MAXSIZE;
}

template<class T>
SqStack<T>::~SqStack()
{
  delete [] this->base;
}

template<class T>
int SqStack<T>::GetLength()
{
	return this->stack_len;
}

template<class T>
bool SqStack<T>::Empty()
{
	if(this->base == this->top)
		return 1;
	else
		return 0;
}

template<class T>
void SqStack<T>::pushSqStack(T elem)
{
	if (this->stack_len == this->stack_size)
	{
		this->base = (T*)realloc(this->base, (this->stack_size + MAXSIZE) * sizeof(T));
		*(this->top) = elem;
		this->top++;
		this->stack_size = this->stack_size + MAXSIZE;
	}
	else
	{
		*(this->top) = elem;
		(this->top)++;
	}
	(this->stack_len)++;
}

template<class T>
T SqStack<T>::popSqStack()
{
	if (Empty())
	{
		cout << "空栈，无法进行出栈！" << endl;
		exit(0);
	}
	T elem = *(--(this->top));
	this->stack_len--;
	return elem;
}

template<class T>
void SqStack<T>::DeleteSqStack()
{
	int num = this->stack_len;
	for(int i = 0; i < num; i++)
		popSqStack();
}


template<class T>
ostream& operator<<<>(ostream& out, SqStack<T>& sqstack)
{
	out << "输出结果：";
	int num = sqstack.GetLength();
	T* temp = sqstack.top;
	for(int i = 0; i < num; i++)
	{
		temp--;
		out << *(temp) << "   ";
	}
	out << endl;
	return out;
}
