#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        vector<int>b(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        int flag=0;
        int swapi=0;
        for(int i=0;i<n;i++)
        {
            int pos=-1;
            for(int j=i;j<n;j++)
            {
                if(a[j]<=b[i])
                {
                    pos=j;
                    break;
                }
            }
            if(pos==-1)
            {
                flag=1;
                break;
            }
            for(int j=pos;j>i;j--)
            {
                swap(a[j],a[j-1]);
                swapi++;
            }
        }
        if(flag==1)
        cout<<"-1\n";
        else
        cout<<swapi<<"\n";
    }
    return 0;
}