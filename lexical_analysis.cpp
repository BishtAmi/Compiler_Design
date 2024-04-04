#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isKeyword(const string &str)
{
    string keywords[] = {
        "asm", "double", "new", "switch", "auto", "else", "operator", "template",
        "break", "enum", "private", "this", "case", "extern", "protected", "throw",
        "catch", "float", "public", "try", "char", "for", "register", "typedef",
        "class", "friend", "return", "union", "const", "goto", "short", "unsigned",
        "continue", "if", "signed", "virtual", "default", "inline", "sizeof", "void",
        "delete", "int", "static", "volatile", "do", "long", "struct", "while"};

    for (const auto &keyword : keywords)
    {
        if (str == keyword)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ifstream f("check.txt");
    char ch;
    string buffer;
    char operators[] = {'/', '+', '-', '*', '%'};

    if (!f.is_open())
    {
        cout << "Issue in opening the file\n";
    }
    else
    {
        while (f.get(ch))
        {
            for (char op : operators)
            {
                if (op == ch)
                {
                    cout << ch << ": is an operator\n";
                }
            }

            if (isalpha(ch))
            {
                buffer += ch;
            }
            else if (ch == ' ' || ch == '\n')
            {
                if (!buffer.empty())
                {
                    if (isKeyword(buffer))
                    {
                        cout << buffer << " is a keyword\n";
                    }
                    else
                    {
                        cout << buffer << " is an identifier\n";
                    }
                    buffer.clear();
                }
            }
        }
    }

    f.close();
    return 0;
}
