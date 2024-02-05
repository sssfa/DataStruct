int qsort(int *a,int l,int r)
{
	int i=l;int j=r-1;int p=a[(l+r)/2];
	while(i<=j){
		while(a[i]<p) i++;
		while(a[j]>p) j--;
		if(i>j) break;
		int t=a[j];a[j]=a[i];a[i]=t;
		i=i+1;
		j=j-1;
	}
	if(i<r) qsort(a,i,r);
	if(j>l) qsort(a,l,j);
	return 0;
}
