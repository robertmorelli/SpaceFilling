#include <stdio.h>
#include <stdlib.h>





unsigned long lut[32]={
0,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219};

unsigned long teeth(unsigned long x,unsigned long y,unsigned short size){
    return (x^y)*size;
}

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

int main() {
   int size = 5;
   for(int y=size;y>=0;y--){
     for(int x=0;x<=size;x++){
        printf("%4d", teeth(x,y,size)*tSquare(x,y,size-2));
     }
     printf("\n");
   }

   return 0;
}










