#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define f fflush(stdin)
#define bills "file.txt"

#include "global.h"
#include "library.h"
#include "edit.h"


//file write
void write_file()
{
	char itemName[10][25] = {"1.Arial Powder","2.Coffee","3.Cheese",
						"4.Groundnut Oil","5.Sugar","6.Cookie",
						"7.Tuvar Dal",
						"8.Rice","9.Wheat","10.Coconut"};
	char wt[10][5] = {"1Kg","1Kg","1Kg","15Kg","1Kg",
		 "1Kg","1Kg","1Kg","1Kg","1Kg"};
	char prices[10][5] = {"80","180","145","2145","210","120","100",
						"98","75","115"};
	int i, j, q, row, price;
	char count;
	fp=fopen(bills,"ab+");
	if(fp==NULL)
	{
		fp=fopen(bills,"wb+");
		if(fp==NULL)
		{
			printf("File doesn't Exist!!");
		}
	}
	do
	{
	  clrscr();
	  for(i=0;i<=79;i++)
	  {
		for(j=61;j<=61;j++)
		{
		    cprintf("%c",j);
		}
	  }
	   printf("\t\t\t   -> Enter Bill Detail: <-\n");
	   for(i=0;i<=79;i++)
		{
			for(j=61;j<=61;j++)
			{
				cprintf("%c",j);
			}
		}
		bill.billno++;
		printf("\t\tEnter Bill no:");
		printf("%d",bill.billno);
		gotoxy(50,4);
		{
		printf("Customer Name:");
		scanf("%s",&bill.cname);
		}
		printf("\n");
		// top line of Menu
		fflush(stdin);
		printf("\t\t---------------------------------------------\n\n");
		gotoxy(24,7);
		{
			printf("!!Select Items From Menu!!");
		}
		gotoxy(2,8);
	    {
		printf("\t\t---------------------------------------------\n\n\n");
	    }
		//left line of Menu
		for(i=6;i<=20;i++)
		{
			gotoxy(17,i);
				{
					printf("|");
				}
		}
		gotoxy(26,9);
		{
			printf("Items");
		}
		 //line right side of item
		 for(i=9;i<=20;i++)
		 {
			gotoxy(40,i);
			{
				printf("|");
			}
		 }
		gotoxy(42,9);
		{
			printf("Kg/gm");
		}
		//line right side of price
		 for(i=9;i<=20;i++)
		 {
			gotoxy(48,i);
			{
				printf("|");
			}
		 }

		//line right side of Price
		gotoxy(50,9);
		{
			printf("Price");
		}
		for(i=9;i<=19;i++)
		{
			gotoxy(56,i);
			{
				printf("|");
			}
		}
		//line right side of Qty
			gotoxy(58,9);
		{
			printf("Qty");
		}
		for(i=6;i<=20;i++)
		{
			gotoxy(62,i);
			{
				printf("|");
			}
		}

		//Entering Items
		//items
		for(row=10;row<=19;row++)
			go(22,row,itemName[row-10],15);	// 8+4+2+1
		 //kg/gm                                // Brigtness
		for(row=10;row<=19;row++)
			go(43,row,wt[row-10],15);
	    //prices
		for(row=10;row<=19;row++)
			go(51,row,prices[row-10],15);
		//bottom line
	    gotoxy(18,20);
	    {
		printf("--------------------------------------------");
	    }
	  do
	  {
		clear(21,1,24,79);
		go(3,21,"Enter your Choice:",15);
		f;
		scanf("%d",&bill.itemno);

		do
		{
			char qty[3];
			go(52,21,"Enter your Quantity[1-99]:",15);
			f;
			//scanf("%d",&bill.qty);
			validQty(21,78,qty,2);
			bill.qty = atoi(qty);
		}while(!(bill.qty>=1 && bill.qty<=99));
		go(20,9+bill.itemno,"->",15+128); 		// cprintf()  \n\r
		gotoxy(58,9+bill.itemno);            // printf()  \n
		printf("%d",bill.qty);

		go(24,24,"Chose Another Item(Y/N):",15); // Normal 7
		fflush(stdin);
		scanf("%c",&count);
		strcpy(bill.iname,itemName[bill.itemno-1]);
		price = atoi(prices[bill.itemno-1]);
		bill.rate = price;
		bill.total = bill.rate * bill.qty;
		fwrite(&bill,sizeof(bill),1,fp);
	  }while(count=='y'||count=='y');
		fflush(stdin);

		go(25,24,"Create Another Bill(Y/N):",15);
		f;
		scanf("%c",&count);
	 }
	 while(count=='y'||count=='Y');
	  fclose(fp);
	textattr(15);
}

//file read
void read_data()
{
	int tbillno;
	int check = 0;
	int r = 0;
   int i,j;
   int grand_total=0;
   time_t t;
   FILE *fp;
   FILE *tfp;
   textattr(15);
   clrscr();
   //tfp=fopen("bill.txt","w");
   fp=fopen(bills,"rb+");
   fread(&bill,sizeof(bill),1,fp);
   tbillno = bill.billno;
   fflush(stdin);
   while(!feof(fp))
	{
		fflush(stdin);
	  printf("\n");
	 if (check == 0)
	 {
		 char fname[30];
		 strcpy(fname, bill.cname);
		 strcat(fname,".txt");
		  tfp=fopen(fname,"ab+");
		  fprintf(tfp,"\n Bill No:%-10d\t\t\t\t\tCustomer Name: %-30s\n",bill.billno,bill.cname);
		  //Top line of output (bill)file
		  for(i=0;i<=70;i++)
		  {
			for(j=61;j<=61;j++)
			{
				fprintf(tfp,"%c",j);
			}
		  }
		  // Heading of OutputBill
		  fprintf(tfp,"\n   %-25s%-25s%-30s%-25s","Items","Quantity","Price","Total Price per Quantity\n");
		  //Bottem line of output (bill)file
		  for(i=0;i<=70;i++)
		  {
			for(j=61;j<=61;j++)
			{
				fprintf(tfp,"%c",j);
			}
		  }
		  fprintf(tfp,"\n");
		  //loop for top line of (File.txt file)
		  for(i=0;i<=79;i++)
		  {
			for(j=61;j<=61;j++)
			{
			cprintf("%c",j);
			}
		  }
		  check = 1;
	  }
	  gotoxy(28,3);

	  printf(" -> View Bill Detail!! <-\n");
	  for(i=0;i<=79;i++)
	  {
		for(j=61;j<=61;j++)
		{
		cprintf("%c",j);
		}
	  }
	  time(&t);
	  printf("%s",ctime(&t));


	  gotoxy(5,9);
	  {
		printf("Bill No:%d",bill.billno);
	  }
	  gotoxy(53,9);
	  {
			printf("Customer Name is:%s",bill.cname);
	  }
	  heading();
	  // 5, 40, 60 ,, row = 12
	  gotoxy(28,14+r);
	  {
	  printf("%d",bill.qty);
	  }
	  // checking the choice
	  /*
			char cname[30];char itemname[30];int total;
			int item;int x_0;int qty;int rate;
/	  */

	  gotoxy(5,14+r);printf("%s",bill.iname);
	  gotoxy(43,14+r);printf("%d",bill.rate);
	  bill.total=bill.rate * bill.qty;
	  gotoxy(63,14+r);printf("%d",bill.total);

	  if (bill.billno > 0)
	  {
		fprintf(tfp, "%s%13d%31d%32d\n",bill.iname,bill.qty,bill.rate,bill.total);
	  }
	  else
	  {
		fprintf(tfp,"no choice!");
	  }
		    grand_total=grand_total+bill.total;
		    delay(100);
		    fread(&bill,sizeof(bill),1,fp);
		    if (tbillno != bill.billno)
		    {
			  printf("\n\n\n\t\t\t\t\t\t\tGrand Total : %d",grand_total);
			  fprintf(tfp,"\n\t\t\t\t\t\tGrand Total:%d",grand_total);
			  grand_total=0;
			  getch();
			  check = 0;
			  r = 0;
			  clrscr();
			  tbillno = bill.billno;
		    }
		    else
			  r++;
		}
  printf("\n\n\t\t\t\t\t\t\tGrand Total : %d",grand_total);
  fprintf(tfp,"\n\t\t\t\t\t\tGrand Total:%d",grand_total);
    printf("\n\n Have a Good Day:)");
    getch();
    fclose(fp);
    fclose(tfp);
}
  void del()
  {
	   char another;
	   char s_name[30];
	   int check;
	   textattr(15);
	   clrscr();
		fp=fopen(bills,"rb+");
		ft=fopen("Temp.dat","wb+");
		another = 'y';
		check = 0;
		while(another == 'y' || another == 'Y')
		{   printf("\n\nEnter Name of Customer to delete: ");
		    fflush(stdin);
		    scanf("%s",&s_name);
		    rewind(fp);
		    while(fread(&bill,sizeof(bill),1,fp)==1)
		    {
			   if(strcmp(s_name,bill.cname)!=0)
			   {
				  fwrite(&bill,sizeof(bill),1,ft);
			   }
			   else
				check = 1; // found

		    }
		    if (check == 1)
			printf("\nDeleted succesfully.");
		    else
			printf("\n%s not found..!!",s_name);
		    fclose(fp);
		    fclose(ft);
		    remove(bills);
		    rename("Temp.dat",bills);
		    printf("\nDelete another record(y/n): ");
		    fflush(stdin);
		    scanf("%c", &another);
		}
  }


    void credits()
    {
	   textattr(15);
	   clrscr();
	printf("\n--------------------------------------------------------------------------------");
	printf("  \t \t \t \t   ==>Credits<==");
	printf("\n--------------------------------------------------------------------------------");
	gotoxy(21,9);
    {
	printf("L.J. INSTITUTE OF COMPUTER APPLICALTION!!!");
    }
	gotoxy(16,13);
    {
	printf("Sem:-III \t Div:-IET\tRollNos.:- 02,18,19.");
    }
    gotoxy(14,17);
    {
	printf("Aman Puthawala");
    }
	printf("----Saiyed Mohammed Uzef");
	printf("----Rashid Mohtasim");
	printf("\n\n\n\t\n\n\t\n\t\t\t!!!!->Press any Key to Exit<-!!!!");
	getch();
	exit(0);
    }
void am_login()
{
  char username[25],password[25];
  char ch;
  int i,j,c;
  FILE *fe;
	   textattr(15);
	   clrscr();
  fe = fopen("cs_login.txt","wb");
  //top line
  gotoxy(25,7);
  {
    printf("|---------------------------|");
  }
  //left line where login print
  gotoxy(25,8);
  {
	printf("|");
  }
  //below left line where login print
  gotoxy(25,9);
  {
    printf("|");
  }

  gotoxy(28,8);
  {
    printf(" !!->Admin Login<-!!\n");
  }
  // right line where login print
  gotoxy(53,8);
  {
    printf("|");
  }
  //  below right line where login print
  gotoxy(53,9);
  {
    printf("|");
  }
  //middle line
  gotoxy(26,9);
  {
    for(j=0;j<=26;j++)
    {
	 for(c=61;c<=61;c++)
	 {
	   cprintf("%c",c);
	 }
    }
  }
 //left strait line
  printf("\n\t\t\t|");
  printf("\n\t\t\t|");
  printf("\n\t\t\t|");
  printf("\n\t\t\t|");
  printf("\n\t\t\t|");
  printf("\n\t\t\t|");
   //right strait line
  gotoxy(53,10);
  {
    printf("|");
  }
  gotoxy(53,11);
  {
    printf("|");
  }
  gotoxy(53,12);
  {
    printf("|");
  }
  gotoxy(53,13);
  {
    printf("|");
  }
  gotoxy(53,14);
  {
    printf("|");
  }
  gotoxy(53,15);
  {
	printf("|");
  }
//last second bottem line
  gotoxy(25,14);
  {
    printf("|---------------------------|");
  }
//bottem line
  gotoxy(25,16);
  {
    printf("|---------------------------|");
  }
  gotoxy(33,10);
  {
    printf("Enter ID:");
    scanf("%s",&username);
  }
  gotoxy(33,12);
  {
    printf("Enter Password:");
    i=0;
    while(1)
    {
		ch=getch();
		if(ch==13)
		{
			break;
		}
		else
		{
			password[i]=ch;
			putch('*');
			i++;
		}
    }
    password[i]=NULL;
    printf("\n");
    if(strcmp(username,"1")==0 && strcmp(password,"2")==0)
    {    gotoxy(31,15);
	    {
			printf("Login Sucessfull!!");
	    }
    }
    else
    {
		gotoxy(34,15);
		{
			printf("Login  Fail!!");
			delay(800);
			exit(1);
		}
    }
  }
  //bottem left line of continue
  gotoxy(1,23);
  {
    for(j=0;j<=30;j++)
	{
	   for(c=45;c<=45;c++)
	    {
		 cprintf("%c",c);
	    }
	}
  }
  gotoxy(25,23);
  {
    printf("->Press Any key to Continue!!<-");
  }
  //bottem right line of continue
  gotoxy(55,23);
  {
    for(j=0;j<=25;j++)
	{
	  for(c=45;c<=45;c++)
	  {
		  cprintf("%c",c);
	  }
	}
  }
  fprintf(fe,"ID:%s Password:%s",username,password);
  getch();
    }

  void admin()
  {
	int ch,i,j,c;
	void (*fptr[3])();
	   textattr(15);
	fflush(stdin);
 //	fptr[0]=write_file;
	fptr[0]=read_data;
	fptr[1]=del;
	fptr[2]=editRecord;
   //	fptr[2]=credits;
		clrscr();
			for(j=0;j<=79;j++)
		{
		  for(c=61;c<=61;c++)
		  {

		    cprintf("%c",c);
		  }
	    }
	    gotoxy(20,2);
	    printf("!!->Welcome to Grocery Management System<-!!\n");
		for(j=0;j<=79;j++)
		{
		  for(c=61;c<=61;c++)
		  {
		    cprintf("%c",c);
		  }
	    }
	    am_login();
	    do
	    {
	    clrscr();
	    {
			for(j=0;j<=79;j++)
			{
				for(c=61;c<=61;c++)
				  {
				    cprintf("%c",c);
				  }
			}
	    }
	   gotoxy(32,2);
	   printf("\b\b\b!!->Welcome To Admin Pannel<-!!\n");
	   {
	    for(j=0;j<=79;j++)
		{
		    for(c=61;c<=61;c++)
		  {
		    cprintf("%c",c);
		  }
		}
	   }
	   printf("\n\t\t\t\t1.View Bill");
	   printf("\n\t\t\t\t2.Delete Bill");
	   printf("\n\t\t\t\t3.Edit Bill");
	   printf("\n\t\t\t\t4.Exit(Return to Login Page!!)");
	   fflush(stdin);
	   printf("\n\n \t\tEnter your choice:");
	   fflush(stdin);
	   scanf("%d",&ch);
	   if (ch != 4)
	   {
		(*fptr [ch-1])();
	   }
	   else if (ch == 4)
		return;
	  }while(ch!=4);
  }


void cs_login()
{
  char username[25],password[25];
  char ch;
  int i,j,c;
  FILE *fe;
	   textattr(15);
  fe = fopen("cs_login.txt","wb");
  //top line
  gotoxy(25,7);
  {
    printf("|---------------------------|");
  }
  //left line where login print
  gotoxy(25,8);
  {
	printf("|");
  }
  //below left line where login print
  gotoxy(25,9);
  {
    printf("|");
  }

  gotoxy(28,8);
  {
    printf(" !!->Customer Login<-!!\n");
  }
  // right line where login print
  gotoxy(53,8);
  {
    printf("|");
  }
  //  below right line where login print
  gotoxy(53,9);
  {
    printf("|");
  }
  //middle line
  gotoxy(26,9);
  {
    for(j=0;j<=26;j++)
    {
	 for(c=61;c<=61;c++)
	 {
	   cprintf("%c",c);
	 }
    }
  }
 //left strait line
  printf("\n\t\t\t|");
  printf("\n\t\t\t|");
  printf("\n\t\t\t|");
  printf("\n\t\t\t|");
  printf("\n\t\t\t|");
  printf("\n\t\t\t|");
   //right strait line
  gotoxy(53,10);
  {
    printf("|");
  }
  gotoxy(53,11);
  {
    printf("|");
  }
  gotoxy(53,12);
  {
    printf("|");
  }
  gotoxy(53,13);
  {
    printf("|");
  }
  gotoxy(53,14);
  {
    printf("|");
  }
  gotoxy(53,15);
  {
	printf("|");
  }
//last second bottem line
  gotoxy(25,14);
  {
    printf("|---------------------------|");
  }
//bottem line
  gotoxy(25,16);
  {
    printf("|---------------------------|");
  }
  gotoxy(33,10);
  {
    printf("Enter ID:");
    scanf("%s",&username);
  }
  gotoxy(33,12);
  {
    printf("Enter Password:");
    i=0;
    while(1)
    {
		ch=getch();
		if(ch==13)
		{
			break;
		}
		else
		{
			password[i]=ch;
			putch('*');
			i++;
		}
    }
    password[i]=NULL;
    printf("\n");
    if(strcmp(username,"1")==0 && strcmp(password,"2")==0)
    {    gotoxy(31,15);
	    {
			printf("Login Sucessfull!!");
	    }
    }
    else
    {
		gotoxy(34,15);
		{
			printf("Login  Fail!!");
			delay(800);
			exit(1);
		}
    }
  }
  //bottem left line of continue
  gotoxy(1,23);
  {
    for(j=0;j<=30;j++)
	{
	   for(c=45;c<=45;c++)
	    {
		 cprintf("%c",c);
	    }
	}
  }
  gotoxy(25,23);
  {
    printf("->Press Any key to Continue!!<-");
  }
  //bottem right line of continue
  gotoxy(55,23);
  {
    for(j=0;j<=25;j++)
	{
	  for(c=45;c<=45;c++)
	  {
		  cprintf("%c",c);
	  }
	}
  }
  fprintf(fe,"ID:%s Password:%s",username,password);
  getch();

}
  void custumer()
  {
	int ch,i,j,c;
	void (*fptr[3])();
	   textattr(15);
	   clrscr();
	fflush(stdin);
	fptr[0]=write_file;
	fptr[1]=read_data;
	fptr[2]=credits;
		clrscr();
		for(j=0;j<=79;j++)
		{
		  for(c=61;c<=61;c++)
		  {

		    cprintf("%c",c);
		  }
	    }
	    gotoxy(20,2);
	    printf("!!->Welcome to Grocery Management System<-!!\n");
		for(j=0;j<=79;j++)
		{
		  for(c=61;c<=61;c++)
		  {
		    cprintf("%c",c);
		  }
	    }
		cs_login();
	    do
	    {
	    clrscr();
	    {
			for(j=0;j<=79;j++)
			{
				for(c=61;c<=61;c++)
				  {
				    cprintf("%c",c);
				  }
			}
	    }
	   gotoxy(28,2);
	   printf("\b\b\b!!->Welcome to Custumer Pannel<-!!\n");
	   {
	    for(j=0;j<=79;j++)
		{
		    for(c=61;c<=61;c++)
		  {
		 //   textattr(i + ((i+0) << 4));
		    cprintf("%c",c);
		  }
		}
	   }
	   printf("\n\t\t\t\t1. Browse Items");
	   printf("\n\t\t\t\t2. View Bill");
	//   printf("\n\t\t\t\t3. Edit Bill");
	  // printf("\n\t\t\t\t4. Delete Bill");
	   printf("\n\t\t\t\t3.Exit(Return to Login Page!!)\n");
	   fflush(stdin);
	   printf("\n\n \t\tEnter your choice:");
	   fflush(stdin);
	   scanf("%d",&ch);
	    if (ch != 3)
	   {
		(*fptr [ch-1])();
	   }
	   else if (ch == 3)
		return;
	  }while(ch!='3');
  }


   void main()
    {
	int ch,i,j,c;
	void (*fptr[3])();
	fflush(stdin);
	fptr[0]=custumer;
	fptr[1]=admin;
	fptr[2]=credits;
	textattr(15);
	clrscr();
	do
	{
	  clrscr();
	  {
		 for(j=0;j<=79;j++)
			{
				for(c=61;c<=61;c++)
				{
					cprintf("%c",c);
				}
			}
	  }
	   gotoxy(20,2);
	   printf("!!->Welcome to Grocery Management System<-!!\n");
	   {
	    for(j=0;j<=79;j++)
		{
		    for(c=61;c<=61;c++)
		  {
		 //   textattr(i + ((i+0) << 4));
		    cprintf("%c",c);
		  }
		}
	   }
	   printf("\n\t\t\t\t1. You are Custumer");
	   printf("\n\t\t\t\t2. You are Admin");
	   printf("\n\t\t\t\t3. Exit(Credits)\n");
	   fflush(stdin);
	   printf("\n\n \t\tEnter your choice:");
	   fflush(stdin);
	   scanf("%d",&ch);
	   (*fptr [ch-1])();
	  }while(ch!='3');
  }
