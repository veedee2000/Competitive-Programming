class Twitter {
public:
    /** Initialize your data structure here. */
    unordered_map<int,unordered_set<int>>following;
    unordered_map<int,vector<pair<int,int>>>tweets;
    int time = 0;
    
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId,time++});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    
    struct comp{
        bool operator()(vector<int>a,vector<int>b){
            return a[2] < b[2];
        }
    };
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>,vector<vector<int>>,comp>pq;
        
        if(tweets[userId].size()) pq.push({userId,(int) tweets[userId].size() - 1,tweets[userId][tweets[userId].size() - 1].second});
        
        for(auto people:following[userId]){
            if(tweets[people].size()) pq.push({people,(int) tweets[people].size() - 1,tweets[people][tweets[people].size() - 1].second});
        }
        
        int req = 10;
        vector<int>ans;
        
        while(!pq.empty() and req){
            vector<int>curr = pq.top();
            pq.pop();
            ans.push_back(tweets[curr[0]][curr[1]].first);
            
            if(curr[1] > 0) pq.push({curr[0],curr[1] - 1,tweets[curr[0]][curr[1] - 1].second});
            
            req--;
        }
        
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) following[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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
