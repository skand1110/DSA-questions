//Approach : use XOR
//XOR of two number will have set bits only at those places where A differs from B
// Count number of bits to be flipped
// to convert A into B
#include <iostream>
using namespace std;
 
// Function that count set bits
int countSetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n &= (n-1);
    }
    return count;
}
 
// Function that return count of
// flipped number
int FlippedCount(int a, int b)
{
    // Return count of set bits in
    // a XOR b
    return countSetBits(a^b);
}
//---------------------------------------------
//using shifting
#include <iostream>
using namespace std;
 
int countFlips(int a, int b)
{
 
  // initially flips is equal to 0
  int flips = 0;
 
  // & each bits of a && b with 1
  // and store them if t1 and t2
  // if t1 != t2 then we will flip that bit
 
  while(a > 0 || b > 0){
 
    int t1 = (a&1);
    int t2 = (b&1);
 
    if(t1!=t2){
      flips++;
    }
    // right shifting a and b
    a>>=1;
    b>>=1;
  }
 
  return flips;
}
 