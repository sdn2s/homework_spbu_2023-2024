// Including necessary header files
#include <iostream> // For input and output operations
#include <stack> // For stack data structure
#include <omp.h> // For OpenMP parallelization
using namespace std;
// Function to check if the parentheses in a given string are balanced or not
bool checkParentheses(const string& str)
{
	// Create a stack to store the opening parentheses
	stack<char> s;
    // Divide the string into two equal parts and execute each half in a separate thread
#pragma omp parallel sections num_threads(2)
    {
        // First half of the string
#pragma omp section
        {
            // Iterate through the first half of the string
            for (size_t i = 0; i < str.size() / 2; ++i)
            {
                // If the current character is an opening parenthesis, push it onto the stack
                if (str[i] == '(' || str[i] == '[' || str[i] == '{')
                {
                    s.push(str[i]);
                }
                // If the current character is a closing parenthesis, pop the top element from the stack and check if they match
                else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
                {
                    // If the stack is empty, the parentheses are not balanced
                    if (s.empty())
                    {
                        return false;
                    }
                    // Otherwise, pop the top element from the stack and check if it matches the current closing parenthesis
                    char top = s.top();
                    s.pop();
                    if ((top == '(' && str[i] != ')') ||
                        (top == '[' && str[i] != ']') ||
                        (top == '{' && str[i] != '}'))
                    {
                        return false;
                    }
                }
            }
        }

        // Second half of the string
#pragma omp section
        {
            // Iterate through the second half of the string
            for (size_t i = str.size() / 2; i < str.size(); ++i)
            {
                // If the current character is an opening parenthesis, push it onto the stack
                if (str[i] == '(' || str[i] == '[' || str[i] == '{')
                {
                    s.push(str[i]);
                }
                // If the current character is a closing parenthesis, pop the top element from the stack and check if they match
                else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
                {
                    // If the stack is empty, the parentheses are not balanced
                    if (s.empty())
                    {
                        return false;
                    }
                    // Otherwise, pop the top element from the stack and check if it matches the current closing parenthesis
                    char top = s.top();
                    s.pop();
                    if ((top == '(' && str[i] != ')') ||
                        (top == '[' && str[i] != ']') ||
                        (top == '{' && str[i] != '}'))
                    {
                        return false;
                    }
                }
            }
        }
    }

    // If the stack is empty, the parentheses are balanced
    return s.empty();
}
// Main function to test the checkParentheses function
int main()
{
    // Input string to check for balanced parentheses
    string str = "{()}[()]";
    if (checkParentheses(str))
    {
        cout << "The parentheses are balanced." << endl;
    }
    else
    {
        cout << "The parentheses are not balanced." << endl;
    }
    return 0;
}