//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i=0;i<n;i++) sum+=arr[i];
	    
	    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
	    dp[0][0] = 1;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            if(arr[i-1]<=j) dp[i][j] = dp[i-1][j-arr[i-1]];
	            dp[i][j] = dp[i-1][j] || dp[i][j];
	        }
	    }
	    int ans = sum;
	    for(int i=0;i<=sum;i++){
	        if(dp[n][i]){
	            ans = min(ans, abs(2*i-sum));
	            
	        }
	        
	    }
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends