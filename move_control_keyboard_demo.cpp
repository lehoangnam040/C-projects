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
int main(){
	char kytu = '*';
	char kytu1 = '$';
	int dk;								//khai bao bien dieu khien
	int x,y,a,b;						//khai bao bien toa do
		printf("Vi tri xuat hien ky tu luc dau la (x,y) = ");
		scanf("%d %d",&x,&y);
		printf("Vi tri xuat hien ky tu 1 luc dau la (a,b) = ");
		scanf("%d %d",&a,&b);
		system("cls");
		gotoxy(x,y);
		printf("%c",kytu);
		gotoxy(a,b);
		printf("%c",kytu1);
	while(1){
		dk = getch() ;
		if( dk == 27 ) break;
		else
		switch( dk ){
			case 80:	if(y>=25)	y=0;
						else	y++;				//mui ten di len
						system("cls");
						gotoxy(x,y);
						printf("%c",kytu);
						gotoxy(a,b);
						printf("%c",kytu1);
						continue;
			case 72:	if(y<=0)	y=25;
						else	y--;				//mui ten di xuong
						system("cls");
						gotoxy(x,y);
						printf("%c",kytu);
						gotoxy(a,b);
						printf("%c",kytu1);
						continue;
			case 77:	if(x>=80) x=0;
						else x++;			//mui ten sang phai
						system("cls");
						gotoxy(x,y);
						printf("%c",kytu);
						gotoxy(a,b);
						printf("%c",kytu1);
						continue;
			case 75:	if(x<=0) x=80;
						else x--;				//mui ten sang trai
						system("cls");
						gotoxy(x,y);
						printf("%c",kytu);
						gotoxy(a,b);
						printf("%c",kytu1);
						continue;
			case 'w':
			case 'W':	if(b<=0)	b=25;
						else	b--;				//mui ten di len
						system("cls");
						gotoxy(x,y);
						printf("%c",kytu);
						gotoxy(a,b);
						printf("%c",kytu1);
						continue;
			case 's':
			case 'S':	if(b>=25)	b=0;
						else	b++;				//mui ten di xuong
						system("cls");
						gotoxy(x,y);
						printf("%c",kytu);
						gotoxy(a,b);
						printf("%c",kytu1);
						continue;
			case 'd':	
			case 'D':	if(a>=80) a=0;
						else a++;			//mui ten sang phai
						system("cls");
						gotoxy(x,y);
						printf("%c",kytu);
						gotoxy(a,b);
						printf("%c",kytu1);
						continue;
			case 'a':
			case 'A':	if(a<=0) a=80;
						else a--;				//mui ten sang trai
						system("cls");
						gotoxy(x,y);
						printf("%c",kytu);
						gotoxy(a,b);
						printf("%c",kytu1);
						continue;
			case 27:	system("cls");
						break;
			default:	continue;
		}
	}
}
