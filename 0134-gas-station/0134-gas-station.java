class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int totalGas = 0; 
        int currGas = 0; 
        int candidate = 0; 
        for(int i = 0; i < gas.length; i++){
            totalGas += gas[i] - cost[i]; 
            currGas += gas[i] - cost[i]; 

            if(currGas < 0){
                candidate = i + 1; 
                currGas = 0; 
            }
        }

        return totalGas < 0 ? -1 : candidate; 
    }
}