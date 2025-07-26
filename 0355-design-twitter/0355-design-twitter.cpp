class Twitter {
private: 
    struct Tweet{
        int time; 
        int tweetId; 
        Tweet* next; 
        Tweet(int time, int tweetId, Tweet* next){
            this->time = time;
            this->tweetId = tweetId; 
            this->next = next; 
        }
    };

    struct FollowNode{
        int userId; 
        FollowNode* next; 
        FollowNode(int userId, FollowNode* next){
            this->userId = userId;
            this->next = next; 
        }
    };

    int globalTime = 0; 

    map<int,Tweet*> tweetMap; 
    map<int,FollowNode*> followMap; 
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        if(!tweetMap.count(userId) || tweetMap[userId] == nullptr){
            Tweet* tweet = new Tweet(globalTime++, tweetId, nullptr); 
            tweetMap[userId] = tweet; 
            return; 
        }

        Tweet* newTweet = new Tweet(globalTime++, tweetId, nullptr); 
        // Find the LAST node
        Tweet* curr = tweetMap[userId];
        while (curr->next != nullptr) {  // Go to tail
            curr = curr->next;
        }
        curr->next = newTweet;  // Add at tail

        // this code overwrites and lose the middle one 
        // Tweet* tweet = new Tweet(globalTime++, tweetId, nullptr); 
        // Tweet* curr = tweetMap[userId]; 
        // curr->next = tweet; 

    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq; 
        vector<int> answer; 

        Tweet* curr = tweetMap[userId]; 
        while(curr != nullptr){
            pq.push({curr->time, curr->tweetId}); 
            curr = curr->next; 
        }

        FollowNode* curr2 = followMap[userId]; 
        while(curr2 != nullptr){ //traverse friends 
            Tweet* nextTweet = tweetMap[curr2->userId]; //traverse friends tweet 
            while(nextTweet != nullptr){
                pq.push({nextTweet->time,nextTweet->tweetId}); 
                nextTweet = nextTweet->next; 
            }

            curr2 = curr2->next; 
        }

        while(!pq.empty() && answer.size() < 10){
            answer.push_back(pq.top().second);
            pq.pop(); 
        }



        return answer; 
    }
    
    void follow(int followerId, int followeeId) {
        if(!followMap.count(followerId) || followMap[followerId] == nullptr){
            FollowNode* newFollow = new FollowNode(followeeId, nullptr); 
            followMap[followerId] = newFollow;
            return; 
        }

        //duplicate case consideration 
        FollowNode* curr_dup = followMap[followerId];
        while(curr_dup != nullptr) {
            if(curr_dup->userId == followeeId) {
                return; // Already following, don't add duplicate
            }
            curr_dup = curr_dup->next;
        }


        FollowNode* newFollow = new FollowNode(followeeId, nullptr); 
        FollowNode* curr = followMap[followerId]; 
        // FIX: Find the actual tail
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newFollow; 
    }
    
    void unfollow(int followerId, int followeeId) {
        if(!followMap.count(followerId)){
            return; 
        }

        FollowNode* curr = followMap[followerId]; 
        if(curr == nullptr) return; 

        //handle header case 
        if(curr->userId == followeeId){
            //curr->next = curr->next->next;
            followMap[followerId] = curr->next;
            //curr = curr->next;
            //delete curr; 
            return; 
        }

        while(curr->next != nullptr){
            if(curr->next->userId == followeeId){
                curr->next = curr->next->next; 
                return; 
            }
            curr = curr->next; 
        }

        //no ones been found 
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