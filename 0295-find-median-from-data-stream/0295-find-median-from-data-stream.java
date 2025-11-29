class MedianFinder {
    private PriorityQueue<Integer> maxQ; 
    private PriorityQueue<Integer> minQ; 
    public MedianFinder() {
        this.maxQ = new PriorityQueue<>(Collections.reverseOrder()); 
        this.minQ = new PriorityQueue<>(); 
    }
    
    public void addNum(int num) {
        //the rule of thumb : maxQ should stay 1 more than the minQ 
        if(maxQ.isEmpty() || maxQ.peek() >= num){
            maxQ.offer(num); 
            System.out.println(maxQ.size()); 
        } else{
            minQ.offer(num); 
        }

        if(maxQ.size() > minQ.size() + 1){
            minQ.offer(maxQ.poll()); 
        } else if(minQ.size() > maxQ.size()) {
            maxQ.offer(minQ.poll()); 
        }

        
    }
    
    public double findMedian() {
        if(maxQ.size() == minQ.size()){
            return (double)(maxQ.peek() + minQ.peek()) /2; 
        } 
        return (double) maxQ.peek(); 
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */