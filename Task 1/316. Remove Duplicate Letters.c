char* removeDuplicateLetters(char* s) {
    int last[26] = {0};

    for(int i = 0; i < strlen(s); i++){
        last[s[i] - 'a'] = i;
    }

    bool visited[26] = {false};
    int stack[26];
    int top = -1;

    for(int i = 0; i < strlen(s); i++){
        int curr = s[i] - 'a';

        if(visited[curr] == true){
            continue;
        }

        while(top != -1 && curr < stack[top] && i < last[stack[top]]){
            visited[stack[top]] = false;
            top--;
        }

        stack[++top] = curr;
        visited[curr] = true;
    }

    char* ans = (char*)malloc((top + 2) * sizeof(char));
    int index = 0;

    while(top != -1){
        ans[index++] = (char)(stack[top--] + 'a');
    }

    ans[index] = '\0';

    int start = 0;
    int end = index - 1;
    while(start < end){
        char temp = ans[start];
        ans[start] = ans[end];
        ans[end] = temp;
        
        start++;
        end--;
    }

    return ans;
}