//Approach: HashTable
//Time Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
     unordered_set<int> set1;
    for(int i=0; i<n; i++) {
        set1.insert(a1[i]);
    }
    
    int siz = set1.size();
    
    for(int i=0; i<m; i++ ){
        set1.insert(a2[i]);
    }
    int siz2 = set1.size();
    
    if(siz == siz2) {
        return "Yes";
    }
    else {
        return "No";
    }
    
    
}