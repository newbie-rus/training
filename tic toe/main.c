#include <stdio.h>

void user_greeting();
void output_dash(char dash[][3]);
void user_move(char dash[][3]);
void computer_move(char dash[][3]);

// #define color_print(color, background_color, )

// "\033[37;1;41;5m Внимание \033[0m\n" 
int main()
{
	user_greeting();

	char dash[3][3] = {};
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			dash[i][j] = ' ';
	
	user_move(dash);

}

void user_greeting()
{
	for (int i = 0; i < 55; i++)
		printf("*");

	printf("\n*");
	for (int i = 0; i < 53; i++)
		printf(" ");
	printf("*\n");
	
	printf("*");
	// "\033[37;1;41;5m Внимание \033[0m\n" 
	printf("\033[36;5m   Hi, user. This is a program for playing tic toe   \033[0m");
	printf("*");
	
	printf("\n*");
	for (int i = 0; i < 53; i++)
		printf(" ");
	printf("*\n");
	
	for (int i = 0; i < 55; i++)
		printf("*");
	printf("\n\n\n");	
}

void output_dash(char dash[][3])
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 13; i++)
			printf("+");
		printf("\n");

		for (int p = 0; p < 3; p++)
		{
			printf("+ ");
			printf("\033[31;5m%c \033[0m", dash[j][p]);
		}
		printf("+\n");
	}
	
	for (int i = 0; i < 13; i++)
		printf("+");

	printf("\n");
}

void user_move(char dash[][3])
{
	printf("Ваша очередь делать ход.\n"
	       "Введите координаты поля, в которое хотите поставить <X>.\n"
		   "Первое число - номер строки, второе - номер столбца(Пример: 2,3).\n");
	output_dash(dash);

	int x = 0, y = 0;
	scanf("%d,%d", &x, &y);
	dash[x-1][y-1] = 'X';
} 

void computer_move(char dash[][3])
{
	if (dash[1][1] != 'X')
	{
		dash[1][1] = 'O';
		return ;
	}
	else
	{
		if(dash[0][0] != 'X')
			dash[0][0] = 'O';
	}
	
}