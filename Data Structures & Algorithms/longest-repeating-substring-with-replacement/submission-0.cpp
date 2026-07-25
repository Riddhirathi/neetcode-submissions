class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int res = 0;
        int i=0, j=0;
        int mx = 0;
        while(j<s.size()){
            mp[s[j]]++;
            mx = max(mx, mp[s[j]]);
            while(((j-i+1)-mx)>k){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            
            res = max(res, (j-i+1));
            j++;
        }
        return res;
    }
};
