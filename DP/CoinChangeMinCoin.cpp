class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
     int dp[coins.size()+1][amount+1];

     for(int i=0;i<=coins.size();i++)
      for(int j=0;j<=amount;j++)
      {
       if(i==0 && j==0) dp[i][j]=0;
       else if(i==0) dp[i][j]=INT_MAX-1;
       else if(j==0) dp[i][j]=0;
       else
       {
        if(j>=coins[i-1])
         dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
        else
         dp[i][j]=dp[i-1][j];
       }
      }

      return dp[coins.size()][amount]==INT_MAX-1?-1:dp[coins.size()][amount];
    }
};