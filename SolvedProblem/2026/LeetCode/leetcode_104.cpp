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
    void visit_node(TreeNode* next)
    {
        visit_nodes_.push(next);
        if (max_depth_ < visit_nodes_.size())
            max_depth_ = visit_nodes_.size();

        return;
    }

    void dfs(TreeNode* cur) {

        visit_node(cur);

        if (cur->left != nullptr) { dfs(cur->left); };
        if (cur->right != nullptr) { dfs(cur->right); };

        visit_nodes_.pop();
        return;
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root);

        return max_depth_;
    }
private:
    std::stack<TreeNode*> visit_nodes_{};
    int max_depth_{};
};

/*

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // 1. 기저 조건(Base Case): 빈 노드에 도달하면 깊이는 0입니다.
        if (root == nullptr) {
            return 0;
        }

        // 2. 왼쪽 서브트리의 최대 깊이를 구합니다.
        int left_depth = maxDepth(root->left);

        // 3. 오른쪽 서브트리의 최대 깊이를 구합니다.
        int right_depth = maxDepth(root->right);

        // 4. 둘 중 더 큰 값에 현재 노드의 깊이(+1)를 더해서 반환합니다.
        return std::max(left_depth, right_depth) + 1;
    }
};

*/