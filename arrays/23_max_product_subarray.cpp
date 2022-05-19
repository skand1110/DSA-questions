//Approach
/*
The question is similar to Maximum Subarray Sum, but here 2 things are different:
-> Negative numbers, we may need to include negative numbers in our Overall products, as it may give positive result.
-> 0, the complete solution nullifies, so we do never include it.
Algo:
1. To check for the max product subarray which starts from the first element, 
we need to traverse the array from 0th index to n-1th index, and look for the
maximum product of elements possible by multiplying each element to the product 
of all the elements before it and maintaining the max product obtained yet. 
2. If a 0 is encountered, we simply skip the elements before it and make the product
as 1 and then start multiplying the elements again from the element just after 0.
3. Similarly, to find the max product subarray which ends at the last element, 
we need to traverse the array from the last element to the first element in a similar manner.
4. Keep a tab of the max product obtained after both the traversals and return it.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

// Function to find maximum product subarray
long long maxProduct(vector<int> arr, int n) {
    // If array only contains one element, return the element
    if(n==1)
        return arr[0];
    
    long long maxProd = 1; //for maintaining the maximum product
    long long prod = 1; //for calculating the product at each element during traversal
    
    // For loop to calc the max prod from subarray including the first element
    for(int i=0;i<n;i++){
        prod *= arr[i];
        maxProd = max(maxProd, prod);
        if(arr[i] == 0){
            prod = 1;
        }
    }
    
    // For loop to calc the max prod from subarray including the last element
    prod = 1;
    for(int i=n-1;i>=0;i--){
        prod*=arr[i];
        maxProd = max(maxProd,prod);
        if(arr[i] == 0){
            prod = 1;
        }
    }
    
    return maxProd;
}
	
};
//----------------------------------------------
//Approach 2: Kadane kinda
//Time Complexity: O(n); Space Complexity: O(1)
/*
The idea is to traverse array from left to right keeping two variables minVal and maxVal 
which represents the minimum and maximum product value till the ith index of the array. 
Now, if the ith element of the array is negative that means now the values of minVal and maxVal 
will be swapped as value of maxVal will become minimum by multiplying it with a negative number. 
Now, compare the minVal and maxVal. 
The value of minVal and maxVal depends on the current index element or the product of the 
current index element and the previous minVal and maxVal respectively.
Below is the implementation of above approach: 
*/

int maxProduct(int* arr, int n)
{
    // Variables to store maximum and minimum
    // product till ith index.
    int minVal = arr[0];
    int maxVal = arr[0];

    int maxProduct = arr[0];

    for (int i = 1; i < n; i++) {

        // When multiplied by -ve number,
        // maxVal becomes minVal
        // and minVal becomes maxVal.
        if (arr[i] < 0)
            swap(maxVal, minVal);

        // maxVal and minVal stores the
        // product of subarray ending at arr[i].
        maxVal = max(arr[i], maxVal * arr[i]);
        minVal = min(arr[i], minVal * arr[i]);

        // Max Product of array.
        maxProduct = max(maxProduct, maxVal);
    }

    // Return maximum product found in array.
    return maxProduct;
}