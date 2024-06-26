class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end()); 
        sort(trainers.begin(), trainers.end()); 
        int firstStart = 0, secondStart = 0; 
        int answer = 0; 
        //4 7 9 
        //2 5 8 8
         
        while(firstStart < players.size() && secondStart < trainers.size()){   
            while(secondStart < trainers.size() && trainers[secondStart] < players[firstStart]){
                secondStart++; 
            }
            //cout << firstStart << ' ' << secondStart << endl; 
            if(secondStart < trainers.size() && players[firstStart] <= trainers[secondStart]) answer++; 
            firstStart++;
            secondStart++; 
        }
        return answer; 
    }
};