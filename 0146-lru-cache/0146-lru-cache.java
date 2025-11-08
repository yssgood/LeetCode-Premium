class Node {
    int key; 
    int value;  
    Node next;  
    Node prev; 
    public Node(int key, int value){
        this.key = key;
        this.value = value; 
        next = null; 
        prev = null; 
    }
}
class LRUCache {
    int cap = 0; 
    int size = 0; 
    Map<Integer, Node> hashMap = new HashMap<>(); 
    Node header = new Node(-1,-1); 
    Node trailer = new Node(-1,-1); 
    public LRUCache(int capacity) {
        cap = capacity; 
        header.next = trailer;
        trailer.prev = header; 
    }
    
    public int get(int key) {
        if(!hashMap.containsKey(key)) return -1; 

        Node currCache = hashMap.get(key); 

        currCache.next.prev = currCache.prev; 
        currCache.prev.next = currCache.next; 

        currCache.next = header.next; 
        header.next.prev = currCache; 

        currCache.prev = header; 
        header.next = currCache; 

        
        hashMap.put(key, currCache); 
        return currCache.value; 
    }
    
    public void put(int key, int value) {
        Node newCache = new Node(key,value);
        if(!hashMap.containsKey(key)){
            size++; 
            if(size > cap){
                Node lru = trailer.prev; 
                lru.prev.next = lru.next; 
                lru.next.prev = lru.prev; 
                hashMap.remove(lru.key); 
                size--; 
            }
            newCache.next = header.next; 
            header.next.prev = newCache; 

            newCache.prev = header; 
            header.next = newCache; 
            hashMap.put(key, newCache); 
        } else{
            Node currCache = hashMap.get(key); 
            currCache.value = value; 
            currCache.prev.next = currCache.next; 
            currCache.next.prev = currCache.prev; 

            currCache.next = header.next; 
            header.next.prev = currCache; 

            currCache.prev = header; 
            header.next = currCache; 

            hashMap.put(key, currCache); 
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */