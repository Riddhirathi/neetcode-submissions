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
    vector<int> ds;
    void recur(TreeNode* root, int lvl){
        if(!root) return;
        
        if(lvl == ds.size()) ds.push_back(root->val);
        recur(root->right, lvl+1);
        recur(root->left, lvl+1); 
    }
    vector<int> rightSideView(TreeNode* root) {
        recur(root, 0);
        return ds;
    }
};
