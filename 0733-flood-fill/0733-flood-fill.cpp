class Solution {
public:
    
    void dfs(vector<vector<int>>&v,int sr,int sc,int color,int ori,int delrow[],int delcol[])
    {
        int n= v.size();
        int m= v[0].size();
        v[sr][sc]=color;
        for(int i=0;i<4;i++)
        {
            int nrow=sr+delrow[i];
            int ncol=sc+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 
            && ncol<m && v[nrow][ncol]==ori && v[nrow][ncol]!=color)
            {
                dfs(v,nrow,ncol,color,ori,delrow,delcol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      
        int original=image[sr][sc];
        vector<vector<int>>v=image;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,+1,0,-1};
        dfs(v,sr,sc,color,original,delrow,delcol);
        return v;
    }
};