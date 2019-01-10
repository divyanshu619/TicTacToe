#include "dllmain.h"

void DLL_EXPORT xyz(const LPCSTR sometext)
{
    MessageBoxA(0, sometext, "DLL Message", MB_OK | MB_ICONINFORMATION);
}
int st[8][3]= {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
int corners[4] = {0,2,6,8};
int edges[4] = {1,3,5,7};
int status[8]= {0};
void DLL_EXPORT _check(int a[])
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
}

int DLL_EXPORT _rfill(int a[])
{
    int i,flag=0;
    for(i=0; i<8; i++)
        if(status[i]==2||status[i]==-2)
        {
            flag=1;
            break;
        }
    if(flag==1)
    {
        for(int j=0; j<3; j++)
        {
            if(a[st[i][j]]==0)
                return st[i][j];
        }

    }
    else if(a[4]==0)
    {
        return 4;
    }
    else if (a[4]!=0)
    {
        if(a[4]==-1)
        {
            if(a[0]==1&&a[8]==0)
                return 8;
            else if(a[0]==0 && a[8]==1)
                return 0;
            else if(a[2]==0 && a[6]==1)
                return 2;
            else if(a[2]==1 && a[6]==0)
                return 6;
            else if (a[0]==1 && a[8]==1)
                for(int q=0; q<4; q++)
                {
                    if (a[edges[q]]==0)
                    {
                        return edges[q];
                    }
                }
            else if (a[2]==1 && a[6]==1)
                for(int q=0; q<4; q++)
                {
                    if (a[edges[q]]==0)
                    {
                        return edges[q];
                    }
                }
            else
            {
                for (int k=0; k<9; k++)
                    if(a[k]==0)
                        return k;
            }


        }
        else if(a[4]==1)
        {
            for(int q=0; q<4; q++)
            {
                if (a[corners[q]]==0)
                {
                    return corners[q];
                }
            }
            for (int k=0; k<9; k++)
                if(a[k]==0)
                    return k;
        }
        else
            for (int k=0; k<9; k++)
                if(a[k]==0)
                    return k;
    }
    else
    {
        for (int k=0; k<9; k++)
            if(a[k]==0)
                return k;
    }

}

int DLL_EXPORT _CheckVictor(int ttt[9])
{
    int sum=0;
    for(int i=0; i<=2; i++)
    {
        sum = 0;
        for(int j=0; j<=6; j+=3)
        {
            sum+=ttt[i+j];
            if(sum==3)
                return 1;
            if(sum==-3)
                return -1;
        }
    }
    for(int i=0; i<=6; i+=3)
    {
        sum=0;
        for(int j=0; j<=2; j++)
        {
            sum+=ttt[i+j];
            if(sum==3)
                return 1;
            if(sum==-3)
                return -1;
        }
    }
    sum = 0;
    for(int i=0; i<=8; i+=4)
    {
        sum+=ttt[i];
        if(sum==3)
            return 1;
        if(sum==-3)
            return -1;
    }
    sum = 0;
    for(int i=2; i<=6; i+=2)
    {
        sum+=ttt[i];
        if(sum==3)
            return 1;
        if(sum==-3)
            return -1;
    }
    return 0;
}

int DLL_EXPORT AI(int a[])
{
    int r;
    _check(a);
    r=_rfill(a);
    return r;
}
extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        break;

    case DLL_PROCESS_DETACH:
        break;

    case DLL_THREAD_ATTACH:
        break;

    case DLL_THREAD_DETACH:
        break;
    }
    return TRUE;
}
