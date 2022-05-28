//given three numbers, we find the max and min

class Solution{
  public:
    int middle(int A, int B, int C){
        int mini = min({A, B, C});
        int maxi = max({A, B, C});
        
        if(mini != A and maxi != A) {
            return A;
        }
        
        if(mini != B and maxi != B) {
            return B;
        }
        
        return C;
    }
};
