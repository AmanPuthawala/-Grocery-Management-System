#include<conio.h>
#include<stdio.h>
#include<time.h>
#define f fflush(stdin)
#define bills "file.txt"
#include "library.h"


FILE *fp,*ft;

struct shop
{
	char name[30];
	int total;
	int item;
	int x_0;
	int qty;
	int rate[11];
}bill;
//file write
void write_file()
{
	FILE *tfp;
	int i,j,q;
	char count;
	fp=fopen(bills,"a");
	tfp=fopen("bill.txt","w");
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
	  //printf("\n");
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
		bill.x_0++;
		printf("\t\tEnter Bill no:");
		printf("%d",bill.x_0);
		gotoxy(50,4);
		{
		printf("Enter Name:");
		scanf("%s",&bill.name);
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
		gotoxy(22,10);
	    {
		printf("1. Arial Powder ");
	    }
		gotoxy(22,11);
	    {
		printf("2. Coffee ");
	    }
	    gotoxy(22,12);
	    {
		printf("3. Chees ");
	    }
	    gotoxy(22,13);
	    {
		printf("4. GroundNut Oil ");
	    }
	    gotoxy(22,14);
	    {
		printf("5. Sugar");
	    }
		gotoxy(22,15);
	    {
		printf("6. Cookis ");
	    }
		gotoxy(22,16);
	    {
		printf("7. Tuvar Dal ");
	    } gotoxy(22,17);
	    {
		printf("8. Rice ");
	    } gotoxy(22,18);
	    {
		printf("9. Wheet ");
	    } gotoxy(22,19);
	    {
		printf("10. Coconut ");
	    }
		 //kg/gm
		 gotoxy(43,10);
		 {
			printf("1Kg");
		 }
		 gotoxy(43,11);
		 {
			printf("1kg");
		 }
		 gotoxy(43,12);
		 {
			printf("1Kg");
		 }
		 gotoxy(43,13);
		 {
			printf("15Kg");
		 }
		 gotoxy(43,14);
		 {
			printf("1Kg");
		 }
		 gotoxy(43,15);
		 {
			printf("1Kg");
		 }
		 gotoxy(43,16);
		 {
			printf("1Kg");
		 }
		 gotoxy(43,17);
		 {
			printf("1Kg");
		 }
		 gotoxy(43,18);
		 {
			printf("1Kg");
		 }
		 gotoxy(43,19);
		 {
			printf("1Kg");
		 }
	    //prices
		gotoxy(51,10);
		{
		 printf("80");
		}
		gotoxy(51,11);
		{
		 printf("180");
		}
		gotoxy(51,12);
		{
		 printf("145");
		}
		gotoxy(51,13);
		{
		 printf("2145");
		}
			gotoxy(51,14);
		{
		 printf("210");
		}
		gotoxy(51,15);
		{
		 printf("120");
		}
		gotoxy(51,16);
		{
		 printf("100");
		}
		gotoxy(51,17);
		{
		 printf("98");
		}
		gotoxy(51,18);
		{
		 printf("75");
		}
		gotoxy(51,19);
		{
		 printf("115");
		}
		//bottom line
	    gotoxy(18,20);
	    {
		printf("--------------------------------------------");
	    }
	  do
	  {
		fflush(stdin);
		gotoxy(3,22);
		{
			printf("Enter your Choice:");
			scanf("%d",&bill.item);
		}
		gotoxy(58,22);
		{
			printf("Enter your Quantity:");
			scanf("%d",&bill.qty);
		}
		fflush(stdin);
		switch(bill.item)
		{
		   case 1:
		   if(bill.item==1)
		   {
			 gotoxy(20,10);
			 {
			  printf("->");
			 }
			 gotoxy(59,10);
			 {
			    printf("%d",bill.qty);
			 }
		   }
		   case 2:
		   if(bill.item==2)
		   {
			 gotoxy(20,11);
			 {
			  printf("->");
			 }
			 gotoxy(59,11);
			 {
			    printf("%d",bill.qty);
			 }
		   }
		  case 3:
		   if(bill.item==3)
		   {
			 gotoxy(20,12);
			 {
			  printf("->");
			 }
			 gotoxy(59,12);
			 {
			    printf("%d",bill.qty);
			 }
		   } case 4:
		   if(bill.item==4)
		   {
			 gotoxy(20,13);
			 {
			  printf("->");
			 }
			 gotoxy(59,13);
			 {
			    printf("%d",bill.qty);
			 }
		   } case 5:
		   if(bill.item==5)
		   {
			 gotoxy(20,14);
			 {
			  printf("->");
			 }
			 gotoxy(59,14);
			 {
			    printf("%d",bill.qty);
			 }
		   } case 6:
		   if(bill.item==6)
		   {
			 gotoxy(20,15);
			 {
			  printf("->");
			 }
			 gotoxy(59,15);
			 {
			    printf("%d",bill.qty);
			 }
		   } case 7:
		   if(bill.item==7)
		   {
			 gotoxy(20,16);
			 {
			  printf("->");
			 }
			 gotoxy(59,16);
			 {
			    printf("%d",bill.qty);
			 }
		   } case 8:
		   if(bill.item==8)
		   {
			 gotoxy(20,17);
			 {
			  printf("->");
			 }
			 gotoxy(59,17);
			 {
			    printf("%d",bill.qty);
			 }
		   }
		   case 9:
		   if(bill.item==9)
		   {
			 gotoxy(20,18);
			 {
			  printf("->");
			 }
			 gotoxy(59,18);
			 {
			    printf("%d",bill.qty);
			 }
		   }
		   case 10:
		   if(bill.item==10)
		   {
			 gotoxy(20,19);
			 {
			  printf("->");
			 }
			 gotoxy(59,19);
			 {
			    printf("%d",bill.qty);
			 }
		   }
		}

	    gotoxy(25,24);
		{
			printf("Chose Another Item(Y/N):");
			scanf("%c",&count);

		}
		fwrite(&bill,sizeof(bill),1,fp);
		fprintf(tfp,"\nCustomer Name: %s\nQuantity : %d",bill.name,bill.qty);
	  }while(count=='y'||count=='y');
		fflush(stdin);

		gotoxy(25,24);
		{
			printf("Create Another Bill(Y/N):");
			scanf("%c",&count);
		}
	 }
	 while(count=='y'||count=='Y');
	  fclose(fp);
	  fclose(tfp);
}

//file read
void read_data()
{
	int tbillno, check = 0;
	int r = 0;
   int i,j;
   time_t t;
   FILE *fp;
   clrscr();
   fp=fopen(bills,"r+");
   fread(&bill,sizeof(bill),1,fp);
   tbillno = bill.x_0;
   fflush(stdin);
   while(!feof(fp))
	{
		fflush(stdin);
	  printf("\n");
	 if (check == 0)
	 {
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


	gotoxy(29,6);
	{
		printf("Bill No:%d",bill.x_0);
	}
	gotoxy(29,8);
	{
			printf("Customer Name is:%s",bill.name);
	}
	heading();
	// 5, 40, 60 ,, row = 12
	gotoxy(40,14+r);
	{
	  printf("%5d",bill.qty);
	}
	// checking the choice
	switch(bill.item)
		{
		   case 1:
		   if(bill.item==1)
		   {
			gotoxy(5,14+r);
			{
			  printf("%d.Arial Powder",bill.item);
			}
			  gotoxy(60,14+r);
			  {
			  bill.rate[bill.item]=80*bill.qty;
			  printf("80 * %d = %d",bill.qty,bill.rate[bill.item]);
			  }
		   }
		   case 2:
		   if(bill.item==2)
		   {
			  gotoxy(5,14+r);
			  {
			   printf("%d.Coffee",bill.item);
			  }
			  gotoxy(60,14+r);
			  {
			  bill.rate[bill.item]=180*bill.qty;
			  printf("180 * %d = %d",bill.qty,bill.rate[bill.item]);
			  }
		   }
		   case 3:
		   if(bill.item==3)
		   {
			  gotoxy(5,14+r);
			  {
			   printf("%d.Chees",bill.item);
			  }
			  gotoxy(60,14+r);
			  {
			  bill.rate[bill.item]=145*bill.qty;
			  printf("145 * %d = %d",bill.qty,bill.rate[bill.item]);
			  }
		   }
		   case 4:
		   if(bill.item==4)
		   {
			  gotoxy(5,14+r);
			  {
			   printf("%d.GroundNut Oil",bill.item);
			  }
			  gotoxy(60,14+r);
			  {
			  bill.rate[bill.item]=2145*bill.qty;
			  printf("2145 * %d = %d",bill.qty,bill.rate[bill.item]);
			  }
		   }
		   case 5:
		   if(bill.item==5)
		   {
			  gotoxy(5,14+r);
			  {
			   printf("%d.Sugar",bill.item);
			  }
			  gotoxy(60,14+r);
			  {
			  bill.rate[bill.item]=210*bill.qty;
			  printf("210 * %d = %d",bill.qty,bill.rate[bill.item]);
			  }
		   }
		   case 6:
		   if(bill.item==6)
		   {
			  gotoxy(5,14+r);
			  {
			   printf("%d.Cookis",bill.item);
			  }
			  gotoxy(60,14+r);
			  {
			  bill.rate[bill.item]=120*bill.qty;
			  printf("120 * %d = %d",bill.qty,bill.rate[bill.item]);
			  }
		   }
		   case 7:
		   if(bill.item==7)
		   {
			  gotoxy(5,14+r);
			  {
			   printf("%d.Tuvar Dal",bill.item);
			  }
			  gotoxy(60,14+r);
			  {
			  bill.rate[bill.item]=100*bill.qty;
			  printf("100 * %d = %d",bill.qty,bill.rate[bill.item]);
			  }
		   }
		   case 8:
		   if(bill.item==8)
		   {
			  gotoxy(5,14+r);
			  {
			   printf("%d.Rice",bill.item);
			  }
			  gotoxy(60,14+r);
			  {
			  bill.rate[bill.item]=98*bill.qty;
			  printf("98 * %d = %d",bill.qty,bill.rate[bill.item]);
			  }
		   }
		   case 9:
		   if(bill.item==9)
		   {
			  gotoxy(5,14+r);
			  {
			   printf("%d.Wheet",bill.item);
			  }
			  gotoxy(60,14+r);
			  {
			  bill.rate[bill.item]=75*bill.qty;
			  printf("75 * %d = %d",bill.qty,bill.rate[bill.item]);
			  }
		   }
		   case 10:
		   if(bill.item==10)
		   {
			  gotoxy(5,14+r);
			  {
			   printf("%d.Coconut",bill.item);
			  }
			  gotoxy(60,14+r);
			  {
			  bill.rate[bill.item]=115*bill.qty;
			  printf("115 * %d = %d",bill.qty,bill.rate[bill.item]);
			  }
		   }
		    fread(&bill,sizeof(bill),1,fp);
		    if (tbillno != bill.x_0)
		    {
			  check = 0;
			  r = 0;
			  getch();
			  clrscr();
			  tbillno = bill.x_0;
		    }
		    else
			  r++;
		}
	  getch();
   }
    printf("\n\n Have a Good Day:)");
    getch();
    fclose(fp);
}
  void del()
  {
	   char another;
	   char s_name[30];
	   int check;
		fp=fopen(bills,"rb+");
		ft=fopen("Temp.dat","wb+");
		another = 'y';
		check = 0;
		while(another == 'y' || another == 'Y')
		{   printf("\n\nEnter Name of Student to delete: ");
		    fflush(stdin);
		    scanf("%s",&s_name);

		    rewind(fp);
		    while(fread(&bill,sizeof(bill),1,fp)==1)
		    {
			   if(strcmp(s_name,bill.name)!=0)
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
  void admin()
  {
  /*
	   printf("\n\t\t\t\t1.View Bill");
	   printf("\n\t\t\t\t2.Delete Bill");
	   printf("\n\t\t\t\t3.Exit(Credits)");

  */
	int ch,i,j,c,ID=1,P=2,id,p;
	void (*fptr[3])();
	fflush(stdin);
 //	fptr[0]=write_file;
	fptr[0]=read_data;
	fptr[1]=del;
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

	    gotoxy(30,8);
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
	    } gotoxy(53,14);
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
			scanf("%d",&id);
	    }
	    gotoxy(33,12);
	    {
			printf("Enter Password:");
			scanf("%d",&p);
	    }
	    if(id==ID && p==P)
	    {    gotoxy(31,15);
			{
				printf("Login Sucessfull!!");
			}
	    }
	    else
	    {
			gotoxy(34,15);
			{
				printf("Login Fail!!");
				delay(800);
				exit(1);
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
	    getch();
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
	   printf("\n\t\t\t\t3.Exit(Credits)");
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

  void custumer()
  {
	int ch,i,j,c,id,p,ID=1,P=2;
	void (*fptr[3])();
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
			 printf(" !!->Custumer Login<-!!\n");
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
	    } gotoxy(53,14);
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
			scanf("%d",&id);
	    }
	    gotoxy(33,12);
	    {
			printf("Enter Password:");
			scanf("%d",&p);
	    }
	    if(id==ID && p==P)
	    {    gotoxy(31,15);
			{
				printf("Login Sucessfull!!");
			}
	    }
	    else
	    {
			gotoxy(34,15);
			{
				printf("Login Fail!!");
				delay(800);
				exit(1);
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
	    getch();
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
	   printf("\n\t\t\t\t3. Exit(Credits)\n");
	   fflush(stdin);
	   printf("\n\n \t\tEnter your choice:");
	   fflush(stdin);
	   scanf("%d",&ch);
	   (*fptr [ch-1])();
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
	//   printf("\n\t\t\t\t3. Edit Bill");
	  // printf("\n\t\t\t\t4. Delete Bill");
	   printf("\n\t\t\t\t3. Exit(Credits)\n");
	   fflush(stdin);
	   printf("\n\n \t\tEnter your choice:");
	   fflush(stdin);
	   scanf("%d",&ch);
	   (*fptr [ch-1])();
	  }while(ch!='3');
  }





