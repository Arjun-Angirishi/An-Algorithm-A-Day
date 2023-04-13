public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initColor=image[sr][sc];
        vector<vector<int>>ans=image;
        pair<int,int> a[4]={{0,1},{0,-1},{1,0},{-1,0}};
        dfs(image,sr,sc,newColor,a,initColor,ans);
        return ans;
    }
private:
    void dfs(vector<vector<int>>& image,int sr,int sc,int newColor,pair<int,int> a[],int initColor,vector<vector<int>> &ans){
        ans[sr][sc]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=sr+a[i].first;
            int ncol=sc+a[i].second;
            if(nrow<n&&nrow>=0&&ncol<m&&ncol>=0&&ans[nrow][ncol]!=newColor&&image[nrow][ncol]==initColor){
                dfs(image,nrow,ncol,newColor,a,initColor,ans);
            }
        }
    }
};