void clear(int r1,int c1,int r2,int c2)
{
	int r, c;
	for(c=c1;c<=c2;c++)
	{
		for(r=r1;r<=r2;r++)
		{
			gotoxy(c,r);
			cprintf(" ");
			//delay(10);
		}
	}
}
void main()
{
	clear(10,10,20,40);
	getch();
}