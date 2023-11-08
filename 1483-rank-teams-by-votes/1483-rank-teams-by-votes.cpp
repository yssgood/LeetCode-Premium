class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string answer = votes[0]; 
        if(votes.size() == 1) return answer; 

        map<char,vector<int>> rankings; 

        for(char & c : votes[0]){
            rankings[c] = vector<int>(votes[0].length(),0); 
        }

        for(string& s : votes){
            for(int i = 0; i < s.length(); i++){
                rankings[s[i]][i]++; 
            }
        }

        sort(answer.begin(), answer.end(), [&](char& a, char& b){
            if(rankings[a] == rankings[b]) return a < b; 
            return rankings[a] > rankings[b]; 
        });

        //cout << answer; 


        return answer; 
    }
};