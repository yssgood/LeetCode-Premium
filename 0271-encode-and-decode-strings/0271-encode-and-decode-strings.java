public class Codec {

    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        String res = ""; 
        for(String s : strs){
            if(s.equals("")){
                res += "??/!!/";
            } else{
                res += s + "/!!/"; 
            }
        }
        //System.out.print(res); 
        return res; 
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        List<String> res = new ArrayList<>(); 
        String[] split = s.split("/!!/"); 
        for(String strs : split){
            if(strs.equals("??")){
                res.add(""); 
            } else{
                res.add(strs); 
            }
        }

        return res; 
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(strs));