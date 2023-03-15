#include <stdio.h>
int main() {
    FILE* fp;
    fp = fopen("example.txt", "w");
    fputs("This is an apple.", fp);
    fseek(fp, ?, SEEK_SET);//trovare il valore corretto
    fputs(" sam", fp);
    fclose(fp);
   return 0;
}
