#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

unsigned long tSquare(unsigned long x,unsigned long y,unsigned short d){
    return 255 *(1^__builtin_popcount(__builtin_popcount(__builtin_popcount(__builtin_popcount(__builtin_popcount((((x<<1)^((x>>1)<<1))&((y<<1)^((y>>1)<<1)))&~(0b1<<d)))))));
}


unsigned long color(unsigned long x,unsigned long y,unsigned short d){
    return (((x<<1)^((x>>1)<<1))&((y<<1)^((y>>1)<<1)))&~(0b1<<d);
}

extern unsigned long long GeoTableDPRI();

void save_image(int w, int h, int channels_num)
{

     unsigned char data[w * h * channels_num];

     int index = 0;
     for (int j = h - 1; j >= 0; --j)
     {
      for (int i = 0; i < w; ++i)
      {
       //float r = (float)i / (float)w;
       //float g = (float)j / (float)h;
       //float b = 0.2f;
       //int ir = 1*(255.0 * r);
       //int ig = 1*(255.0 * g);
       //int ib = 1*(255.0 * b);
       unsigned long ir = GeoTableDPRI(i,j,9,4,0,0);
       //int ig = 0;
       //int ib = 0;

       data[index++] = ir;
       //data[index++] = (ir&(0b1100))<<4;
       //data[index++] = (ir&(0b110000))<<2;
      }
     }

    stbi_write_png("hilbert.png", w, h, channels_num, data,0);
}


int main(){

save_image( 512 , 512 ,1);



}










