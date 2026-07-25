class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>mp1;
        unordered_map<char, int>mp2;
        for(char i:t){
            mp1[i]++;
        }
        int k = mp1.size();
        int i=0, j=0, ans = INT_MAX;
        int form = 0;
        int start = 0;
        while(j<s.size()){
            mp2[s[j]]++;
            if(mp1.count(s[j]) && mp1[s[j]]==mp2[s[j]]){
                form++;
            }
            while(form==k){
                if(j-i+1 < ans){
                    ans = j-i+1;
                    start = i;
                }
                mp2[s[i]]--;
                if(mp1.count(s[i]) && mp2[s[i]]<mp1[s[i]]){
                    form--;
                }
                i++;
            }
            j++;
        }
        if(ans == INT_MAX) return "";
        return s.substr(start, ans);
    }
};
