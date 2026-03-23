#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
struct snake
{
	int x[100];
	int y[100];
	char ky;
	int len;
};
struct snake snake;
struct food
{
	int x,y;
};
struct food food;
void gotoxy(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void direction()
{
	if(_kbhit())
	{
	snake.ky=_getch();
	}
	switch(snake.ky)
	{
		case 'w':snake.y[0]--;break; 
		case 's':snake.y[0]++;break;
		case 'a':snake.x[0]--;break;
		case 'd':snake.x[0]++;break;
	}
}
void border()
{
	int width,height;
	for(height=0;height<=30;height++)
	{
		for(width=0;width<=40;width++)
		{
			if(width==0||width==40||height==0||height==30)
			printf("*");
			else
			printf(" ");
		}
		printf("\n");
	}
}
void Food()
{
	food.x=rand()%39+1;
	food.y=rand()%29+1;
}
void snakemove()//给蛇的身子赋值
{
	for(int i=snake.len-1;i>0;i--)
	{
		snake.x[i]=snake.x[i-1];
		snake.y[i]=snake.y[i-1];
	}
}
vo
int main()
{
	snake.ky='d';
	snake.len=3;
	border();
	srand((unsigned)time(NULL));
	snake.x[0]=rand()%39+1;
	snake.y[0]=rand()%29+1;
	while(1)
	{
		direction();
		gotoxy(snake.x[0],snake.y[0]);
		printf("#");
		for(int i=1;i<snake.len-1;i++)
		{
			gotoxy(snake.x[i-1],snake.y[i-1]);
			printf("#");
		}
		gotoxy(food.x,food.y);
		printf("$");
	}
	return 0;
}