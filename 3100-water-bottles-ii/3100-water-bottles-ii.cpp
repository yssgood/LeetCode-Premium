class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottles = numBottles, currBottles = 0; 
        int totalBottles =  numBottles;  
        bool flag = true;
        while(flag){
                flag = false; 
                if(emptyBottles >= numExchange){
                    emptyBottles -= numExchange; 
                    numExchange++; 
                    currBottles++; 
                    //totalBottles++; 
                    flag = true; 
                } else if(currBottles + emptyBottles >= numExchange){
                    emptyBottles += currBottles; 
                    totalBottles+= currBottles; 
                    currBottles = 0; 
                    //numExchange++; 
                    flag = true; 
                }
        } 

        if(currBottles > 0) totalBottles += currBottles; 
        return totalBottles; 

    }
};