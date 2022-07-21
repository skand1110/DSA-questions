//approach: using two pointers
//tc: O(n); sc: O(1)

/* A linked list node */
class Node 
{ 
    public:
    int data; 
    Node *next; 
}; 
  
/* We are using a double pointer
head_ref here because we change 
head of the linked list inside 
this function.*/
void moveToFront(Node **head_ref) 
{ 
    /* If linked list is empty, or 
    it contains only one node, 
    then nothing needs to be done,
    simply return */
    if (*head_ref == NULL || (*head_ref)->next == NULL) 
        return; 
  
    /* Initialize second last
    and last pointers */
    Node *secLast = NULL; 
    Node *last = *head_ref; 
  
    /*After this loop secLast contains
    address of second last node and 
    last contains address of last node in Linked List */
    while (last->next != NULL) 
    { 
        secLast = last; 
        last = last->next; 
    } 
  
    /* Set the next of second last as NULL */
    secLast->next = NULL; 
  
    /* Set next of last as head node */
    last->next = *head_ref; 
  
    /* Change the head pointer
    to point to last node now */
    *head_ref = last; 
} 
  
