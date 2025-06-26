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
    bool helper(TreeNode* root, int* lower,int* upper){
        if(!root) return true;

        if(upper && root->val>=*upper) return false;
        if(lower && root->val<=*lower) return false;

        return helper(root->left,lower, &(root->val)) &&
        helper(root->right,&(root->val),upper);

    }
    bool isValidBST(TreeNode* root) {
        return helper(root,NULL,NULL);
    }
};