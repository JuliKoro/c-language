// Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. 
// It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.

#include <stdio.h>

#define BUFFER 100

int main(void)
{
	int histogram[BUFFER];
	int histogram_length = 0; //cantidad de las distintas longitudes de palabras

	int max_word_count = 0; //contador de la palabra más larga

	// Initialize the histogram array with 0
	int i;
	for (i = 0; i < BUFFER; ++i) histogram[i] = 0;
	
	// Count the words length and store in histogram array at the specific index
	char c;
	int word_count_index = 0; //indice por cantidad de letras de las palabras
	while (c = getchar())
	{
		if (c == ' ' || c == '\t' || c == '\n' || c == EOF) //cuando termina una palabra
		{
			if (word_count_index > 0) //si la palabra no es nula
			{
				++histogram[word_count_index - 1]; //aumenta el contador en esa longitud

				if (histogram[word_count_index - 1] > max_word_count) // si es la palabra más larga
					max_word_count = histogram[word_count_index - 1];

				if (histogram_length < word_count_index - 1) //si aparecen nuevas longitudes
					histogram_length = word_count_index - 1;

				word_count_index = 0; // reinicia el contador de letras
			}

			if (c == EOF) break; //Cuando termina de ingresar palabras (Ctrl + C)
		}

		else ++word_count_index; //cuenta las letras de una palabra
	}

	// Add in the histogram array a end of useful data char
  	histogram[histogram_length + 1] = '$';

  	putchar('\n');

  	int column_index = 0; //indice de columna
  	int line_index = 0; // indice de linea


  	// Print horizontal histogram
  	printf("Horizontal Histogram\n--------------------\n");

  	while (histogram[column_index] != '$') //Hasta llegar al final q hay '$'
  	{
  		printf("%3d: \t", column_index + 1); //imprime un decimal usando hasta 3 espacios de ser necesario

  		// Imprime tantos '#' por el numero de veces que se repite una palabra (en cada casilla de histogram)
  		for (line_index = 0; line_index < histogram[column_index]; ++line_index) putchar('#');

  		putchar('\n');

  		++column_index; //siguiente columna horizontal
  	}

  	putchar('\n');

  	// Print a vertical histogram
  	printf("Vertical Histogram\n------------------\n");
	// Vertical Histogram
    for (i = max_word_count; i > 0; --i) // desde la frecuencia máxima hacia abajo
    {
        for (column_index = 0; column_index <= histogram_length; ++column_index)
        {
            if (histogram[column_index] >= i)
                printf("  # ");
            else
                printf("    ");
        }
        putchar('\n');
    }

    // Imprimir los números de longitud de palabra debajo del histograma
    for (column_index = 0; column_index <= histogram_length; ++column_index)
        printf("%3d ", column_index + 1);
    putchar('\n');

}	
