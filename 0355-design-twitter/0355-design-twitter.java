class Tweet {
    int userId; 
    int tweetId; 
    int globalTime;
    Tweet next; 
    public Tweet(int userId, int tweetId, int globalTime){
        this.userId = userId; 
        this.tweetId = tweetId; 
        this.globalTime = globalTime; 
        this.next = null;
    } 
}
class Twitter {
    int globalTime = 0; 
    Map<Integer,Tweet> hashMap = new HashMap<>(); 
    Map<Integer,Set<Integer>> friendMap = new HashMap<>(); 
    public Twitter() {
        
    }
    
    public void postTweet(int userId, int tweetId) {
        Tweet newTweet = new Tweet(userId, tweetId, globalTime++); 
        if(!hashMap.containsKey(userId)){
            hashMap.put(userId, newTweet); 
            return; 
        }

        Tweet curr = hashMap.get(userId); 
        newTweet.next = curr; 
        hashMap.put(userId, newTweet); 
    }
    
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> feeds = new ArrayList<>(); 
        PriorityQueue<Tweet> pq = new PriorityQueue<>((a,b) -> b.globalTime - a.globalTime); 
        Tweet curr = hashMap.get(userId); 
        if(curr != null) pq.offer(curr);
        if(friendMap.containsKey(userId)){
            for(int friends : friendMap.get(userId)){
                if(hashMap.containsKey(friends)) pq.offer(hashMap.get(friends)); 
            }
        }

        int k = 10; 
        while(!pq.isEmpty() && k > 0){
            Tweet top = pq.poll(); 
            feeds.add(top.tweetId); 
            k--; 
            if(top.next != null){
                pq.offer(top.next); 
            }
        }

        return feeds; 
    }
    
    public void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return; 
        friendMap.computeIfAbsent(followerId, k -> new HashSet<>()).add(followeeId); 
    }
    
    public void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId || !friendMap.containsKey(followerId)) return; 
        friendMap.get(followerId).remove(followeeId); 
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */


 /*

postTweet -> using linked list it gives O(1) 

follow -> gives O(1) 
unofllow -> gives O(1)

 */ 