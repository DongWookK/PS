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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;

        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }

        int remain_sum = targetSum - root->val;
        return hasPathSum(root->left, remain_sum) || hasPathSum(root->right, remain_sum);
    }
};