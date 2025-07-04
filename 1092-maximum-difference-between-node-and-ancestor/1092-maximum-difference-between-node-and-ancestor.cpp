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
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        int minVal=root->val,maxVal=root->val;
        differ(root,minVal,maxVal);
        return diff;
    }

private:
    int diff=0;
    void differ(TreeNode* root, int minVal, int maxVal){
        if(!root) return ;
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        diff=max(diff, maxVal-minVal);
        differ(root->left,minVal,maxVal);
        differ(root->right,minVal,maxVal);
    }
};