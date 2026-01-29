class Solution {
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        
        long INF = Long.MAX_VALUE / 2;  // 오버플로우 방지
        
        // 1. 거리 배열 초기화
        long[][] dist = new long[26][26];
        for(int i = 0; i < 26; i++){
            Arrays.fill(dist[i], INF);
            dist[i][i] = 0;  // 자기 자신은 0
        }
        
        // 2. 간선 정보 입력 (중복 간선은 최소값만)
        for(int i = 0; i < original.length; i++){
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            dist[from][to] = Math.min(dist[from][to], cost[i]);
        }
        
        // 3. Floyd-Warshall: 경유지 k를 거쳐가는 경로 확인
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    dist[i][j] = Math.min(dist[i][j], 
                                          dist[i][k] + dist[k][j]);
                }
            }
        }
        
        // 4. 변환 비용 합산
        long answer = 0;
        for(int i = 0; i < source.length(); i++){
            int from = source.charAt(i) - 'a';
            int to = target.charAt(i) - 'a';
            
            if(from == to) continue;
            if(dist[from][to] >= INF) return -1;
            
            answer += dist[from][to];
        }
        
        return answer;
    }
}