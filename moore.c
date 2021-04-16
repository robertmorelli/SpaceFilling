


extern unsigned long long GeoTableRI();

short mooreTable[32]={
0b00,
0b01,
0b11,
0b10
};


unsigned long long Moore(unsigned long x,unsigned  long y,unsigned short depth) {
      depth--;
      unsigned register short r = ((1&(x>>(depth)))<<1)|1;
      return mooreTable[(r&(0b10|(y>>(depth)&1)))]<<((depth)<<1)|GeoTableRI(x,y,depth,r,0);

}













