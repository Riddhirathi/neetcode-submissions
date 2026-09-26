class Solution {
public:
    string longestPalindrome(string s) {
        int len=0, ind=0;
        int n=s.size();
        for(int i=0; i<s.size(); i++){
                int l=i, r=i;
                while(l>=0 && r<n && s[l]==s[r]){
                    if(r-l+1 > len){
                        len=r-l+1;
                        ind=l;
                    }
                    r++;
                    l--;
                }
            
                 l=i, r=i+1;
                while(l>=0 && r<n && s[l]==s[r]){
                    if(r-l+1 > len){
                        len=r-l+1;
                        ind=l;
                    }
                    r++;
                    l--;
                }
            
        }
        return s.substr(ind, len);
    }
};
