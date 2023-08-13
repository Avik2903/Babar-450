#include <iostream>
using namespace std;
bool areBracketsBalanced(string s) {
		int i=-1;
		for(auto& ch:s){
			if(ch=='(' || ch=='{' || ch=='[')
				s[++i]=ch;
			else{
				if(i>=0 && ((s[i]=='(' && ch==')') || (s[i]=='{' && ch=='}') || (s[i]=='[' && ch==']')))
					i--;
				else
					return false;
			}
		}
		return i==-1;
	}
int main()
{
	string expr = "{()}[]";
	if (areBracketsBalanced(expr))
		cout << "Balanced";
	else
		cout << "Not Balanced";
	return 0;
}

/*#include<bits/stdc++.h>
using namespace std;
void bal(string s)
{
    stack<char> temp;
    for(int i=0;i<s.length();i++)
    {
        if(temp.empty())
        {
            temp.push(s[i]);
        }
        else if((temp.top() == '(' && s[i] == ')') || (temp.top() == '{' && s[i] == '}') || (temp.top() == '[' && s[i]== ']'))
        {
            temp.pop();
        }
        else
        {
            temp.push(s[i]);
        }
    }
    if(temp.empty())
    cout<<"Balanced Expression";
    else
    cout<<"Not Balanced Expression";
}
int main()
{
    string s;
    getline(cin,s);
    bal(s);
    return 0;
}*/

