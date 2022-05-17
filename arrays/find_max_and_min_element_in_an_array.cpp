// Approach 1: Brute force, iterate over the array
// Time complexity: O(n); Space complexity: O(1)
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int mini = arr[0];
        int maxi = arr[0];
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }
        cout << mini << " " << maxi << endl;
    }
    return 0;
}
//----------------------------------------------------------------------
// APPROACH 2: Comparing in pairs, single scan
// Time complexity: O(n),
// Total no. of comparision operations = 3n/2 - 2 if n is even , worst case
// Space complexity: O(1)

// C++ program of above implementation
#include <iostream>
using namespace std;

// Structure is used to return
// two values from minMax()
struct Pair
{
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int n)
{
    struct Pair minmax;
    int i;

    // If array has even number of elements
    // then initialize the first two elements
    // as minimum and maximum
    if (n % 2 == 0)
    {
        if (arr[0] > arr[1])
        {
            minmax.max = arr[0];
            minmax.min = arr[1];
        }
        else
        {
            minmax.min = arr[0];
            minmax.max = arr[1];
        }

        // Set the starting index for loop
        i = 2;
    }

    // If array has odd number of elements
    // then initialize the first element as
    // minimum and maximum
    else
    {
        minmax.min = arr[0];
        minmax.max = arr[0];

        // Set the starting index for loop
        i = 1;
    }

    // In the while loop, pick elements in
    // pair and compare the pair with max
    // and min so far
    while (i < n - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > minmax.max)
                minmax.max = arr[i];

            if (arr[i + 1] < minmax.min)
                minmax.min = arr[i + 1];
        }
        else
        {
            if (arr[i + 1] > minmax.max)
                minmax.max = arr[i + 1];

            if (arr[i] < minmax.min)
                minmax.min = arr[i];
        }

        // Increment the index by 2 as
        // two elements are processed in loop
        i += 2;
    }
    return minmax;
}

// Driver code
int main()
{
    int arr[] = {1000, 11, 445,
                 1, 330, 3000};
    int arr_size = 6;

    Pair minmax = getMinMax(arr, arr_size);

    cout << "nMinimum element is "
         << minmax.min << endl;
    cout << "nMaximum element is "
         << minmax.max;

    return 0;
}
