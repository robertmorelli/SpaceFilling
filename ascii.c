#include <stdio.h>
#include <stdlib.h>



char chars[16]={
			197,
			181,
			210,
			187,
			198,
			205,
			201,
			203,
			208,
			188,
			186,
			185,
			200,
			202,
			204,
			206
	};



int main() {
   for(int y=0;y<256;y++){
     printf("          %c     %d       \n", y,y);
   }

   printf("list\n\n\n");
   for(int y=0;y<16;y++){
     printf("'%c',", chars[y]);
   }
   return 0;
}










