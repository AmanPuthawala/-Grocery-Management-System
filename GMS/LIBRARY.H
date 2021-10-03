void validQty(int row, int col, char qty[3], int len)
{

	char ch;
	int i = 0, tcol = col;
	f;
	do
	{
		gotoxy(col, row);
		ch = getche();
		if (ch >= '0' && ch <= '9')
		{
			qty[i] = ch;
			i++;
			col++;
		}
		else if (ch == '\r')
			break;
		else if (ch == '\b' && col > tcol)
		{
			col--;
			gotoxy(col,row);
			printf(" ");
		}
	}while(i<len);
	qty[i] = '\0';
}
void clear(int r1,int c1,int r2,int c2)
{
	int r, c;
	for(r=r1;r<=r2;r++)
	{
		for(c=c1;c<=c2;c++)
		{
			gotoxy(c,r);
			cprintf(" ");
		}
	}
}
void go(int  col, int row, char *msg, int color)
{
	textattr(color);
	gotoxy(col, row);
	cprintf("%s",msg);
}
void drawline(int r1, int c1, int  r2, int c2, int color)
{
	int r, c;
	textattr(color);
	for(r=r1;r<=r2;r++)
	{
		for(c=c1;c<=c2;c++)
		{
			go(c, r, "-", 15);
		}
	}
}
// heading for one bill
void heading()
{
	drawline(11,4,11,78,15);
	go(5, 12, "Choice", 12);
	go(25, 12, "Quantity", 12);
	go(42, 12,  "Price",12);
	go(55, 12, "Total Price per Quantity", 12);
	drawline(13,4,13,78,15);
}