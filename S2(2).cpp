#include<stdio.h>
#include<math.h>
int main()
{
    int n,rev=0,c=0,sum=0;
    printf("enter the n value:");
    scanf("%d",&n);
    int z=n;
    while(n!=0)
    {
    	rev=(rev*10)+n%10;
    	n=n/10;
    	c++;
	}
	while(rev!=0)
	{
		sum=sum+pow(rev%10,c);
		rev=rev/10;
	}
	printf("%d\n",sum);
	if(sum==z)
	{
		printf("it is a armstrong number");
	}
	else
	{
		printf("it is not a armstrong number");
	}

}
