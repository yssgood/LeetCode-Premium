class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() <= 1) return triangle[0][0]; 
        int m = triangle.size(); 
        for(int i = 1; i < m; i++){
            int top = triangle[i-1].size()-1; 
            int bottom = triangle[i].size()-1; 
            triangle[i][0] = triangle[i-1][0] + triangle[i][0]; 
            triangle[i][bottom] = triangle[i-1][top] + triangle[i][bottom]; 
        }

        for(int i = 2; i < m; i++){
            int n = triangle[i].size(); 
            for(int j = 1; j < n - 1; j++){
                triangle[i][j] = min(triangle[i-1][j-1],triangle[i-1][j]) + triangle[i][j]; 
            }
        }

        // for(int i = 0; i < m; i++){
        //     int n = triangle[i].size(); 
        //     for(int j = 0; j < n; j++){
        //         cout << triangle[i][j] << ' '; 
        //     }
        //     cout << endl; 
        // }

        return *min_element(triangle[m-1].begin(), triangle[m-1].end()); 
    }
};