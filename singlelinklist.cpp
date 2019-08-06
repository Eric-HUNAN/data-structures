#include "iostream"
#include "singlelinklist.h"

using namespace std;

int main()
{
	//Init:测试初始化构造函数
	//operator:测试增、删、查
	//标注行代码为异常测试，主要包括length_error和out_of_range
	//最后输出的是析构函数，下面代码行中未给出，见.h文件中的析构函数定义
	cout << "**************************************************" << endl;
	cout << "test Innit<SLinkList()>" << endl;		 
	SLinkList<int> sqlinklist1;
	cout << "**************************************************" << endl;
	cout << "test Init<SLinkList(int num, T elem[])>"  << endl;
	int num = 5;
	int a[] = {1, 2, 3, 4, 5};
	cout << "input list:" ;
	for(int i = 0; i < num; i++)
		cout << a[i] << "     ";
	cout << endl;
	SLinkList<int> sqlinklist2(num, a);
	cout <<  "length:" << sqlinklist2.LengthSLinkList()  << endl;
	sqlinklist2.OutputList();
	cout << endl;
	//cout << "test error" << endl;
	//SLinkList<int> error1(0, a);
	cout << "**************************************************" << endl;
	cout << "test Init<SLinkList(int num)>" << endl;
	int num1 = 5;
	SLinkList<int> slistlink3(num1);
	cout << "length:" << slistlink3.LengthSLinkList() << endl;
	slistlink3.OutputList();
	cout << endl;
	//cout << "test error" << endl;
	//SLinkList<int> errror(0);
	cout << "**************************************************" << endl;
	cout << "test operation<InsertNode(int i, T elem)>" << endl;
	sqlinklist2.InsertNode(2, 1996);
	sqlinklist2.OutputList();
	cout << endl;
	//cout << "test error" << endl;
	//error.InsertNode(0, 0);
	//error.InsertNode(7, 0);
	cout << "test operation<InsertNode(T elem)>" << endl;
	sqlinklist2.InsertNode(256);
	sqlinklist2.OutputList();
	cout << endl;
	//cout << "test error" << endl;
	//error.InsertNode(0);
	//error.InsertNode(7);
	cout << "**************************************************" << endl;
	cout << "test operation<DeleteNode(int i)>" << endl;
	sqlinklist2.DeleteNode(1);
	sqlinklist2.OutputList();
	cout << endl;
	//cout << "test error" << endl;
	//error.DeleteNode(18);
	//cout << "test operation<DeleteAllNode()>" << endl;
	//sqlinklist2.DeleteAllNode();
	cout << "**************************************************" << endl;
	cout << "test operation<GetElem(int i)>" << endl;
	cout << "num '2' is:" << sqlinklist2.GetElem(2) << endl;
	//cout << "test error" << endl;
	//error.DeleteNode(18);
	cout << "test operation<GetNum(T elem)>" << endl;
	cout << "elem '2' is :"	 << *(sqlinklist2.GetNum(2)) << endl;
	cout << endl;
	return 0;
}
