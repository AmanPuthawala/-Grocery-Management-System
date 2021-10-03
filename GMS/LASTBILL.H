// Find Last Bill No
void	findLastBillNo(int *b)
{
	struct structureBill bill;
	fpBill=fopen(Bill,"rb+");
	if (fpBill == NULL)
	{
		*b = 101;
	}
	else
	{
		fread(&bill,sizeof(bill),1,fpBill);
		while(!feof(fpBill))
		{
			fread(&bill,sizeof(bill),1,fpBill);
		}
		*b = bill.billno;
		(*b)++;
		fclose(fpBill);
	}
}