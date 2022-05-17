//Approach 1:
/*Following are steps. 
1) Store last element in a variable say x. 
2) Shift all elements one position ahead. 
3) Replace first element of array with x.
*/
//Time Complexity: O(n); Space Complexity: O(1)
# include <iostream>
using namespace std;
 
void rotate(int arr[], int n)
{
    int x = arr[n - 1];
    for (int i = n - 1; i > 0; i--)
    arr[i] = arr[i - 1];
    arr[0] = x;
}