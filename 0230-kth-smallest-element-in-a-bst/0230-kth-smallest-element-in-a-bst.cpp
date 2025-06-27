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
    void inOrder(TreeNode* root,int k,vector<int>&ans){
        if(!root|| ans.size()>k) return;
        inOrder(root->left,k,ans);
        if(ans.size()<k){
            ans.push_back(root->val);
        }
        inOrder(root->right,k,ans);

    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        inOrder(root,k,ans);
        return ans.back();
    }
};