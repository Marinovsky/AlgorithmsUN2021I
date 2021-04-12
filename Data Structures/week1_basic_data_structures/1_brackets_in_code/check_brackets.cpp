
#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    std::stack <Bracket> opening_brackets_stack;
    int position;
    for (position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket temp(next,position);
            opening_brackets_stack.push(temp);
        }

        if (next == ')' || next == ']' || next == '}') {
            if(!opening_brackets_stack.empty()){
                    if(!opening_brackets_stack.top().Matchc(next)){
                        Bracket temp(next,position);
                        opening_brackets_stack.push(temp);
                        break;
                    }else{
                        opening_brackets_stack.pop();
                    }
            }else{
                Bracket temp(next,position);
                opening_brackets_stack.push(temp);
                break;
            }
        }
    }
    if(opening_brackets_stack.empty()){
        std::cout<<"Success"<<std::endl;
    }else{
        std::cout<<(opening_brackets_stack.top().position+1)<<std::endl;
    }

    return 0;
}
