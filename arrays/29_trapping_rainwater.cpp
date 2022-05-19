//Approach: Two pointer

#include<bits/stdc++.h>
using namespace std;

long long trappingWater(int arr[], int n){
        // code here
        long long ans=0;
        int l=0,r=n-1;
        int lmost=0,rmost=0;
        while(l<r){
            if(arr[l]<=arr[r]){
                if(arr[l]>=lmost)lmost=arr[l];
                else{
                    ans+=lmost-arr[l];
                }
                l++;
            }
            else{
                if(arr[r]>=rmost)rmost=arr[r];
                else{
                    ans+=rmost-arr[r];
                }
                r--;
            }
        }
        return ans;
    }