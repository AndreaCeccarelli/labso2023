#define DIM_MAX 1000
int main(void) {
	#if DIM_MAX>100
			printf("Dimensione enorme.");
	#else
			printf("Dimensione normale.");
	#endif
}

