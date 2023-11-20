#include <iostream>
using namespace std;

void swap(float m, float n)
{
	float temp;
	temp = m;
	m = n;
	n = temp;
}

/*void main()
{
	float a, b;
	cin >> a >> b;
	swap(a, b);
	cout << a << endl << b << endl;
}*/
//把实参的值ab传送给函数局部工作区相应的副本中
//函数使用的这个副本执行必要的功能
//函数修改的是副本的值
//实参的值不变
void swap1(float* m, float* n)
{
	float t;
	t = *m;
	*m = *n;
	*n = t;
}
//形参实参改变
void swap2(float *m, float *n)
{
	float *t;
	t = m;
	m = n;
	n = t;
}//实参不变
void main()
{
	float a, b, * p1, * p2;
	cin >> a >> b;
	p1 = &a; p2 = &b;
	cout << p1 << endl << p2 << endl;
	swap1(p1, p2);
	cout << a << endl << b << endl;
	cout << &a << endl << &b << endl;
}

void swap3(float& m, float& n)
{
	float temp1;
	temp1 = m;
	m = n;
	n = temp1;
}//实参改变引用变量