void editRecord()
{
	int tempBillNo, isFound = 0;
	long int pos;
	char reply;
	FILE *editFp;
	clrscr();
	fpBill = fopen(Bill,"rb");
	if (fpBill == NULL)
	{
		printf("\nData file not found..!!");
		getch();
		return;
	}
	else
	{
		printf("Enter bill number to edit : ");
		f;
		scanf("%d",&tempBillNo);
		fread(&bill,sizeof(bill),1,fpBill);
		printf("\nCurrent position : %ld",ftell(fpBill));delay(1000);
		while(!feof(fpBill))
		{
			if (tempBillNo == bill.billno)
			{
				isFound = 1;
				pos = ftell(fpBill);
				printf("\nOld details are : \n");
				printf("\nBill number : %d",bill.billno);
				printf("\nItem Number : %d",bill.itemno);
				printf("\nItem Name : %s",bill.iname);
				printf("\nRate : %d",bill.rate);
				printf("\nQty : %d",bill.qty);
				printf("\n\nWant to edit the record..[y/n] ? : ");
				f;
				reply = getche();
				if (reply == 'y' || reply == 'Y')
				{
					// read new details
					printf("\n\nPlease enter new details : ");
					printf("\nEnter new Item no : ");
					f;
					scanf("%d",&bill.itemno);
					printf("\nEnter new item name : ");
					f;
					gets(bill.iname);
					printf("\nEnter new rate : ");
					f;
					scanf("%d",&bill.rate);
					printf("\nEnter new quantity : ");
					f;
					scanf("%d",&bill.qty);
					editFp = fopen(Bill,"rb+");
					fseek(editFp,pos-sizeof(bill),0);
					fwrite(&bill,sizeof(bill),1,editFp);
					fclose(editFp);
				}
				printf("\nPress any key..!!!");
				delay(2000);
			}
			fread(&bill,sizeof(bill),1,fpBill);
		}
		if (isFound == 0)
		{
			printf("\nSorry..Bill # %d not found..!!",tempBillNo);
		}
		else
		{
			printf("\n\nEditing done successfully...!!!");
		}
		fclose(fpBill);
	}
	getch();
}