class Solution {
public:
    /*
    void dfs(vector<vector<int>>&graph,vector<vector<int>>&ans,vector<int>re,int s,int d){
        if(s == d){
            ans.push_back(re);
            return;
        }
        for(auto it: graph[s]){
            vector<int> temp = re;
            re.push_back(it);
            dfs(graph,ans,re,it,d);
            re = temp;
        }
        return;
    }
    */
    void dfs(vector<vector<int>>&graph,vector<vector<int>>&ans,int s,int d,vector<int>&re){
        if(s == d){
            ans.push_back(re);
            return;
        }
        for(auto it: graph[s]){
            // vector<int>temp= re;
            re.push_back(it);
            dfs(graph,ans,it,d,re);
            re.pop_back();
            // re = temp;
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        /*
        vector<vector<int>>ans;
        int s =0;
        int d = graph.size()-1;
        vector<int>re;
        re.push_back(0);
        dfs(graph,ans,re,s,d);
        return ans;
        */
        vector<vector<int>>ans;
        int d = graph.size()-1;
        int s = 0;
        vector<int>re;
        re.push_back(0);
        // map already been constructed
        dfs(graph,ans,s,d,re);
        return ans;
    }
};