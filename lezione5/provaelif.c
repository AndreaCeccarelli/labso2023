#define NAZIONE ita
int main(void) {
	#if NAZIONE==ita
			char valuta[] = "EURO";
	#elif NAZIONE==usa
			char valuta[] = "USD";
	#endif
}

