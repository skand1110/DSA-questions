class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node*temp = head;
      Node*prev = NULL;
      Node*slow = head;
      Node*fast = head;
      
      while(fast && fast->next){
          prev = slow;
          slow = slow->next;
          fast = fast->next->next;
          if(slow == fast){
              while(slow != temp){
                  temp = temp->next;
                  prev = slow;
                  slow = slow->next;
              }
              prev->next = NULL;
          }
      }
    }
};
