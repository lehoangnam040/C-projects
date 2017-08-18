#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(unsigned int n){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++);
	}
}
int main(){
	char kytu = '*';
	int x=0,y=0;
	int ch = 77;
	system("cls");
	gotoxy(x,y);
	printf("%c",kytu);
	while(1){
		if(kbhit()) ch = getch();
		else
		switch(ch){
			case 80:	if(y>=24)	y=1;
						else	y++;				//mui ten di len
						system("cls");
						gotoxy(x,y);
						printf("%c",kytu);
						delay(6000);
						break;
			case 72:	if(y<=1)	y=24;
						else	y--;				//mui ten di xuong
						system("cls");
						gotoxy(x,y);
						printf("%c",kytu);
						delay(6000);
						break;
			case 77:	if(x>=79) x=1;
						else x++;			//mui ten sang phai
						system("cls");
						gotoxy(x,y);
						printf("%c",kytu);
						delay(6000);
						break;
			case 75:	if(x<=1) x=79;
						else x--;				//mui ten sang trai
						system("cls");
						gotoxy(x,y);
						printf("%c",kytu);
						delay(6000);
						break;
		}
	}
}
