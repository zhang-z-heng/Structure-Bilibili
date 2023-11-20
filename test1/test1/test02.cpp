/*#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

void sub(char b[]) 
{
	string s;
	s = "World";
	strcpy_s(b, 10,s.c_str());
}
void main(void)
{
	char a[10] = "hello";
	sub(a);
	cout << a <<endl;
}*/
#include<iostream>
using namespace std;
void main() {
	int i = 5;
	int& j = i;
	i = 7;
	cout << "i=" << i << "j=" << j;
}