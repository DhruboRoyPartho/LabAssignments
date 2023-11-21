#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

stack<float> st;

float prefix_expression(string str)
{
    for(int i = str.length() - 1; i>=0;i--){
        if(str[i]>='0' && str[i]<='9'){
            st.push((float)str[i]-48);
        }
        else{
            float op1 = st.top();
            st.pop();
            float op2 = st.top();
            st.pop();
            switch(str[i]){
                case '+':
                    st.push(op1+op2);
                    break;
                case '-':
                    st.push(op1-op2);
                    break;
                case '*':
                    st.push(op1*op2);
                    break;
                case '/':
                    st.push(op1/op2);
                    break;
                case '^':
                    st.push(pow(op1,op2));
                    break;
            }
        }
    }
    return st.top();
}

float postfix_expression(string str)
{
    for(int i=0;i<str.length();i++){
        if(str[i]>='0' && str[i]<='9'){
            st.push(str[i] - '0');
        }
        else{
            float op1 = st.top();
            st.pop();
            float op2 = st.top();
            st.pop();
            switch(str[i]){
                case '+':
                    st.push(op2+op1);
                    break;
                case '-':
                    st.push(op2-op1);
                    break;
                case '*':
                    st.push(op2*op1);
                    break;
                case '/':
                    st.push(op2/op1);
                    break;
                case '^':
                    st.push(pow(op2,op1));
                    break;
            }
        }
    }
    return st.top();
}

int main()
{
    cout<<prefix_expression("+*423")<<endl;  //(4*2)+3  === 42*3+
    cout<<postfix_expression("42*3+")<<endl;
    return 0;
}