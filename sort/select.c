int select(int *a,int len)
{
	int max,t;
	for(int i=0;i<len;i++)
	{
		max=0;	
		for(int j=0;j<len-i;j++)
		{
			if(a[j]>a[max])	max=j;
		}
		t=a[len-i-1];
		a[len-i-1]=a[max];
		a[max]=t;
	}
	return 0;
}
