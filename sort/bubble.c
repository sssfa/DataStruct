int bubble(int *a,int len)
{
	int i,j,t;
	for(i=0;i<len;i++)
	{	 for(j=0;j<len-i-1;j++)
		{     if(a[j]>a[j+1])
			{	t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	return 0;
}
