#include <cstring>;
class Solution {
public:
    int t[101];
    int solve(int i, string& s){
        int n = s.size();
        int ans = 0;
        if(t[i]!=-1) return t[i];
        if(i==n) return t[i] = 1;
        if(s[i]=='0') return t[i] = 0;
        int res = solve(i+1, s);
        if(i+1<n){
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6')){
                res += solve(i+2, s);
            }
        }
        return t[i] = res;
    }
    int numDecodings(string s) {
        memset(t, -1, sizeof(t));
        return solve(0, s);
    }
};
