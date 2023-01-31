class Solution {
public:
    // This is a pretty simple question if you have to check the no of the edges e given
    // and no of components in the graph (can be count using BFS or DFS)
    // no check if c ==1 return 0; no need to remove the connections
    // if c != 1 && e>= (n-1) return c-1 only each componnet need to connect
    // else -1 no avilable extra cables
    int makeConnected(int n, vector<vector<int>>& connections) {
        map<int,set<int>>mp;
        for(int i = 0;i<connections.size();i++){
            mp[connections[i][0]].insert(connections[i][1]);
            mp[connections[i][1]].insert(connections[i][0]);
        }
        // let's find out total no of edges we have and total disconnected componnets
        int e = connections.size();
        // total no of disconnected components
        vector<bool>vis(n,false);
        int c = 0;
        for(int i = 0;i<n;i++){
            if(vis[i] ==  false){
                c++;
                queue<int>q;
                q.push(i);
                vis[i] = true;
                while(!q.empty()){
                    int f = q.front();q.pop();
                    for(auto it: mp[f]){
                        if(vis[it] ==  false){
                            q.push(it);
                            vis[it] = true;
                        }
                    }
                }
            }
        }
        if(c == 1){
            return 0;
        }
        else if(c != 1 && (e>=(n-1))){
            // c-1 extra edges are required
            return c-1;
        }
        return -1;
    }
};