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
    bool water_vapour;  //true or false
    Temperature temperature;


};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Machine object1;
    cin >> object1.Brand >> object1.color >> object1.width >> object1.height >> object1.length >> object1.power >> object1.water_vapour;

    cin >> object1.temperature.high >> object1.temperature.low >> object1.temperature.freeze;
    cin >> object1.speed_of_work;
    cout << "1-Brand\n2-color\n3-width\n4-height\n5-length\n6-power\n7-speed_of_work\n8-water_vapour(1-yes,0-no)\n" << object1.Brand << endl << object1.color << endl << object1.width << "meters" << endl << object1.height << "meters" << endl << object1.length << "meters" << endl << object1.power << "kW" << endl << object1.speed_of_work << "rps" << endl;
    if (object1.water_vapour)
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "0" << endl;
    }
    cout << "temperature:1-high\n2-low\n3-freeze\n" << object1.temperature.high << "*C" << endl << object1.temperature.low << "*C" << endl << object1.temperature.freeze << "*C" << endl;
    return 0;
}