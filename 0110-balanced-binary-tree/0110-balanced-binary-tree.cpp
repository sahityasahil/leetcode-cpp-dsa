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
    bool isBalanced(TreeNode* root) {
        return height(root) != -1; // Tree is balanced if height doesn't return -1
    }
private:
    int height(TreeNode* root) {
        if (root == NULL) return 0; // Base case: empty tree has height 0

        int lh = height(root->left);
        if (lh == -1) return -1; // Left subtree is unbalanced

        int rh = height(root->right);
        if (rh == -1) return -1; // Right subtree is unbalanced

        // Check if current node is balanced
        if (abs(lh - rh) > 1) return -1; // unbalanced
        
        return max(lh, rh) + 1;
    }
};