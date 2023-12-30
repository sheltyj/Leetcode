//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    int A[] = new int[n];
                    for(int i = 0;i<n;i++)
                        A[i] = sc.nextInt();
                    Solution ob = new Solution();
                    System.out.println(ob.minDifference(A,n));
                }
        }
}    
// } Driver Code Ends


//User function Template for Java

class Solution
{
    private int util(int arr[], int totSum, int currSum,  int currInd,int[][] dp){
        int n = arr.length;
        if(currInd==n) return Math.abs(2*currSum-totSum);
        if(dp[currInd][currSum]!=-1){
            return dp[currInd][currSum];
        }
        return dp[currInd][currSum]=Math.min(util(arr,totSum,currSum+arr[currInd],currInd+1,dp), util(arr,totSum,currSum,currInd+1,dp));
    }
	public int minDifference(int arr[], int n) 
	{ 
	    int sum=0;
	    for(int a:arr){
	        sum+=a;
	    }
	    int[][] dp=new int[n][sum+1];
	    for(int i=0;i<n;i++){
	        Arrays.fill(dp[i],-1);
	    }
	    return util(arr,sum,0,0,dp);
	} 
}
