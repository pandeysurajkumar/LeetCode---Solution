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
    TreeNode* dummy = new TreeNode(-1);
    TreeNode* prev = dummy;
    void inorder(TreeNode* root)
    {
        if(root==nullptr) return;
        inorder(root->left);
        prev->right = root;
        root->left = nullptr;
        prev = root;
        inorder(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return dummy->right;
    }
};