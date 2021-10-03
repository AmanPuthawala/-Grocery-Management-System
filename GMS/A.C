#include<conio.h>
#include<stdio.h>
#include<string.h>
void main(int argc, char *argv[])
{
	char c[50];
	clrscr();
	if(argc == 2)
	{
		strcpy(c,"type ");	// c = "type "
		strcat(c,argv[1]);  // c = "type ama.txt"
		strcat(c," | more");  // c = "type ama.txt | more"
		system(c);
	}
	else
	{
		printf("\nPlease type:\n A filename.ext\n\n");
	}
}