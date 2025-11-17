class Cache {
    int key; 
    int value; 
    Cache next, prev; 
    public Cache(int key, int value){
        this.key = key;
        this.value = value; 
        this.next = null;
        this.prev = null; 
    }
}
class LRUCache {

    Cache header; 
    Cache trailer; 
    int size = 0; 
    int capacity = 0; 

    Map<Integer, Cache> hashMap = new HashMap<>(); 

    public LRUCache(int capacity) {
        this.header = new Cache(-1,-1); 
        this.trailer = new Cache(-1,-1); 
        this.capacity = capacity; 
        header.next = trailer; 
        trailer.prev = header; 
    }
    
    public int get(int key) {
        if(!hashMap.containsKey(key)) return -1; 

        Cache target = hashMap.get(key); 

        //update that its been used 
        target.prev.next = target.next;
        target.next.prev = target.prev; 

        target.next = header.next;
        target.prev = header; 
        header.next.prev = target;
        header.next = target; 

        hashMap.put(key, target); 

        return target.value; 
    }
    
    public void put(int key, int value) {
        if(hashMap.containsKey(key)){
            Cache target = hashMap.get(key); 
            target.value = value; 

            //update that its been used; 
            target.prev.next = target.next;
            target.next.prev = target.prev; 

            target.next = header.next;
            target.prev = header; 
            header.next.prev = target;
            header.next = target; 

            hashMap.put(key, target); 
            return; 
        }

        Cache newCache = new Cache(key,value); 
        if(size >= capacity){
            Cache lru = trailer.prev; 
            lru.prev.next = lru.next; 
            lru.next.prev = lru.prev;  
            hashMap.remove(lru.key); 
            size--; 
        }

        size++; 
        newCache.next = header.next; 
        newCache.prev = header;  
        header.next.prev = newCache;
        header.next = newCache; 
        hashMap.put(key, newCache); 
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */