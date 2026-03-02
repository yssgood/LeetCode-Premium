class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        answer = 1
        currMax = points[0][1] 
        for i in range(1, len(points)):
            if points[i][0] <= currMax:
                currMax = min(currMax, points[i][1])
            else:
                answer += 1 
                currMax = points[i][1] 
        
        return answer
