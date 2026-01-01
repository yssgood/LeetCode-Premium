class Leaderboard {
    Map<Integer,Integer> leaderBoard; 
    public Leaderboard() {
        leaderBoard = new HashMap<>(); 
    }
    
    public void addScore(int playerId, int score) {
        leaderBoard.put(playerId, leaderBoard.getOrDefault(playerId,0) + score); 
    }
    
    public int top(int K) {
        int res = 0; 
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> b - a); 
        for(Map.Entry<Integer,Integer> entry : leaderBoard.entrySet()){
            pq.offer(entry.getValue()); 
        }
        while(K > 0){
            res += pq.poll(); 
            K--; 
        }
        return res; 
    }
    
    public void reset(int playerId) {
        leaderBoard.put(playerId,0); 
    }
}

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard obj = new Leaderboard();
 * obj.addScore(playerId,score);
 * int param_2 = obj.top(K);
 * obj.reset(playerId);
 */