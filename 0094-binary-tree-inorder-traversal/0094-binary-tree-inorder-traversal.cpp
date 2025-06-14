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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inOrder(root, res);
        return res;
    }

private:
    void inOrder(TreeNode* node, vector<int>& res) {
        if (node == NULL) return; // base case

        // inorder traversal = LNR
        inOrder(node->left, res); // recursive call for left
        res.push_back(node->val); // push node value
        inOrder(node->right, res); // recursive call for right
    }
};