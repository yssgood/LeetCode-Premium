class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        vector<int> maxRightIndex(n);  // Stores the index of the max digit from
                                       // current position to the end

        // First pass: Populate maxRightIndex with the index of the largest
        // digit to the right of each position
        maxRightIndex[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            maxRightIndex[i] = (numStr[i] > numStr[maxRightIndex[i + 1]])
                                   ? i
                                   : maxRightIndex[i + 1];
        }

        // Second pass: Find the first place where we can swap to maximize the
        // number
        for (int i = 0; i < n; ++i) {
            if (numStr[i] < numStr[maxRightIndex[i]]) {
                swap(numStr[i],
                     numStr[maxRightIndex[i]]);  // Swap to maximize the number
                return stoi(numStr);  // Return the new number immediately after
                                      // the swap
            }
        }

        return num;  // Return the original number if no swap can maximize it
    }
};