class LFUCache {
    class Node {
        int key; 
        int value; 
        int frequency; 
        Node next, prev; 
        public Node(int key, int value, int frequency){
            this.key = key;
            this.value = value; 
            this.frequency = frequency; 
            this.next = null;
            this.prev = null; 
        }
    }
    class DLL {
        Node header, trailer; 

        public DLL(){
            this.header = new Node(-1,-1,-1); 
            this.trailer = new Node(-1,-1,-1); 
            header.next = trailer;
            trailer.prev = header; 
        }

        public void addNewNode(Node node){
            node.prev = header;
            node.next = header.next; 
            header.next.prev = node; 
            header.next = node; 
        }

        public void removeNode(Node node){
            node.prev.next = node.next; 
            node.next.prev = node.prev; 
        }

        public Node getLRU(){
            return trailer.prev; 
        }

        public boolean isEmpty(){
            return header.next == trailer; 
        }
    }

    Map<Integer, Node> hashMap = new HashMap<>(); 
    Map<Integer, DLL> lfuMap = new HashMap<>(); 
    int capacity = 0; 
    int size = 0; 
    int minCount = 1; 

    public LFUCache(int capacity) {
        this.capacity = capacity; 
    }
    
    public int get(int key) {
        if(!hashMap.containsKey(key)) return -1; 
        Node target = hashMap.get(key); 
        int oldFrequency = target.frequency; 
        target.frequency++; 

        DLL oldGroup = lfuMap.get(oldFrequency); 
        oldGroup.removeNode(target); 
        if(oldGroup.isEmpty() && oldFrequency == minCount) minCount++; 
        lfuMap.computeIfAbsent(target.frequency, k -> new DLL()).addNewNode(target); 
        hashMap.put(key,target); 

        return target.value; 
    }
    
    public void put(int key, int value) {
        if(hashMap.containsKey(key)){
            Node target = hashMap.get(key); 
            target.value = value; 
            int oldFrequency = target.frequency; 
            target.frequency++; 
            DLL oldGroup = lfuMap.get(oldFrequency); 
            oldGroup.removeNode(target); 
            if(oldGroup.isEmpty() && oldFrequency == minCount) minCount++; 
            lfuMap.computeIfAbsent(target.frequency, k -> new DLL()).addNewNode(target); 
            hashMap.put(key, target);
            return; 
        }

        Node newNode = new Node(key,value,1); 
        if(size >= capacity){
            DLL lfuGroup = lfuMap.get(minCount); 
            Node lru = lfuGroup.getLRU(); 
            if(lru.value != -1){
                lfuGroup.removeNode(lru); 
                hashMap.remove(lru.key); 
                size--; 
            }
        }
        minCount = 1; 
        size++; 
        lfuMap.computeIfAbsent(1, k -> new DLL()).addNewNode(newNode); 
        hashMap.put(key, newNode); 
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */