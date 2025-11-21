class MaxStack {
    class Node {
        int value; 
        Node next, prev; 
        public Node(int value){
            this.value = value; 
            this.next = null; 
            this.prev= null; 
        }
    }

    private Node header; 
    private Node trailer; 
    //private PriorityQueue<Node> pq; 
    private TreeMap<Integer, List<Node>> map; 

    public MaxStack() {
        this.header = new Node(-1); 
        this.trailer = new Node(-1); 
        //this.pq = new PriorityQueue<>((a,b) -> b.value - a.value);
        this.map = new TreeMap<>(); 
        header.next = trailer;
        trailer.prev = header;
    }
    
    public void push(int x) {
        Node newNode = new Node(x); 
        newNode.next = trailer; 
        newNode.prev = trailer.prev; 
        trailer.prev.next = newNode;
        trailer.prev = newNode; 
        //pq.offer(newNode); 
        map.computeIfAbsent(x, k -> new ArrayList<>()).add(newNode); 
    }
    
    public int pop() {
        Node target = trailer.prev; 
        target.prev.next = target.next; 
        target.next.prev = target.prev; 

        List<Node> lst = map.get(target.value); 
        lst.removeLast(); 
        if(lst.isEmpty()) map.remove(target.value); 
        return target.value; 
    }
    
    public int top() {
        Node target = trailer.prev; 
        return target.value; 
    }
    
    public int peekMax() {
        return map.lastKey(); 
    }
    
    public int popMax() {
        int maxVal = map.lastKey(); 
        List<Node> lst = map.get(maxVal); 

        Node node = lst.removeLast(); 
        if(lst.isEmpty()) map.remove(maxVal); 
        node.prev.next = node.next; 
        node.next.prev = node.prev; 
        return node.value; 
    }
}

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */