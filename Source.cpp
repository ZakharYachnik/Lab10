#include <stdio.h>
#include <string.h>
#include <locale.h>

char a[100];

int vvod()
{
	int ch;

	while (1)
	{
		if (scanf_s("%d", &ch) != 1) {
			getchar();
			printf("\nВведен неверный тип, попробуйте еще раз ");
		}
		else break;

	}
	getchar();
	return ch;
}

void perevod()
{
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] >= -96 && a[i] <= -81)//для маленьких букв
			a[i] += 64;
		else
			if (a[i] >= -32 && a[i] <= -17)
				a[i] += 16;
			else if (a[i] >= -128 && a[i] <= -97) // для больших букв
				a[i] += 64;

	}
}

void zad1()
{

	printf("Введите строку: ");
	gets_s(a);

	for (int i = 0; i < strlen(a); i++)
		switch (a[i])
		{
		case 'a':
			a[i] = 'b';
			break;
		case 'A':
			a[i] = 'B';
			break;
		case 'b':
			a[i] = 'a';
			break;
		case 'B':
			a[i] = 'A';
			break;
		}
	printf("Итоговый вид строки: ");
	puts(a);

}

void zad3()
{
	printf("Введите строку: ");
	gets_s(a);
	perevod();

	int k = 0;
	printf("\n%d", strlen(a));
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] == 'а' && (a[i + 1] == ' ' || a[i + 1] == ',' || a[i + 1] == '.' || a[i + 1] == '\0'))
			k++;
	}

	printf("Количество слов заканчивающихся на 'а' равно: %d\n", k);
}

void zad4()
{
	printf("Введите строку: ");
	gets_s(a);

	int k = 0;
	for (int i = 0; i < strlen(a); i++)
		if (a[i] != ' ' && (a[i + 1] == ' ' || a[i + 1] == 0))
			k++;

	printf("Количество слов равно: %d", k);
}

void zad8()
{
	printf("Введите строку: ");
	gets_s(a);

	char c;

	for (int i = 0; i < strlen(a) - 1; i++)
	{
		c = a[i];
		a[i] = a[i + 1];
		a[i + 1] = c;
	}

	printf("Итоговая строка: ");
	puts(a);
}

void zad10()
{
	printf("Введите имя: ");
	gets_s(a);
	perevod();
	printf("Привет, %s!", a);
}

int menu()
{
	int ch = 0;
	while (ch < 1 || ch > 6)
	{
		printf("\n\nВыберите какую задачу хотите выполнить ");
		printf("\n1. Ввести символьную строку, заменить все буквы а на буквы б как заглавные, так и строчные.");
		printf("\n2. Ввести предложение и определить, сколько слов заканчиваются на русскую букву 'а'. ");
		printf("\n3. Ввести предложение и разобрать его на отдельные слова.");
		printf("\n4. Разработать функцию, которая переставляет пары соседних символов.");
		printf("\n5. Написать программу, которая предлагает ввести имя и выводит сообщение Привет, «имя»!");
		printf("\n6. Выход");
		printf("\nВаш выбор: ");
		ch = vvod();
		
	}
	printf("\n\n");
	return ch;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	while(1){
		switch (menu())
		{
			case 1:
				zad1();
				break;

			case 2:
				zad3();
				break;

			case 3: 
				zad4();
				break;

			case 4:
				zad8();
				break;

			case 5:
				zad10();
				break;

			case 6:
				return 0;
		}
	}
}
