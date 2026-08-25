class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(!words.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        int length = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                string word = q.front();
                q.pop();
                for(int j=0; j<word.size(); j++){
                    char original = word[j];
                    for(char ch = 'a'; ch<='z'; ch++){
                        word[j] = ch;
                        if(word==endWord) return length+1;
                        if(words.count(word)){
                            q.push(word);
                            words.erase(word);
                        }
                    }
                    word[j] = original;
                }
            }
            length++;
        }
        return 0;
    }
};
