class Solution {
public:
    vector<string> split(string& s){
        vector<string> res; 
        stringstream ss(s); 
        string tmp; 
        while(ss >> tmp){
            res.push_back(tmp); 
        }
        return res; 
    }
    
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        vector<string> answer; 
        map<string, vector<int>> beforeMap;  // word -> indices of phrases that start with this word
        map<string, vector<int>> afterMap;   // word -> indices of phrases that end with this word
        
        // Build the maps using indices
        for(int i = 0; i < phrases.size(); i++){
            vector<string> words = split(phrases[i]); 
            string firstWord = words[0]; 
            string lastWord = words[words.size()-1]; 
            
            beforeMap[firstWord].push_back(i);
            afterMap[lastWord].push_back(i);
        }
        
        // Find combinations
        set<string> resultSet;  // Use set to avoid duplicates
        
        for(auto& entry : afterMap){
            string connectingWord = entry.first;
            vector<int>& indicesEndingWith = entry.second;
            
            // Check if any phrases start with this connecting word
            if(beforeMap.count(connectingWord)){
                vector<int>& indicesStartingWith = beforeMap[connectingWord];
                
                // Combine each phrase ending with connectingWord 
                // with each phrase starting with connectingWord
                for(int firstIdx : indicesEndingWith){
                    for(int secondIdx : indicesStartingWith){
                        // Don't combine a phrase with itself (same index)
                        if(firstIdx != secondIdx){
                            vector<string> firstWords = split(phrases[firstIdx]);
                            vector<string> secondWords = split(phrases[secondIdx]);
                            
                            // Create combined phrase
                            string combined = "";
                            // Add all words from first phrase
                            for(string& word : firstWords){
                                combined += word + " ";
                            }
                            // Add all words from second phrase except the first 
                            // (since it's the connecting word)
                            for(int i = 1; i < secondWords.size(); i++){
                                combined += secondWords[i] + " ";
                            }
                            
                            // Remove trailing space
                            if(!combined.empty()){
                                combined.pop_back();
                                resultSet.insert(combined);
                            }
                        }
                    }
                }
            }
        }
        
        // Convert set to vector and sort
        for(const string& s : resultSet){
            answer.push_back(s);
        }
        sort(answer.begin(), answer.end());
        
        return answer; 
    }
};