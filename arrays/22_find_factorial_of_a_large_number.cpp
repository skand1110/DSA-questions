//Approach 1: Array of digits Simple Mathematical approach
//Time Complexity: O(n^2); Space Complexity: O(1) 
/*
Since the factorial of N can be a very large number. It can not be stored in a regular integer data type. 
To store the factorial use an array of digits. 
Use simple school mathematics to conduct each multiplication operation. Keep track of carry.

1) Create an array ‘res[]’ of MAX size where MAX is number of maximum digits in output. 
2) Initialize value stored in ‘res[]’ as 1 and initialize ‘res_size’ (size of ‘res[]’) as 1. 
3) Do following for all numbers from x = 2 to n. 
……a) Multiply x with res[] and update res[] and res_size to store the multiplication result.

How to multiply a number ‘x’ with the number stored in res[]? 
The idea is to use simple school mathematics. We one by one multiply x with every digit of res[]. 
The important point to note here is digits are multiplied from rightmost digit to leftmost digit. 
If we store digits in same order in res[], then it becomes difficult to update res[] without extra space. 
That is why res[] is maintained in reverse way, i.e., digits from right to left are stored.

multiply(res[], x) 
1) Initialize carry as 0. 
2) Do following for i = 0 to res_size – 1 
….a) Find value of res[i] * x + carry. Let this value be prod. 
….b) Update res[i] by storing last digit of prod in it. 
….c) Update carry by storing remaining digits in carry. 
3) Put all digits of carry in res[] and increase res_size by number of digits in carry.

*/
// C++ program to compute factorial of big numbers
#include<iostream>
using namespace std;
 
// Maximum number of digits in output
#define MAX 500
 
int multiply(int x, int res[], int res_size);
 
// This function finds factorial of large numbers
// and prints them
void factorial(int n)
{
    int res[MAX];
 
    // Initialize result
    res[0] = 1;
    int res_size = 1;
 
    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
    for (int x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);
 
    cout << "Factorial of given number is \n";
    for (int i=res_size-1; i>=0; i--)
        cout << res[i];
}
 
// This function multiplies x with the number
// represented by res[].
// res_size is size of res[] or number of digits in the
// number represented by res[]. This function uses simple
// school mathematics for multiplication.
// This function may value of res_size and returns the
// new value of res_size
int multiply(int x, int res[], int res_size)
{
    int carry = 0;  // Initialize carry
 
    // One by one multiply n with individual digits of res[]
    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
 
        // Store last digit of 'prod' in res[] 
        res[i] = prod % 10; 
 
        // Put rest in carry
        carry  = prod/10;   
    }
 
    // Put carry in res and increase result size
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}
//---------------------------------------------------------
//Approach 2: using Linked List
//Space Complexity: O(1)

#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i, a, b) for (int i = a; i <= b; i++)
 
using namespace std;
// Made a class node containing data and previous pointer as
// we are using tail pointer
class Node {
public:
    int data;
    Node* prev;
    Node(int n)
    {
        data = n;
        prev = NULL;
    }
};
 
void Multiply(Node* tail, int n)
{
    Node *temp = tail,
         *prevNode = tail; // Temp variable for keeping tail
    int carry = 0;
    while (temp != NULL) {
        int data = temp->data * n + carry;
        temp->data = data % 10; // stores the last digit
        carry = data / 10;
        prevNode = temp;
        temp = temp->prev; // Moving temp by 1 prevNode will
                           // now denote temp
    }
    // If carry is greater than 0 then we create another
    // node for it.
    while (carry != 0) {
        prevNode->prev = new Node((int)(carry % 10));
        carry /= 10;
        prevNode = prevNode->prev;
    }
}
 
void print(Node* tail)
{
    if (tail == NULL) // Using tail recursion
        return;
    print(tail->prev);
    cout
        << tail->data; // Print linked list in reverse order
}