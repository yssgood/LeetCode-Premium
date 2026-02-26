class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        totalGas = 0 
        currGas = 0 
        currLoc = 0
        answer = -1 

        for index in range(0, len(gas)):
            totalGas += gas[index] - cost[index]
            currGas = gas[index] - cost[index] 

            if currGas < 0:
                currLoc = index + 1
            else:
                answer = currLoc 
        
        if totalGas < 0 : return - 1
        return answer
