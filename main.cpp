#include "fcgi_stdio.h"

int main() {
	while (FCGI_Accept() >= 0) {
		printf("test");
	}
	return 0;
}
