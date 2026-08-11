class Solution {
public:
    vector<string> ans;
    string temp;
    vector<string> mp = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };
    void dfs(string& digits, int i){
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }
        string letter = mp[digits[i]-'0'];
        for(char c:letter){
            temp.push_back(c);
            dfs(digits, i+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        dfs(digits, 0);
        return ans;
    }
};
