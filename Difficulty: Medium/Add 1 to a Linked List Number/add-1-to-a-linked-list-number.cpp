/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  Node* reverse(Node* head){
      
      Node* prev=NULL;
      Node* curr=NULL;
      Node* forward=head;
      while(forward){
          curr=forward;
          forward=forward->next;
          curr->next=prev;
          prev=curr;
      }
      return prev;
      
  }
    Node* addOne(Node* head) {
        // Your Code here
        Node* rev=reverse(head);
        int carry=1;
        Node* temp=rev;
        Node* prev=rev;
        while(temp){
        carry=carry+temp->data;
        
        temp->data=carry%10;
        carry=carry/10;
        prev =temp;
        temp=temp->next;
        }
        if(carry){
            Node* n=new Node(carry);
            prev->next=n;
            n->data=carry;
            n->next=NULL;
            
        }
        Node* last=reverse(rev);
        return last;
        // return head of list after adding one
    }
};