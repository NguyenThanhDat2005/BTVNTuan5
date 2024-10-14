#include<bits/stdc++.h>
using namespace std;
void sortColors(char colors[], int n)
{
    int red=0, white=0, blue=0;
    for(int i=0; i<n; i++)
    {
        if(colors[i]=='d')
        {
            red++;
        }
        else if(colors[i]=='t')
        {
            white++;
        }
        else if(colors[i]=='x')
        {
            blue++;
        }
    }
    int index=0;
    for(int i=0; i<red; i++)
    {
        colors[index++]='d';
    }
    for(int i=0; i<white; i++)
    {
        colors[index++]='t';
    }
    for(int i=0; i<blue; i++)
    {
        colors[index++]='x';
    }
}
    int main()
    {
        char colors[]={'x','d','x','d','d','t','d','x','t'};
        int n=sizeof(colors)/sizeof(colors[0]);
        sortColors(colors,n);
        cout<<"Day sau sap xep la: ";
        for(int i=0; i<n; i++)
        {
            cout<<colors[i];
            if(i<n-1)
            {
                cout<<", ";
            }
        }
        return 0;
    }

