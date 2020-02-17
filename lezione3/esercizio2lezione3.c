#include<stdio.h>
main()
{
int v[3]={1,2,3};
 *(v+1)=20;
 printf("\n%d\t%d\t%d",v[0],v[1],v[2]);
}

