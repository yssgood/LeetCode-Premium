class MyCircularQueue {

    int[] cirCularQ; 
    int size; 
    int maxSize; 
    int frontIndex; 
    int rearIndex; 
    int lastNum = -1; 
    int firstNum = -1; 

    public MyCircularQueue(int k) {
        cirCularQ = new int[k]; 
        size = 0; 
        frontIndex = 0; 
        rearIndex = 0; 
        maxSize = k; 
        Arrays.fill(cirCularQ,-1); 
    }
    
    public boolean enQueue(int value) {
        if(isFull()) return false; 
        cirCularQ[rearIndex] = value;  
        lastNum = cirCularQ[rearIndex]; 
        if(firstNum == -1) firstNum = lastNum; 
        rearIndex = (rearIndex + 1) % maxSize;
        size++; 
        return true; 
    }
    
    public boolean deQueue() {
        if(isEmpty()) return false; 
        cirCularQ[frontIndex] = -1; 
        frontIndex = (frontIndex + 1) % maxSize; 
        firstNum = cirCularQ[frontIndex]; 
        size--; 
        return true; 
    }
    
    public int Front() {
        if(isEmpty()) return -1; 
        return firstNum; 
    }
    
    public int Rear() {
        if(isEmpty())  return -1; 
        return lastNum; 
    }
    
    public boolean isEmpty() {
        return size == 0; 
    }
    
    public boolean isFull() {
        return size >= maxSize; 
    }
}


/* 

[1,2,3] 
 enqueue: 
 rearIndex = 1 -> 2 -> 0
 dequeue: 
 frontINdex = 

 index % maxSize 
 size = 0 

*/ 

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */