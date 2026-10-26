#include<iostream>
#include<stack>
using namespace std;

bool Paran_Match(string str){
    stack<char>s;
    for(char ch :str){
        if(ch=='('||ch=='{'||ch=='['){
            s.push(ch);
        }
        else if(ch==')'||ch=='}'||ch==']'){
            if(s.empty()){
                return false;
            }
            char topchar=s.top();
            s.pop();
            if((ch==')'&& topchar!='(')||
            (ch=='}'&& topchar!='{')||
            (ch==']'&& topchar!='[')){
                return false;
            }
        }
    }
    return s.empty();
}
int main() {
    string expr = "{[()}";
    if (Paran_Match(expr)) {
        cout << "Balanced\n";
    } else {
        cout << "Not Balanced\n";
    }
    return 0;
}
