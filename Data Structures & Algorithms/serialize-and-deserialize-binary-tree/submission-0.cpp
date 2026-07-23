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

class Codec {
public:
    vector<string> split(const string& s, char delim){
        vector<string> ele;
        stringstream ss(s);
        string item;
        while(getline(ss, item, delim)){
            ele.push_back(item);
        }
        return ele;
    }
    string join(const vector<string>& v, const string& delim){
        ostringstream s;
        for(auto& i : v){
            if(&i != &v[0]) s<< delim;
            s<<i;
        }
        return s.str();
    }

    void dfsse(TreeNode* node, vector<string>& res){
        if(!node){
            res.push_back("N");
            return;
        }
        res.push_back(to_string(node->val));
        dfsse(node->left, res);
        dfsse(node->right, res);
    }
    TreeNode* dfsdese(vector<string>& vals, int& i){
        if(vals[i] == "N"){
            i++;
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;
        node->left = dfsdese(vals, i);
        node->right = dfsdese(vals, i);
        return node;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsse(root, res);
        return join(res, ",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data, ',');
        int i=0;
        return dfsdese(vals, i);
    }
};
