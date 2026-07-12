class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> answer = new ArrayList<>();
        if (words.length == 0 || s.isEmpty()) return answer;

        int wordLen = words[0].length();
        int numWords = words.length;
        int windowLength = wordLen * numWords;
        int n = s.length();

        Map<String, Integer> need = new HashMap<>();
        for (String w : words) need.put(w, need.getOrDefault(w, 0) + 1);

        // 시작 오프셋 0 ~ wordLen-1, 각 레인마다 슬라이딩
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int count = 0;
            Map<String, Integer> seen = new HashMap<>();

            for (int right = offset; right + wordLen <= n; right += wordLen) {
                String word = s.substring(right, right + wordLen);

                if (need.containsKey(word)) {
                    seen.put(word, seen.getOrDefault(word, 0) + 1);
                    count++;

                    // 개수 초과 → 왼쪽에서 같은 단어 빠질 때까지 축소
                    while (seen.get(word) > need.get(word)) {
                        String leftWord = s.substring(left, left + wordLen);
                        seen.put(leftWord, seen.get(leftWord) - 1);
                        count--;
                        left += wordLen;
                    }

                    // 윈도우가 딱 numWords개 → 답
                    if (count == numWords) {
                        answer.add(left);
                        String leftWord = s.substring(left, left + wordLen);
                        seen.put(leftWord, seen.get(leftWord) - 1);
                        count--;
                        left += wordLen;
                    }
                } else {
                    // 없는 단어 → 윈도우 리셋
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return answer;
    }
}