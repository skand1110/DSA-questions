bool isPossible(vector<int> &stalls, int k, int mid){
    int cowCount = 1;	//start with first cow
    int lastPosition = stalls[0];	//last position is the position where we kept first cow and from where we are measuring safe distance
    //arr[i] will denote the dynamic place where i am wanting to place my 2nd cow such that their min distance is met and maximised
    for(int i =0; i<stalls.size();i++){
        if(stalls[i]-lastPosition >= mid){	//distance between the placing position and placed position should be greater than equal to the mid value which is required
            //place cow=> how to place -> increement cow value count
            cowCount++;
            if(cowCount==k){
                return true;	//if we got the cows as needed
            }
            //update lastPosition of cow & keep checking on right side for further max value
            lastPosition = stalls[i];
        }//if end
    }//for end
    return false;	//if not found till here -> no solution exists with this value of mid, so return false
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //sort stall array for getting a linear number line for code
    sort(stalls.begin(), stalls.end());
    
    int start = 0;
    int maxi=-1;
    for(int i =0; i<stalls.size(); i++){
        maxi = max(maxi,stalls[i]);
    }
    int end = maxi;
    int ans = -1;
    int mid  = start+(end-start)/2;
    
    while(start<=end){
        if(isPossible(stalls,k,mid)){
            //possible solution -> save in ans and move right coz we need to find largest max distance, right side move
            ans = mid;
            start = mid+1;
        }
        else{
            //solution not possible, move left
            end = mid-1;
        }
        mid = start+(end-start)/2;
    }
    return ans;
}
