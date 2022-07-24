//approach 1: using array

#include <bits/stdc++.h>
  
using namespace std;
  
#define MAX 1000
  
class Stack {
    int top;
  
public:
    int a[MAX]; // Maximum size of Stack
  
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};
  
bool Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}
  
int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}
  
bool Stack::isEmpty()
{
    return (top < 0);
}
  
// Driver program to test above functions
int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";
    
    //print top element of stack after poping
    cout << "Top element is : " << s.peek() << endl;
    
    //print all elements in stack :
    cout<<"Elements present in stack : ";
    while(!s.isEmpty())
    {
        // print top element in stack
        cout<<s.peek()<<" ";
        // remove top element in stack
        s.pop();
    }
  
    return 0;
}
//----------------------------------------------------
//approach 2: using linked list

#include <bits/stdc++.h>
using namespace std;
  
// A structure to represent a stack
class StackNode {
public:
    int data;
    StackNode* next;
};
  
StackNode* newNode(int data)
{
    StackNode* stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
  
int isEmpty(StackNode* root)
{
    return !root;
}
  
void push(StackNode** root, int data)
{
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    cout << data << " pushed to stack\n";
}
  
int pop(StackNode** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
  
    return popped;
}
  
int peek(StackNode* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}
  
// Driver code
int main()
{
    StackNode* root = NULL;
  
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
  
    cout << pop(&root) << " popped from stack\n";
  
    cout << "Top element is " << peek(root) << endl;
      
    cout<<"Elements present in stack : ";
     //print all elements in stack :
    while(!isEmpty(root))
    {
        // print top element in stack
        cout<<peek(root)<<" ";
        // remove top element in stack
        pop(&root);
    }
  
    return 0;
}
