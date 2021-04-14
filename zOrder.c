

unsigned long long zOrder(unsigned long x,unsigned  long y,short size) {
    unsigned register long long hash = 0;
    for(register int n=size-1;n>=0;n--){
       hash |= (((1&(~(y>>n)))<<1)|(1&(x>>n)))<<(n<<1);
   }
   return hash;
}



unsigned long inverseZOrderX(unsigned long long hash,short size) {
    unsigned register long x = 0;
    for(register int n=size-1;n>=0;n--){
       x |= (1&(hash >> ((n<<1))))<<n;
   }
   return x;
}



unsigned long inverseZOrderY(unsigned long long hash,short size) {
    unsigned register long y = 0;
    for(register int n=size-1;n>=0;n--){
       y |= (          1&(~(hash >> ((n<<1)+1)))             )                <<n;
   }
   return y;
}













