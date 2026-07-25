class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        for(auto i:s1){
            v1[i-'a']++;
        }
        int k = s1.size();
        int i=0, j=0;
        while(j<s2.size()){
            v2[s2[j] - 'a']++;
            if((j-i+1)==k){
                if(v1==v2) return true;
                v2[s2[i]-'a']--;
                i++;
            }
            j++;
        }
        return false;
    }
};
