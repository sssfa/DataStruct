int shell(int *a,int len)
{
        int increments[20];
        int i,j,h,k;

        for(h=1,i=0;h<len;i++) {
                increments[i] = h;
                h = 3 * h + 1;
        }
        //Build a increments value array
        i-=1;
        //May cause segment error because the index of array
        for(i;i>=0;i--)
        {
                h=increments[i];
                for(k=h;k<2 * h;k++)
                {
                        for(j=k;j<len;j+=h)
                        {
                                int	temp=a[j];
                                int 	g=j;

                                while(temp < a[g-h] && g-h >= 0) {//当前值小于前面排过序的值
                                        a[g] = a[g-h];	
                                           g = g - h;
                                }
                                a[g] = temp;
                        }
                }
        }

        return 0;
}
