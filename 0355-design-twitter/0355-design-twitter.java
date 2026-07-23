class Twitter {

    class Tweet {
        int tweetId; 
        int time; 
        Tweet next; 
        public Tweet(int tweetId, int time){
            this.tweetId = tweetId;
            this.time = time; 
            this.next = null; 
        }
    }

    //Map<Integer,List<Integer>> tweetMap; 
    int time = 0; 
    Map<Integer, Tweet> tweetMap; 
    Map<Integer,Set<Integer>> followMap; 

    public Twitter() {
        tweetMap = new HashMap<>(); 
        followMap = new HashMap<>(); 
    }
    
    public void postTweet(int userId, int tweetId) {
        Tweet newTweet = new Tweet(tweetId,time++); 
        if(tweetMap.containsKey(userId)){
            Tweet curr = tweetMap.get(userId); 

            newTweet.next = curr; 
            //curr.next = newTweet; 
            tweetMap.put(userId, newTweet); 
            return; 
        }
        tweetMap.put(userId, newTweet); 
    }
    
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> answer = new ArrayList<>(); 
        PriorityQueue<Tweet> pq = new PriorityQueue<>((a,b) -> Integer.compare(b.time,a.time)); 

        if(tweetMap.containsKey(userId)) pq.offer(tweetMap.get(userId));

        if(followMap.containsKey(userId)){
            for(int followId : followMap.get(userId)){
                if(tweetMap.containsKey(followId)){
                    pq.offer(tweetMap.get(followId)); 
                }
            }
        }

        while(!pq.isEmpty() && answer.size() < 10){
            Tweet top = pq.poll(); 
            answer.add(top.tweetId);
            if(top.next != null) pq.offer(top.next);  
        }

        return answer; 
    }
    
    public void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return; 
        followMap.computeIfAbsent(followerId, k -> new HashSet<>()).add(followeeId); 
    }
    
    public void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return; 
        if(followMap.containsKey(followerId)){
            followMap.get(followerId).remove(followeeId); 
        }
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