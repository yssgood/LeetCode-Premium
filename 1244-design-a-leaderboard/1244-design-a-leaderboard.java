class Leaderboard {
    private Map<Integer,Integer> hashMap; 
    public Leaderboard() {
        hashMap = new HashMap<>(); 
    }
    
    public void addScore(int playerId, int score) {
        hashMap.put(playerId, hashMap.getOrDefault(playerId,0) + score); 
    }
    
    public int top(int K) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder()); 

        for(int scores : hashMap.values()){
            pq.offer(scores); 
        }
        int sum = 0; 
        while(K > 0){
            sum += pq.poll(); 
            K--; 
        }
        return sum; 
    }
    
    public void reset(int playerId) {
        hashMap.remove(playerId); 
    }
}

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard obj = new Leaderboard();
 * obj.addScore(playerId,score);
 * int param_2 = obj.top(K);
 * obj.reset(playerId);
 */