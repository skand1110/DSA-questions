void push(stack<int>& s, int a){
	s.push(a);
}

bool isFull(stack<int>& s,int n){
	if(s.size()==n){
	    return 1;
	}
	return 0;
}

bool isEmpty(stack<int>& s){
	return s.empty();
}

int pop(stack<int>& s){
	int a=s.top();
	s.pop();
	return a;
}

int getMin(stack<int>& s){
	int ans=s.top();
    while(!s.empty()){
        ans=min(ans,s.top());
        s.pop();
        
    }
    return ans;
}
