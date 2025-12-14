class Solution {
    public int shortestWay(String source, String target) {
        Map<Character, List<Integer>> map = new HashMap<>();

        // store indexes for each char
        for(int i = 0; i < source.length(); i++) {
            char c = source.charAt(i);
            map.computeIfAbsent(c, k -> new ArrayList<>()).add(i);
        }

        int count = 1;
        int start = -1; // last used position in source

        for(int e = 0; e < target.length(); e++) {
            char curr = target.charAt(e);

            if(!map.containsKey(curr)) return -1;

            List<Integer> positions = map.get(curr);

            // binary search for first index > start
            int idx = upperBound(positions, start);

            if(idx == positions.size()) {
                // restart source
                count++;
                start = -1;
                idx = upperBound(positions, start);
            }

            start = positions.get(idx);
        }

        return count;
    }

    // returns 첫 번째 value > target
    private int upperBound(List<Integer> list, int target) {
        int lo = 0;
        int hi = list.size();
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(list.get(mid) > target) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
}
