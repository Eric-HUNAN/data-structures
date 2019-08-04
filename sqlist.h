#pragma once
#include "iostream"
#include "stdlib.h"

using namespace std;
template<class T>
struct DataType 	 
{
   T *Elem;		   //动态创建数组
   int length;
   int listsize;
};

template<class T>
class SqList
{
public:
	SqList(int num);  //建立空表
	SqList(int num, T elem[]);	//赋值构造(给出数组长度)
	SqList(T* elem);	//赋值构造(未给出数组长度)
	~SqList(); //析构函数
	int LengthSqList();	 //表长
	int EmptySqList();	//空表
	void InsertSqList(int i, T elem);	 //增
	void InsertSqList1(T elem);
	void DeleteSqList(int i);	  //删
    void DeleteSqList1(T elem);
	void GetElemSqList(int i);		//查
    void LocateSqList(T elem);
	void OutputSqList();

protected:
	struct DataType<T> Data;
};


template<class T>
SqList<T>::SqList(int num)
{
	this->Data.listsize = num;
	this->Data.length = 0;
	this->Data.Elem = new T[this->Data.listsize];
}

//带初始值的初始化线性表
template<class T>
SqList<T>::SqList(int num, T elem[])	
{
	this->Data.listsize = 2 * num;
	this->Data.length = num;
	this->Data.Elem = new T [this->Data.listsize];
	cout << "初始化中..." << endl;
	for (int j = 0; j < num; j++)
	{
		this->Data.Elem[j] = elem[j];
	}
	cout << "初始化完成！" << endl;
}

//未给出数组长度的初始化
template<class T>
SqList<T>::SqList(T* elem)
{
	int i = sizeof(elem) / sizeof(elem[0]);
	this->Data.listsize = 2 * i;
	this->Data.length = i;
	this->Data.Elem = new T[this->Data.listsize];
	try
	{
		if(i != 0)
		{
			for(int j = 0; j < i; j++)
			{
				this->Data.Elem[j] = elem[j];
				cout << "初始化完成！" << endl;
			}
		}
		else
			throw 1;
	}
	catch(int)
	{
		cout << "输入的数组为空数组" << endl;
		exit(1);
	}
}

//析构函数
template<class T>
SqList<T>::~SqList()
{
	delete [] this->Data.Elem;
}

//表长
template<class T>
int SqList<T>::LengthSqList()
{
	return (this->Data.length);
}

//判断空表
template<class T>
int SqList<T>::EmptySqList()
{
	if (this->Data.length == 0)
	{
		cout << "空表！" << endl;
		return 1;
	}
	else
		return 0;
}

//增
template<class T>
void SqList<T>::InsertSqList(int i, T elem)
{
	try
	{
		if (i<1 && i>this->Data.listsize)
			throw 1;
		else
		{
			if(i < this->Data.length)
			{
				for(int j = this->Data.length - 1; j > i - 2; j--)
					this->Data.Elem[j + 1] = this->Data.Elem[j];
				this->Data.Elem[i - 1] = elem;
				this->Data.length++;
			}
			else
			{
				this->Data.Elem[i] = elem;
			}
			cout << "已完成在" << i << "位置添加元素"  << elem << endl;
		}
	}
	catch(int)
	{
		cout << "输入位置错误！" << endl;
		exit(1);
	}
}


template<class T>
void  SqList<T>::InsertSqList1(T elem)
{
	try
	{
		if (this->Data.length == this->Data.listsize)
			throw 1;
		else
		{
			this->Data.Elem[this->Data.length] = elem;
			this->Data.length++;
			cout << "已在末尾添加元素" << elem << endl;
		}
	}
	catch(int)
	{
		cout << "表已满，无法进行添加！" << endl;
		exit(1);
	}
}

//删
template<class T>
void SqList<T>::DeleteSqList(int i)
{
	try
	{
		if (i<1 && i>this->Data.length)
			throw 1;
		else
		{
			for (int j = i; j < this->Data.length; j++)
				this->Data.Elem[j - 1] = this->Data.Elem[j];
			this->Data.length--;
			cout << "删除完成！" << endl;	
		}
	}
	catch(int)
	{
		cout << "输入参数有误！" << endl;
		exit(1);
	}
}

template<class T>
void SqList<T>::DeleteSqList1(T elem)
{
	try
	{
		int* count = new int[this->Data.length] ;
		int num = 0;
		for (int i = 0; i < this->Data.length; i++)		  //遍历元素看是否含elem
		{
			if(this->Data.Elem[i] == elem)
			{
				count[num] = i;
				num++;
			}
		}
		if (num == 0)
			throw 1;
		else
		{
			cout << "表中共有" << num << "个" << elem << "元素" << endl;
			for (int j = 0; j < num; j++)
			{
				int temp = count[j] + 1;
				DeleteSqList(temp);
			}
		}
	}
	catch(int)
	{
		cout << "表中不存在" << elem << "元素！" << endl;
		exit(1);
	}
}

//查
template<class T>
void SqList<T>::GetElemSqList(int i)
{
	try
	{
		if (i<1 && i>this->Data.length)
			throw 1;
		else
			cout << "查询的结果是：" << this->Data.Elem[i] << endl;
	}
	catch(int)
	{
		cout << "输入参数有误！" << endl;
		exit(1);
	}

}

template<class T>
void SqList<T>::LocateSqList(T elem)
{
	int* count = new int [this->Data.length];
	int num = 0;
	for(int i = 0; i < this->Data.length; i++)
	{
		if (this->Data.Elem[i] == elem)
		{
			count[num] = i;
			num++;
		}
	}
	cout << "元素的位置为：" << endl;
	for (int j = 0; j < num; j++)
	{
		cout << count[j]+ 1 << "    " ;
	}
	cout << endl;
}

template<class T>
void SqList<T>::OutputSqList()
{
	cout << "输出表为：" << endl;
	for (int i = 0; i < this->Data.length; i++)
	{
		cout << this->Data.Elem[i] << "    " ;
	}
	cout << endl;
}
