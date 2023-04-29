//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
     vector<vector<int>> dp(N,vector<int>(N,-1));
     
     return sol(1,N-1,arr,dp);
    }
    
    int sol(int i,int j,int *arr,vector<vector<int>> &dp)
    {
     if(i>=j) return 0;
     int ans=INT_MAX;
     if(dp[i][j]!=-1) return dp[i][j];
     for(int k=i;k<j;k++)
     {
      int operations=arr[i-1]*arr[k]*arr[j]+sol(i,k,arr,dp)+sol(k+1,j,arr,dp);
      ans=min(ans,operations);
     }
     return dp[i][j]=ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends