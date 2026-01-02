class Twitter {
    class Tweet{
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
    
    Map<Integer, Set<Integer>> followerMap; 
    Map<Integer, LinkedList<Tweet>> tweetMap; 
    //Map<Integer, Tweet> tweetMap; 
    int globalTime; 

    public Twitter() {
        followerMap = new HashMap<>(); 
        tweetMap = new HashMap<>(); 
        globalTime = 1; 
    }
    
    public void postTweet(int userId, int tweetId) {
        Tweet newTweet = new Tweet(userId, tweetId, globalTime++); 
        if(tweetMap.containsKey(userId)){
            tweetMap.get(userId).addFirst(newTweet); 
            return; 
        }
        tweetMap.computeIfAbsent(userId, k -> new LinkedList<>()).add(newTweet); 
    }
    
    public List<Integer> getNewsFeed(int userId) {
        PriorityQueue<Tweet> pq = new PriorityQueue<>((a,b) -> b.globalTime - a.globalTime); 
        if(tweetMap.containsKey(userId)){
            LinkedList<Tweet> curr = tweetMap.get(userId); 
            for(Tweet t : curr) pq.offer(t);
        } 
        if(followerMap.containsKey(userId)){
            for(Integer ids : followerMap.get(userId)){
                if(tweetMap.containsKey(ids)){
                    for(Tweet t : tweetMap.get(ids)) pq.offer(t); 
                }
            }
        }

        List<Integer> res = new ArrayList<>(); 
        int K = 10; 
        while(K > 0 && pq.size() > 0){
            res.add(pq.poll().tweetId); 
            K--; 
        }
        return res; 
    }
    
    public void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return; 
        followerMap.computeIfAbsent(followerId, k -> new HashSet<>()).add(followeeId); 
    }
    
    public void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId || !followerMap.containsKey(followerId)) return; 
        followerMap.get(followerId).remove(followeeId); 
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