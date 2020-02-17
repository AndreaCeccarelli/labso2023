#include<stdio.h>
struct Esempio {
  int a;
  float b;
  char c;
  char *d;
};

int main() {
  struct Esempio x;
  struct Esempio *p;
  p=&x;	
  (*p).a=12;
  printf("Valore di x.a: %d\n", x.a); 
  x.c='z';
  printf("Valore di x.c: %c\n", (*p).c);
  printf("Valore di x.c: %c\n", p->c);
  x.a=100;
  printf("valore di x.a: %d\n", x.a); 
  p->a=300;
  printf("valore di x.a: %d\n", p->a); 
  p->c='s';
  printf("Valore di x.c: %c\n", p->c);
  p->d=&(p->c);
  printf("Valore di x.c: %c\n", *(p->d));

  return 0;
}

