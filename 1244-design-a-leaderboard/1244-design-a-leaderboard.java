class Leaderboard {
    private Map<Integer,Integer> hashMap; 
    public Leaderboard() {
        hashMap = new HashMap<>(); 
    }
    
    public void addScore(int playerId, int score) {
        hashMap.put(playerId, hashMap.getOrDefault(playerId,0) + score); 
    }
    
    public int top(int K) {
        TreeSet<Integer> playerList = new TreeSet<>((a,b) -> {
            //return hashMap.getOrDefault(b,0) - hashMap.getOrDefault(a,0); 
            int scoreDiff = hashMap.get(b) - hashMap.get(a); 
            if(scoreDiff != 0) return scoreDiff; 
            return a - b; 
        });
        for(int playerId : hashMap.keySet()){
            playerList.add(playerId); 
        }
        int sum = 0; 
        for(Integer vals : playerList){
            if(K > 0){
                //System.out.println(hashMap.get(vals)); 
                sum += hashMap.get(vals); 
            }
            K--; 
        }
        return sum; 
    }
    
    public void reset(int playerId) {
        hashMap.put(playerId,0); 
    }
}

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard obj = new Leaderboard();
 * obj.addScore(playerId,score);
 * int param_2 = obj.top(K);
 * obj.reset(playerId);
 */