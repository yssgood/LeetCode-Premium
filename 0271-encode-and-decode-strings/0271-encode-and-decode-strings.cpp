class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded_string = ""; 
        for(string& s : strs){
            s = s.empty() ? "\01" : s; 
            encoded_string += s + '\n'; 
        }
        encoded_string.pop_back(); 
        return encoded_string; 
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res; 
        stringstream ss(s); 
        string token; 
        while(getline(ss,token,'\n')){
            token = token == "\01" ? "" : token; 
            cout << token << ' '; 
            res.push_back(token); 
        }
        return res; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));