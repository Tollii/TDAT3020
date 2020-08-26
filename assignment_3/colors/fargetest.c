#include <stdlib.h>
#include <stdio.h>
#include "fargeskrift.h"

int main(int argc, char *argv[]) {
	unsigned int fargenr, bakgr, limit;
	
	if (argc != 2 || (limit = atoi(argv[1])) < 1 ) {
		printf("Oppgi en grense\n");
		exit(1);
	}
	bakgr = fargenr ? 0 : 7;
	for (int i = 0; i < limit; i++) {
		if (fargenr > 7) {
			fargenr = 0;
			bakgr = 0;
		}
		fargenr++;
		bakgr++;
		farge_printf(fargenr, bakgr, "\u2588", fargenr);
	}
	return 0;
}
