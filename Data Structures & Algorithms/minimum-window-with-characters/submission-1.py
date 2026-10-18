class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t:
            return ""
        countt, window = {}, {}
        for c in t:
            countt[c] = 1 + countt.get(c, 0)
        have = 0
        need = len(countt)
        res = [-1, -1]
        reslen = float("inf")
        l=0
        for r in range(len(s)):
            c = s[r]
            window[c] = 1+window.get(c, 0)
            if c in countt and window[c]==countt[c]:
                have+=1
            while have==need:
                if (r-l+1)<reslen:
                    reslen = r-l+1
                    res = [l, r]
                window[s[l]]-=1
                if s[l] in countt and window[s[l]]<countt[s[l]]:
                    have-=1
                l+=1
        if reslen == float("inf"):
            return ""
        return s[res[0]:res[1]+1]