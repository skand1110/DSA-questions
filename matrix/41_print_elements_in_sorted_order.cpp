//Approach 1:
//Time Complexity: O(N^2log(N^2))
//Auxiliary Space: O(N^2)

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int n, vector<vector<int>> Mat) {
       priority_queue<int , vector<int> , greater<int>>vec;
        
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            vec.push(Mat[i][j]);
        }
        
        
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            Mat[i][j] = vec.top();
            vec.pop();
        }
        
        return Mat;
    }
};
//---------------------------------------------------------------------

//Approach 2: Priority queue

class Solution {
  public:
     vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        vector<int> v;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                v.push_back(Mat[i][j]);
            }
        }
        int k=0;
        sort(v.begin(),v.end());
        vector<vector<int>> ans(N,vector<int>(N));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                ans[i][j]=v[k];
                k++;
            }
        }
        return ans;
    }
};