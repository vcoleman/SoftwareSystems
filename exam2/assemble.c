
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint16_t assemble(uint8_t most, uint8_t least){
	uint16_t *ans = (uint16_t *)malloc(sizeof(uint16_t));
	uint16_t together = 0;
	together = 0 | least;
	together = together | most<<8;
	*ans = together;
	return *ans;
}

main(){
	uint16_t ans = assemble(1,2);
	printf("%d", ans);
}