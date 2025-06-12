public class Codec {

    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder(); 
        for(String s : strs){
            sb.append(s.length()).append('#').append(s); 
        }
        return sb.toString(); 
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        List<String> decoded = new ArrayList<>();
        int i = 0; 
        while(i < s.length()){
            int delimiterPos = s.indexOf('#',i);
            int length = Integer.parseInt(s.substring(i,delimiterPos)); 
            int start = delimiterPos + 1; 
            String str = s.substring(start, start + length); 
            decoded.add(str); 
            i = start + length; 
        }
        return decoded; 
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(strs));