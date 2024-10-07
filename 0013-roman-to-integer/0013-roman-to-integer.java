class Solution {
    public int romanToInt(String s) {
        HashMap<Character,Integer> hashMap = new HashMap<>();
        hashMap.put('I',1);
        hashMap.put('V',5);
        hashMap.put('X',10); 
        hashMap.put('L',50);
        hashMap.put('C',100);
        hashMap.put('D',500);
        hashMap.put('M',1000); 

        HashSet<String> hashSet = new HashSet<>();
        hashSet.add("IV");
        hashSet.add("IX");
        hashSet.add("XL");
        hashSet.add("XC");
        hashSet.add("CD");
        hashSet.add("CM"); 
        int answer = 0; 

        for(int i = 0; i < s.length();){
            if(i < s.length() - 1){
                String sub = s.substring(i,i+2);
                if(hashSet.contains(sub)){
                    //System.out.println(sub); 
                    answer += hashMap.get(s.charAt(i+1));
                    answer -= hashMap.get(s.charAt(i)); 
                    i += 2;
                    continue; 
                } 
            } 
            answer += hashMap.get(s.charAt(i)); 
            //System.out.println(answer); 
            i++; 
        }

        return answer;
    }
}