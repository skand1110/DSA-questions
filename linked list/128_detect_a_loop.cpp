//approach using tortoise hare algo

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

  
class Solution
{
    public:
    //Function to check if the linked list has a loop.
        bool detectLoop(Node* head)
    {
        if(head == NULL){
            return 0;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                return 1;
            }
        }
        return 0;
    }
    
};
