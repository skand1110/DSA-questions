//Approach 1: iterative
//time complexity: O(n); space complexity: O(1)
/*
Initialize three pointers prev as NULL, curr as head and next as NULL.
Iterate through the linked list. In loop, do following. 
// Before changing next of current, 
// store next node 
next = curr->next
// Now change next of current 
// This is where actual reversing happens 
curr->next = prev 
// Move prev and curr one step forward 
prev = curr 
curr = next
*/

// Iterative C++ program to reverse a linked list
#include<bits/stdc++.h>
 
using namespace std;
 
struct node {
    int data;
    struct node *next;
};
 
// We construct a linked list and use this function to push elements to the list 
void push(struct node **head_ref, int data) {
    struct node *node;
    node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = (*head_ref);
    (*head_ref) = node;
}
 
// Function to reverse the list
void reverse(struct node **head_ref) {
    struct node *temp = NULL;
    struct node *prev = NULL;
    struct node *current = (*head_ref);
    while(current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head_ref) = prev;
}
 
// Checking our program 
void printnodes(struct node *head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}
 
// Driver function
int main() {
    struct node *head = NULL;
    push(&head, 28);
    push(&head, 21);
    push(&head, 14);
    push(&head, 7);

    cout << "Original Linked List" << endl;
    printnodes(head);
    reverse(&head);
    cout << endl;
    cout << "Reversed Linked List"<<endl;
    printnodes(head);
    return 0;
}

//----------------------------------------------------------------
//Approach 2: REcursive
//time complexity: O(); space complexity: O()
/*
 1) Divide the list in two parts - first node and 
      rest of the linked list.
   2) Call reverse for the rest of the linked list.
   3) Link rest to first.
   4) Fix head pointer
*/

// Recursive C++ program to reverse
// a linked list
#include<bits/stdc++.h>
using namespace std;
 
 
struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
 
struct LinkedList {
    Node* head;
    LinkedList()
    {
        head = NULL;
    }
 
    Node* reverse(Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        // Recursive call
        Node* rest = reverse(head->next);
        head->next->next = head;
        
        head->next = NULL;
 
        return rest;
    }
 
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
 
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};
 
int main()
{
    LinkedList ll;
    ll.push(28);
    ll.push(21);
    ll.push(14);
    ll.push(7);
 
    cout << "Original Linked List\n";
    ll.print();
 
    ll.head = ll.reverse(ll.head);
 
    cout << "\nReversed Linked List \n";
    ll.print();
    return 0;
}
