//Given a set of points as and a line as ax+by+c = 0. 
//We need to find a point on given line for which sum of distances from given set of points is minimum. 
//Approach:
/*
If we take one point on given line at infinite distance then total distance cost will be infinite, 
now when we move this point on line towards given points the total distance cost starts decreasing and after some time, 
it again starts increasing which reached to infinite on the other infinite end of line so distance cost curve looks like a U-curve 
and we have to find the bottom value of this U-curve. 

As U-curve is not monotonically increasing or decreasing we can’t use binary search for finding bottom most point, 
here we will use ternary search for finding bottom most point, ternary search skips one third of search space at each iteration.

A ternary search algorithm is a technique in computer science for finding the minimum or maximum of a unimodal function. 
A ternary search determines either that the minimum or maximum cannot be in the first third of the domain or 
that it cannot be in the last third of the domain, then repeats on the remaining two thirds. 
A ternary search is an example of a divide and conquer algorithm.

Algo for ternary search:
We can divide the array into three parts by taking mid1 and mid2 which can be calculated as shown below. 
Initially, l and r will be equal to 0 and n-1 respectively, where n is the length of the array. 

mid1 = l + (r-l)/3 
mid2 = r – (r-l)/3 

Note: Array needs to be sorted to perform ternary search on it.

Steps to perform Ternary Search: 

First, we compare the key with the element at mid1. If found equal, we return mid1.
If not, then we compare the key with the element at mid2. If found equal, we return mid2.
If not, then we check whether the key is less than the element at mid1. If yes, then recur to the first part.
If not, then we check whether the key is greater than the element at mid2. If yes, then recur to the third part.
If not, then we recur to the second (middle) part.


Time Complexity for Binary search = 2clog base 2 n + O(1)
Time Complexity for Ternary search = 4clog base 3 n + O(1)
Space Complexity: O(1)
*/

//  C/C++ program to find optimum location and total cost
#include <bits/stdc++.h>
using namespace std;
#define sq(x) ((x) * (x))
#define EPS 1e-6
#define N 5
 
//  structure defining a point
struct point {
    int x, y;
    point() {}
    point(int x, int y)
        : x(x)
        , y(y)
    {
    }
};
 
//  structure defining a line of ax + by + c = 0 form
struct line {
    int a, b, c;
    line(int a, int b, int c)
        : a(a)
        , b(b)
        , c(c)
    {
    }
};
 
//  method to get distance of point (x, y) from point p
double dist(double x, double y, point p)
{
    return sqrt(sq(x - p.x) + sq(y - p.y));
}
 
/*  Utility method to compute total distance all points
    when choose point on given line has x-coordinate
    value as X   */
double compute(point p[], int n, line l, double X)
{
    double res = 0;
 
    //  calculating Y of chosen point by line equation
    double Y = -1 * (l.c + l.a * X) / l.b;
    for (int i = 0; i < n; i++)
        res += dist(X, Y, p[i]);
 
    return res;
}
 
//  Utility method to find minimum total distance
double findOptimumCostUtil(point p[], int n, line l)
{
    double low = -1e6;
    double high = 1e6;
 
    // loop until difference between low and high
    // become less than EPS
    while ((high - low) > EPS) {
        // mid1 and mid2 are representative x co-ordiantes
        // of search space
        double mid1 = low + (high - low) / 3;
        double mid2 = high - (high - low) / 3;
 
        //
        double dist1 = compute(p, n, l, mid1);
        double dist2 = compute(p, n, l, mid2);
 
        // if mid2 point gives more total distance,
        // skip third part
        if (dist1 < dist2)
            high = mid2;
 
        // if mid1 point gives more total distance,
        // skip first part
        else
            low = mid1;
    }
 
    // compute optimum distance cost by sending average
    // of low and high as X
    return compute(p, n, l, (low + high) / 2);
}
 
//  method to find optimum cost
double findOptimumCost(int points[N][2], line l)
{
    point p[N];
 
    //  converting 2D array input to point array
    for (int i = 0; i < N; i++)
        p[i] = point(points[i][0], points[i][1]);
 
    return findOptimumCostUtil(p, N, l);
}
 
//  Driver code to test above method
int main()
{
    line l(1, -1, -3);
    int points[N][2] = {
        { -3, -2 }, { -1, 0 }, { -1, 2 }, { 1, 2 }, { 3, 4 }
    };
    cout << findOptimumCost(points, l) << endl;
    return 0;
}