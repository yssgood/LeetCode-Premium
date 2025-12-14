class Solution {
    public long minMoves(int[] balance) {
        long sum = 0;
        int negIdx = -1;
        int negVal = 0;
        
        for (int i = 0; i < balance.length; i++) {
            sum += balance[i];
            if (balance[i] < 0) {
                negIdx = i;
                negVal = balance[i];
            }
        }
        
        if (sum < 0) return -1;
        if (negIdx == -1) return 0;
        
        int n = balance.length;
        
        // (value, distance) 리스트 생성
        List<int[]> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (balance[i] > 0) {
                int dist = Math.min(Math.abs(i - negIdx), n - Math.abs(i - negIdx));
                list.add(new int[]{balance[i], dist});
            }
        }
        
        // 거리 기준 오름차순 정렬
        Collections.sort(list, (a, b) -> a[1] - b[1]);
        
        long answer = 0;
        int need = -negVal;
        
        for (int[] pair : list) {
            int val = pair[0];
            int dist = pair[1];
            
            int use = Math.min(val, need);
            answer += (long) use * dist;
            need -= use;
            
            if (need == 0) break;
        }
        
        return answer;
    }
}