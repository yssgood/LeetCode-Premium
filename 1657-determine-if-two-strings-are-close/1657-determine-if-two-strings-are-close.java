class Solution {
    public boolean closeStrings(String word1, String word2) {
        if(word1.length() != word2.length()) return false;

        Map<Character,Integer> mapA = new HashMap<>();
        Map<Character,Integer> mapB = new HashMap<>();

        for(char c : word1.toCharArray()) mapA.merge(c,1,Integer::sum);
        for(char c : word2.toCharArray()){
            if(!mapA.containsKey(c)) return false;
            mapB.merge(c,1,Integer::sum);
        }

        // // 키 집합도 확인 (word1 글자가 word2에 있는지 - 양방향)
        // if(!mapA.keySet().equals(mapB.keySet())) return false;

        // Set → 정렬 List (개수 유지)
        List<Integer> listA = new ArrayList<>();
        List<Integer> listB = new ArrayList<>();

        for(var e : mapA.entrySet()) listA.add(e.getValue());
        for(var e : mapB.entrySet()) listB.add(e.getValue());

        Collections.sort(listA);
        Collections.sort(listB);

        return listA.equals(listB);
    }
}