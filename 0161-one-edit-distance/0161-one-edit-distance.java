class Solution {
    public boolean isOneEditDistance(String s, String t) {
        if(s.equals(t)) return false; 
        if(s.length() > t.length()){
            String tmp = s; 
            s = t; 
            t = tmp; 
        }

        for(int i = 0; i < s.length(); i++){
            char sChar = s.charAt(i); 
            char tChar = t.charAt(i); 

            if(sChar != tChar){
                if(s.length() == t.length()){
                    return s.substring(i+1).equals(t.substring(i+1)); 
                } 
                if(s.length() < t.length()){
                    return s.substring(i).equals(t.substring(i+1)); 
                }
            }
        }

        return s.length()+1 == t.length(); 
    }
}