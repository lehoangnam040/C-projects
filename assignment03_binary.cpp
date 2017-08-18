//Assignment03
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define allowance 4000.0
float tax(float *taxable){			//Function that calculate tax from taxable
	if(*taxable <= 5000.0)
		return *taxable*0.05;
	if(*taxable >5000.0 && *taxable <= 10000.0)
		return 250.0+(*taxable-5000.0)*0.1;
	if(*taxable >10000.0 && *taxable <= 20000.0)
		return 750.0+(*taxable-10000.0)*0.15;
	if(*taxable >20000.0 && *taxable <= 30000.0)
		return 2250.0+(*taxable-20000.0)*0.2;
	if(*taxable >30000.0 && *taxable <= 50000.0)
		return 4250.0+(*taxable-30000.0)*0.25;
	if(*taxable >50000.0 && *taxable <= 80000.0)
		return 9250.0+(*taxable-50000.0)*0.3;
	if(*taxable >80000.0)
		return 18250.0+(*taxable-80000.0)*0.35;
}

typedef struct{
	int code;
	char name[30];
	float income;
	float pension;
	float insurance;
	float dependant;
	float charity;
	float taxable;
	float tax;
	float net;
}employee;

void add(FILE *f,char fname[20]){
	int i,j,keeptrying,code,n=0;
	char choice;
	employee *nv;
	printf("\nEnter financial information for employees:\n");
	f = fopen(fname,"ab");
	nv=(employee*)malloc(n*sizeof(employee));
	while(1){
		printf("\nEnter personal information:\n");
		keeptrying=1;
		do{
			int rc;		char after;
			printf("Enter code (0 to stop): ");
			fflush(stdin);
			rc = scanf("%d%c",&code,&after);
			if( rc == 0 )
				printf("No input!!\n");
			else if( after != '\n')
				printf("Trailing character!!\n");
			else
				keeptrying = 0;
		}while(keeptrying == 1);
		if(code==0) break;
		else{
			n++;
			nv = (employee*)realloc(nv,n*sizeof(employee));
			i =n-1;
			nv[i].code=code;
			printf("Enter name: ");
			fflush(stdin);
			gets(nv[i].name);
			while(1){
				printf("Income for the current month (In thousand of VND): ");
				scanf("%f",&nv[i].income);
				if(nv[i].income <= 0 ){
					printf("Invalid input, try again!!\n");
					continue;
				}
				else break;
			}
			printf("Pension contributions (5%%) y/n??: ");
			scanf(" %c",&choice);
			if(choice=='n') nv[i].pension = 0;
			else if(choice=='y') nv[i].pension = 0.05*nv[i].income;
			printf("Health insurance (1%%) y/n??: ");
			scanf(" %c",&choice);
			if(choice=='n') nv[i].insurance = 0;
			else if(choice=='y') nv[i].insurance = 0.01*nv[i].income;
			while(1){
				printf("Number of dependants < 18 years old: ");
				scanf("%d",&j);
				if(j < 0 ){
					printf("Invalid input, try again!!\n");
					continue;
				}
				else break;
			}
			nv[i].dependant = 1600.0*float(j);
			printf("Gift of charity: ");
			scanf("%f",&nv[i].charity);
			nv[i].taxable = nv[i].income - ( allowance + nv[i].pension + nv[i].insurance + nv[i].dependant + nv[i].charity);
			nv[i].tax = tax(&nv[i].taxable);
			nv[i].net = nv[i].income - nv[i].tax;
		}
	}
	for(int i=0;i<n;i++)
		fwrite(&nv[i],sizeof(employee),1,f);
	fclose(f);
}

void overwrite(FILE *f,char fname[20]){
	int i,j,keeptrying,code,n=0;
	char choice;
	employee *nv;
	printf("\nEnter financial information for employees:\n");
	f = fopen(fname,"wb");
	nv = (employee*)malloc(n*sizeof(employee));
	while(1){
		printf("\nEnter personal information:\n");
		keeptrying=1;
		do{
			int rc;		char after;
			printf("Enter code (0 to stop): ");
			fflush(stdin);
			rc = scanf("%d%c",&code,&after);
			if( rc == 0 )
				printf("No input!!\n");
			else if( after != '\n')
				printf("Trailing character!!\n");
			else
				keeptrying = 0;
		}while(keeptrying == 1);
		if(code==0) break;
		else{
			n++;
			nv = (employee*)realloc(nv,n*sizeof(employee));
			i =n-1;
			nv[i].code=code;
			printf("Enter name: ");
			fflush(stdin);
			gets(nv[i].name);
			while(1){
				printf("Income for the current month (In thousand of VND): ");
				scanf("%f",&nv[i].income);
				if(nv[i].income <= 0 ){
					printf("Invalid input, try again!!\n");
					continue;
				}
				else break;
			}
			printf("Pension contributions (5%%) y/n??: ");
			scanf(" %c",&choice);
			if(choice=='n') nv[i].pension = 0;
			else if(choice=='y') nv[i].pension = 0.05*nv[i].income;
			printf("Health insurance (1%%) y/n??: ");
			scanf(" %c",&choice);
			if(choice=='n') nv[i].insurance = 0;
			else if(choice=='y') nv[i].insurance = 0.01*nv[i].income;
			while(1){
				printf("Number of dependants < 18 years old: ");
				scanf("%d",&j);
				if(j < 0 ){
					printf("Invalid input, try again!!\n");
					continue;
				}
				else break;
			}
			nv[i].dependant = 1600.0*float(j);
			printf("Gift of charity: ");
			scanf("%f",&nv[i].charity);
			nv[i].taxable = nv[i].income - ( allowance + nv[i].pension + nv[i].insurance + nv[i].dependant + nv[i].charity);
			nv[i].tax = tax(&nv[i].taxable);
			nv[i].net = nv[i].income - nv[i].tax;
		}
	}
	for(int i=0;i<n;i++)
		fwrite(&nv[i],sizeof(employee),1,f);
	fclose(f);
}

void display(FILE *f,char fname[20]){
	employee nv[1];
	f = fopen(fname,"rb");
	printf("\nCode name    income   allow  pens  ins   char depend taxable  tax     net\n--------------------------------------------------------------------------------\n");
	while( fread(&nv[0],sizeof(employee),1,f) == 1)
		printf("%-4d %-8s %-8.0f %-5.0f %-5.0f %-5.0f %-4.0f %-5.0f  %-7.0f %-8.0f %-8.0f\n",nv[0].code,nv[0].name,nv[0].income,allowance,nv[0].pension,nv[0].insurance,nv[0].charity,nv[0].dependant,nv[0].taxable,nv[0].tax,nv[0].net);
	fclose(f);
}

void search(FILE *f,char fname[20]){
	int code;
	employee nv[1];
	printf("\nEnter code to be searched ");
	scanf("%d",&code);
	f = fopen(fname,"rb");
	printf("\nCode name    income   allow  pens  ins   char depend taxable  tax     net\n--------------------------------------------------------------------------------\n");
	while(fread(&nv[0],sizeof(employee),1,f) == 1 ){
		if(code == nv[0].code)
			printf("%-4d %-8s %-8.0f %-5.0f %-5.0f %-5.0f %-4.0f %-5.0f  %-7.0f %-8.0f %-8.0f\n",nv[0].code,nv[0].name,nv[0].income,allowance,nv[0].pension,nv[0].insurance,nv[0].charity,nv[0].dependant,nv[0].taxable,nv[0].tax,nv[0].net);
	}
	fclose(f);
}
				
void sortcode(FILE *f,char fname[20]){
	int n=0;
	employee test[1];
	f = fopen(fname,"rb");
	while( fread(&test[0],sizeof(employee),1,f) == 1)	n++;
	employee nv[n];
	rewind(f);
	int i=0;
	while( fread(&test[0],sizeof(employee),1,f) == 1){
		nv[i]=test[0];
		i++;
	}
	fclose(f);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)				//interchange sort
			if(nv[i].code > nv[j].code){
				test[0]=nv[i];
				nv[i]=nv[j];
				nv[j]=test[0];
			}		
	f = fopen(fname,"wb");
	for(int i=0;i<n;i++)
		fwrite(&nv[i],sizeof(employee),1,f);
	fclose(f);
	printf("Sorted!!\n");
}

void sortbubble(FILE *f, char fname[20]){
	int n=0;
	employee test[1];
	f = fopen(fname,"rb");
	while( fread(&test[0],sizeof(employee),1,f) == 1)	n++;
	employee nv[n];
	rewind(f);
	int i=0;
	while( fread(&test[0],sizeof(employee),1,f) == 1){
		nv[i]=test[0];
		i++;
	}
	fclose(f);
	for(int i=0;i<n;i++)
		for(int j=n-1;j>i;j--)
			if(nv[j].code < nv[j-1].code ){			//bubble sort
				test[0]= nv[j];
				nv[j]=nv[j-1];
				nv[j-1]=test[0];
			}
	f = fopen(fname,"wb");
	for(int i=0;i<n;i++)
		fwrite(&nv[i],sizeof(employee),1,f);
	fclose(f);
	printf("Sorted!!\n");
}

void check(FILE *f,char fname[20]){
	int n=0;
	f = fopen(fname,"rb");
	employee test[1];
	while( fread(&test[0],sizeof(employee),1,f) == 1)	n++;
	rewind(f);
	employee nv[n];
	int b=0;
	int i=0;
	while( fread(&test[0],sizeof(employee),1,f) == 1){
		nv[i]=test[0];
		i++;
	}
	for(int i=0;i<n-1;i++)
		if(nv[i].code > nv[i+1].code)	b=1;
	if(b==0) printf("File was sorted!!\n");
	else printf("File was not sorted!!\n");
	fclose(f);
}

void delbycode(FILE *f,char fname[20]){
	int n=0,x;
	employee test[1];
	printf("Enter code to be deleted ");
	scanf("%d",&x);
	f = fopen(fname,"rb");
	while( fread(&test[0],sizeof(employee),1,f) == 1)	n++;
	employee nv[n];
	rewind(f);
	int i=0;
	while( fread(&test[0],sizeof(employee),1,f) == 1){
		nv[i]=test[0];
		i++;
	}
	fclose(f);
	f = fopen(fname,"wb");
	for(int i=0;i<n;i++)
		if(nv[i].code != x)
			fwrite(&nv[i],sizeof(employee),1,f);
	fclose(f);
	printf("Deleted!!\n");
}

int main(){
	FILE *f=NULL;
	char choice;
	char fname[20] = "tax.dat" , constfname[20] = "tax.dat";
	while(1){
		system("cls");
		printf("  Choose one of following options\n  1.Enter name of file to store data\n  2. Enter a list of employees\n  3. Display tax information\n  4. Search an employee by code\n  5.Sort in increasing order by code\n  6.Sort directly on file by bubble sort\n  7.Check if data on file is sorted or not\n  8.Delete an employee by code\n  0. Exit");
		printf("\nYour selection (0 - 8): ");
		fflush(stdin);
		scanf(" %c",&choice);
		if(choice=='0') break;
		else switch(choice){
			case '1':	printf("\nEnter file name (1 character: tax.txt): ");	//Enter name of file to store data
						fflush(stdin);
						gets(fname);
						if(strlen(fname)==1)	strcpy(fname,constfname);
					break;
			case '2':	char c;							//Enter a list of employees
						printf("\nDo you want to Add more employee into a list, or overwrite it (a,o)?? ");
						scanf(" %c",&c);
						if(c=='o')	overwrite(f,fname);
						else if(c=='a') add(f,fname);						
					break;
			case '3':	display(f,fname);					//Display tax information
					break;		
			case '4':	search(f,fname);				//Search an employee by code
					break;		
			case '5':	sortcode(f,fname);					//Sort in increasing order by code
					break;		
			case '6':	sortbubble(f,fname);			//Sort directly on file by bubble sort
					break;		
			case '7':	check(f,fname);		//Check if data on file is sorted or not
					break;		
			case '8':	delbycode(f,fname);		//Delete an employee by code
					break;	
		}
		printf("Press anykey to continue...");
		getch();
	}
}
	
