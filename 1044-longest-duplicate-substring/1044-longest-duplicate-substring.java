class Solution {
    private static final long MOD = (long) 1e9 + 7;
    private static final long BASE = 26;
    
    public String longestDupSubstring(String s) {
        int n = s.length();
        int left = 1, right = n - 1;
        String result = "";
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            String dup = search(s, mid);
            
            if (dup != null) {
                result = dup;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
    private String search(String s, int len) {
        if (len == 0) return "";
        
        long hash = 0;
        long pow = 1;
        
        for (int i = 0; i < len; i++) {
            hash = (hash * BASE + s.charAt(i) - 'a') % MOD;
            if (i < len - 1) {
                pow = (pow * BASE) % MOD;
            }
        }
        
        Map<Long, List<Integer>> seen = new HashMap<>();
        seen.computeIfAbsent(hash, k -> new ArrayList<>()).add(0);
        
        for (int i = len; i < s.length(); i++) {
            hash = (hash - (s.charAt(i - len) - 'a') * pow % MOD + MOD) % MOD;
            hash = (hash * BASE + s.charAt(i) - 'a') % MOD;
            
            if (seen.containsKey(hash)) {
                String current = s.substring(i - len + 1, i + 1);
                for (int idx : seen.get(hash)) {
                    if (s.substring(idx, idx + len).equals(current)) {
                        return current;
                    }
                }
            }
            seen.computeIfAbsent(hash, k -> new ArrayList<>()).add(i - len + 1);
        }
        
        return null;
    }
}
