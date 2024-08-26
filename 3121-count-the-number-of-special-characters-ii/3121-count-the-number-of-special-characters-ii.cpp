class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0; 
        map<char,pair<int,bool>> hashMap; 
        map<char,int> keepTrack; 
        for(char& c : word){
            if(islower(c)){
                hashMap[c].first++; 
                hashMap[c].second = true; 
            }
        }

        for(char& c : word){
            if(isupper(c)){
                char find = tolower(c); 
                if(hashMap[find].second){
                    if(keepTrack[find] == hashMap[find].first) count++;
                    //cout << find << endl; 
                    hashMap[find].second = false; 
                }
            } else if(islower(c)){
                keepTrack[c]++; 
            }
        }

        return count; 
    }
};