class HitCounter {
    class Pair{
        int time; 
        int numHits; 
        public Pair(int time, int numHits){
            this.time = time;
            this.numHits = numHits; 
        }
    }

    private Queue<Pair> q; 
    int size = 0; 

    public HitCounter() {
        this.q = new LinkedList<>(); 
    }
    
    public void hit(int timestamp) {
        size++; 
        if(!q.isEmpty() && q.peek().time == timestamp){
            q.peek().numHits++; 
            return; 
        } 
        q.add(new Pair(timestamp,1)); 
    }
    
    public int getHits(int timestamp) {
        while(!q.isEmpty() && timestamp - q.peek().time >= 300){
            size -= q.peek().numHits; 
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