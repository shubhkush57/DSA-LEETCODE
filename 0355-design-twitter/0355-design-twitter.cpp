class Twitter {
public:
    #define pp pair<int,int>
    unordered_map<int,set<int>>followers;
    unordered_map<int,vector<pp>>tweets;
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time,tweetId});
        time++;
        
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<pp>pq;
        if(tweets.find(userId)!= tweets.end()){
            for(auto tweet: tweets[userId]){
                pq.push({tweet});
            }
        }
        for(auto followee: followers[userId]){
            if(tweets.find(followee) != tweets.end()){
                for(auto tweet: tweets[followee]){
                    pq.push({tweet});
                }
            }
           
        }
        while(!pq.empty() && ans.size()<10){
            auto tweet = pq.top();pq.pop();
            ans.push_back(tweet.second);
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
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