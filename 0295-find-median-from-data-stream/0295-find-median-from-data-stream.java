class MedianFinder {

    PriorityQueue<Integer> minHeap = new PriorityQueue<>(); 
    PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder()); 

    public MedianFinder() {
        
    }
    
    public void addNum(int num) {
        if(maxHeap.isEmpty() || maxHeap.peek() >= num){
            maxHeap.offer(num); 
        } else{
            minHeap.offer(num); 
        }

        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.offer(maxHeap.poll());   // ✔ 방향 올바름
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.offer(minHeap.poll());
        }
    }
    
    public double findMedian() {
        if(maxHeap.size() == minHeap.size()){
            return (double)(maxHeap.peek() + minHeap.peek()) / 2; 
        } else{
            return maxHeap.peek(); 
        }
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */