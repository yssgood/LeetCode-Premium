class Solution {

struct Node{
    int distance, windex, bindex; 
};

struct NodeCompare{
    bool operator()(Node& a, Node& b){
        if(a.distance != b.distance){
            return a.distance > b.distance; 
        }
        else{
            if(a.windex != b.windex){
                return a.windex > b.windex; 
            }
            else{
                return a.bindex > b.bindex; 
            }
        }
        // if(a.distance != b.distance){
        //     return a.distance > b.distance; 
        // } else if(a.distance == b.distance){
        //     return a.windex > b.windex; 
        // } 
        // return a.bindex > b.bindex; 
    }
};
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<int> workerVec(workers.size(), -1); 
        vector<int> bikeVec(bikes.size(), -1); 
        vector<int> answer(workers.size(), -1);
        priority_queue<Node, vector<Node>, NodeCompare> pq; 
        for(int i = 0; i < workers.size(); i++){
            vector<int> currWorkers = workers[i];
            for(int j = 0; j < bikes.size(); j++){
                vector<int> currBikes = bikes[j]; 

                int manDist = abs(currWorkers[0] - currBikes[0]) + abs(currWorkers[1] - currBikes[1]); 
                pq.push({manDist, i, j}); 
            }
        }

        while(!pq.empty()){
            int size = pq.size();
            for(int i = 0; i < size; i++){
                Node node = pq.top();
                pq.pop(); 

                int distance = node.distance, workerIndex = node.windex, bikeIndex = node.bindex; 
                if(workerVec[workerIndex] == -1 && bikeVec[bikeIndex] == -1){
                    //workere did not get bikes yet, bike was not assigned yet 
                    answer[workerIndex] = bikeIndex; 
                    workerVec[workerIndex]++; 
                    bikeVec[bikeIndex]++; 
                }
            }
        }
        return answer; 
    }
};