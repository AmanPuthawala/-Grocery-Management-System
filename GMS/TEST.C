#include<conio.h>
#include<stdio.h>

#include"global.h"
void main()
{
	FILE *fp;
	clrscr();
	fp = fopen("bill.txt","rb");
	fread(&bill, sizeof(bill),1,fp);
	while(!feof(fp))
	{
		printf("%d %s\n",bill.billno, bill.iname);
		fread(&bill, sizeof(bill),1,fp);
	}
	fclose(fp);
	getch();
}