public class ZigzagIterator {
    int index1 = 0, index2 = 0; 
    int turn = 1;
    private List<Integer> v1; 
    private List<Integer> v2; 
    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        this.v1 = v1;
        this.v2 =v2; 
    }

    public int next() {
        if(index1 >= v1.size() && index2 < v2.size()) return v2.get(index2++); 
        if(index1 < v1.size() && index2 >= v2.size()) return v1.get(index1++); 

        if(turn == 1 && index1 < v1.size()){
            turn++; 
            return v1.get(index1++); 
        } 

        if(turn == 2 && index2 < v2.size()){
            turn--; 
            return v2.get(index2++); 
        }
        return -1; 
    }

    public boolean hasNext() {
        return (index1 < v1.size() || index2 < v2.size()); 
    }
}

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i = new ZigzagIterator(v1, v2);
 * while (i.hasNext()) v[f()] = i.next();
 */