//Approach: simple question but take care of corner cases

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
    long long ans = 1;
      int count = 0;
      vector<long long int> solution;
       for(int i=0;i<n;i++){
           if(nums[i] != 0) ans *= nums[i];
           else count++;
       } 
       for(int i=0;i<n;i++){
           if(nums[i] == 0){
               if(count > 1) solution.push_back(0);
               else if(count == 1) solution.push_back(ans);
           }
           else if(nums[i] != 0){
               if(count >= 1) solution.push_back(0);
               else solution.push_back(ans/nums[i]);
           }
           
       }
       return solution;
    }
};
