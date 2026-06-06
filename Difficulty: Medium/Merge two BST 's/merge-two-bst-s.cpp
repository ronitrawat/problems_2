/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:

    vector<int> merge(Node *root1, Node *root2) {

        vector<int> ans;

        stack<Node*> s1, s2;

        Node* a = root1;
        Node* b = root2;

        while (1) {

            while (a) {
                s1.push(a);
                a = a->left;
            }

            while (b) {
                s2.push(b);
                b = b->left;
            }

            // both empty
            if (s1.empty() && s2.empty())
                break;

            // if s2 empty OR s1 smaller
            if (s2.empty() || (!s1.empty() &&
                s1.top()->data <= s2.top()->data)) {

                Node* n1 = s1.top();
                s1.pop();

                ans.push_back(n1->data);

                a = n1->right;
            }

            else {

                Node* n2 = s2.top();
                s2.pop();

                ans.push_back(n2->data);

                b = n2->right;
            }
        }

        return ans;
    }
};