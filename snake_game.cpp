#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

int Random(int n){
	return rand()%(n+1);
}
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
void cpytoado(int *x,int *y,int n){
	for(int i=n;i>=1;i--){
			x[i]=x[i-1];
			y[i]=y[i-1];
	}
}
void veran(int *x,int *y,int n,char kytu,unsigned int time){
	for(int i=0;i<n-2;i++){
		gotoxy(x[i],y[i]);
		printf("%c",kytu);
	}
		gotoxy(x[n-1],y[n-1]);
		printf(" ");
		delay(time);
}
int main(){
	unsigned int time = 5000;
	char food = '$';
	int xf,yf;
	int thuc_an;
	char kytu = '*';
	int *x,*y;
	int n=3;
	x = (int *) malloc(n*sizeof(int));	//cap phat dong cho mang
	y = (int *) malloc(n*sizeof(int));	
	x[0]=0; x[1]=0; x[2]=x[1]-1;
	y[0]=0; y[1]=0; y[2]=y[1];
	int ch = 77, dk = 77;	// 2 bien dieu khien
	gotoxy(x[0],y[0]);
	printf("%c",kytu);
	xf = Random(80);
	yf = Random(25);
	gotoxy(xf,yf);
	printf("%c",food);
	thuc_an = 1;
	while(1){
		if(ch == 27) break;
		if(kbhit()){
			dk = getch();				
			if(ch == 80 && (dk == 80 || dk == 77 || dk == 75)) ch = dk;	//Di len thi ko the di xuong		
			if(ch == 72 && (dk == 72 || dk == 77 || dk == 75)) ch = dk;	//Di xuong thi ko the di len
			if(ch == 77 && (dk == 80 || dk == 72 || dk == 77)) ch = dk;	//sang phai thi ko the sang trai
			if(ch == 75 && (dk == 80 || dk == 72 || dk == 75)) ch = dk;	//sang trai thi ko the sang phai
		}
		else		
		switch(ch){
			case 80:	cpytoado(x,y,n);
						if(y[0]>=24)	y[0]=0;
						else	y[0]++;			//mui ten di len
						veran(x,y,n,kytu,time);
						break;
			case 72:	cpytoado(x,y,n);
						if(y[0]<=0)	y[0]=24;
						else	y[0]--;			//mui ten di xuong
						veran(x,y,n,kytu,time);
						break;
			case 77:	cpytoado(x,y,n);
						if(x[0]>=79) x[0]=1;
						else x[0]++;			//mui ten sang phai
						veran(x,y,n,kytu,time);
						break;
			case 75:	cpytoado(x,y,n);
						if(x[0]<=1) x[0]=79;
						else x[0]--;			//mui ten sang trai
						veran(x,y,n,kytu,time);
						break;
		}
		if(x[0] == xf && y[0] == yf){
			thuc_an = 0;
			n+=1;
			x = (int *) realloc(x,n*sizeof(int));	//cap phat dong cho mang
			y = (int *) realloc(y,n*sizeof(int));	
		}
		if(thuc_an == 0){		//tao thuc an
			xf = Random(79);
			yf = Random(24);
			gotoxy(xf,yf);
			printf("%c",food);
			thuc_an = 1;
		}
	}
	delete [] x;
	delete [] y;
	return 0;
}
		
