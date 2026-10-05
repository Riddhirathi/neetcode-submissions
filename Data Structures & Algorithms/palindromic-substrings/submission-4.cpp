class Solution {
public:
    void check(int i, int j, string &s, int& ans){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            ans++;
            i--;
            j++;
        }
    }
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            check(i,i,s,ans);
            check(i,i+1,s,ans);
        }
        return ans;
    }
};
