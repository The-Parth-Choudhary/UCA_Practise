bool isValid(char* s) {
    char stack[strlen(s)];
    int top = -1;

    char c = *s;
    
    for(int i = 0; i < strlen(s); i++){
        if(c == '(' || c == '[' || c == '{'){
            stack[++top] = c;
        }
        else{
            if(top == -1){
                return false;
            }
            else{
                if(c == ')' && stack[top] != '('){
                    return false;
                }
                else if(c == '}' && stack[top] != '{'){
                    return false;
                }
                else if(c == ']' && stack[top] != '['){
                    return false;
                }

                top--;
            }
        }

        c = *(s+i+1);
    }

    return top == -1;
}