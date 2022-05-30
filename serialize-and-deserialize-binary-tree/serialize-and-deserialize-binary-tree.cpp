/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "";
        string ans="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*curr=q.front();
            q.pop();
            if(curr==NULL)
                ans+="N,";
            else ans+=to_string(curr->val)+",";
            if(curr){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="")
            return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            getline(s, str, ',');
            // cout<<str;
            if(str=="N"){
                curr->left=NULL;
            }else{
                TreeNode *left=new TreeNode(stoi(str));
                curr->left=left;
                q.push(left);
            }
            getline(s, str, ',');
            if(str=="N"){
                curr->right=NULL;
            }else{
                TreeNode *right=new TreeNode(stoi(str));
                curr->right=right;
                q.push(right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));