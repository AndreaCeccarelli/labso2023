#include <stdio.h>
#define square(a) ((a)*(a))
#define square2(a) (a*a)
#define square3(a) a*a
int main(void){
        float j=0;
        j = 2 * square(3+4);
        printf("%f\n", j);
        j = 2 * square2(3+4);
        printf("%f\n", j);
        j = 2 * square3(3+4);
        printf("%f\n", j);
return 0;
}
