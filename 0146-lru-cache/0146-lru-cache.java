class LRUCache {
    class Node{
        int key;
        int val; 
        Node next = null;
        Node prev = null; 
        public Node(int key, int val){
            this.key = key;
            this.val = val; 
        }
    }

    Map<Integer, Node> hashMap; 
    Node header;
    Node trailer; 
    int cap; 

    public LRUCache(int capacity) {
        hashMap = new HashMap<>(); 
        cap = capacity; 
        header = new Node(-1,-1); 
        trailer = new Node(-1,-1);
        header.next = trailer;
        trailer.prev = header; 
    }
    
    public int get(int key) {
        if(!hashMap.containsKey(key)) return -1; 

        Node target = hashMap.get(key); 
        target.prev.next = target.next; 
        target.next.prev = target.prev; 

        target.next = header.next;
        target.prev = header; 
        header.next.prev = target;
        header.next = target; 

        return target.val; 
    }
    
    public void put(int key, int value) {
        if(hashMap.containsKey(key)){
            Node target = hashMap.get(key); 
            target.val = value; 

            target.prev.next = target.next;
            target.next.prev = target.prev; 

            target.next = header.next;
            target.prev = header;
            header.next.prev = target; 
            header.next = target; 

            return; 
        }

        Node newCache = new Node(key,value);
        //System.out.println(hashMap.size()); 
        if(hashMap.size() + 1 > cap){
            Node lru = trailer.prev; 
            lru.prev.next = lru.next;
            lru.next.prev = lru.prev; 
            hashMap.remove(lru.key); 
        }

        hashMap.put(key, newCache); 
        newCache.next = header.next;
        newCache.prev = header;
        header.next.prev = newCache;
        header.next = newCache; 
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */