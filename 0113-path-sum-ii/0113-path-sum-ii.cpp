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
    vector<vector<int>> ans;
    vector<int> temp;
    void sol(TreeNode* root,int targetSum){
        if(root==NULL)return;
        if(!root->left && !root->right){
         if(targetSum==root->val){
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
         }
         return;
        }
        temp.push_back(root->val);
        sol(root->left,targetSum-root->val);
        // temp.pop_back();
        // temp.push_back(root->val);
        sol(root->right,targetSum-root->val);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        sol(root,targetSum);
        return ans;
    }
};