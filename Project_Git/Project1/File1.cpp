#include<iostream>
#include<Windows.h>
#include<String.h>
#define CRT_SECURE_NO_WARNINGS
using namespace std;


void task1(char* arr, char* word)
{
    int count = 0;
    int length = strlen(arr);
    int wordLength = strlen(word);

    for (int i = 0; i <= length - wordLength; ++i) {
        bool found = true;
        for (int j = 0; j < wordLength; ++j) {
            if (arr[i + j] != word[j]) {
                found = false;
                break;
            }
        }
        // Додаткова перевірка, щоб знайдене слово не було фрагментом більшого слова
        if (found && (i == 0 || arr[i - 1] == ' ') &&
            (i + wordLength == length || arr[i + wordLength] == ' ' || arr[i + wordLength] == '!' || arr[i + wordLength] == '?')) {
            ++count;
        }
    }

    cout << "Слово \"" << word << "\" зустрічається " << count << " разів." << endl;
}
void task2(char* arr, int size)
{
    cout << "зайнято: " << strlen(arr) + 1 << "\nвільно: " << size - (strlen(arr) + 1) << "\nусього: " << size << endl;
}
void task3(char*& arr, char* pattern)
{
    int length = strlen(arr);
    int plength = strlen(pattern);
    int count = 0;
    bool Isthere = false;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < plength; j++)
        {
            if (arr[i] == pattern[j])
            {
                count++;
                break;
            }
        }
    }
    char* new_str = new char[length - count + 1];
    count = 0;
    for (int i = 0; i < length; i++)
    {
        Isthere = false;
        for (int j = 0; j < plength; j++)
        {
            if (arr[i] == pattern[j])
            {
                Isthere = true;
                break;
            }
        }
        if (!Isthere)
            new_str[count++] = arr[i];

    }
    delete[] arr;
    new_str[count] = '\0';
    arr = new_str;

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int Max_SIZE = 100;
    char str[Max_SIZE], word[Max_SIZE], str2[Max_SIZE], pattern[Max_SIZE];
    char* str3 = new char[Max_SIZE];
    //task 1
    cin.getline(str, Max_SIZE);
    cin.getline(word, Max_SIZE);
    task1(str, word);
    //task 2
    cin.getline(str2, Max_SIZE);
    task2(str2, Max_SIZE);
    //task 3
    cin.getline(str3, Max_SIZE);
    cin.getline(pattern, Max_SIZE);
    task3(str3, pattern);
    cout << str3 << endl;
    delete[] str3;
    return 0;
}