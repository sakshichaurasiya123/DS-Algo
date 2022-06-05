/*
This will return true,
IsSum will return true.
if: 
  for every node sum of left subtree and right subtree is equal to  root node.
else:
  It will return false;
 */


struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    pair<bool,int> isSumFast(Node* root){
        if(root==NULL){
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        
        if(root->left==NULL && root->right==NULL){
             pair<bool,int>p=make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int>left=isSumFast(root->left);
        pair<bool,int>right=isSumFast(root->right);
        
        bool l=left.first;
        bool r=right.first;
        bool data=root->data==left.second+right.second;
        pair<bool,int>ans;
        if(l && r && data)
        {
            ans.first=true;
            ans.second=2*root->data;
        }
        else
        {
            ans.first=false;
        }
        return ans;
        
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         return isSumFast(root).first;
    }
};
