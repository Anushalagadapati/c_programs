#include<stdio.h>


int func(int n,long int p[],long int d[])
{
    int finals,i;
    long int petrol;
    for(finals=0;finals<n;finals++)
    {
        i=finals;petrol=0;
        while(petrol>=0)
        {
            petrol=petrol+p[i]-d[i];i=(i+1)%n;
            if(i==finals)return finals;
        }
        
       
    }
    return -1;
}

int main()
{
    int n,i,ans;
    scanf("%d",&n);
    long int p[n],d[n];
    for(i=0;i<n;i++)
    {
        scanf("%ld%ld",&p[i],&d[i]);
    }
    ans=func(n,p,d);
    printf("%d",ans);
return 0;
}

