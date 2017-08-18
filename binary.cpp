//Sinh cac day nhi phan co do dai n
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
	int n,count=1;
	char *a;
	FILE *f;
	printf("Nhap so nguyen duong n <=30: ");
	scanf("%d",&n);
	a = (char*)malloc(n*sizeof(char));
	for(int i=0;i<n;i++)
		a[i]='0';
	f = fopen("binary.txt","w");
	fprintf(f,"%s\n",a);
	while(1){
		for(int i=n;i>=0;i--){
			if(a[i]=='0'){
				a[i]='1';
				for(int j=i+1;j<n;j++)	a[j]='0';
				fprintf(f,"%s\n",a);
				break;
			}
			else if(a[i]=='1' && i==0){
				count = 0;
				break;
			}
			else  continue;
		}
		if(count == 0 ) break;
	}
	fclose(f);
}
