class Node {
    int key, value; 
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

    Node header = new Node(-1,-1); 
    Node trailer = new Node(-1,-1); 
    Map<Integer,Node> hashMap = new HashMap<>(); 
    int cap = 0; 
    int size = 0; 
    public LRUCache(int capacity) {
        cap = capacity; 
        header.next = trailer; 
        trailer.prev = header; 
    }
    
    public int get(int key) {
        if(!hashMap.containsKey(key)) return -1; 

        Node target = hashMap.get(key); 

        target.prev.next = target.next; 
        target.next.prev = target.prev; 

        target.next = header.next; 
        header.next.prev = target; 

        header.next = target; 
        target.prev = header; 


        return target.value; 
    }
    
    public void put(int key, int value) {
        if(hashMap.containsKey(key)){
            Node target = hashMap.get(key); 
            target.value = value; 

            target.prev.next = target.next; 
            target.next.prev = target.prev; 

            target.next = header.next; 
            header.next.prev = target; 

            header.next = target; 
            target.prev = header; 

        } else{
            Node newNode = new Node(key,value); 
            //header 앞에 place 
            newNode.next = header.next; 
            newNode.prev = header; 
            
            header.next.prev = newNode; 
            header.next = newNode; 

            hashMap.put(key, newNode); 
            size++; 
            if(size > cap){
                //trailer 의 prev 제거 
                Node lru = trailer.prev; 
                trailer.prev = lru.prev; 
                lru.prev.next = lru.next; 

                hashMap.remove(lru.key); 
                size--; 
            }

        }
        
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */