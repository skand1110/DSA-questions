/*Given heights of n towers and a value k. We need to either increase 
or decrease the height of every tower by k (only once) where k > 0. 
The task is to minimize the difference between the heights
of the longest and the shortest tower after modifications and output this difference.

//Approach:
//Time Complexity: O(nlogn); Space complexity: O(n)

-> sort the array and make each height of the tower maximum 
by decreasing the height of all the towers towards the right by k
and increasing all the height of the towers towards the left by k. 
-> It is also possible that the tower you are trying to increase the 
height doesn't have the maximum height. Therefore we only need to check whether 
it has the maximum height or not by comparing it with the last element on the right
side which is a[n]-k. 
-> Since the array is sorted if the tower's height is 
greater than the [n]-k then it's the tallest tower available. 
-> Similar reasoning can also be applied to finding the shortest tower.  
Note:- We need not consider where a[i]<k because the height of the tower 
can't be negative so we have to neglect that case.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
       if (arr == NULL || n<=0) return -1;
       sort(arr,arr+n);
       int mini = 0, maxi = 0,res = 0;
       res = arr[n-1] - arr[0];
       for (int i = 1;i<n;++i){
           if (arr[i]>=k){
               maxi =max(arr[i-1]+k,arr[n-1]-k);
               mini =min(arr[i]-k,arr[0]+k);
       
               res = min(res,maxi-mini);
           }else {
               continue;
           }
       }
       return res;
    }
};

