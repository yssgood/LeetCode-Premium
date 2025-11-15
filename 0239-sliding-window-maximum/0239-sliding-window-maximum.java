class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        LinkedList<Integer> dq = new LinkedList<>(); 
        List<Integer> answer = new ArrayList<>(); 
        
        int start = 0, end = 0;
        
        while (end < nums.length) {

            // 1) 윈도우 범위 벗어나면 앞에서 제거해야 합니다
            if (!dq.isEmpty() && dq.peekFirst() < end - k + 1) {
                dq.pollFirst();
            }

            // 2) 새로운 값보다 작은 값들 뒤에서 제거
            while (!dq.isEmpty() && nums[dq.peekLast()] < nums[end]) {
                dq.pollLast();
            }

            // 3) 현재 인덱스 삽입
            dq.offerLast(end);

            // 4) 윈도우 크기 도달 시 최대값 저장
            if (end - start + 1 == k) {
                answer.add(nums[dq.peekFirst()]);
                start++;
            }

            end++;
        }

        int[] res = new int[answer.size()];
        for (int i = 0; i < answer.size(); i++) {
            res[i] = answer.get(i);
        }
        return res;
    }
}
