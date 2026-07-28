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
    // bool sol(TreeNode* root){
    //     if(root==NULL)return true;
    //    bool left= sol(root->left);
    //    bool right= sol(root->right);
    //     return left
    // }
    vector<int> inorderArr;
    void inorder(TreeNode* root){
        if(root==NULL)return;
        inorder(root->left);
        inorderArr.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(int i=1;i<inorderArr.size();i++){
            if(inorderArr[i-1]>=inorderArr[i])return false;
        }
        return true;
    }
};