char* reverse(char *S, int len)
{
    stack<char> st;
    char *v = new char[len];
    
    for(int i=0; i<len; i++){
        st.push(S[i]);
    }
    
    for(int i=0; i<len; i++){
        v[i]=st.top();
        st.pop();
    }
    
    return v;
}
