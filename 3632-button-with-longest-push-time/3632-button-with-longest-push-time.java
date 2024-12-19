class Solution {
    public int buttonWithLongestTime(int[][] events) {
        int maxTime = events[0][1]; 
        int currIndex = events[0][0]; 
        for(int i = 1; i < events.length; i++){
            int time = events[i][1] - events[i-1][1]; 
            if(time > maxTime || time == maxTime && events[i][0] < currIndex){
                currIndex = events[i][0]; 
                maxTime = time; 
            }
        }
        return currIndex; 
    }
}