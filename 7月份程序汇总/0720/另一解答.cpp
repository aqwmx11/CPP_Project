#include <cstring>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    string inp;
    int ndir = 1;
    priority_queue <string,vector<string>, greater<string> > q[1005];
    int mark = 1;
    int ca = 1;

    while(true)
    {
        cin >> inp;
        if(inp[0] == '#') break;
        if(mark)
        {
            cout <<"DATA SET "<< ca << ":" <<endl;
            cout << "ROOT" << endl;
            mark = 0;
        }
        if(inp[0] == 'd')
        {
            for(int i = 0; i < ndir; i++)
                cout << "|     ";
            cout << inp << endl;
            ndir++;
        }
        else if(inp[0] == 'f')
        {
            q[ndir].push(inp);
        }
        else if(inp[0] == ']' || inp[0] == '*')
        {
            while(!q[ndir].empty())
            {
                for(int i = 0; i < ndir - 1; i++)
                    cout << "|     ";
                cout << q[ndir].top() << endl;
                q[ndir].pop();
            }
            ndir--;
        }
        if(inp[0] == '*')
        {
            mark = 1;
            ndir = 1;
            ca++;
            cout <<endl;
        }
    }
    return 0;
}
