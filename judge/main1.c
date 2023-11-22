#include <stdio.h>
#include <string.h>

int main()
{

}

struct Point {
        int x;
        int y;
};

int cmp_Point(const void * p1, const void * p2)
{
	int x1 = (*(struct Point*)p1).x;
	int y1 = (*(struct Point*)p1).y;
	
	int x2 = (*(struct Point*)p2).x;
	int y2 = (*(struct Point*)p2).y;
	
	if ((x1*x1 + y1*y1) > (x2*x2 + y2*y2))
		return 1;

	if ((x1*x1 + y1*y1) < (x2*x2 + y2*y2))
		return -1;

	else
		return 0;

}
которая сравнивает две точки, хранящихся как struct Point, лежащих по адресам p1 и p2 и возвращает:
0 - если точки лежат на равном расстоянии от центра координат
<0 - если первая ближе второй к центру координат
>0 - если первая дальше второй от центра координат

Функцию main реализовывать НЕ нужно. Проверку корректности аргументов не делать.

Язык:	gcc-vg - GNU C (valgrind) 4.8.3
Файл	Файл не выбран
Отправить!	
