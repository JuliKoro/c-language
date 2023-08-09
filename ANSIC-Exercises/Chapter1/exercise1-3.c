/*
Exercise 1-3. Modify the temperature conversion program to print a heading above the table.
*/

#include <stdio.h>

main(void)
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;		// límite inferior de la escala de temperatura
	upper = 300;	// límite superior de la escala de temperatura
	step = 20;		// tamaño escala

	printf("Fahrenheit\tCelsius\n"); // heading above the table
	printf("------------------------\n");

	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("   %3.0f\t\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

	return 0;
}
