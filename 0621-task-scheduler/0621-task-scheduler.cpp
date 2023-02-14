class Solution {
public:
    #define pp pair<int,char>
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        int siz = tasks.size();
        unordered_map<char,int>mp;
        for(int i = 0;i<siz;i++){
            mp[tasks[i]]++;
        }
        // tasks Schedular
        priority_queue<pp>pq;
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            vector<pp>re;
            if(pq.size() > n){
                // cout<<"NOt here"<<endl;
                int resiz = n+1;
                while(resiz--){
                    pp our = pq.top();
                    pq.pop();
                    ans++;
                    our.first = our.first-1;
                    if(our.first != 0){
                        re.push_back(our);
                    }
                }
                for(auto it: re){
                    pq.push(it);
                }
                
            }
            else{
                // cout<<"Here"<<endl;
                int count = 0;
                while(!pq.empty()){
                    pp our = pq.top();
                    pq.pop();
                    count++;
                    ans++;
                    our.first = our.first-1;
                    if(our.first != 0){
                        re.push_back(our);
                    }
                }
                // cout<<n+1-count<<endl;
                for(auto it: re){
                    pq.push(it);
                }
                if(!pq.empty())
                ans += (n+1-count);
                
            }
        }
        return ans;
    }
};