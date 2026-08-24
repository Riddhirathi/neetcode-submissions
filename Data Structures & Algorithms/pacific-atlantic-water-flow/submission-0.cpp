class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        queue<pair<int,int>> pacificQ;
        queue<pair<int,int>> atlanticQ;
        for(int c=0; c<cols; c++){
            pacific[0][c] = true;
            pacificQ.push({0, c});
        }
        for(int r=0; r<rows; r++){
            pacific[r][0] = true;
            pacificQ.push({r, 0});
        }
        for(int c=0; c<cols; c++){
            atlantic[rows-1][c] = true;
            atlanticQ.push({rows-1, c});
        }
        for(int r=0; r<rows; r++){
            atlantic[r][cols-1] = true;
            atlanticQ.push({r, cols-1});
        }
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        while(!pacificQ.empty()){
            auto [r,c] = pacificQ.front();
            pacificQ.pop();
            for(int d=0; d<4; d++){
                int nr = r+dr[d];
                int nc = c+dc[d];
                if(nr<0 || nr>=rows || nc<0 || nc>=cols) continue;
                if(pacific[nr][nc]) continue;
                if(heights[nr][nc]<heights[r][c]) continue;
                pacific[nr][nc] = true;
                pacificQ.push({nr,nc});
            }
        }
        while(!atlanticQ.empty()){
            auto [r,c] = atlanticQ.front();
            atlanticQ.pop();
            for(int d=0; d<4; d++){
                int nr = r+dr[d];
                int nc = c+dc[d];
                if(nr<0 || nr>=rows || nc<0 || nc>=cols) continue;
                if(atlantic[nr][nc]) continue;
                if(heights[nr][nc]<heights[r][c]) continue;
                atlantic[nr][nc] = true;
                atlanticQ.push({nr,nc});
            }
        }
        vector<vector<int>> ans;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(pacific[r][c] && atlantic[r][c]) ans.push_back({r,c});
            }
        }
        return ans;
    }
};
