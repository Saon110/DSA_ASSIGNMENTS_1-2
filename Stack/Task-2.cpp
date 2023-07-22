#include<iostream>
#include"StackArr.h"

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int priority(char op) {
    if (op == '+' || op == '-')return 1;
    else if (op == '*' || op == '/')return 2;
    return 0;
}

bool isUnary(int i,string &str){

    if(str[i-1]=='('||str[i-1]=='+'||str[i-1]=='*'||str[i-1]=='/')return true;
    return false;
}



string convert(string infix)
{
    int i = 0;
    string postfix = "";
    char c;
    // using inbuilt stack< > from C++ stack library
    Stack <char>s;

    while(infix[i]!='\0')
    {
        // if operand add to the postfix expression
        if(isdigit(infix[i]))          
        {
            postfix += infix[i];
            i++;
        }
        // if opening bracket then push the stack
        else if(infix[i]=='(')
        {
            s.push(infix[i]);
            i++;
        }
        // if closing bracket encounted then keep popping from stack until 
        // closing a pair opening bracket is not encountered
        else if(infix[i]==')')
        {
            while(s.topValue()!='('){
                postfix += s.topValue();
                c=s.pop();
            }
            c=s.pop();
            i++;
        }
        else            
        {
            while (!s.isEmpty() && priority(infix[i]) <= priority(s.topValue())){
                postfix += s.topValue();
                c=s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while(!s.isEmpty()){
        postfix += s.topValue();
        c=s.pop();
    }


    //cout << "Postfix is : " << postfix; //it will print postfix conversion  
    return postfix;
}


//validity

bool isvalid(string str){

    int operators=0;
    int operand=0;
    int i=0;
    while(str[i]!='\0'){
        if(str[i]==')'||str[i]=='('){
            return false;
        }
        i++;
    }
    //i=0;
    // while(str[i]!='\0'){
    //     if(isOperator(str[i]))operators++;
    //     else if(str[i]!='('&&str[i]!=')')operand++;
    //     i++;
    // }
    // if(operand<operators){
    //     return false;
    // }
    return true;

}

float evaluator(string str){

    int l=str.length();
    Stack<float> op;
    float val;
    //int i;
    for(int i=0;i<l;i++){

        if(isdigit(str[i])){
            float a;
            a=str[i]-'0';
            op.push(a);

        }

        else{

            // if(op.length()<2){
            //     std::cout<<"Invalid expression"<<endl;
            //     return INT_MIN;
            // }

            {

                float a=op.pop();
                float b=op.pop();

                char ch=str[i];

                switch (ch)
                {
                case '+':
                    
                    val=b+a;
                    op.push(val);
                    break;

                case '-':
                    val=b-a;
                    op.push(val);
                    break;    
                case '*':
                    val=b*a;
                    op.push(val);
                    break;

                case '/':
                    val=b/a;
                    op.push(val);
                    break;    

                default:
                    break;
                }
                
            }
            //op.push(val);
        }
        //i++;
    }
    return op.topValue();

}


int main(){

    string str;
    std::cin>>str;
    string e;
    e=convert(str);
    std::cout<<e<<endl;
    if(!isvalid(e)){
        std::cout<<"Expresion not valid"<<endl;
    }
    //std::cout<<e<<endl;
    else
    {std::cout<<evaluator(e);}
    
}