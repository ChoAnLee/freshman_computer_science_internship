/*
 * Practice 10
 * Name: 李倬安
 * Student Number: 110403516
 * Course 2022-CE1003-A
 */

#include <iostream>
#include <vector>
using namespace std;

// ========== Global Variables ==========

vector<string> g_token_list; // Global token list
char g_char = 0;

// ========== Print Function ==========

void print_types_info(int i_num, int n_num, int s_num)
{
    cout << "Identifier: " << i_num << ", "
         << "Number: " << n_num << ", "
         << "Special Symbol: " << s_num << endl;
}

void print_invalid_command()
{
    cout << "Invalid command." << endl;
}

void print_token(string token)
{
    cout << "[" << token << "]" << endl;
}

void print_token_sum(int sum)
{
    cout << "Total number of tokens: " << sum << endl;
}

// ========== Other Functions ==========

void skip_white_space()
{
    // skip white space such as ' ', '\t', '\n', and make g_char the first character of the next token
    if (g_char == ' ' || g_char == '\t' || g_char == '\n')
    {
        cin.get(g_char);
        skip_white_space();
    }
    /*Your Code Here*/
}

bool is_identifier(char c)
{
    // given a character, return true if it is a part of a identifier
    bool result = false;
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_')
        result = true;
    else
        return false;
    /*Your Code Here*/
    return result;
}

bool is_number(char c)
{
    // given a character, return true if it is a number

    bool result = false;
    if (c >= '0' && c <= '9')
        result = true;
    else
        return false;
    /*Your Code Here*/
    return result;
}

bool is_special_symbol(char c)
{
    // given a character, return true if it is a special symbol or not

    bool result = false;
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' || c == ',' || c == ';' || c == '.')
        result = true;
    else if (c == '!' || c == '<' || c == '>' || c == ':' || c == '&' || c == '|' || c == '^' || c == '%' || c == '\'' || c == '\"')
        return true;
    else
        return false;
    /*Your Code Here*/
    return result;
}

void get_user_input()
{
    // Get user input until END_OF_FILE appears, and store the tokens into g_token_list.
    string s;
    while (cin >> s)
    {
        if (s == "END_OF_FILE")
            break;
        g_token_list.push_back(s);
    }
    /*Your Code Here*/
}

string get_token_type(string token)
{
    // Given a token, return the type of the token.(Identifier, Number, or Special Symbol?)

    string type;
    if (is_identifier(token[0]))
        type = "Identifier";
    else if (is_number(token[0]))
        type = "Number";
    else if (is_special_symbol(token[0]))
        type = "Special Symbol";
    /*Your Code Here*/
    return type;
}

void excute_command(int cmd)
{
    // Given a command:
    // if command == 1, print token sum
    // if command == 2, print all tokens
    // if command == 3, token sum in each cases
    switch (cmd)
    {
    case 1:
    {
        print_token_sum(g_token_list.size());
        break;
    }
    case 2:
    {
        for (int i = 0; i < g_token_list.size(); i++)
        {
            print_token(g_token_list[i]);
        }
        break;
    }
    case 3:
    {
        int i_num = 0, n_num = 0, s_num = 0;
        for (int i = 0; i < g_token_list.size(); i++)
        {
            if (get_token_type(g_token_list[i]) == "Identifier")
                i_num++;
            else if (get_token_type(g_token_list[i]) == "Number")
                n_num++;
            else if (get_token_type(g_token_list[i]) == "Special Symbol")
                s_num++;
        }
        print_types_info(i_num, n_num, s_num);
        break;
    }
    default:
        print_invalid_command();
        break;
    }
}

// ========== Main Function ==========

int main()
{
    // Get User Input form the input stream, and execute the command until command == 0.
    get_user_input();
    int cmd;
    while (cin >> cmd)
    {
        if (cmd == 0)
            break;
        excute_command(cmd);
    }
    return 0;
    /*Your Code Here*/
}
