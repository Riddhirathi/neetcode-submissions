#include <cstring>
class Solution {
public:
    int t[1001][1001];
    bool check(int i, int j, string& s){
        if(i>j) return true;
        if(t[i][j] != -1){
            return t[i][j];
        }
        if(s[i]==s[j]){
            t[i][j] = check(i+1, j-1, s);
        }
        else t[i][j] = false;
        return t[i][j];
    }
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        memset(t, -1, sizeof(t));
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check(i,j,s)) ans++;
            }
        }
        return ans;
    }
};
