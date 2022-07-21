//approach 1: using two loops
//tc: O(n^2); sc: O(1)

#include<iostream>
using namespace std;

struct node{
  int data;
  struct node* next;
}

void removeDuplicates(struct Node* start)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;
 
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
 
        /* Compare the picked element with rest
           of the elements */
        while (ptr2->next != NULL) {
            /* If duplicate then delete it */
            if (ptr1->data == ptr2->next->data) {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

//------------------------------------------------------------------
//approach 2: using merge sort for linked list then use the same process as for removing duplicates from sorted linked list
//tc: O(nlogn); sc: O(1)

//-------------------------------------------------------------------
//approach 3: using hashing
//tc: O(n); sc: O(n)

struct node{
 int data;
  struct node* next;
}

void removeDuplicates(struct node* head){
  //hashmap to store seen values
 unordered_set<int> seen;
  struct node* curr = head;
  struct node* prev = NULL;
  while(curr!= NULL){
    if(seen.find(curr->data)!=seen.end()){
     prev->next = curr->next;
      delete(curr);
    }
    else{
      seen.insert(curr->data);
      prev = curr;
       }
       curr = prev->next;
  }
}
