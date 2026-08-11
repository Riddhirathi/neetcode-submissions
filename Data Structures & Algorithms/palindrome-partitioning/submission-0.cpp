class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    bool pal(string s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void dfs(string s, int start){
        if(start==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=start; i<s.size(); i++){
            if(!pal(s, start, i)) continue;
            temp.push_back(s.substr(start, i-start+1));
            dfs(s, i+1);
            temp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return ans;
    }
};
