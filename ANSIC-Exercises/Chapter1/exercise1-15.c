// Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.

#include <stdio.h>

float fahr_to_celsius(float fahr); // function prototype

int main(void)
{
	float fahr;
	float lower, upper, step;

	lower = 0;		// límite inferior de la escala de temperatura
	upper = 300;	// límite superior de la escala de temperatura
	step = 20;		// tamaño escala

	printf("Fahrenheit\tCelsius\n"); // heading above the table
	printf("------------------------\n");

	fahr = lower;
	while (fahr <= upper) {
		printf("   %3.0f\t\t%6.1f\n", fahr, fahr_to_celsius(fahr));
		fahr = fahr + step;
	}

	return 0;
}

/* fahr_to_celsius:  converts the Fahrenheit temperature (fahr) to Celsius */ 
float fahr_to_celsius(float fahr)
{
    float celsius;
    celsius = (5.0/9.0) * (fahr-32.0);
    return celsius;
}