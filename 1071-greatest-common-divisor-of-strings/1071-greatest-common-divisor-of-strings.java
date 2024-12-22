class Solution {
    public boolean valid(String str1, String str2) {
        for (int i = 0; i <= str1.length() - str2.length(); i += str2.length()) { // 조건 수정
            String tmp = str1.substring(i, i + str2.length()); // 올바른 범위 사용
            if (!tmp.equals(str2)) {
                return false;
            }
        }
        return true;
    }

    public String gcdOfStrings(String str1, String str2) {
        if (str2.length() > str1.length()) return gcdOfStrings(str2, str1); 
        // str1이 항상 str2보다 길거나 같도록 보장

        for (int i = str2.length(); i > 0; i--) {
            if (str1.length() % i != 0 || str2.length() % i != 0) continue; // 길이 검증 추가

            String candidate = str2.substring(0, i);
            if (valid(str1, candidate) && valid(str2, candidate)) { // str1과 str2 모두에서 유효성 검사
                return candidate;
            }
        }

        return "";
    }
}
