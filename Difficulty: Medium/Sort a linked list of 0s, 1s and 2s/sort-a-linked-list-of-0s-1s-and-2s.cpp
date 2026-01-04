class Solution {
public:
    Node* segregate(Node* head) {

               // next position for 1
        Node* n = head;             // iterator
        int countz=0;
        int counto=0;
        int countt=0;
        while (n) {

            if (n->data == 0) {
                countz++;
            }
            else if (n->data == 1) {
                counto++;
            }
            else{countt++; }
            

            n = n->next;
        }
        n=head;
        while(n){
            if(countz!=0){
                n->data=0;
                countz--;
            }
            else if(countz==0 && counto!=0){
                n->data=1;
                counto--;
            }
            else{
                n->data=2;
                countt--;
            }
            n=n->next;
        }
        

        return head;
    }
};
