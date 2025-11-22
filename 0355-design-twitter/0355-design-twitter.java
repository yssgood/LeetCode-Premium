class Twitter {
    class Tweet {
        int userId, tweetId; 
        int globalTime; 
        Tweet next; 
        public Tweet(int userId, int tweetId, int globalTime){
            this.userId = userId; 
            this.tweetId = tweetId; 
            this.globalTime = globalTime; 
        }
    }

    Map<Integer,Tweet> hashMap; 
    Map<Integer,Set<Integer>> followMap; 
    int globalTime = 0; 

    public Twitter() {
        this.hashMap = new HashMap<>(); 
        this.followMap = new HashMap<>(); 
    }
    
    public void postTweet(int userId, int tweetId) {
        Tweet newTweet = new Tweet(userId, tweetId, globalTime++); 
        if(!hashMap.containsKey(userId)){
            hashMap.put(userId, newTweet); 
            return;  
        }
        Tweet oldTweet = hashMap.get(userId); 
        newTweet.next = oldTweet; 
        hashMap.put(userId, newTweet); 
    }
    
    public List<Integer> getNewsFeed(int userId) {
        PriorityQueue<Tweet> pq = new PriorityQueue<>((a,b) -> b.globalTime - a.globalTime); 
        Tweet target = hashMap.get(userId); 
        List<Integer> answer = new ArrayList<>(); 
        //if(target == null) return answer; 
        if(target != null) pq.offer(target); 
        if(followMap.containsKey(userId)){
            for(int followers : followMap.get(userId)){
                if(hashMap.containsKey(followers)){
                    pq.offer(hashMap.get(followers)); 
                }
            }
        }

        int K = 10; 
        while(!pq.isEmpty() && K > 0){
            Tweet curr = pq.poll(); 
            answer.add(curr.tweetId); 
            if(curr.next != null){
                pq.offer(curr.next); 
            }
            K--; 
        }

        return answer;
    }
    
    public void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return; 
        followMap.computeIfAbsent(followerId, k -> new HashSet<>()).add(followeeId); 
    }
    
    public void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId || !followMap.containsKey(followerId)) return; 
        followMap.get(followerId).remove(followeeId); 
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