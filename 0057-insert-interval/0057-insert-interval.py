class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        answer = [] 
        index = 0 
        while index < len(intervals):
            lst = intervals[index] 
            if lst[1] < newInterval[0]:
                answer.append(lst) 
            else:
                break 
            
            index += 1
        

        while index < len(intervals):
            currMin = intervals[index][0] 
            currMax = intervals[index][1] 

            if currMin <= newInterval[1]:
                newInterval[0] = min(newInterval[0], currMin) 
                newInterval[1] = max(newInterval[1], currMax)
            else:
                break

            index += 1 
        
        answer.append(newInterval) 

        while index < len(intervals):
            answer.append(intervals[index])
            index += 1

        
        return answer