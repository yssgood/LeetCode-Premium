class Twitter {
private:
    map<int,vector<pair<int,int>>> postMap; 
    map<int,set<int>> friendMap; 
    int globalTimeStamp = 0; 
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        postMap[userId].push_back({globalTimeStamp++,tweetId}); 
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq; 
        for(auto& p : postMap[userId]){
            pq.push(p); 
        }
        for(auto& it : friendMap[userId]){
            for(pair<int,int>& p : postMap[it]) pq.push(p); 
        }
        
        vector<int> answer; 
        vector<pair<int,int>> tmp; 
        while(!pq.empty()){
            answer.push_back(pq.top().second); 
            pq.pop(); 
            if(answer.size() >= 10) break; 
        }
        return answer; 
    }
    
    void follow(int followerId, int followeeId) {
        friendMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friendMap[followerId].erase(followeeId); 
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