#include <stdio.h>

int	ft_printf(const char *fm, ...);

int main(void) {
	ft_printf("%d\n", 6);
	ft_printf("%f\n", 340);
	printf("%f\n", 1245.493758*2);
	printf("%7.f\n", 1.f/3*4);
	printf("%f\n", 0.0001*10000);
	printf("%7f\n", 1.f/3*4);
}
