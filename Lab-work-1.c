#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>


static long long factorial(int n);
int get_integer(const char* msg);

int main() {
	char* locale = setlocale(LC_ALL, ""); //Локализация русского

	int n, k;

	//printf("Здравстуйте! У меня 8 вариант: \n\"Ввести целые числа N и K. Вычислить и вывести число сочетаний из N по K.\"\n");
	n = get_integer("input N: ");	
	k = get_integer("input K: ");
	long long result = factorial(n) / (factorial(n - k) * factorial(k)); // Формула для нахождения сочетаний
	printf("total combinations: %I64d", result);


	return result;
}


static long long factorial(int n)
{
	long long r;
	for (r = 1; n > 1; r *= (n--));
	return r;
}

int get_integer(const char* msg) {
	char answer[256]; // строка для чтения
	int n; // итоговое целое число

	printf("%s", msg); // выводим приглашение ко вводу
	fgets(answer, sizeof(answer), stdin); // считываем строку

	// пока не будет считано целое число
	while (sscanf(answer, "%d", &n) != 1) {
		printf("Incorrect input. Try again: "); // выводим сообщение об ошибке
		fgets(answer, sizeof(answer), stdin); // и заново считываем строку
	}

	return n; // возвращаем корректное целое число
}