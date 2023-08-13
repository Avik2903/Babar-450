#include<bits/stdc++.h>
using namespace std;
void swap(char *a, char *b)
{
    int temp= *a;
    *a=*b;
    *b=temp;
}
void fnext(char s[],int n)
{
    int i,j;
    for(i=n-1;i>0;i--)
    {
        if(s[i]>s[i-1])
        break;
    }
    if(i==0)
    {
        cout<<"Not Possible";
        return;
    }
    int x = s[i-1], a = i;
    for (j = i+1; j < n; j++)
        if (s[j] > x && s[j] < s[a])
            a = j;
    
    swap(&s[a],&s[i-1]);
    sort(s+i,s+n);
    cout<<s;
    return;
}
int main()
{
    char s[]="218765";
    int n = strlen(s);
    fnext(s,n);
    return 0;
}