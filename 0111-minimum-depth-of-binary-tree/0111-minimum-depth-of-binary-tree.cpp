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
private:
    int calc(TreeNode* root){
        if(root->right==NULL && root->left==NULL) return 1;
        int left=INT_MAX, right= INT_MAX;
        if(root->left) left= calc(root->left);
        if(root->right) right = calc(root->right);
        return min(left,right) + 1;
    }
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return calc(root);
    }
};