// To print the binary form of a decimal number as a string
string PrintBinary(int n)
{
  return bitset<16>(n).to_string();
}
