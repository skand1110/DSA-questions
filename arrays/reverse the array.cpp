// APPROACH 1: simple iteration and creating a new/auxiliary array
// Space complexity: O(n); Time complexity: O(n)
#include <iostream>
using namespace std;

int main()
{
    int t, n; // where t is no. of testcases and n is length of array
    cin >> t;
    while (t--)
    {
        cin >> n;
        int array[n]; // allocating space for user-defined array
        for (int i = 0; i < n; i++)
        {
            cin >> array[i]; // user input for array values
        }
        int k = 0;
        int reverse[n]; // allocating space for a new array

        // Looping from back and assigning values to new array
        for (int i = 0; i < n; i++)
        {
            reverse[k++] = array[n - i - 1];
        }

        // output the reverse array
        for (int i = 0; i < n; i++)
        {
            cout << reverse[i] << " ";
        }
        cout << endl;
    }
    return 0;
}


//----------------------------------------------------------------------
// APPROACH 2: swapping in the given array (in-place implementation)
// Space complexity: O(1); Time complexity: O(n)
#include <iostream>
using namespace std;

int main() {
	int t, n;   // where t is no. of testcases and n is length of array
	cin>>t;
	while(t--){
	    cin>>n;
	    int array[n];   // allocating space for user-defined array
	    for(int i=0; i<n; i++){
	        cin>>array[i];  // user input for array values
	    }
    	int start = 0;
    	int end = n-1;
    while (start < end)    //swapping the values 
    {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
        //output the reverse array
        for(int i=0; i<n; i++){
            cout << array[i] <<" ";
        }
        cout<<endl;
	}
	return 0;
}

//----------------------------------------------------------------------
// APPROACH 3: swapping using recursion (in-place implementation)
// Space complexity: O(n); Time complexity: O(n)
// Not recommended as it can cause memory issues in large arrays
#include <iostream>
using namespace std;

// Function to reverse arr[] from start to end
void reverseArray(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursive Function calling
    reverseArray(arr, start + 1, end - 1);
}
int main() {
	int t, n;   // where t is no. of testcases and n is length of array
	cin>>t;
	while(t--){
	    cin>>n;
	    int array[n];   // allocating space for user-defined array
	    for(int i=0; i<n; i++){
	        cin>>array[i];  // user input for array values
	    }
        // calling the ReverseArray Function 
        reverseArray(array, 0, n-1);
   
        for(int i=0; i<n; i++){
            cout << array[i] <<" "; //output the reverse array
        }
        cout<<endl;
	}
	return 0;
}

//----------------------------------------------------------------------
// APPROACH 4: using reverse funtion from STL (in-place implementation)
// Space complexity: O(1); Time complexity: O(n)
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t, n;   // where t is no. of testcases and n is length of array
	cin>>t;
	while(t--){
	    cin>>n;
	    int array[n];   // allocating space for user-defined array
	    for(int i=0; i<n; i++){
	        cin>>array[i];  // user input for array values
	    }
   reverse(array, array+n); //using reverse function from STL
   
        //output the reverse array
        for(int i=0; i<n; i++){
            cout << array[i] <<" ";
        }
        cout<<endl;
	}
	return 0;
}
