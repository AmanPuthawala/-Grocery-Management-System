FILE *fpCustomer, *fpBill, *ft;

struct structureCustomer
{
	int cid;			// customer id		[PK]
	char cname[30];     // customer name
	int billno;		// billno           [FK]
};

struct structureBill
{
	int billno;		// billno           [PK]
	int itemno;           // item number
	char iname[30];	// item name
	int qty;            // quantity
	int rate;           // rate / price
};

