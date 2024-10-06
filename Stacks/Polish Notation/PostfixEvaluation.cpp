// Don't do amendment in code otherwise program will malfunction
#include "InfixToPostFix.cpp"
#include <cmath>
int eval(int val1,char op,int val2){ // op is an operator that operates on val1 and val2
    if(op == '^'){ // If op is an exponential function
        return (pow(val1,val2));
    }
    else if(op == '/'){
        return (val1/val2);
    }
    else if(op == '*'){
        return (val1*val2);
    }
    else if(op == '-'){
        return (val1-val2);
    }
    else if(op == '+'){
        return (val1+val2);
    }
    else{
        cout<<"Invalid operator\n";
    }
    return -1;
}
int evaluatePostFix(string exp){ // Postfix expression exp in form of string 
    stack<int>st; // helping stack
    exp.push_back(')'); //Add a right parenthesis ")” at the end  of P. [This act as delimeter]
    for(int i=0;i<exp.length();i++){
        if(exp[i]>=48 && exp[i]<=57){ // If char is an operand i.e numbers from 1 to 9
            st.push(exp[i]-48); // Push Operand in stack
        }
        else{
            if(exp[i] != ')'){ // if char is operator
                int val2 = st.top(); // Ascii value of 1 to 9 ranges from 48 to 57
                st.pop(); // Removing the 2nd operand
                int val1 = st.top(); // Ascii value of 1 to 9 ranges from 48 to 57
                st.pop(); // Removing the 1st operand
                char op = exp[i];
                int ans = eval(val1,op,val2);
                st.push(ans);
            }
        }
    }
    return st.top();
}