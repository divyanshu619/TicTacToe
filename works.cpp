#include<iostream>

using namespace std;

int st[8][3]= {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
int status[8]= {0};

void check(int a[])
{

    int s;
    for(int i=0; i<8; i++)
    {
        s=0;
        for(int j=0; j<3; j++)
        {
            s+=a[st[i][j]];

        }
        status[i]=s;
    }
    //return status;
}

int rfill(int a[])
{
    int i;
    for(i=0; i<8; i++)
        if(status[i]==2||status[i]==-2)
            break;
    for(int j=0; j<3; j++)
    {
        if(a[st[i][j]]==0)
            return st[i][j];
    }
}


int main()
{
    int a[]= {1,0,-1,0,-1,0,1,0,1};

    //int *temp = check(a);
    check(a);
    for(int i=0; i<8; i++)
        cout<<status[i]<<" ";
    cout<<rfill(a);


}
