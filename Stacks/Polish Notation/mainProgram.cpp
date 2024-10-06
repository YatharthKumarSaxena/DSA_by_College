// Note:- In your algebraic expression value of operand must be from 0 to 9
// if operand is not single digit program will malfunction
// Don't do amendment in code otherwise program will malfunction
#include "PostfixEvaluation.cpp"
int main(){
    cout<<"Please enter your Infix Expression = ";
    string exp;
    cin>>exp;
    string postExp = infixToPostfix(exp);
    cout<<"The postfix expression of your infix expression = "<<postExp<<endl;
    cout<<"The value of your expression by postfix expression = "<<evaluatePostFix(postExp);
    return 0;
}