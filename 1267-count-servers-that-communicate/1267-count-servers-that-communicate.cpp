class Solution {
public:
//     void makeset(vector<vector<int>>&grid,vector<vector<pair<int,int>>>&parent){
//         int m = grid.size();
//         int n = grid[0].size();
//         for(int i = 0;i<m;i++){
//             for(int j = 0;j<n;j++){
//                 parent[i][j] = {i,j};
//             }
//         }
//         return;
//     }
//     pair<int,int> findParent(vector<vector<pair<int,int>>>&parent,pair<int,int>node){
//         if(node == parent[i][j]){
//             return node;
//         }
//         return parent[node.first][node.second] = findParent(parent,parent[node.first][node.second]);
//     }
//     void unionF(pair<int,int>node1,pair<int,int>node2,vector<vector<pair<int,int>>>&parent,vector<vector<int>>rank){
//         node1 = parent[node1.first][node1.second];
//         node2 = parent[node2.first][node2.second];
//         if(rank[node1.first][node1.second]< rank[node2.first][node2.second]){
//             parent[node1.first][node1.second] = node2;
//             rank[node1.first][node1.second]++;
//         }
//         else if(rank[node2.first][node2.second]< rank[node1.first][node1.second]){
//             parent[node2.first][node2.second] = node1;
//             rank[node2.first][node2.second]++;

//         }
//         else{
//             parent[node2.first][node2.second] = node1;
//             rank[node2.first][node2.second]++;
//         }
//     }
//     bool isDisjoin(pair<int,int>p1,pair<int,int>p2){
//         p1 = parent[p1.first][p1.second];
//         p2 = parent[p2.first][p2.second];
//         return !(p1 == p2)
//     }
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<pair<int,int>>>parent(m,vector<pair<int,int>>(n));
        // vector<vector<int>>rank(m,vector<int>(n,0));
        // makeset(grid,parent);
        vector<vector<int>>vis(m,vector<int>(n,false));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    for(int k = 0;k<m;k++){
                        if(k != i){
                            if(grid[k][j] == 1){
                                vis[k][j] = true;
                                vis[i][j] = true;
                            }
                        }
                    }
                    for(int k = 0;k<n;k++){
                        if(k != j){
                            if(grid[i][k] == 1){
                                vis[i][k] = true;
                                vis[i][k] = true;
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                // cout<<vis[i][j]<<' ';
                if(vis[i][j] == true){
                    ans++;
                }
            }
            // cout<<endl;
        }
        return ans;
    }
};