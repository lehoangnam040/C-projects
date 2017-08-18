#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int isword(char x){
	if((x<=90 && x>=65)  || (x>=97 && x<=122)) return 1;
	else return 0;
}
int word(char source_str[100],int *n){
	int count=0;
	int i=0;
	while(i<*n){
		if( isword(source_str[i]) == 1  )
		{
			int j=i+1;
			while( isword(source_str[j]) == 1  )
				j++;
			i=j;
			count++;
		}
		i++;
	}
	return count;
}
void upper_words(char source_str[100],int *n){
	int i=0;
	while(i<*n){
		if( isword(source_str[i]) ==1   )
		{
			source_str[i]=toupper(source_str[i]);
			int j=i+1;
			while( isword(source_str[j]) == 1  )
				j++;
			i=j;
		}
		i++;
	}
	for(int i=0;i<*n;i++)
		printf("%c",source_str[i]);
}
void find_longest(char source_str[100],int *n){
	int i=0,l=0,mark;
	while(i<*n){
		if( isword(source_str[i]) == 1  )
		{
			int j=i+1;
			while( isword(source_str[j]) == 1  )
				j++;
			if(l < (j-i)){
				l=(j-i);
				mark=i;
			} 
			i=j;
		}
		i++;
	}
	printf("The longest word is:\n");
		for(int k=mark;k< (mark+l);k++)
			printf("%c",source_str[k]);
}
void sentence(char source_str[100],int *n){
	char sample_str[(*n)+1];
	strcpy(sample_str,source_str);
	int length=0,sentences=0;
	for(int i=0;i<*n;i++){
		if(sample_str[i]==' ' && isword(sample_str[i+1]) == 0);
		else{
			source_str[length]=sample_str[i];
			length++;	
		}
	}
	*n = length;
	int k=0;
	while(k<length){
		if(isword(source_str[k]) == 1){
			source_str[k]=toupper(source_str[k]);
			k++;
			break;
		}
		k++;
	}
	for(int i=k;i<length;i++){
		if(isword(source_str[i]) == 1){
			if(source_str[i-1] == '?' || source_str[i-1] == '.' || source_str[i-1] == '!' )
			{
			source_str[i]=toupper(source_str[i]);
			sentences++;
			}
		else if(source_str[i-1]==' ' && (source_str[i-2] == '?' || source_str[i-2] == '.' || source_str[i-2] == '!' ))
			{
			source_str[i]=toupper(source_str[i]);
			sentences++;
			}	
		}
	}
	printf("The string has %d sentences.\n",sentences+1);
	for(int i=0;i<length;i++)
		printf("%c",source_str[i]);
}
int main(){
	char choice;
	int n;
	char source_str[100];
		printf("Enter the string that need to process: ");
		fflush(stdin);
		gets(source_str);
		n=strlen(source_str);
	while(1){
		system("cls");
		printf("1. Capitalize all letters of the string\n");
		printf("2. Low case all letters of the string\n");
		printf("3. Check how many words in the string\n");
		printf("4. Capitalize all first letter of each word\n");
		printf("5. find the word that has longest length\n");
		printf("6. Check how many sentences? Capitalize the first word of each sentence\n");
		printf("0. Exit\n");
		printf("your selection(1 - 6 ): ");
		fflush(stdin);
		scanf("%c",&choice);
		if(choice=='0') break;
		else switch(choice){
			case '1':	for(int i=0;i<n;i++)
						source_str[i] = toupper(source_str[i]);
						for(int i=0;i<n;i++)
							printf("%c",source_str[i]);
						break;
			case '2':	for(int i=0;i<n;i++)
						source_str[i] = tolower(source_str[i]);
						for(int i=0;i<n;i++)
							printf("%c",source_str[i]);
				break;
			case '3':	printf("The string has %d words",word(source_str,&n));
					break;
			case '4':	upper_words(source_str,&n);
				break;
			case '5':	find_longest(source_str,&n);
				break;
			case '6':	sentence(source_str,&n);
				break;
		}
		getch();
	}
	
}
