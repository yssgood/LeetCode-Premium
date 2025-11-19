class LRUCache {
    class Cache {
        int key, value; 
        Cache prev, next; 
        public Cache(int key, int value){
            this.key = key; 
            this.value = value; 
            prev = null; 
            next = null; 
        }
    }

    int capacity; 
    int size; 
    Cache header; 
    Cache trailer;
    Map<Integer, Cache> hashMap; 

    public LRUCache(int capacity) {
        this.capacity = capacity; 
        this.size = 0; 
        this.hashMap = new HashMap<>(); 
        this.header = new Cache(-1,-1); 
        this.trailer = new Cache(-1,-1); 
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

        hashMap.put(key, target); 


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
            size--;
            hashMap.remove(lru.key); 
        }

        Cache newCache = new Cache(key,value); 
        newCache.next = header.next;
        newCache.prev = header; 
        header.next.prev = newCache; 
        header.next = newCache; 
        hashMap.put(key, newCache);
        size++; 
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */