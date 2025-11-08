class HitCounter {
    Deque<int[]> dq = new LinkedList<>(); 

    public HitCounter() {
        
    }
    
    public void hit(int timestamp) {
        if(dq.isEmpty() || dq.peekLast()[0] != timestamp){
            dq.offer(new int[]{timestamp, 1});
        } else{
            dq.peekLast()[1]++; 
        }
    }
    
    public int getHits(int timestamp) {
        while(!dq.isEmpty() && timestamp - dq.peek()[0] >= 300){
            dq.poll(); 
        }
        int total = 0; 
        for(int[] pair : dq){
            total += pair[1]; 
        }
        return total; 
    }
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */