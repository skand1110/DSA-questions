/*
A simple solution is to consider all subarrays one by one and check if sum of every subarray is equal to 0 or not. The complexity of this solution would be O(n^2).
A better approach is to use Hashing.
Do following for each element in the array:
 
Maintain sum of elements encountered so far in a variable (say sum).
If current sum is 0, we found a subarray starting from index 0 and ending at index current index
Check if current sum exists in the hash table or not.
If current sum already exists in the hash table then it indicates that this sum was the sum of some sub-array elements arr[0]...arr[i] 
and now the same sum is obtained for the current sub-array arr[0]...arr[j] which means that the sum of the sub-array arr[i+1]...arr[j] must be 0.
Insert current sum into the hash table

*/
//Approach: using hashing
//Time Complexity: O(N); Auxiliary Space: O(N)

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
           ll cnt=0,sum=0;
       
       unordered_map<ll,int>mp;
       mp[0]=1;
       for(int i=0;i<n;i++){
           sum+=arr[i];
           if(mp[sum]>=1 || sum==0)cnt+=mp[sum];
           mp[sum]++;
       }
       return cnt;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends
