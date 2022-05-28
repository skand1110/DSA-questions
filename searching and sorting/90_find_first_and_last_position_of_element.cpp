//Approach 1: traverse array from the front and then from the back

vector<int> find(int arr[], int n , int x )
{
    vector<int> num;
    for(int i=0; i<n; i++){
        if(arr[i]==x){
            num.push_back(i);
            break;
        }
    }
    for(int i=n-1; i>=0; i--){
        if(arr[i]==x){
            num.push_back(i);
            break;
        }
    }
    if(num.empty()==1){
        return {-1, -1};
    }
    return num;
    
}