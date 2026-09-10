class Solution {
public:

    int count = 0;

    pair<int,int> sol(TreeNode* root) {

        if(root == NULL)
            return {0, 0};

        pair<int,int> left = sol(root->left);
        pair<int,int> right = sol(root->right);

        int sum = root->val + left.first + right.first;
        int nodes = 1 + left.second + right.second;

        if(sum / nodes == root->val)
            count++;

        return {sum, nodes};
    }

    int averageOfSubtree(TreeNode* root) {

        sol(root);

        return count;
    }
};