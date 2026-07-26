class SmallestInfiniteSet {

    PriorityQueue<Integer> minHeap; 
    Set<Integer> hashSet; 
    int nextInt = 1; 

    public SmallestInfiniteSet() {
        minHeap = new PriorityQueue<>(); 
        hashSet = new HashSet<>(); 
    }
    
    public int popSmallest() {
        if(!minHeap.isEmpty()){
            int min_ = minHeap.poll(); 
            if(hashSet.contains(min_)) hashSet.remove(min_); 
            return min_; 
        }
        return nextInt++; 
    }
    
    public void addBack(int num) {
        if(nextInt > num && !hashSet.contains(num)){
            hashSet.add(num); 
            minHeap.offer(num); 
        }
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet obj = new SmallestInfiniteSet();
 * int param_1 = obj.popSmallest();
 * obj.addBack(num);
 */