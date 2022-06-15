class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	     vector<pair<int,int>>v;
         for(int i=0; i<nums.size(); i++){
             v.push_back({nums[i],i});
         }
         int c=0;
         sort(v.begin(),v.end());
         for(int i=0; i<nums.size(); i++){
             if(v[i].second!=i){
                 swap(v[i],v[v[i].second]);
                 c++;
                 i--;
             }
         }
         return c;
	}
};
