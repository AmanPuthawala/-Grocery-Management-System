// Find Last Customer No
void	findLastCustomerNo(int *cid)
{
	struct structureCustomer customer;
	fpCustomer=fopen(Customer,"rb+");
	if(fpCustomer == NULL)
	{
		*cid = 1;
	}
	else
	{
		fread(&customer,sizeof(customer),1,fpCustomer);
		while(!feof(fpCustomer))
		{
			fread(&customer,sizeof(customer),1,fpCustomer);
		}
		*cid = ++customer.cid;
		fclose(fpCustomer);
	}

}