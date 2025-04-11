/* Right shit :
   num >> x ------->num/2^x
   Left shit :
   num << x ------->num*2^x
   1<<x -----------> Will set the bit at ith position
   Set the bit:
   num | (1<<i)
   Clear the bit:
   num &  ~(1<<i)
   Toggle the bit:
   num ^ (1<<i)
   Set the right most bit:
   num | (num-1)
   Clear the right most bit:
   num & (num-1)
   No of set bits in cpp:
   _builtin_popcount(num)
   To check whether is no is odd or even:
   num & 1 == 1   --->odd
   To check whether is power of 2:
   num & (num-1) ==0
   To check the only element present in an array
   res = res ^ num[i];3e4
   */