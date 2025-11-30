class Solution {
public:
int fun(int ind,vector<int> &arr, int target,vector<vector<int>> &dp){
      if(target==0) return true;
      if(ind==0){
          return arr[0]==target;
      }
      if(dp[ind][target]!=-1) return dp[ind][target];
      bool ntake=fun(ind-1,arr,target,dp);
      bool take=false;
      if(arr[ind]<=target){
          take=fun(ind-1,arr,target-arr[ind],dp);
      }
      return dp[ind][target] = take||ntake;
  }
    bool canPartition(vector<int>& nums) {
         int n=nums.size();
         int sum=0;
         for(int i=0;i<n;i++) sum+=nums[i];
         if(sum%2) return false;
         int target=sum/2;
         vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
         return fun(n-1,nums,target,dp); 
    }
};