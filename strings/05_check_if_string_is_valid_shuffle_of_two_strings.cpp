//Given strings str1 and str2. The task is to find if str1 is a substring in the shuffled form of str2 or not.
//Approach 1: using substring method
//time complexity: O(m*n*log(n)) space complexity: O(n)
/*
Algo: Let n = length of str1, m = length of str2. 

If n > m, then string str1 can never be the substring of str2.
Else sort the string str1.
Traverse string str2 
Put all the characters of str2 of length n in another string str.
Sort the string str and Compare str and str1.
If str = str1, then string str1 is a shuffled substring of string str2.
else repeat the above process till ith index of str2 such that (i +n – 1 > m)(as after this index the length of remaining string str2 will be less than str1.
If str is not equals to str1 in above steps, then string str1 can never be substring of str2.
*/
// C++ program to check if string
// str1 is substring of str2 or not.
#include <bits/stdc++.h>
using namespace std;
 
// Function two check string A
// is shuffled  substring of B
// or not
bool isShuffledSubstring(string A, string B)
{
    int n = A.length();
    int m = B.length();
 
    // Return false if length of
    // string A is greater than
    // length of string B
    if (n > m) {
        return false;
    }
    else {
 
        // Sort string A
        sort(A.begin(), A.end());
 
        // Traverse string B
        for (int i = 0; i < m; i++) {
 
            // Return false if (i+n-1 >= m)
            // doesn't satisfy
            if (i + n - 1 >= m)
                return false;
 
            // Initialise the new string
            string str = "";
 
            // Copy the characters of
            // string B in str till
            // length n
            for (int j = 0; j < n; j++)
                str.push_back(B[i + j]);
 
            // Sort the string str
            sort(str.begin(), str.end());
 
            // Return true if sorted
            // string of "str" & sorted
            // string of "A" are equal
            if (str == A)
                return true;
        }
    }
}

//-------------------------------------------------------
//Approach 2: anagram search type

/*algo: This problem is a simpler version of Anagram Search. It can be solved in linear time using character frequency counting.
We can achieve O(n) time complexity under the assumption that alphabet size is fixed which is typically true as we have maximum of 256 possible characters in ASCII.
The idea is to use two count arrays:

1) The first count array stores frequencies of characters in a pattern. 
2) The second count array stores frequencies of characters in the current window of text.
The important thing to note is, time complexity to compare two counted arrays is O(1) as the number of elements in them is fixed 
(independent of pattern and text sizes). The following are steps of this algorithm. 
1) Store counts of frequencies of pattern in first count array countP[]. 
   Also, store counts of frequencies of characters in the first window of text in array countTW[].
2) Now run a loop from i = M to N-1. Do following in loop. 
…..a) If the two count arrays are identical, we found an occurrence. 
…..b) Increment count of current character of text in countTW[] 
…..c) Decrement count of the first character in the previous window in countWT[]
3) The last window is not checked by the above loop, so explicitly check it

*/

#include<iostream>
#include<cstring>
#define MAX 256
using namespace std;
 
// This function returns true if contents of arr1[] and arr2[]
// are same, otherwise false.
bool compare(char arr1[], char arr2[])
{
    for (int i=0; i<MAX; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}
 
// This function search for all permutations of pat[] in txt[]
bool search(char *pat, char *txt)
{
    int M = strlen(pat), N = strlen(txt);
 
    // countP[]: Store count of all characters of pattern
    // countTW[]: Store count of current window of text
    int countP[MAX] = {0}, countTW[MAX] = {0};
    for (int i = 0; i < M; i++)
    {
        countP[pat[i]]++;
        countTW[txt[i]]++;
    }
 
    // Traverse through remaining characters of pattern
    for (int i = M; i < N; i++)
    {
        // Compare counts of current window of text with
        // counts of pattern[]
        if (compare(countP, countTW))
           return true;
 
        // Add current character to current window
        (countTW[txt[i]])++;
 
        // Remove the first character of previous window
        countTW[txt[i-M]]--;
    }
 
    // Check for the last window in text
    if (compare(countP, countTW))
        return true;
        return false;
}
 
/* Driver program to test above function */
int main()
{
    char txt[] = "BACDGABCDA";
    char pat[] = "ABCD";
    if (search(pat, txt))
       cout << "Yes";
    else
       cout << "No";
    return 0;
}

//-------------------------------------------------------
