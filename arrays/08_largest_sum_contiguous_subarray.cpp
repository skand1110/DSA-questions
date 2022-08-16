//Approach 1: using Kadane algo
// time complexity: O(n) 

#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n){
        long long res = arr[0];
        long long cur = res;
        for (int i = 1; i < n; i++){
            cur = (cur < 0) ? arr[i] : cur + arr[i];
            res = max(res, cur);
        }
        return res;
    }
