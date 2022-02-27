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
			printf("\n������ �������� ���, ���������� ��� ��� ");
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
		if (a[i] >= -96 && a[i] <= -81)//��� ��������� ����
			a[i] += 64;
		else
			if (a[i] >= -32 && a[i] <= -17)
				a[i] += 16;
			else if (a[i] >= -128 && a[i] <= -97) // ��� ������� ����
				a[i] += 64;

	}
}

void zad1()
{

	printf("������� ������: ");
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
	printf("�������� ��� ������: ");
	puts(a);

}

void zad3()
{
	printf("������� ������: ");
	gets_s(a);
	perevod();

	int k = 0;
	printf("\n%d", strlen(a));
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] == '�' && (a[i + 1] == ' ' || a[i + 1] == ',' || a[i + 1] == '.' || a[i + 1] == '\0'))
			k++;
	}

	printf("���������� ���� ��������������� �� '�' �����: %d\n", k);
}

void zad4()
{
	printf("������� ������: ");
	gets_s(a);

	int k = 0;
	for (int i = 0; i < strlen(a); i++)
		if (a[i] != ' ' && (a[i + 1] == ' ' || a[i + 1] == 0))
			k++;

	printf("���������� ���� �����: %d", k);
}

void zad8()
{
	printf("������� ������: ");
	gets_s(a);

	char c;

	for (int i = 0; i < strlen(a) - 1; i++)
	{
		c = a[i];
		a[i] = a[i + 1];
		a[i + 1] = c;
	}

	printf("�������� ������: ");
	puts(a);
}

void zad10()
{
	printf("������� ���: ");
	gets_s(a);
	perevod();
	printf("������, %s!", a);
}

int menu()
{
	int ch = 0;
	while (ch < 1 || ch > 6)
	{
		printf("\n\n�������� ����� ������ ������ ��������� ");
		printf("\n1. ������ ���������� ������, �������� ��� ����� � �� ����� � ��� ���������, ��� � ��������.");
		printf("\n2. ������ ����������� � ����������, ������� ���� ������������� �� ������� ����� '�'. ");
		printf("\n3. ������ ����������� � ��������� ��� �� ��������� �����.");
		printf("\n4. ����������� �������, ������� ������������ ���� �������� ��������.");
		printf("\n5. �������� ���������, ������� ���������� ������ ��� � ������� ��������� ������, �����!");
		printf("\n6. �����");
		printf("\n��� �����: ");
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
