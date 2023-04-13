class Solution {
    private: bool CheckCycle(int cur,vector<int> adj[],int v[]){
        v[cur]=1;
        queue<pair<int,int>> q;
        q.push({cur,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto p: adj[node]){
                if(!v[p]){
                    v[p]=1;
                    q.push({p,node});
                }else if(parent!=p){
                    return true;
                }
            }
        }
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int v[V]={0};
        for(int i=0;i<V;i++){
            if(!v[i]){
                
                if(CheckCycle(i,adj,v)==true){
                    return true;
                }
                
            }
            
        }
        return false;
    }
};