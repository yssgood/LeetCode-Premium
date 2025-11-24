class LRUCache {
    class Cache{
        int key, value; 
        Cache next, prev; 
        public Cache(int key, int value){
            this.key = key;
            this.value = value; 
        }
    }

    Cache header = new Cache(-1,-1); 
    Cache trailer = new Cache(-1,-1); 
    Map<Integer, Cache> hashMap = new HashMap<>(); 
    int size = 0; 
    int capacity = 0; 

    public LRUCache(int capacity) {
        this.capacity = capacity; 
        header.next = trailer;
        trailer.prev = header; 
    }
    
    public int get(int key) {
        if(!hashMap.containsKey(key)) return -1; 
        
        Cache target = hashMap.get(key); 

        target.prev.next = target.next;
        target.next.prev = target.prev; 

        target.next = header.next; 
        target.prev = header; 
        header.next.prev = target; 
        header.next = target; 

        return target.value; 
    }
    
    public void put(int key, int value) {
        if(hashMap.containsKey(key)){
            Cache target = hashMap.get(key); 
            target.value = value; 

            target.prev.next = target.next;
            target.next.prev = target.prev; 

            target.next = header.next;
            target.prev = header;
            header.next.prev = target; 
            header.next = target; 
            hashMap.put(key, target); 
            return; 
        }

        if(size >= capacity){
            Cache lru = trailer.prev; 
            lru.prev.next = lru.next; 
            lru.next.prev = lru.prev; 

            hashMap.remove(lru.key); 
            size--; 
        }

        Cache newCache = new Cache(key,value); 
        newCache.next = header.next;  
        newCache.prev = header; 
        header.next.prev = newCache;
        header.next = newCache; 
        size++; 
        hashMap.put(key, newCache); 
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */