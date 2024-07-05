#include<iostream>
#include<Windows.h>
#include<String.h>
#define CRT_SECURE_NO_WARNINGS
using namespace std;

struct Temperature
{
	float high;
	float low;
	float freeze;
};
struct Machine
{
	char Brand[100];
	char color[100];
	int width;
	int length;
	int height;
	int power;
	int speed_of_work;

	Temperature temperature;


};
struct Machine2
{
	char Brand[100];
	char color[100];
	int power;
	int Water_VAPOUR; //1-yes or 0-no
	Temperature temperature;
};
struct Machine3
{
	char Brand[100];
	char color[100];
	int power;
	int V; //одиниці вимірювання-м³
	Temperature temperature;
};
struct Animal
{
	char kind[200];
	char Class[200];
	char Name[100];
	void Signal()
	{
		if (strcmp(Class, "Dog") == 0)
		{
			cout << "How-How-How" << endl;
		}
		else if (strcmp(Class, "Cat") == 0)
		{
			cout << "Meow-Meow-Meow" << endl;
		}
		else if (strcmp(Class, "Cow") == 0)
		{
			cout << "Muuuuu-Muuuu" << endl;
		}
		else if (strcmp(Class, "Snake") == 0)
		{
			cout << "Ssssssss-sssssss" << endl;
		}
		else if (strcmp(Class, "Parrot") == 0)
		{
			cout << "cqwick-cqwick" << endl;
		}
		else if (strcmp(Class, "Wolf") == 0)
		{
			cout << "Wouuuuuuuu" << endl;
		}
		else if (strcmp(Class, "") == 0)
		{
			cout << "you didn't enter the class of your animal!!" << endl;
		}
		else
		{
			cout << "your animal can't signal!" << endl;
		}
	}
	void InitPet()
	{
		cout << "enter the Latin name of your animal species(for example:Chamaeleonidae):" << endl;
		cin >> kind;
		cout << "Enter the class of your animal(for example:Wolf,Dog,Cat,Cow,Snake,Parrot):" << endl;
		cin >> Class;
		cout << "Enter the name of your animal(for example Phillip):" << endl;
		cin >> Name;
	}
	void SeeParameters()
	{
		cout << "kind: " << kind << endl;
		cout << "Class: " << Class << endl;
		cout << "Name: " << Name << endl;
	}
};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//завдання 1
	Machine object1;
	cin >> object1.Brand >> object1.color >> object1.width >> object1.height >> object1.length >> object1.power;
	cin >> object1.speed_of_work;
	cin >> object1.temperature.high >> object1.temperature.low >> object1.temperature.freeze;

	cout << "1-Brand\n2-color\n3-width\n4-height\n5-length\n6-power\n7-speed_of_work\n" << object1.Brand << endl << object1.color << endl << object1.width << "meters" << endl << object1.height << "meters" << endl << object1.length << "meters" << endl << object1.power << "kW" << endl << object1.speed_of_work << "rps" << endl;

	cout << "temperature:1-high\n2-low\n3-freeze\n" << object1.temperature.high << "*C" << endl << object1.temperature.low << "*C" << endl << object1.temperature.freeze << "*C" << endl;
	//завдання 2
	Machine2 object2;
	cin >> object2.Brand >> object2.color >> object2.power >> object2.Water_VAPOUR >> object2.temperature.freeze >> object2.temperature.low >> object2.temperature.high;
	cout << "1-Brand\n2-color\n3-power\n4-Water vapour\n5-freeze temperature\n6-low temperature\n7-high temperature\n" << object2.Brand << endl << object2.color << endl << object2.power << "kW" << endl;
	if (object2.Water_VAPOUR)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << object2.temperature.freeze << endl << object2.temperature.low << endl << object2.temperature.high << endl;
	//завдання 3
	Machine3 object3;
	cin >> object3.Brand >> object3.color >> object3.power >> object3.V >> object3.temperature.freeze >> object3.temperature.low >> object3.temperature.high;
	cout << "1-Brand\n2-color\n3-power\n4-volume\n5-freeze temperature\n6-low temperature\n7-high temperature\n" << object3.Brand << endl << object3.color << endl << object3.power << "kW" << endl;
	cout << object3.V << "M^3" << endl;
	cout << object3.temperature.freeze << endl << object3.temperature.low << endl << object3.temperature.high << endl;
	//завдання 4
	Animal MyPet;
	MyPet.InitPet();
	MyPet.SeeParameters();
	MyPet.Signal();

	return 0;
}