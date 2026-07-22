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
    string serialize(TreeNode* root){
        if(root == nullptr) return "$#";
        return "$"+to_string(root->val) + serialize(root->left) + serialize(root->right);
    }
    vector<int> z_fn(string s){
        vector<int> z(s.length());
        int l=0, r=0, n = s.length();
        for(int i=1; i<n; i++){
            if(i<=r){
                z[i] = min(r-i+1, z[i-1]);
            }
            while(i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
            if(i+z[i]-1 > r){
                l = i;
                r = i+z[i]-1;
            }
        }
        return z;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string serial_root = serialize(root);
        string serial_sub = serialize(subRoot);
        string combined = serial_sub + "|" + serial_root;
        vector<int> z = z_fn(combined);
        int sub_len = serial_sub.length();
        for(int i=sub_len+1; i<combined.length(); i++){
            if(z[i]==sub_len) return true;;
        }
        return false;
    }
};
