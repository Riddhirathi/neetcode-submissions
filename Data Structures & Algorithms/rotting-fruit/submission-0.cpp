class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                if(grid[r][c]==2) q.push({r,c});
                if(grid[r][c]==1) fresh++;
            }
        }
        int mins = 0;
        int nr[] = {-1,1,0,0};
        int nc[] = {0,0,-1,1};
        while(!q.empty() && fresh>0){    
            int size = q.size();                
            for(int i=0; i<size; i++){
                auto [r,c] = q.front();
                q.pop();
                for(int d=0; d<4; d++){
                    int dr = r+nr[d];
                    int dc = c+nc[d];
                    if(dr<0 || dc<0 || dr>=n || dc>=m){
                        continue;
                    }
                    if(grid[dr][dc]!=1) continue;
                    grid[dr][dc]=2;
                    fresh--;
                    q.push({dr,dc});
                }
            }
            mins++;
        }
        if(fresh>0) return -1;
        return mins;
    }
};
