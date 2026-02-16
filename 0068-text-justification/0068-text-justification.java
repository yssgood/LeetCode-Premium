class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> answer = new ArrayList<>();
        int currLength = words[0].length();
        int last = 0;

        for (int i = 1; i <= words.length; i++) {
            // i == words.length이면 마지막 줄 강제 처리
            if (i == words.length || currLength + 1 + words[i].length() > maxWidth) {
                StringBuilder sb = new StringBuilder();
                int numWords = i - last;
                int totalSpaces = maxWidth - (currLength - (numWords - 1));
                // currLength에는 단어사이 공백1씩 포함되어 있으므로 빼줌

                if (numWords == 1 || i == words.length) {
                    // 단어 1개이거나 마지막 줄 → 왼쪽 정렬
                    for (int j = last; j < i; j++) {
                        if (j > last) sb.append(' ');
                        sb.append(words[j]);
                    }
                    while (sb.length() < maxWidth) sb.append(' ');
                } else {
                    // 균등 분배
                    int gaps = numWords - 1;
                    int eachSpace = totalSpaces / gaps;
                    int remain = totalSpaces % gaps;

                    for (int j = last; j < i; j++) {
                        sb.append(words[j]);
                        if (j < i - 1) {
                            int spaces = eachSpace + (j - last < remain ? 1 : 0);
                            for (int k = 0; k < spaces; k++) sb.append(' ');
                        }
                    }
                }

                answer.add(sb.toString());
                last = i;
                currLength = (i < words.length) ? words[i].length() : 0;
            } else {
                currLength += 1 + words[i].length();
            }
        }

        return answer;
    }
}