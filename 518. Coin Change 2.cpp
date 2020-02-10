class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        sort( coins.begin(), coins.end() );
        
        
        int n = amount;
        int m = (int)coins.size();
        
        int dp[n+5][m+5];
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                dp[i][j] = 0;
            }
        }
        
        dp[0][0] = 1;
        
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if( i - coins[j-1] < 0 ) continue;
                
                for(int k=0;k<=j; k++){
                    dp[i][j]+= dp[i- coins[j-1] ][k];
                }
                
                
            }
        }
        
        int ans = 0;
        
        for(int i=0; i<=m; i++){
            ans+=dp[n][i];
        }
        
        return ans;
        
        
        
    }
};
