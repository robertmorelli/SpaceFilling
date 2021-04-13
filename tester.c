#include <stdio.h>



extern unsigned long long GeoTableDPRI();

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


   return 0;
}










