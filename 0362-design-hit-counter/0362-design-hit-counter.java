class HitCounter {
    Queue<Integer> q = new LinkedList<>();
    public HitCounter() {
        
    }
    
    public void hit(int timestamp) {
        q.add(timestamp); 
    }
    
    public int getHits(int timestamp) {
        while(!q.isEmpty() && timestamp - q.peek() >= 300){
            q.poll(); 
        }
        return q.size(); 
    }
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */