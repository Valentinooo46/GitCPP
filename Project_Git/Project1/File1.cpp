#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<String.h>
#include <stdio.h>
using namespace std;
struct contact {
	char* name = new char[100];
	char fax[14];
	void fill() {
		char temp_name[200];
		char temp_fax[50];

		cout << "Введіть ім'я: ";
		bool Isvalid = false;
		do
		{
			cin.getline(temp_name, 200);

			// Перевірка довжини імені
			if (strlen(temp_name) >= 100) {
				cout << "Ім'я занадто довге. Введіть коректне ім'я (не більше 100 символів).\n";
				Isvalid = false;
			}
			else
			{
				Isvalid = true;
			}
		} while (!Isvalid);


		cout << "Введіть номер факсу: ";
		Isvalid = false;
		do
		{
			cin.getline(temp_fax, 50);

			// Перевірка довжини номера факсу
			if (strlen(temp_fax) > 14) {
				cout << "Номер телефону занадто довгий. Введіть коректний номер (не більше 14 символів).\n";
				Isvalid = false;
			}
			else
			{
				Isvalid = true;
			}
		} while (!Isvalid);


		// Копіюємо дані до полів екземпляру структури
		strcpy(name, temp_name);
		strcpy(fax, temp_fax);
	}
	void read_info()
	{
		printf("%s %s\n", name, fax);
	}
};
void new_contact(contact*& list, int& count) {
	contact* new_list = new contact[count + 1];
	if (list != nullptr)
	{
		for (int i = 0; i < count; i++)
		{
			new_list[i] = list[i];
		}
		delete[] list;
	}

	list = new_list;
	list[count].fill();
	count++;
}
void sort_name(contact*& list, int count)
{
	contact temp;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (strcmp(list[j].name, list[j + 1].name) > 0)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}
void sort_fax(contact*& list, int count)
{
	contact temp;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (strcmp(list[j].fax, list[j + 1].fax) > 0)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}
int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*contact example;
	example.fill();
	example.read_info();*/
	contact* list = nullptr;
	int count = 0;
	int exit = 0;
	char select[50];
	printf("Вас вітає меню керування контактами!\nось наявні команди:\n/see_list - вивести весь список контактів\n/new_contact - додати контакт\n/sort_name - сортувати список за ім'ям\n/sort_fax - сортувати список за телефоном\n");
	printf("/exit- вийти з программи\n");
	while (exit == 0)
	{

		cin.getline(select, 50);
		if (strcmp(select, "/exit") == 0)
		{
			exit = 1;
			printf("До зустрічі!\n");
		}
		else if (list != nullptr)
		{
			if (strcmp(select, "/see_list") == 0)
			{
				for (int i = 0; i < count; i++)
				{
					printf("------------------------------\n");
					list[i].read_info();
					printf("------------------------------\n");
				}
			}
			else if (strcmp(select, "/new_contact") == 0)
			{
				new_contact(list, count);

				printf("контакт успішно доданий!\n");
			}
			else if (strcmp(select, "/sort_name") == 0)
			{
				sort_name(list, count);
				printf("Список успішно відсортовано!\n");
			}
			else if (strcmp(select, "/sort_fax") == 0)
			{
				sort_fax(list, count);
				printf("Список успішно відсортовано!\n");
			}


			else
			{
				printf("Ви ввели щось не зрозуміле..Спробуйте ще раз\n");
			}
		}
		else {
			if (strcmp(select, "/exit") == 0)
			{
				exit = 1;
				printf("До зустрічі!\n");
			}
			else if (strcmp(select, "/see_list") == 0 || strcmp(select, "/sort_name") == 0 || strcmp(select, "/sort_fax") == 0)
			{
				printf("У вас немає наявних контактів:додайте нові контакти\n");
			}
			else if (strcmp(select, "/new_contact") == 0)
			{
				new_contact(list, count);
				printf("контакт успішно доданий!\n");
			}

			else
			{
				printf("Ви ввели щось не зрозуміле..Спробуйте ще раз\n");
			}
		}
	}
	if (list != nullptr)
	{
		for (int i = 0; i < count; i++)
		{
			delete[] list[i].name;
		}
		delete[] list;
	}



	return 0;
}