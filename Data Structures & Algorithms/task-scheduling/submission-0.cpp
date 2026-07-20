class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        vector<char> processed;
        unordered_map<char, int> mp;
        for(char task: tasks){
            mp[task]++;
        }
        while(!mp.empty()){
            int maxi = -1;
            char ch = '#';
            for (auto i:mp){
                bool avai = true;
                for(int t=max(0, time-n); t<time; t++){
                    if(processed[t]==i.first){
                        avai = false;
                        break;
                    }
                }
                if(avai && i.second>maxi){
                    maxi = i.second;
                    ch = i.first;
                }
            }
            if(ch!='#'){
                processed.push_back(ch);
                mp[ch]--;
                if(mp[ch]==0) mp.erase(ch);
            }
            else{
                processed.push_back('#');
            }

            time++;
        }
        return time;
    }
};
