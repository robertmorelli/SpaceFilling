#include <stdio.h>
#include <stdlib.h>





unsigned long lut[32]={
0,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219};

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
     mov eax, lut[eax*4]
   }
}


int main() {
   char number[3];
   printf("\n\nenter log of size:");
   scanf("%2s", number); 
   int power=(number[1]==0)?number[0]-'0':(10*(number[0]-'0')+(number[1]-'0'));
   int size=(1<<power)-1;
   for(int y=size;y>=0;y--){
     for(int x=0;x<=size;x++){
        printf("%c", tSquare(x,y,power));
     }
     printf("\n");
   }
   printf("\n\npress [enter] to quit\n");
   getchar();
   getchar();

   return 0;
}










