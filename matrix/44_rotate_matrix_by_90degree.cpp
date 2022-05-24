//also refer to: how to rotate an image by 90 degrees

//Approach 1: for a square matrix (n*n)
/*
we can rotate a matrix by taking transpose of it and then reversing the rows
*/
//time complexity: O(n^2); space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix, int n){
    //for transpose
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    //for reverse
    for(int i=0; i<n; i++){
    reverse(matrix[i].begin(), matrix[i].end());
    }
}

void printMatrix(vector<vector<int>>& matrix, int n){
     for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
}

