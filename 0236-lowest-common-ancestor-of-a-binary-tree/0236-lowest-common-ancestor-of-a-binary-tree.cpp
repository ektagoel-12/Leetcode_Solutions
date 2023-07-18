/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recurLCA(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        
        if(root==NULL||root==p || root==q ) return root;
        TreeNode* lt=recurLCA(root->left,p,q);
        TreeNode* rt=recurLCA(root->right,p,q);
        if(lt==NULL) 
            return rt;
        else if(rt==NULL)
            return lt;
        else
        return root;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return recurLCA(root,p,q);
    }
};