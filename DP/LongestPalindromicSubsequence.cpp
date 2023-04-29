class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
     vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));     
     return sol(0,s.size()-1,s,dp);   
    }

    int sol(int i,int j,string &s,vector<vector<int>> &dp)
    {
     if(i>j) return 0;
     if(i==j) return 1;

     if(dp[i][j]!=-1) return dp[i][j];
     if(s[i]==s[j])
      return dp[i][j]=2+sol(i+1,j-1,s,dp);
     
     return dp[i][j]=max(sol(i+1,j,s,dp),sol(i,j-1,s,dp));
    }
};