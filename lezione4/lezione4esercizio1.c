int main(){
  struct Esempio x;
  struct Esempio *p;
  p = &x;
  (*p).a = 12;
  printf("Valore di x.a: ?\n",???);
  x.c = 'z';
  printf("Valore di x.c: ?\n",???);

  inserire in a il valore 100, usando la struttura x, e stampare il valore di a
  inserire in a il valore 300, usando il puntatore p, e stampare il valore di a
  inserire in c il carattere s, usando il puntatore p, e stampare il valore di c
  puntare il puntatore a carattere d all'indirizzo del carattere c e stampare a video il contenuto della cella puntata da d (ovvero, visualizzare "s")
  return 0;
}
