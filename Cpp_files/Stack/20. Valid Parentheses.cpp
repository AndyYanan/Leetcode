
class Solution {
public:
    bool isValid(string s) {
      stack<char> stackLeft;
      for(int i = 0; i < s.size(); ++i){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stackLeft.push(s[i]);
        }else{
            if(stackLeft.empty())
                return false;
            char tmpLest = stackLeft.top(); stackLeft.pop();
            if(tmpLest == '[' && s[i] != ']'){
                return false;
            }else if(tmpLest == '(' && s[i] != ')'){
                return false;
            }else if(tmpLest == '{' && s[i] != '}'){
                return false;
            }
        }
      }
      return stackLeft.empty();
#if 0
        stack<char> v;
        for(auto & ch : s){
            if(ch  == '('){
                v.push(')');
            }else if(ch  == '['){
                v.push(']');
            }else if(ch  == '{'){
                v.push('}');
            }else if(v.empty() || (v.top() != ch)){
                return false;
            }else if ((v.top() == ch)){
                v.pop();
            }
        }
        return v.empty();
#endif
    }
};
/*class Solution {
public:
    bool isValid(string s) {
        stack<char> v;
        for(int i = 0; i < s.size(); i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                v.push(s[i]);
            }else{
                if(v.empty() || (v.top()=='(' && s[i] != ')') || (v.top()=='[' && s[i] != ']') || (v.top()=='{' && s[i] != '}')){
                    return false;
                }else{
                    v.pop();
                }
            }
        }
        return v.empty();
    }
};*/