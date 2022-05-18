
/*
Use a hash map to solve the question in O(n) time. 

-> Create a map to store frequency of each number in the array. 
(Single traversal is required)
-> For every element check if it can be combined with any other element 
(other than itself!) to give the desired sum. Increment the counter accordingly. 
-> After completion of second traversal, we’d have twice the required value 
stored in counter because every pair is counted two times. 
-> Also take care of pairs with duplicate elements like (2,2) when K =4.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
     unordered_map<int,int> m;
        
        
        int count=0;
        for(int i=0;i<n;i++){
            if(m[k-arr[i]]){
                count+=m[k-arr[i]];
            }
             m[arr[i]]++;
        }
        return count;
        
    }
};