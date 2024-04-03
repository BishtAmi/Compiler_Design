#include <iostream>
#include <string>
#include <cstring>



using namespace std;

char input[100];
int i, l;

bool E();
bool EP();
bool T();
bool TP();
bool F();

int main()
{
    cout << "\nRecursive descent parsing for the following grammar\n";
    cout << "\nE->TE'\nE'->+TE'/@\nT->FT'\nT'->*FT'/@\nF->(E)/ID\n";
    cout << "\nEnter the string to be checked:";
    cin.getline(input, 100);

    l = strlen(input);
    i = 0;

    if (E())
    {
        if (input[i] == '\0')
            cout << "\nString is accepted";
        else
            cout << "\nString is not accepted";
    }
    else
        cout << "\nString not accepted";

    return 0;
}

bool E()
{
    if (T())
    {
        if (EP())
            return true;
        else
            return false;
    }
    else
        return false;
}

bool EP()
{
    if (input[i] == '+')
    {
        i++;
        if (T())
        {
            if (EP())
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return true;
}

bool T()
{
    if (F())
    {
        if (TP())
            return true;
        else
            return false;
    }
    else
        return false;
}

bool TP()
{
    if (input[i] == '*')
    {
        i++;
        if (F())
        {
            if (TP())
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return true;
}

bool F()
{
    if (input[i] == '(')
    {
        i++;
        if (E())
        {
            if (input[i] == ')')
            {
                i++;
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    else if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
    {
        i++;
        return true;
    }
    else
        return false;
}
