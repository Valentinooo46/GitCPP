#include<iostream>
#include<Windows.h>
#include<String.h>
#define CRT_SECURE_NO_WARNINGS
using namespace std;
bool IsCorrectGramatic(char* arr)
{
	int len = strlen(arr), Under_review=0;
	
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == '(')
			Under_review++;
		else if (arr[i] == ')')
			Under_review--;
		if (Under_review<0)
		{
			return false;
		}
	}
	if (Under_review == 0)
		return true;
	else
	{
		return false;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char str[100];
	cin.getline(str, 100);
	if (IsCorrectGramatic(str))
		cout << "Дужки розставленні правильно!" << endl;
	else
		cout << "Дужки розставлені неправильно!" << endl;
	return 0;
}