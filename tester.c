#include <stdio.h>



extern unsigned long long GeoTableDPRI();
extern unsigned long long zOrder();
extern unsigned long inverseZOrderX();
extern unsigned long inverseZOrderY();

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


   return 0;
}










