#include<conio.h>
#include<stdio.h>
#include<time.h>

#include<stdlib.h>

#define f fflush(stdin)


#define Customer "customer.txt"
#define Bill "bill.txt"

#include "global.h"
#include "library.h"
#include "billedit.h"
#include "lastcust.h"
#include "lastbill.h"

void mostDemandableProduct()
{
	struct structureBill bill, sort[100];
	FILE *fp;
	int i,j,k;
	int trate,tbillno,titemno,tqty;
	char tiname[30],names[100][30];
	int count[10], icount, tcount;
	textattr(15);
	clrscr();
	fp = fopen(Bill, "rb");
	fread(&bill,sizeof(bill),1,fp);
	k=0;
	while(!feof(fp))
	{
		sort[k++] = bill;
		fread(&bill,sizeof(bill),1,fp);
	}
	fclose(fp);
	for(i=0;i<=k-1;i++)
	{
		for(j=i+1;j<=k-1;j++)
		{
			if (strcmp(sort[i].iname, sort[j].iname) > 0)
			{
				trate = sort[i].rate;
				sort[i].rate = sort[j].rate;
				sort[j].rate = trate;

				tbillno = sort[i].billno;
				sort[i].billno = sort[j].billno;
				sort[j].billno = tbillno;

				titemno = sort[i].itemno;
				sort[i].itemno = sort[j].itemno;
				sort[j].itemno = titemno;

				tqty = sort[i].qty;
				sort[i].qty = sort[j].qty;
				sort[j].qty = tqty;

				strcpy(tiname, sort[i].iname);
				strcpy(sort[i].iname, sort[j].iname);
				strcpy(sort[j].iname, tiname);
			}
		}
	}
	strcpy(tiname,sort[0].iname);
	icount = 1;
	j=0;
	for(i=1;i<=k;i++)
	{
		if (strcmp(tiname, sort[i].iname) == 0)
		{
			icount++;
		}
		else
		{
			count[j] = icount;
			strcpy(names[j],tiname);
			j++;
			icount=1;
			strcpy(tiname,sort[i].iname);
		}
	}

	for(i=0;i<=j-1;i++)
	{
		for(k=i+1;k<=j-1;k++)
		{
			if (count[i] < count[k])
			{
				tcount = count[i];
				count[i] = count[k];
				count[k] = tcount;

				strcpy(tiname, names[i]);
				strcpy(names[i], names[k]);
				strcpy(names[k], tiname);
			}
		}
	}

	cprintf("\n\r\n\rMost sellable product : %s",names[0]);
	for(i=1;i<=j-1;i++)
	{
		if (count[0] == count[i])
		{
			cprintf("\n\r\n\rMost sellable product : %s",names[i]);
		}
	}
	getch();
}

//file write
void write_file()
{
	struct structureBill bill;
	struct structureCustomer customer;
	char itemName[10][25] = {"Arial Powder","Coffee","Cheese",
						"Groundnut Oil","Sugar","Cookie",
						"Tuvar Dal",
						"Rice","Wheat","Coconut"};
	char wt[10][5] = {"1Kg","1Kg","1Kg","15Kg","1Kg",
				    "1Kg","1Kg","1Kg","1Kg","1Kg"};
	char prices[10][5] = {"80","180","145","2145","210","120","100",
					    "98","75","115"};
	int i, j, q, row, price;
	char count;
	do
	{
		clrscr();
		findLastCustomerNo(&customer.cid);
		findLastBillNo(&bill.billno);
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
		gotoxy(15,4);
		printf("Bill no:%d",bill.billno);
		gotoxy(35,4);
		printf("Customer id : %d",customer.cid);
		gotoxy(55,4);
		printf("Customer Name:");
		f;
		scanf("%s",&customer.cname);

		fpCustomer = fopen(Customer,"ab+");
		customer.billno = bill.billno;

		fwrite(&customer,sizeof(customer),1,fpCustomer);
		fclose(fpCustomer);

		printf("\n");

		// top line of Menu
		fflush(stdin);
		printf("\t\t---------------------------------------------\n\n");
		gotoxy(27,7);
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
		{
			char arr[5];
			itoa(row-9, arr, 10);
			go(22,row,arr,15);
			go(24,row,itemName[row-10],15);
		}

		//kg/gm
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
			go(3,21," Enter the Choice:",15);
			f;
			scanf("%d",&bill.itemno);

			do
			{
				char qty[3];
				go(52,21,"Enter the Quantity[1-99]:",15);
				f;
				validQty(21,77,qty,2);
				bill.qty = atoi(qty);
			}while(!(bill.qty>=1 && bill.qty<=99));

			go(20,9+bill.itemno,"->",15+128);
			gotoxy(58,9+bill.itemno);
			printf("%d",bill.qty);

			go(24,24,"Chose Another Item(Y/N):",15);
			fflush(stdin);
			scanf("%c",&count);
			strcpy(bill.iname,itemName[bill.itemno-1]);
			price = atoi(prices[bill.itemno-1]);
			bill.rate = price;
			fpBill = fopen(Bill,"ab+");
			fwrite(&bill,sizeof(bill),1,fpBill);
			fclose(fpBill);
		}while(count=='y'||count=='y');
		fflush(stdin);
		clear(24,1,24,79);
		go(21,24,"Create Another Bill(Y/N):",15);
		f;
		scanf("%c",&count);
	}while(count=='y'||count=='Y');
	textattr(15);
}

//file read
void read_data()
{
	struct structureBill bill;
	struct structureCustomer customer;
	int check = 0, r = 0, i,j, total, grand_total=0;
	time_t t;
	FILE *tfp;
	textattr(15);
	clrscr();
	fpCustomer = fopen(Customer,"rb+");
	fpBill = fopen(Bill,"rb+");


	fflush(stdin);
	fread(&customer, sizeof(customer), 1, fpCustomer);

	while(!feof(fpCustomer))
	{
		 char fname[30];
		 strcpy(fname, customer.cname);
		 strcat(fname,".txt");
		 tfp=fopen(fname,"wb+");
		 grand_total = 0;
		 rewind(fpBill);
		 fread(&bill,sizeof(bill),1,fpBill);
		 while(!feof(fpBill))
		 {
			if (customer.billno == bill.billno)
			{
				fflush(stdin);
				printf("\n");
				if (check == 0)
				{
					time(&t);
					gotoxy(1,4);
					printf("\nTime : %s\n",ctime(&t));
					fprintf(tfp,"\nTime : %s\n",ctime(&t));

					fprintf(tfp,"\n Bill No:%-10d\t\t\t\t\tCustomer Name: %-30s\n",
					bill.billno,customer.cname);
					//Top line of output (bill)file
					for(i=0;i<=70;i++)
					{
						for(j=61;j<=61;j++)
						{
							fprintf(tfp,"%c",j);
						}
					}
					// Heading of OutputBill
					fprintf(tfp,"\n%-25s%-15s%-25s%-25s\n","Items","Quantity","Price","Total");
					//Bottem line of output (bill)file
					for(i=0,j=61;i<=70;i++)
					{
						fprintf(tfp,"%c",j);
					}
					fprintf(tfp,"\n");
					//loop for top line of stdout
					for(i=1,j=61;i<=79;i++)
					{
						go(i,1,"=",15);
					}
					check = 1;
				}
				gotoxy(28,2);
				printf(" -> View Bill Detail!! <-\n");
				for(i=1,j=61;i<=79;i++)
				{
					go(i,3,"=",15);
				}

				gotoxy(5,9);
				printf("Bill No:%d",bill.billno);

				gotoxy(53,9);
				printf("Customer Name is:%s",customer.cname);

				heading();

				gotoxy(28,14+r);
				printf("%d",bill.qty);

				gotoxy(5,14+r);printf("%s",bill.iname);
				gotoxy(43,14+r);printf("%d",bill.rate);

				total = bill.rate*bill.qty;
				gotoxy(63,14+r);printf("%d",total);

				if (bill.billno > 0)
				{
					fprintf(tfp,"%-25s%-15d%-25d%-25d\n",bill.iname,bill.qty,bill.rate,total);
				}
				else
				{
					fprintf(tfp,"no choice!");
				}
				grand_total=grand_total+total;
				delay(100);

				fread(&bill,sizeof(bill),1,fpBill);

				if (customer.billno != bill.billno)
				{
					printf("\n\n\n\t\t\t\t\t\t\tGrand Total : %d",grand_total);
					fprintf(tfp,"\n\t\t\t\t\t\tGrand Total:%d",grand_total);
					grand_total=0;
					getch();
					check = 0;
					r = 0;
					clrscr();
				}
				else
					r++;
			}
			else
			{
				fread(&bill,sizeof(bill),1,fpBill);
			}
		 }
		 fread(&customer, sizeof(customer), 1, fpCustomer);
	}
	printf("\n\n\t\t\t\t\t\t\tGrand Total : %d",grand_total);
	fprintf(tfp,"\n\t\t\t\t\t\tGrand Total:%d",grand_total);
	printf("\n\n Have a Good Day:)");
	getch();
	fclose(fpBill);
	fclose(tfp);
}
void del()
{
	struct structureBill bill;
	struct structureCustomer customer;
	char another;
	int tbillno;
	int check;
	int c,j;
	textattr(15);
	clrscr();
	gotoxy(1,1);
		for(j=0;j<=79;j++)
		{
			for(c=61;c<=61;c++)
			{
				cprintf("%c",c);
			}
		}
		gotoxy(20,2);
		printf("\t !!->Welcome to Delete Pannel<-!!\n");
		gotoxy(1,3);
		for(j=0;j<=79;j++)
		{
			for(c=61;c<=61;c++)
			{
				cprintf("%c",c);
			}
		}
		another = 'y';
		while(another == 'y' || another == 'Y')
		{
			fpBill=fopen(Bill,"rb+");
			ft=fopen("Temp.dat","wb");
			check = 0;
			printf("\n\nEnter bill Number to delete: ");
			fflush(stdin);
			scanf("%d",&tbillno);
			rewind(fpBill);
			while(fread(&bill,sizeof(bill),1,fpBill)==1)
			{
				if(tbillno != bill.billno)
				{
					fwrite(&bill,sizeof(bill),1,ft);
				}
				else
				{
					check = 1; // found
				}
			}
			if (check == 1)
			{
				printf("\nDeleted succesfully.");
			}
			else
			{
				printf("\n%d not found..!!",tbillno);
			}
			fclose(fpBill);
			fclose(ft);
			fcloseall();

			remove(Bill);

			rename("Temp.dat",Bill);

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
	printf("L.J. INSTITUTE OF COMPUTER APPLICALTION!!!");

	gotoxy(16,13);
	printf("Sem:-III \t Div:-IET\tRollNos.:- 02,18,19.");

	gotoxy(14,17);
	printf("Aman Puthawala");
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
	fe = fopen("cs_login.txt","wb");

	//top line
	gotoxy(25,7);
	printf("|---------------------------|");

	//left line where login print
	gotoxy(25,8);
	printf("|");

	//below left line where login print
	gotoxy(25,9);
	printf("|");

	gotoxy(28,8);
	printf(" !!->Admin Login<-!!\n");

	// right line where login print
	gotoxy(53,8);
	printf("|");

	//  below right line where login print
	gotoxy(53,9);
	printf("|");

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
	printf("|");

	gotoxy(53,11);
	printf("|");

	gotoxy(53,12);
	printf("|");

	gotoxy(53,13);
	printf("|");

	gotoxy(53,14);
	printf("|");

	gotoxy(53,15);
	printf("|");

	//last second bottem line
	gotoxy(25,14);
	printf("|---------------------------|");

	//bottem line
	gotoxy(25,16);
	printf("|---------------------------|");

	gotoxy(33,10);
	printf("Enter ID:");
	scanf("%s",&username);

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
		{
			gotoxy(31,15);
			printf("Login Sucessfull!!");
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
	printf("->Press Any key to Continue!!<-");

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
	void (*fptr[4])();
	textattr(15);
	fflush(stdin);
	fptr[0]=read_data;
	fptr[1]=del;
	fptr[2]=editRecord;
	fptr[3]=mostDemandableProduct;
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
	    printf("\n\t\t\t\t4.Most Demandable Product");
	    printf("\n\t\t\t\t5.Exit(Return to Login Page!!)");
	    f;
	    printf("\n\n \t\tEnter your choice:");
	    f;
	    scanf("%d",&ch);

	    if (ch != 5)
	    {
			(*fptr [ch-1])();
	    }
	}while(ch!=5);
	return;
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


void customer()
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
	    //  clrscr();
		gotoxy(28,2);
		printf("\b\b\b!!->Welcome to Custumer Pannel<-!!\n");
		{
			for(j=0;j<=79;j++)
			{
				for(c=61;c<=61;c++)
				{

					cprintf("%c",c);
				}
			}
		}
		printf("\n\t\t\t\t1. Browse Items");
		printf("\n\t\t\t\t2. View Bill");
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
	fptr[0]=customer;
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
					cprintf("%c",c);
				}
			}
		}
		printf("\n\t\t\t\t1. You are Customer");
		printf("\n\t\t\t\t2. You are Admin");
		printf("\n\t\t\t\t3. Exit(Credits)\n");
		f;
		printf("\n\n \t\tEnter your choice:");
		f;
		scanf("%d",&ch);
		(*fptr [ch-1])();
	}while(ch!='3');
}
