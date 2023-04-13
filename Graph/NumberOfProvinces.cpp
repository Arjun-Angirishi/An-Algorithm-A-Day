class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        int sz=adj[0].size();
        vector<int> adjLs[sz];
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                if(adj[i][j]==1&&i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int> v(sz,0);
        int ctr=0;
        for(int i=0;i<sz;i++){
            if(!v[i]){
                ctr++;
                dfs(i,adjLs,v);
            }
        }
        return ctr;
    }
    
    
    private:
    void dfs(int node,vector<int>adjLs[],vector<int> &v){
        v[node]=1;
        for(auto p: adjLs[node]){
            if(!v[p]){
                dfs(p,adjLs,v);
            }
        }
    }
};