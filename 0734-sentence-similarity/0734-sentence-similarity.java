class Solution {
    public boolean areSentencesSimilar(String[] sentence1, String[] sentence2, List<List<String>> similarPairs) {
        if(sentence1.length != sentence2.length) return false; 
        HashMap<String,Set<String>> hashMap = new HashMap<>(); 
        for(List<String> ls : similarPairs){
            hashMap.putIfAbsent(ls.get(0), new HashSet<>());
            hashMap.putIfAbsent(ls.get(1), new HashSet<>());
            
            // 관계 추가
            hashMap.get(ls.get(0)).add(ls.get(1));
            hashMap.get(ls.get(1)).add(ls.get(0));
        }

        for(int i = 0; i < sentence1.length; i++){
            String word1 = sentence1[i];
            String word2 = sentence2[i];
            
            // 같거나 유사한 경우만 허용
            if (!word1.equals(word2) && (!hashMap.containsKey(word1) || !hashMap.get(word1).contains(word2))) {
                return false;
            }
        }

        return true; 
    }
}