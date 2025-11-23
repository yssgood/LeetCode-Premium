class HitCounter {
    class Pair{
        int time; 
        int hits; 
        public Pair(int time, int hits){
            this.time = time;
            this.hits = hits; 
        }
    }

    private Queue<Pair> q = new LinkedList<>(); 
    int size = 0; 

    public HitCounter() {
        
    }
    
    public void hit(int timestamp) {
        size++; 
        if(!q.isEmpty() && q.peek().time == timestamp){
            q.peek().hits++; 
        } else{
            q.offer(new Pair(timestamp, 1)); 
        }
    }
    
    public int getHits(int timestamp) {
        while(!q.isEmpty() && timestamp - q.peek().time >= 300){
            size -= q.peek().hits; 
            q.poll(); 
        }
        return size; 
    }
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */