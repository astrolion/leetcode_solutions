class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector< int > dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<= amount; i++){
            for(auto it: coins){
                if( i - it < 0 ) continue;
                
                if( dp[i-it] == INT_MAX ) continue;
                dp[i] = min( dp[i] , dp[i-it]+1 );
                
            }
        }
        
        if( dp[amount] == INT_MAX ) return -1;
        else return dp[amount];
        
    }
};
