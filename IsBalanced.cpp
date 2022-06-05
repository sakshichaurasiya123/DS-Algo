/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL)
            return 1;
        int l=height(root->left);
        int r=height(root->right);
        return (max(l,r)+1);
    }
    
    pair<bool,int> balencedFast(TreeNode* root){
        if(root==NULL)
        {
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        pair<bool,int>l=balencedFast(root->left);
        pair<bool,int>r=balencedFast(root->right);
        bool left=l.first;
        bool right=r.first;
        bool diff=(abs(l.second-r.second))<=1;
        pair<bool,int>ans;
        if(left && right && diff)
            ans.first=1;
        else
            ans.first=0;
        ans.second=max(l.second,r.second)+1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        
    //o(n) time complexity
      
        pair<bool,int>result=balencedFast(root);
        return result.first;
        
        //O(n^2) time complexity
       /* bool l=isBalanced(root->left);
        bool r=isBalanced(root->right);
        bool diff=abs((height(root->left) - height(root->right)))<=1;
        if(diff && l && r)
            return true;
        return false;
        */
    }
};
