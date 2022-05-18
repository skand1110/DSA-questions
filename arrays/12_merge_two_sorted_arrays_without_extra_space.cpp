// Approach: The idea is: We will traverse the first array
/*and compare it with the first element of the second array.
If the first element of the second array is smaller
than the first array, we will swap and then sort the second array.
-> First, we have to traverse array1 and then compare it with the first element of array2.
If it is less than array1 then we swap both.
-> After swapping we are going to sort the array2 again so that the smallest element of the array2
comes at the first position and we can again swap with the array1
-> To sort the array2 we will store the first element of array2 in a variable and left shift all the elements and store
the first element in array2 in the last.
*/
// Time Complexity: O(n*m); Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(int arr1[], int arr2[], int n, int m)
    {
        int i = n - 1;
        int j = 0;

        while (i >= 0 && j < m)
        {
            if (arr1[i] > arr2[j])
            {
                swap(arr1[i], arr2[j]);
            }
            i--;
            j++;
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};
//------------------------------------------------------------------
// Approach 2:
// TC: O(m+n)
/*Suppose we have a number A and we want to
convert it to a number B and there is also a
constraint that we can recover number A any
time without using other variable.To achieve
this we chose a number N which is greater
than both numbers and add B*N in A.
so A --> A+B*N
-> To get number B out of (A+B*N)
we divide (A+B*N) by N.
so (A+B*N)/N = B.
-> To get number A out of (A+B*N)
we take modulo with N.
so (A+B*N)%N = A.
-> In short by taking modulo
we get old number back and taking divide
we new number.

We first find the maximum element of both arrays and increment
it by one to avoid collision of 0 and maximum element during modulo operation.
The idea is to traverse both arrays from starting simultaneously.
Let's say an element in a is a[i] and in b is b[j] and
k is the position at where the next minimum number will come.
Now update value a[k] if k<n else b[k-n] by adding min(a[i],b[j])*maximum_element.
After updating all the elements divide all the elements by maximum_element
so we get the updated array back.
*/
#include <bits/stdc++.h>
using namespace std;

void mergeArray(int a[], int b[], int n, int m)
{
    int mx = 0;

    // Find maximum element of both array
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        mx = max(mx, b[i]);
    }

    // increment by one to avoid collision of 0 and maximum
    // element of array in modulo operation
    mx++;
    int i = 0, j = 0, k = 0;
    while (i < n && j < m && k < (n + m))
    {

        // recover back original element to compare
        int e1 = a[i] % mx;
        int e2 = b[j] % mx;
        if (e1 <= e2)
        {

            // update element by adding multiplication
            // with new number
            if (k < n)
                a[k] += (e1 * mx);
            else
                b[k - n] += (e1 * mx);
            i++;
            k++;
        }
        else
        {

            // update element by adding multiplication
            // with new number
            if (k < n)
                a[k] += (e2 * mx);
            else
                b[k - n] += (e2 * mx);
            j++;
            k++;
        }
    }

    // process those elements which are left in array a
    while (i < n)
    {
        int el = a[i] % mx;
        if (k < n)
            a[k] += (el * mx);
        else
            b[k - n] += (el * mx);
        i++;
        k++;
    }

    // process those elements which are left in array b
    while (j < m)
    {
        int el = b[j] % mx;
        if (k < n)
            a[k] += (el * mx);
        else
            b[k - n] += (el * mx);
        j++;
        k++;
    }

    // finally update elements by dividing
    // with maximum element
    for (int i = 0; i < n; i++)
        a[i] = a[i] / mx;

    // finally update elements by dividing
    // with maximum element
    for (int i = 0; i < m; i++)
        b[i] = b[i] / mx;

    return;
}
//--------------------------------------------------------
//Approach 3:

/*The idea: We start comparing elements 
that are far from each other rather than adjacent. 
For every pass, we calculate the gap and compare 
the elements towards the right of the gap. 
Every pass, the gap reduces to the ceiling value of dividing by 2.
*/

// Merging two sorted arrays with O(1)
// extra space
#include <bits/stdc++.h>
using namespace std;

// Function to find next gap.
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

void merge(int* arr1, int* arr2, int n, int m)
{
    int i, j, gap = n + m;
    for (gap = nextGap(gap); 
         gap > 0; gap = nextGap(gap)) 
    {
        // comparing elements in the first array.
        for (i = 0; i + gap < n; i++)
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);

        // comparing elements in both arrays.
        for (j = gap > n ? gap - n : 0; 
             i < n && j < m;
             i++, j++)
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);

        if (j < m) {
            // comparing elements in the second array.
            for (j = 0; j + gap < m; j++)
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
        }
    }
}
//-------------------------------------------------------------