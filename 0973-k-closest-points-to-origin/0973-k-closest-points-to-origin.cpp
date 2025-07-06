class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // A max-heap to store pairs of {squared_distance, index}
        priority_queue<pair<long long, int>> max_heap;

        for (int i = 0; i < points.size(); ++i) {
            long long dist = (long long)points[i][0] * points[i][0] + (long long)points[i][1] * points[i][1];

            // Push the current point's info onto the heap.
            max_heap.push({dist, i});

            // If the heap size exceeds k, pop the element with the largest distance.
            // This ensures our heap always contains the k closest points seen so far.
            if (max_heap.size() > k) {
                max_heap.pop();
            }
        }

        // Extract the indices from the heap to build the final answer.
        vector<vector<int>> answer;
        while (!max_heap.empty()) {
            answer.push_back(points[max_heap.top().second]);
            max_heap.pop();
        }

        return answer;
    }
};
