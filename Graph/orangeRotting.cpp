    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue < pair < pair < int, int > , int >> q;
        int vis[n][m];
        int countone = 0;
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (grid[i][j] == 2) {
            q.push({{i, j}, 0}); 
            vis[i][j] = 2;
          }
          else {
            vis[i][j] = 0;
          }
          if (grid[i][j] == 1) countone++;
        }
        }
        int mintime=0;
        pair<int,int> a[]={{0,-1},{0,+1},{1,0},{-1,0}};
        int cnt = 0;
        while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        mintime = max(mintime, t);
        q.pop();
        for (int i = 0; i < 4; i++) {
          int nrow = r + a[i].first;
          int ncol = c + a[i].second;
          if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
             q.push({{nrow, ncol}, t + 1}); 
            vis[nrow][ncol] = 2;
            cnt++;
          }
        }
      }
      if (cnt != countone) return -1;
      return mintime;
    }