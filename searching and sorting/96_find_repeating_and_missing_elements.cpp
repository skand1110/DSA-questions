//Approach 1: sorting
/*
Sort and traverse the array and check for missing and repeating.
Time Complexity: O(nLogn)
*/ 
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        sort(arr, arr+n);
        int *ans= new int[2];
       int rep,miss=1;
       
       for(int i=0;i<n;i++)
       {
           if(arr[i]==arr[i+1])
           {
           rep=arr[i];
           }
           if(miss==arr[i])
           miss++;
       }
       
       ans[0]=rep;
       ans[1]=miss;
       
       return ans;
    }
};
//-------------------------------------------------------
//Approach 2: use count variable
/*
Create a temp array temp[] of size n with all initial values as 0.
Traverse the input array arr[], and do following for each arr[i] 
if(temp[arr[i]] == 0) temp[arr[i]] = 1;
if(temp[arr[i]] == 1) output “arr[i]” //repeating
Traverse temp[] and output the array element having value as 0 (This is the missing element)
Time Complexity: O(n); space complexity: O(n)
*/
//-------------------------------------------------------------
//Approach 3: using XOR 
/*
Let x and y be the desired output elements.
Calculate XOR of all the array elements.
xor1 = arr[0]^arr[1]^arr[2]…..arr[n-1]

XOR the result with all numbers from 1 to n
xor1 = xor1^1^2^…..^n

In the result xor1, all elements would nullify each other except x and y. 
All the bits that are set in xor1 will be set in either x or y. 
So if we take any set bit (We have chosen the rightmost set bit in code) of xor1 and
divide the elements of the array in two sets – one set of elements with the same bit set 
and other set with same bit not set. By doing so, we will get x in one set and y in another set. 
Now if we do XOR of all the elements in first set, we will get x, and by doing same in other set we will get y. 
*/
// time complexity: O(n); 
 
#include <bits/stdc++.h>
using namespace std;
 
/* The output of this function is stored at
*x and *y */
void getTwoElements(int arr[], int n,
                    int* x, int* y)
{
    /* Will hold xor of all elements
    and numbers from 1 to n */
    int xor1;
 
    /* Will have only single set bit of xor1 */
    int set_bit_no;
 
    int i;
    *x = 0;
    *y = 0;
 
    xor1 = arr[0];
 
    /* Get the xor of all array elements */
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];
 
    /* XOR the previous result with numbers
    from 1 to n*/
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;
 
    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);
 
    /* Now divide elements into two
    sets by comparing a rightmost set
    bit of xor1 with the bit at the same
    position in each element. Also,
    get XORs of two sets. The two
    XORs are the output elements.
    The following two for loops
    serve the purpose */
    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no)
            /* arr[i] belongs to first set */
            *x = *x ^ arr[i];
 
        else
            /* arr[i] belongs to second set*/
            *y = *y ^ arr[i];
    }
    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            /* i belongs to first set */
            *x = *x ^ i;
 
        else
            /* i belongs to second set*/
            *y = *y ^ i;
    }
 
    /* *x and *y hold the desired
        output elements */
}
 
/* Driver code */
int main()
{
    int arr[] = { 1, 3, 4, 5, 5, 6, 2 };
    int* x = (int*)malloc(sizeof(int));
    int* y = (int*)malloc(sizeof(int));
    int n = sizeof(arr) / sizeof(arr[0]);
 
    getTwoElements(arr, n, x, y);
    cout << " The missing element is " << *x << " and the repeating"
         << " number is " << *y;
    getchar();
}
//---------------------------------------------------
//Approach 4: hash map
//time complexity: o(1); space complexity: O(n)
#include <iostream>
#include <unordered_map>
using namespace std;
 
int main()
{
    int arr[] = { 4, 3, 6, 2, 1, 1 };
    int n = 6;
     
    unordered_map<int, bool> numberMap;
     
    for(int i : arr)
    {
        if (numberMap.find(i) ==
            numberMap.end())
        {
            numberMap[i] = true;
        }
        else
        {
            cout << "Repeating = " << i;
        }
    }
    cout << endl;
     
    for(int i = 1; i <= n; i++)
    {
        if (numberMap.find(i) ==
            numberMap.end())
        {
            cout << "Missing = " << i;
        }
    }
    return 0;
}