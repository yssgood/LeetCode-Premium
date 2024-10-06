class Solution {
    public int hIndex(int[] citations) {
        //3 0 6 1 5 
        //0 1 3 5 6 
        //1 1 3 
        Arrays.sort(citations); 
        int start = 0;  
        while(start < citations.length && citations[citations.length-1 - start] > start){
            start++; 
        }
        return start; 
    }
}