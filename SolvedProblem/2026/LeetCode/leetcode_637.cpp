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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result{};
        if (nullptr == root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int level_size = q.size();
            vector<int> current_level{};

            for (int i = 0; i < level_size; ++i)
            {
                auto node = q.front();
                q.pop();

                current_level.push_back(node->val);

                if (nullptr != node->left) q.push(node->left);
                if (nullptr != node->right) q.push(node->right);
            }

            double avg_level = accumulate(current_level.begin(), current_level.end(), 0.0) / current_level.size();
            result.push_back(avg_level);
        }
        return result;
    }
};