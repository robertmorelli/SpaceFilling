short hilbertTable[32]={
0b00101,
0b01000,
0b11111,
0b10000,
0b01001,
0b10001,
0b00100,
0b11110,
0b10010,
0b11101,
0b01010,
0b00111,
0b11100,
0b00110,
0b10011,
0b01011,
0b11011,
0b10100,
0b00001,
0b01100,
0b00000,
0b11010,
0b01101,
0b10101,
0b01110,
0b00011,
0b10110,
0b11001,
0b10111,
0b01111,
0b11000,
0b00010
};


unsigned long long GeoTable(unsigned long x,unsigned  long y,short depth) {
   unsigned register long long hash = 0;
   unsigned register short r = 0;
   unsigned register short i = 0;
   unsigned register short t = 0;
   for(register int n=depth-1;n>=0;n--){
       t=hilbertTable[(i<<4)|(r<<2)|((1&(x>>n))<<1)|(1&(y>>n))];
       hash |= (3&(t>>3))<<(n<<1);
       i = 1&(t>>2);
       r = 3&t;
   }
   return hash;
}



unsigned long long GeoTableRI(unsigned long x,unsigned  long y,short depth,unsigned short r,unsigned short i) {
   unsigned register long long hash = 0;
   unsigned register short t = 0;
   for(register int n=depth-1;n>=0;n--){
       t=hilbertTable[(i<<4)|(r<<2)|((1&(x>>n))<<1)|(1&(y>>n))];
       hash |= (3&(t>>3))<<(n<<1);
       i = 1&(t>>2);
       r = 3&t;
   }
   return hash;
}

unsigned long long GeoTableFL(unsigned long x,unsigned  long y,short depth,short floor) {
   unsigned register long long hash = 0;
   unsigned register short r = 0;
   unsigned register short i = 0;
   unsigned register short t = 0;
   for(register int n=depth-1;n>=floor;n--){
       t=hilbertTable[(i<<4)|(r<<2)|((1&(x>>n))<<1)|(1&(y>>n))];
       hash |= (3&(t>>3))<<(n<<1);
       i = 1&(t>>2);
       r = 3&t;
   }
   return hash;
}


unsigned long long GeoTableDP(unsigned long x,unsigned  long y,short height,short depth) {
   unsigned register long long hash = 0;
   unsigned register short r = 0;
   unsigned register short i = 0;
   unsigned register short t = 0;
   for(register int n=height-1;n>=height-depth;n--){
       t=hilbertTable[(i<<4)|(r<<2)|((1&(x>>n))<<1)|(1&(y>>n))];
       hash |= (3&(t>>3))<<(n<<1);
       i = 1&(t>>2);
       r = 3&t;
   }
   return hash;
}




unsigned long long GeoTableDPRI(unsigned long x,unsigned  long y,short height,short depth,unsigned short r,unsigned short i) {
   unsigned register long long hash = 0;
   unsigned register short t = 0;
   for(register int n=height-1;n>=height-depth;n--){
       t=hilbertTable[(i<<4)|(r<<2)|((1&(x>>n))<<1)|(1&(y>>n))];
       hash |= (3&(t>>3))<<((n-(height-depth))<<1);
       i = 1&(t>>2);
       r = 3&t;
   }
   return hash;
}














