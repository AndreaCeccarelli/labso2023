#include <stdio.h>
void scambia(int *,int *);
main( )
{
 int x, y;
 printf ("\n Dammi due interi decimali");
 scanf("%d %d",&x,&y);
 printf("%d%d",x,y);
 scambia(&x,&y);
 printf("%d%d",x,y);
}

 void scambia(int *a, int *b)
{
 int z;
 z=*a;
 *a=*b;
 *b=z;
 printf("%d%d",*a,*b);
}

