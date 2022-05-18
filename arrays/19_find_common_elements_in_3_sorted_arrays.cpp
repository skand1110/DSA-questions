//Approach: Maintain 3 pointers, one for each array and traverse till any of them reaches the end of the array.
#include<bits/stdc++.h>
using namespace std;

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
       {
           //code here.
           int p1=0,p2=0,p3=0;
           vector<int>v;
           set<int>s;
           while(p1<n1&&p2<n2&&p3<n3){
               if(A[p1]==B[p2]&&A[p1]==C[p3]){
               s.insert(A[p1]);
                   p1++;
                   p2++;
                   p3++;
               }
               else if(C[p3]>A[p1]||B[p2]>A[p1])
               p1++;
               else if(C[p3]<A[p1]||B[p2]>C[p3])
               p3++;
               else if(B[p2]<A[p1]||B[p2]<C[p3])
               p2++;
            }
            for (auto itr = s.begin(); itr != s.end(); itr++) {
               v.push_back(*itr);
                // cout << *itr << " ";
            }
           return v;
       }

//-----------------------------------------------------------------------------------------------------------------------