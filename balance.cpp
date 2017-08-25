#include <string>
#include <stack>
#include <iostream>
#include <stdio.h>
using namespace std;
// Added to test git 2
//added this for test3
bool ArePair(char opening, char closing)
{
  cout<<"In Arepair and I have -->" , opening , "  ==" ,closing , "\n";
  cout<<opening;
  cout<<closing;
  //printf("the top value is %s",opening);
    if (opening == '(' && closing == ')') return true;
    else if (opening == '[' && closing == ']') return true;
    else if (opening == '{' && closing == '}') return true;
    return false;
}
bool CheckIfInBalance(string user_string)
{
        stack<char> S;  //declare our stack
         cout<<"In CheckIfInBalance string is -->" + user_string  || "\n";

        for (int i=0;i<user_string.length(); i++)    //for loop to process all the items
        {
            if(user_string[i] == '(' || user_string[i] == '{' || user_string[i] == '[')
                        S.push(user_string[i]);
               else if (user_string[i] == ']' || user_string[i] == ')'||  user_string[i] == '}' )  // if it is a close then check
                {
                  if (S.empty() || !ArePair(S.top(), user_string[i]))  // if empty stack then not balanced

                        return false;                       //
                    else
                        S.pop();  // if it pairs then pop and don't push
                }
        }
        return S.empty() ? true:false;

 }

//Main line

int main()
{
        string expression;
        cout<<"Enter an expression:";  //get an expression from user
        cin>>expression;
        if (CheckIfInBalance(expression))
            cout<<"It is balanced!\n";
        else
            cout<<"not balanced\n";


}
