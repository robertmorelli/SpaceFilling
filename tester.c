#include <stdio.h>



extern unsigned long long GeoTableDPRI();
extern unsigned long long zOrder();
extern unsigned long inverseZOrderX();
extern unsigned long inverseZOrderY();
extern unsigned long long Moore();
unsigned long tSquare(unsigned long x,unsigned long y,unsigned short d){
   __asm 
   {
     mov eax, x
     mov ebx,eax 
     mov edx, y
     mov edi,edx 
     mov cx, d
     mov esi, 1
     



     shl esi, cl
     shl eax, 1
     shl edx, 1
     not esi
     xor esi, 1
     xor eax, ebx
     and eax, esi
     xor edx, edi
     and eax, edx

     popcnt eax,eax
     popcnt eax,eax
     popcnt eax,eax
   }
}
//return 0;//219 *__builtin_popcount(__builtin_popcount(__builtin_popcount(
//__builtin_popcount(__builtin_popcount(
//(((x<<1)^((x>>1)<<1))&((y<<1)^((y>>1)<<1)))&~(0b1<<d))))));



int main() {
   printf("resolution 1\n\n");
   for(int y=15;y>=0;y--){
     for(int x=0;x<=15;x++){
        printf(" %4llu", GeoTableDPRI(x,y,4,1,0,0));
     }
     printf("\n");
   }
   printf("\n\n\nresolution 2\n\n");
   for(int y=15;y>=0;y--){
     for(int x=0;x<=15;x++){
        printf(" %4llu", GeoTableDPRI(x,y,4,2,0,0));
     }
     printf("\n");
   }

   printf("\n\n\nresolution 3\n\n");
   for(int y=15;y>=0;y--){
     for(int x=0;x<=15;x++){
        printf(" %4llu", GeoTableDPRI(x,y,4,3,0,0));
     }
     printf("\n");
   }
   printf("\n\n\nresolution 4\n\n");
   for(int y=15;y>=0;y--){
     for(int x=0;x<=15;x++){
        printf(" %4llu", GeoTableDPRI(x,y,4,4,0,0));
     }
     printf("\n");
   }

   printf("\n\n\nrotation 3 invertion 1\n\n");
   for(int y=15;y>=0;y--){
     for(int x=0;x<=15;x++){
        printf(" %4llu", GeoTableDPRI(x,y,4,4,3,1));
     }
     printf("\n");
   }

   printf("\n\n\nmoore 1\n\n");
   for(int y=15;y>=0;y--){
     for(int x=0;x<=15;x++){
        printf(" %4llu", Moore(x,y,4));
     }
     printf("\n");
   }

   printf("\n\n\nzorder\n\n");
   for(int y=31;y>=0;y--){
     for(int x=0;x<=31;x++){
        printf(" %4llu", zOrder(x,y,5));
     }
     printf("\n");
   }

   printf("\n\n\nzorder then inverted\n\n");
   for(int y=31;y>=0;y--){
     for(int x=0;x<=31;x++){
        printf(" %2lu,%2lu", inverseZOrderX(zOrder(x,y,5)),inverseZOrderY(zOrder(x,y,5)));
     }
     printf("\n");
   }




   printf("t square \n\n");
   for(int y=127;y>=0;y--){
     for(int x=0;x<=127;x++){
        //printf(" %4llu", (((x<<1)^((x>>1)<<1))&((y<<1)^((y>>1)<<1)))&~(0b1<<5)     );
          printf("%c", tSquare(x,y,7)     );
     }
     printf("\n");
   }
   printf("t square \n\n");
   for(int y=63;y>=0;y--){
     for(int x=0;x<=63;x++){
        //printf(" %4llu", (((x<<1)^((x>>1)<<1))&((y<<1)^((y>>1)<<1)))&~(0b1<<5)     );
          printf("%c", tSquare(x,y,6)     );
     }
     printf("\n");
   }
   printf("t square \n\n");
   for(int y=31;y>=0;y--){
     for(int x=0;x<=31;x++){
        //printf(" %4llu", (((x<<1)^((x>>1)<<1))&((y<<1)^((y>>1)<<1)))&~(0b1<<5)     );
          printf("%c", tSquare(x,y,5)     );
     }
     printf("\n");
   }
   printf("t square \n\n");
   for(int y=15;y>=0;y--){
     for(int x=0;x<=15;x++){
        //printf(" %4llu", (((x<<1)^((x>>1)<<1))&((y<<1)^((y>>1)<<1)))&~(0b1<<5)     );
          printf("%c", tSquare(x,y,4)     );
     }
     printf("\n");
   }
   printf("t square \n\n");
   for(int y=7;y>=0;y--){
     for(int x=0;x<=7;x++){
        //printf(" %4llu", (((x<<1)^((x>>1)<<1))&((y<<1)^((y>>1)<<1)))&~(0b1<<5)     );
          printf("%c", tSquare(x,y,3)     );
     }
     printf("\n");
   }
   printf("t square \n\n");
   for(int y=3;y>=0;y--){
     for(int x=0;x<=3;x++){
        //printf(" %4llu", (((x<<1)^((x>>1)<<1))&((y<<1)^((y>>1)<<1)))&~(0b1<<5)     );
          printf("%c", tSquare(x,y,2)     );
     }
     printf("\n");
   }




   
   return 0;
}










