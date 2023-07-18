class Solution {
public:
    void dfs(int node,vector<int> &vis, vector<int>adj[])
    {
        vis[node]=1;
        for(auto itr:adj[node])
        {
            if(!vis[itr])
            {
                dfs(itr,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<int>adj[V];
        //To change adjacency matrix to list
         for(int i = 0;i<V;i++) {
            for(int j = 0;j<V;j++) {
                // self nodes are not considered
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j); 
                    adj[j].push_back(i); 
                }
            }
        }
        vector<int>vis(V,0);
        int count=0;
         for(int i = 0;i<V;i++) {
            // if the node is not visited
            if(!vis[i]) {
                // counter to count the number of provinces 
                count++;
               dfs(i, vis,adj); 
            }
        }
        return count;
    }
};