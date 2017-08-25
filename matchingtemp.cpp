//matcher(expression)
//    for each character in expression
//        if  the character is an opener
//            push on stack
//        else if the character is a closr
//            if stack is empty return false
//            if the (opener at) the top of the stack does not match the closer
//               return false
//            pop the stack
//
//     if the stack is not empty return false
//     return true

//This is what I have.

template <typename T>
bool parenMatching(string c) {
    stack<char> s;
    for (int i = 0; i < c.size(); i++) {
            c2 = c[i];
        if (c2 == '(' || c2 == '[' || c2 == '{' || c2 == '<')
            s.push(c2);
        else if (c2 == ')' || c2 == ']' || c2 == '}' || c2 == '>') {
            if (s.empty()) return false;
            if (s.top() != '(' || s.top() != '[' || s.top() != '{' || s.top() != '<')
                return false;
            s.pop();
        }
    }
}
