#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<String.h>
#include <stdio.h>
using namespace std;
void task2(FILE* f, int N)
{
	char line[1000];
	char long_line[1000] = "";
	while (fgets(line, N, f))
	{
		if (strlen(line) > strlen(long_line)) {
			strcpy(long_line, line);
		}
	}
	printf("Найдовший рядок: %s\n", long_line);
	printf("Довжина найдовшого рядка: %i\n", strlen(long_line));

}
void task1(FILE* f, FILE* f2, int N)
{
	char line[1000];
	char last_line[1000] = "";

	while (fgets(line, N, f)) {
		strcpy(last_line, line);
	}


	rewind(f); // Повертаємо позицію вказівника файла на початок
	while (fgets(line, N, f)) {
		if (strcmp(line, last_line) != 0) {
			fputs(line, f2);
		}
	}
	printf("Останній рядок видалено та результат записано в file2.txt.\n");

}
void task3(FILE*& f, int N, char tword[])
{
	int count = 0;
	char line[1000];
	char* select_word;
	while (fgets(line, N, f))
	{
		select_word = strtok(line, "\t ");
		while (select_word != NULL)
		{
			if (strcmp(select_word, tword) == 0) {
				count++;
			}
			select_word = strtok(NULL, " \t\n");
		}
	}
	printf("count:%i\n", count);

}
void task4(FILE*& f,char file_path[],const int N, char find_word[], char new_word[])
{
	
	char temp_file_path[1000]; // шлях для створення тимчасового файлу temp_file.txt(бажано щоб розташовувався там де й file3)
	cin.getline(temp_file_path, N);
	FILE* f2 = fopen(temp_file_path, "w");
	char line[1000];
	while (fgets(line, N, f)) {
		char* token = strtok(line, " ");
		while (token != NULL) {
			if (strcmp(token, find_word) == 0) {
				fputs(new_word, f2);
				fputs(" ", f2);
			}
			else {
				fputs(token, f2);
				fputs(" ", f2);
			}
			token = strtok(NULL, " ");
		}
	}
	fclose(f);
	fclose(f2);
	f = fopen(file_path, "w");  
	f2 = fopen(temp_file_path, "r");
	while (fgets(line, N, f2)) {
		fputs(line, f);
		fputs("\n", f);
	}
	fclose(f);
	fclose(f2);
	remove(temp_file_path);
	printf("Операція успішно виконана!\n");



}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int N = 1000;
	char file1_path[N], file2_path[N], file3_path[N];
	cin.getline(file1_path, N); //введіть шлях до file1
	cin.getline(file2_path, N);//введіть шлях до file2
	cin.getline(file3_path, N);//введіть шлях до file3
	FILE* f = fopen(file1_path, "r");
	FILE* f2 = fopen(file2_path, "w");
	FILE* f3 = fopen(file3_path, "r");
	
	char inputword[1000];
	char find_word[1000];
	char new_word[1000];

	cin.getline(inputword, 1000);
	task1(f, f2, N);
	rewind(f);

	task2(f, N);
	rewind(f);
	task3(f, N, inputword);
	fclose(f);
	fclose(f2);
	cin.getline(find_word, N);
	cin.getline(new_word, N);
	task4(f3, file3_path, N, find_word, new_word);
	return 0;
}