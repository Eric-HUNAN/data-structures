#include "sqlist.h"
#include "iostream"


using namespace std;


int main()
{
	float a[] = {1.2, 2.0, 1.2, 4.0, 1.2};
	int i = 5;
	cout << "************************************" << endl;
	SqList<float> sqlist(i, a);
	sqlist.OutputSqList();
	cout << "表长为：" << sqlist.LengthSqList() << endl;
	cout << endl;
	cout << endl;
	cout << "************************************" << endl;
	sqlist.InsertSqList(1, 15.5);
	sqlist.OutputSqList();
	cout << "表长为：" << sqlist.LengthSqList() << endl;
	cout << endl;
	cout << endl;
	cout << "************************************" << endl;
	sqlist.InsertSqList1(16.7);
	sqlist.OutputSqList();
	cout << "表长为：" << sqlist.LengthSqList() << endl;
	cout << endl;
	cout << endl;
	cout << "************************************" << endl;
	sqlist.GetElemSqList(5);
	cout << endl;
	cout << endl;
	cout << "************************************" << endl;
	sqlist.LocateSqList(1.2);
	cout << endl;
	cout << endl;
	cout << "************************************" << endl;
	sqlist.DeleteSqList(2);
	sqlist.OutputSqList();
	cout << endl;
	cout << endl;
	cout << "************************************" << endl;
	sqlist.DeleteSqList1(1.2);
	sqlist.OutputSqList();
	cout << endl;
	cout << endl;
	cout << "************************************" << endl;
	return 0;
}
