class Twitter {
public:
#define pp pair<int,int>
    unordered_map<int,priority_queue<pp>>u_p; // user feed
    unordered_map<int,set<int>>u_f; // user follower.
    unordered_map<int,int>t_u;
    unordered_map<int,vector<pp>>u_t;
    int count = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        t_u[tweetId]=userId;
        u_t[userId].push_back({count,tweetId});
        // go in the follwers.
        u_f[userId].insert(userId);
        // each user is follower of himself.
        for(auto it: u_f[userId]){
            // int siz = u_p[it].size();
            // u_p[it].push_back(tweetId);
            // if(u_p[it].size() >10){
            //     u_p[it].pop_front();
            // // }
            // if(siz<10){
            //     u_p[it].push({count,tweetId});
            // }
            // else{
            //     u_p[it].pop();
                u_p[it].push({count,tweetId});
            // }
        }
        count++;
        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        int t= u_p[userId].size();
        vector<int>ans;
        vector<pp>v;
        while(t--){
            pp to = u_p[userId].top();
            u_p[userId].pop();
            if(ans.size()<10)
            ans.push_back(to.second);
            v.push_back(to);
        }
        for(auto it: v){
            u_p[userId].push(it);
        }
        // vector<int>ans(u_p[userId].begin(),u_p[userId].end());
        // reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        // if some one start followerng someone then we should show user.
        if(u_f[followeeId].count(followerId)){
            return;
        }
        u_f[followeeId].insert(followerId);
        for(auto it: u_t[followeeId]){
            // int siz = u_p[followerId].size();
            // if(siz<10){
            //     u_p[followerId].push(it);
            // }
            // else{
            //     if(it.first > u_p[followerId].top().first){
            //         u_p[followerId].pop();
            u_p[followerId].push(it);
            //     }
            // }
        }
        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        u_f[followeeId].erase(followerId);
        int t = u_p[followerId].size();
        vector<pp>v;
        while(t--){
            pp to = u_p[followerId].top();
            u_p[followerId].pop();
            if(t_u[to.second] != followeeId){
                // u_p[followerId].push_front(t);
                v.push_back(to);
            }
        }
        for(auto it: v){
            u_p[followerId].push(it);
        }
        return;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */