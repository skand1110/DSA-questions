//Approach 1: 
//Time Complexity: O(nlogn) [for using the sort function] + O(n) [for traversing the interval] = O(nlogn)
//Space Complexity : O(n) [For our resultant vector]
/*Given an array of intervals where intervals[i] = [starti, endi], 
merge all overlapping intervals, and return an array of the 
non-overlapping intervals that cover all the intervals in the input.

After reading the question we get that we need to merge the over lapping intervals 
and return the result by keeping the rest of the elements as it is.
To find the overlapping intervals the intervals should be atleast sorted think about this .
Thus for solving we need to sort and then check the consecutive intervals. 
Once we find the overlapping interval. we will take the max element from it.

Algorithm:-

-> Firstly, the base case : if there are no intervals return [] .
-> Sort the intervals .
-> While traversing the intervals vector we will come accross two conditions.
-> First condition : if there is a overlapping between the intervals then 
just take out the max element from the ending point and thus we merged them
eg:- [1,4],[2,8] =Mergerd intervals will be> [1,8]
-> second condition : if there is no overlapping then simply push those interval to our resultant vector .
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //base case
        if(intervals.size()<=1) return intervals;
        //resultan vector
        vector<vector<int>> result;
        //sort takes O(nlogn) time
        sort(intervals.begin(), intervals.end()); 
        //insert the the the first interval in the result
        result.push_back(intervals[0]);
         //Traverse the whole vector .Takes O(n) time
        for(int i=1; i<intervals.size(); i++) {
             //if intevals are overlapping
            if(result.back()[1] >= intervals[i][0]) result.back()[1] = max(result.back()[1] , intervals[i][1]);
            //else they are not overlapping
            else result.push_back(intervals[i]); 
        }
        return result;
    }
};