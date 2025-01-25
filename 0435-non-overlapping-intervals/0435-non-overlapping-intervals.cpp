class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 끝값 기준으로 오름차순 정렬
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int answer = 0;
        int currEnd = intervals[0][1]; // 첫 번째 구간의 끝값

        for (int i = 1; i < intervals.size(); i++) {
            // 현재 구간이 겹치는 경우
            if (intervals[i][0] < currEnd) {
                answer++; // 구간 제거
            } else {
                // 겹치지 않으면 currEnd를 업데이트
                currEnd = intervals[i][1];
            }
        }

        return answer;
    }
};
