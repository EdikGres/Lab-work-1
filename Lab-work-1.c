#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>


static long long factorial(int n);

int main() {
	char* locale = setlocale(LC_ALL, ""); //Локализация русского

	int n, k;

	//printf("Здравстуйте! У меня 8 вариант: \n\"Ввести целые числа N и K. Вычислить и вывести число сочетаний из N по K.\"\n");
	printf("input N: ");
	scanf("%d", &n);
	printf("input K: ");
	scanf("%d", &k);
	long result = factorial(n) / ( factorial(n - k) * factorial(k) ); // Формула для нахождения сочетаний
	printf("total combinations: %d", result);


	return result;
}

 /*static long factorial(int n)
{
	//Использую рекуррентную формулу и тернарное условие для 1
	return (n < 2) ? 1 : n * factorial(n - 1); 
} */
 static long long factorial(int n)
{
	long long r;
	for (r = 1; n > 1; r *= (n--));
	return r;
} 
/*static int factorial_1(int n, int p)
{
	return (n < 2) ? p : factorial_1(n - 1, p * n);
}

static int factorial(int n)
{
	return factorial_1(n, 1);
} */