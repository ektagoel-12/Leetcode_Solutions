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
    void good(TreeNode* root,int maxnum,int &count){
        if(!root) return;
        if(root->val>=maxnum){
            count++;
            maxnum=root->val;
            cout<<root->val<<" ";
        }
        good(root->left,maxnum,count);
        good(root->right,maxnum,count);
    }
    int goodNodes(TreeNode* root) {
        int maxnum=INT_MIN;
        int count=0;
        good(root,maxnum,count);
        return count;
    }
};