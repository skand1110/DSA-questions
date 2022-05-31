// Approach : using two pointers
/*
-> Create an auxiliary array aux[] and store sum of all possible pairs in aux[].
The size of aux[] will be n*(n-1)/2 where n is the size of A[].
-> Sort the auxiliary array aux[].
Now the problem reduces to find two elements in aux[] with sum equal to X.

An element of aux[] represents a pair from A[]. While picking two elements from aux[],
we must check whether the two elements have an element of A[] in common.
For example, if first element sum of A[1] and A[2], and second element is sum of A[2] and A[4],
then these two elements of aux[] don’t represent four distinct elements of input array A[].

The step 1 takes O(n^2) time.
The second step is sorting an array of size O(n^2).
Sorting can be done in O(n^2Logn) time using merge sort or heap sort or any other O(nLogn) algorithm.
The third step takes O(n^2) time. So overall complexity is O(n^2Logn).
*/
// time complexity:O(n^2 logn) ; space complexity: O(n^2)

// C++ program to find 4 elements
// with given sum
#include <bits/stdc++.h>
using namespace std;

// The following structure is needed
// to store pair sums in aux[]
class pairSum
{
public:
    // index (int A[]) of first element in pair
    int first;

    // index of second element in pair
    int sec;

    // sum of the pair
    int sum;
};

// Following function is needed
// for library function qsort()
int compare(const void *a, const void *b)
{
    return ((*(pairSum *)a).sum - (*(pairSum *)b).sum);
}

// Function to check if two given pairs
// have any common element or not
bool noCommon(pairSum a, pairSum b)
{
    if (a.first == b.first || a.first == b.sec || a.sec == b.first || a.sec == b.sec)
        return false;
    return true;
}

// The function finds four
// elements with given sum X
void findFourElements(int arr[], int n, int X)
{
    int i, j;

    // Create an auxiliary array
    // to store all pair sums
    int size = (n * (n - 1)) / 2;
    pairSum aux[size];

    // Generate all possible pairs
    // from A[] and store sums
    // of all possible pairs in aux[]
    int k = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            aux[k].sum = arr[i] + arr[j];
            aux[k].first = i;
            aux[k].sec = j;
            k++;
        }
    }

    // Sort the aux[] array using
    // library function for sorting
    qsort(aux, size, sizeof(aux[0]), compare);

    // Now start two index variables
    // from two corners of array
    // and move them toward each other.
    i = 0;
    j = size - 1;
    while (i < size && j >= 0)
    {
        if ((aux[i].sum + aux[j].sum == X) && noCommon(aux[i], aux[j]))
        {
            cout<<arr[aux[i].first]<<", "<<arr[aux[i].sec]<<", "<< arr[aux[j].first] <<", "<<arr[aux[j].sec] << endl;
            return;
        }
        else if (aux[i].sum + aux[j].sum < X)
            i++;
        else
            j--;
    }
}

//--------------------------------------------------------------
// Approach : using Hashing
/*
-> Store sums of all pairs in a hash table
-> Traverse through all pairs again and search for X – (current pair sum) in the hash table.
-> If a pair is found with the required sum, then make sure that all elements are distinct array elements
    and an element is not considered more than once.
*/
// time complexity: O(n^2); space complexity: O(n^2)

#include <bits/stdc++.h>
using namespace std;

// The function finds four
// elements with given sum X
void findFourElements(int arr[], int n, int X)
{
    // Store sums of all pairs
    // in a hash table
    unordered_map<int, pair<int, int>> mp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            mp[arr[i] + arr[j]] = {i, j};

    // Traverse through all pairs and search
    // for X - (current pair sum).
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];

            // If X - sum is present in hash table,
            if (mp.find(X - sum) != mp.end())
            {

                // Making sure that all elements are
                // distinct array elements and an element
                // is not considered more than once.
                pair<int, int> p = mp[X - sum];
                if (p.first != i && p.first != j && p.second != i && p.second != j)
                {
                    cout << arr[i] << ", " << arr[j] << ", "
                         << arr[p.first] << ", "
                         << arr[p.second];
                    return;
                }
            }
        }
    }
}