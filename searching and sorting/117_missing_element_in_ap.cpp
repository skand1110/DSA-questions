//Find the missing element from an ordered array arr[], consisting of N elements representing an Arithmetic Progression(AP).
//Approach: Binary search
class Solution{   
public:
    int findMissing(int arr[], int n) {
        int d=(arr[n-1]- arr[0])/(n);
        for(int i=0; i<n; i++){
            int element= arr[0]+ i*d;
            if(element!=arr[i]){
                return element;
            }
        }
    }
};
