class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string answer = "";

        while (!pq.empty()) {
            pair<int, char> first = pq.top();
            pq.pop();

            // 이전 문자와 동일한 문자가 아니면 추가
            if (answer.size() < 2 || !(answer[answer.size() - 1] == first.second && answer[answer.size() - 2] == first.second)) {
                answer += first.second;
                first.first--;
            } else {
                // 두 번째로 많은 문자 처리
                if (pq.empty()) break;
                pair<int, char> second = pq.top();
                pq.pop();
                answer += second.second;
                second.first--;
                if (second.first > 0) pq.push(second);
            }

            if (first.first > 0) pq.push(first);
        }

        return answer;
    }
};
