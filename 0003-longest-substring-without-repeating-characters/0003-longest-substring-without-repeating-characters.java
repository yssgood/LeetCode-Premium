class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> hashMap = new HashMap<>();
        int start = 0;
        int end = 0;
        int answer = 0;

        while (end < s.length()) {
            // 현재 문자를 해시맵에 추가 또는 갱신
            hashMap.put(s.charAt(end), hashMap.getOrDefault(s.charAt(end), 0) + 1);

            // 중복 문자가 있을 경우, 시작 위치를 앞으로 이동
            while (hashMap.get(s.charAt(end)) > 1) {
                hashMap.put(s.charAt(start), hashMap.get(s.charAt(start)) - 1);
                start++;
            }

            // 최대 길이 갱신
            answer = Math.max(answer, end - start + 1);
            end++;
        }

        return answer;
    }
}