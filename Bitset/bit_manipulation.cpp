// To get which bit is present at ith position
int getbit(int n,int i)
{
  return ((n>>i) & 1);
} 

// To make bit set(i.e. '1') make ith bit as '1'
int setbit(int n,int i)
{
  return ((n<<i) | 1);
}

// To clear bit (i.e. '0') make ith bit as '0'
int clearbit(int n,int i)
{ 
  int mask = ~(1<<i);
  return (mask & n);
}

// To toggle the bit i.e. to invert the one already present
int togglebit(int n,int i)
{
  retunr (n ^ (1<<i));
}

// To update bit at a position to K i.e. either '0' or '1'
int update bit(int n,int i,int k)
{
  int mask = ~(1<<i);
  n = n & mask;
  return (n | (k<<i));
}

// To remove the last SET Bit i.e '1'
int remove_setbit(int n)
{
  return (n&(n-1));
}

// To convert a binary string into it's decimal form
stoll(s,0,2);

// To convert a number into a string of it binary form
string s = bitset<32>(X).to_string();
