#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 500
#define HEIGHT 200
#define DURATION 10 /* durée de l'effet en secondes */

const char charset[] = {
	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#$%&*()"
};
/**
 * random_char - Generates a random character from the charset
 * Return: A random character
 */
char random_char(void)
{
	return (charset[rand() % (sizeof(charset) - 1)]);
}
/**
 * matrix_rain - Displays a Matrix-style falling text effect on the terminal
 */
void matrix_rain(void)
{
	int x, y;
	int column_y[WIDTH];
	time_t start_time;

	srand(time(NULL));
	for (x = 0; x < WIDTH; x++)
		column_y[x] = rand() % HEIGHT;
	printf("\033[2J\033[?25l"); /* Clear screen + hide cursor */
	start_time = time(NULL);
	while (difftime(time(NULL), start_time) < DURATION)
	{
		for (y = 0; y < HEIGHT; y++)
		{
			for (x = 0; x < WIDTH; x++)
			{
				if (y == column_y[x])
					printf("\033[%d;%dH\033[1;32m%c", y + 1, x + 1, random_char());
				else if (y == column_y[x] - 1)
					printf("\033[%d;%dH\033[0;32m%c", y + 1, x + 1, random_char());
				else if (y == column_y[x] - 2)
					printf("\033[%d;%dH\033[2;32m%c", y + 1, x + 1, random_char());
				else if (y == column_y[x] - 3)
					printf("\033[%d;%dH ", y + 1, x + 1);
			}
		}
		for (x = 0; x < WIDTH; x++)
		{
			if (rand() % 10 < 2)
				column_y[x] = (column_y[x] + 1) % HEIGHT;
		}
		fflush(stdout);
		usleep(60000); /* 60 ms */
	}
	printf("\033[?25h\033[0m\n");
}
/**
 * dramatic_intro - Displays a dramatic countdown and launches the Matrix
 * @argv: Unused command-line arguments
 * @last_status: Unused pointer to last shell status
 * Return: Always returns 0
 */
int dramatic_intro(char **argv, int *last_status)
{
	int count = 5;

	(void) argv;
	(void) last_status;

	printf("\n🟢 Préparation de la Matrice...\n");
	sleep(1);
	while (count > 0)
	{
		printf("📟 Insertion dans la Matrice dans... %d\n", count);
		sleep(1);
		count--;
	}
	printf("\n🔌 Connexion établie. you have a haked...\n");
	sleep(1);
	matrix_rain();
	system("clear");
	return (0);
}
