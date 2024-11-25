class Solution {
public:
    #define vi vector<vector<int>>
    #define pp pair<int,vi>
    int dx[4] =  {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int slidingPuzzle(vector<vector<int>>& board) {
        // we have to find the minimum number to solve this puzzles.
        int m = board.size();
        int n = board[0].size();
        vi ans = {{1,2,3},{4,5,0}};
        queue<pp>q;
        set<vi>st;
        st.insert(board);
        q.push({0,board});
        while(!q.empty()){
            int t = q.size();
            while(t--){
                pp f= q.front();q.pop();
                if(f.second == ans){
                    return f.first;
                }
                for(int i = 0;i<m;i++){
                    for(int j = 0;j<n;j++){
                        vi newv = f.second;
                        if(f.second[i][j] == 0){
                            for(int k = 0;k<4;k++){
                                int nx = i+dx[k];
                                int ny = j+dy[k];
                                if(nx>=0 && nx<m && ny>=0 && ny<n){
                                    swap(newv[i][j],newv[nx][ny]);
                                    if(st.count(newv) == false){
                                        st.insert(newv);
                                        q.push({f.first+1,newv});
                                    }
                                    swap(newv[i][j],newv[nx][ny]);
                                }
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};