#include <stdio.h>
int main()
{
    FILE* fp;
    fp = fopen("example.txt", "w");
    fputs("This is an apple.", fp);
    fseek(fp, 1 , SEEK_SET); //1 non è la soluzione giusta...
    fputs(" sam", fp);
    fclose(fp);
   return 0;
}

