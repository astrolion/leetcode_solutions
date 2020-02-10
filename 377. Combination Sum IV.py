class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = []
        for i in range(target+5):
            dp.append(0)
        
        dp[0] = 1
        
        mx = 0
        for i in range(1, target+1):
            for x in nums:
                if (i-x) >= 0:
                    dp[i]+=dp[i-x]
                    mx = max(mx, dp[i])
        
        print (mx)
        return dp[target]
        
