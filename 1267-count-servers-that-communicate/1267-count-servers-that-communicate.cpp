class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        vector<int>rCnt(n,0);
        vector<int>cCnt(m,0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) {
                    rCnt[i]++;
                    cCnt[j]++;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) {
                    if(rCnt[i] > 1 || cCnt[j] > 1){
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};