class Solution {
private:
    class TrieNode{
    public:
        string word;
        TrieNode* alpha[26];
        TrieNode(){
            for(int i=0; i<26; i++) alpha[i]=nullptr;
            word = "";
        }
    };
    TrieNode* root;
    vector<string> result;
    void insert(string word){
        TrieNode* curr = root;
        for(char ch:word){
            int i = ch-'a';
            if(curr->alpha[i]==nullptr) curr->alpha[i]=new TrieNode();
            curr = curr->alpha[i];
        }
        curr->word = word;
    }
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node){
        char ch = board[r][c];
        int index = ch-'a';
        if(node->alpha[index]==nullptr) return;
        TrieNode* next = node->alpha[index];
        if(next->word!=""){
            result.push_back(next->word);
            next->word="";
        }
        board[r][c] = '#';
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        for(int k=0; k<4; k++){
            int nr = r+dr[k];
            int nc = c+dc[k];
            if(nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size() && board[nr][nc]!='#'){
                dfs(board, nr, nc, next);
            }
        }
        board[r][c] = ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for(string s:words){
            insert(s);
        }
        for(int r=0; r<board.size(); r++){
            for(int c=0; c<board[0].size(); c++){
                dfs(board, r, c, root);
            }
        }
        return result;
    }
};
