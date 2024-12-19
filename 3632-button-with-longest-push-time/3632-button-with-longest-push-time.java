class Solution {
    public int buttonWithLongestTime(int[][] events) {
        int curr = events[0][1]; 
        for(int i = 1; i < events.length; i++){
            int next = events[i][1]; 
            events[i][1] = next - curr; 
            curr = next; 
        }

        Arrays.sort(events, (a,b)->{
            if(a[1] == b[1]){
                return a[0] - b[0]; 
            }
            return b[1] - a[1]; 
        });

        return events[0][0]; 
    }
}