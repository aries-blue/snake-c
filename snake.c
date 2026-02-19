#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
int main()
{
	int g,k,x,y;/*g=height，k=width*/
	char i;
	srand((unsigned)time(NULL));
	x=rand()%34+1;
	y=rand()%24+1;
	while(1)
	{
		if(kbhit())
		{
			i=getch();
			if(i=='w')
			y=y-1;
			if(i=='s')
			y=y+1;
			if(i=='a')
			x=x-1;
			if(i=='d')
			x=x+1;
		}
		system("cls");
		for(g=0;g<=25;g++)
		{
			for(k=0;k<=35;k++)
			{
				if(g==0||k==0||g==25||k==35)
				printf("*");
				else if(g==y&&k==x)
				printf("0");
				else
				printf(" ");
			}
			printf("\n");
		}
		Sleep(100);	
		if(i=='a')
		x--;
		else
		x++;
		if(x==35||x==0)
		x=1;
		if(y==0||y==25)
		y=1;
		
	}
}
