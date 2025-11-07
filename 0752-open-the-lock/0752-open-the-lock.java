class Pair{
    StringBuilder sb; 
    int count; 
    public Pair(StringBuilder sb, int count){
        this.sb = sb; 
        this.count = count; 
    } 
}
class Solution {
    public int openLock(String[] deadends, String target) {
        Map<String,Boolean> hashMap = new HashMap<>(); 
        for(String s : deadends){
            hashMap.put(s, true); 
        }

        if(hashMap.containsKey("0000")) return -1; 
        if(target.equals("0000")) return 0; 

        hashMap.put("0000",true); 

        Queue<Pair> q = new LinkedList<>(); 
        q.add(new Pair(new StringBuilder("0000"), 0)); 
        while(!q.isEmpty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                Pair first = q.poll(); 
                int currCount = first.count; 

                //if(hashMap.containsKey(first.sb.toString())) continue; 

                for(int j = 0; j < 4; j++){
                    StringBuilder curr = first.sb; 
                    char digitChar = curr.charAt(j); 

                    int digit = digitChar - '0'; 
                    //System.out.print(digit); 

                    char upDigit = digit + 1 > 9 ? (char)(0 + '0') : (char)((digit + 1) + '0');
                    char downDigit = digit - 1 < 0 ? (char)(9 + '0') : (char)((digit -1) + '0'); 
                    
                    StringBuilder upCurr = new StringBuilder(first.sb); 
                    StringBuilder downCurr = new StringBuilder(first.sb); 

                    //System.out.println(upDigit); 

                    upCurr.setCharAt(j,upDigit); 
                    downCurr.setCharAt(j,downDigit); 

                    //System.out.println(upCurr.toString()); 

                    if(upCurr.toString().equals(target) || downCurr.toString().equals(target)) return currCount + 1; 

                    //if(hashMap.containsKey(upCurr) || hashMap.containsKey(downCurr)) return -1; 

                    if(!hashMap.containsKey(upCurr.toString())){
                        hashMap.put(upCurr.toString(),true); 
                        q.offer(new Pair(upCurr,currCount + 1)); 
                    }

                    if(!hashMap.containsKey(downCurr.toString())){
                        hashMap.put(downCurr.toString(),true); 
                        q.offer(new Pair(downCurr,currCount + 1)); 
                    }
                    

                }
            }
        }
        return -1; 
    }
}