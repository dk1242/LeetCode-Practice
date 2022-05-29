/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* prev=q.front();
            q.pop();
            int sz=q.size();
            // cout<<prev->val;
            if(prev->left)
                q.push(prev->left);
            if(prev->right)
                q.push(prev->right);
            for(int i=0;i<sz;i++){
                Node* curr=q.front();
                // cout<<curr->val;
                q.pop();
                prev->next=curr;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                if(curr){
                    prev=curr;
                }
            }
            prev->next=NULL;
        }
        // cout<<root->val;
        return root;
    }
};