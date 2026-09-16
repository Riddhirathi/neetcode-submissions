class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> graph (26);
        vector<int> indegree(26, 0);
        vector <bool> present (26, false);
        for(string & word : words){
            for(char c: word){
                present[c-'a'] = true;
            }
        }
        for(int i=0; i<words.size()-1; i++){
            string &word1 = words[i];
            string &word2 = words[i+1];
            int minlen = min(word1.size(), word2.size());
            int j=0;
            while(j<minlen && word1[j]==word2[j]){
                j++;
            }
            if(j==minlen && word1.size()>word2.size()) return "";
            if(j<minlen){
                int u = word1[j] - 'a';
                int v = word2[j] - 'a';
                bool alreadyExists = false;
                for(int x:graph[u]){
                    if(x==v){
                        alreadyExists = true;
                        break;
                    }
                }
                if(!alreadyExists) {
                    graph[u].push_back(v);
                    indegree[v]++;
                }
            }
        }

        queue<int>q;
        for(int i=0; i<26; i++){
            if(present[i] && indegree[i]==0){
                q.push(i);
            }
        }
        string result;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            result += char(u+'a');
            for(int v: graph[u]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }

        int totalCharacters = 0;
        for(bool x:present){
            if(x) totalCharacters++;
        }
        if(result.size() != totalCharacters) return "";
        return result;
    }
};
