void editRecord()
{
	struct structureBill bill;
	struct structureCustomer customer;
	int tempBillNo, isFound = 0,j,c,total;
	long int pos;
	char reply;
	FILE *editFp;
	textattr(15);
	clrscr();

	fpBill = fopen(Bill,"rb");
	fpCustomer = fopen(Customer,"rb");
	if (fpBill == NULL)
	{
		printf("\nData file not found..!!");
		getch();
		return;
	}
	else
	{    gotoxy(1,1);
		for(j=0;j<=79;j++)
		{
			for(c=61;c<=61;c++)
			{
				cprintf("%c",c);
			}
		}
		gotoxy(20,2);
		printf("\t !!->Welcome to Edit Pannel<-!!\n");
		gotoxy(1,3);
		for(j=0;j<=79;j++)
		{
			for(c=61;c<=61;c++)
			{
				cprintf("%c",c);
			}
		}
		printf("Enter bill number to edit : ");
		f;
		scanf("%d",&tempBillNo);
		fread(&bill,sizeof(bill),1,fpBill);
		while(!feof(fpBill))
		{
			while(fread(&customer, sizeof(customer), 1, fpCustomer)==1)
			{
				if (customer.billno == bill.billno)
				{
					break;
				}
			}
			if (tempBillNo == bill.billno)
			{
				isFound = 1;
				pos = ftell(fpBill);
				gotoxy(1,1);
				for(j=0;j<=79;j++)
				{
					for(c=61;c<=61;c++)
					{
						cprintf("%c",c);
					}
				}
				gotoxy(20,2);
				printf("\t !!->Welcome to Edit Pannel<-!!\n");
				gotoxy(1,3);
				for(j=0;j<=79;j++)
				{
					for(c=61;c<=61;c++)
					{
						cprintf("%c",c);
					}
				}
				heading();

				gotoxy(6,9);
				printf("Bill number : %d",bill.billno);
				//PRINTF OLD DETAIL
				gotoxy(52,9);printf("Customer name : %s",customer.cname);
				gotoxy(5,14);printf("%s",bill.iname);
				gotoxy(43,14);printf("%d",bill.rate);
				gotoxy(28,14);printf("%d",bill.qty);

				//CALCULATE THE TOTAL PRICE
				total = bill.rate*bill.qty;
				gotoxy(65,14);printf("%d",total);

				go(24,24,"Want to edit the record..[y/n] ? : ",15);
				f;
				reply = getche();
				if (reply == 'y' || reply == 'Y')
				{

					clear(24,1,24,55);

					go(24,24,"Want to edit the Item Name[y/n] ? : ",15);
					f;
					reply = getche();
					if (reply == 'y' || reply == 'Y')
					{
						f;
						clear(14,1,14,18);
						gotoxy(5,14);
						gets(bill.iname);

					}
					clear(24,1,24,55);

					go(24,24,"Want to edit the Item Quantity..[y/n] ? : ",15);
					f;
					reply = getche();
					if (reply == 'y' || reply == 'Y')
					{
						f;
						clear(14,20,14,30);
						gotoxy(28,14);
						scanf("%d",&bill.qty);
					}
					clear(24,1,24,66);

					go(24,24,"Want to edit the Item Price..[y/n] ? : ",15);
					f;
					reply = getche();
					if (reply == 'y' || reply == 'Y')
					{
						f;
						clear(14,30,14,55);
						gotoxy(43,14);
						scanf("%d",&bill.rate);
					}

					total = bill.rate*bill.qty;
					gotoxy(65,14);printf("%d",total);

					editFp = fopen(Bill,"rb+");
					fseek(editFp,pos-sizeof(bill),0);
					fwrite(&bill,sizeof(bill),1,editFp);
					fclose(editFp);
				}
				gotoxy(5,16);
				printf("\nPress any key..!!!");
				delay(1000);
				clrscr();
			}
			fread(&bill,sizeof(bill),1,fpBill);
		}
		if (isFound == 0)
		{
			printf("\nSorry..Bill %d not found..!!",tempBillNo);
		}
		else
		{
			printf("\n\nEditing done successfully...!!!");
		}
		fclose(fpBill);
	}
	fcloseall();
	getch();
}