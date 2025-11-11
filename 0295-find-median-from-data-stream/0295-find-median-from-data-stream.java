import java.util.*;

class MedianFinder {
    List<Integer> nums = new ArrayList<>();

    public void addNum(int num) {
        int pos = Collections.binarySearch(nums, num);
        if (pos < 0) pos = -(pos + 1);
        nums.add(pos, num); // 항상 정렬 유지
    }

    public double findMedian() {
        int n = nums.size();
        if (n % 2 == 1) return nums.get(n/2);
        return (nums.get(n/2 - 1) + nums.get(n/2)) / 2.0;
    }
}
