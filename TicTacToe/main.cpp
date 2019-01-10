#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"
#include "dllmain.h"

HINSTANCE hInst;
HWND hbn;

int TFlag=1;
int TCount=0;
int CVResult;
int TTTArray[9]= {0,0,0,
                  0,0,0,
                  0,0,0
                 };

int _DrawUI(HWND hwndDlg);
int _ChangeTurn();
int _ResetUI(HWND hwndDlg);
int _move(int,HWND);

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)//THIS FUNCTION IS THE EVENT MANAGER FOR THE DIALOG "IDD_TICTAC"..
{
    switch(uMsg)
    {
    case WM_INITDIALOG:
    {
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndDlg, 0);
    }
    return TRUE;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        case IDC_BUTTON1:
        case IDC_BUTTON2:
        case IDC_BUTTON3:
        case IDC_BUTTON4:
        case IDC_BUTTON5:
        case IDC_BUTTON6:
        case IDC_BUTTON7:
        case IDC_BUTTON8:
        case IDC_BUTTON9://I COULD HAVE USED THE RANGE OR LIMITS...THIS IS FOR THE SAKE OF UNDERSTANDABLITY....
            _move(LOWORD(wParam),hwndDlg);
            if(TCount==0)
                break;
            _move(1000+AI(TTTArray),hwndDlg);
            break;
        case IDM_EXIT:
            EndDialog(hwndDlg, 0);
            break;
        case IDM_NEW:
            _ResetUI(hwndDlg);
            break;
        case IDM_ABOUT:
            MessageBox(hwndDlg,"T O X IC Game\nUI Coded by : DIVYANSHU & HARSH\nRecoded in C by : HARSH\nEasy Difficulty Coded by : DIVYANSHU\nMedium Difficulty Coded by : DIVYANSHU\nHard Difficulty Coded by : DIVYANSHU","About us",MB_OK);
            break;
        }
    }
    return TRUE;
    }
    return FALSE;

}

int _DrawUI(HWND hwndDlg)
{
    for(int i=0; i<=8; i++)
    {
        if(TTTArray[i]==1)
            SetDlgItemText(hwndDlg, (IDC_BUTTON1+i), "X"); //MANIPULATION OF SERIAL WISE ARRANGEMENT OF BUTTON CONSTANTS SEE "RESOURCE.H"...
        else if(TTTArray[i]==-1)
            SetDlgItemText(hwndDlg, (IDC_BUTTON1+i), "O");
        else
            SetDlgItemText(hwndDlg, (IDC_BUTTON1+i), "");
    }
    return 0;
}
int _ChangeTurn()
{
    if(TFlag==1)
        TFlag=-1;
    else
        TFlag=1;
    return 0;
}
int _ResetUI(HWND hwndDlg)
{
    for(int i=0; i<=8; i++)
    {
        TTTArray[i]=0;
        hbn=GetDlgItem(hwndDlg,1000+i);
        EnableWindow(hbn,TRUE);
    }
    _DrawUI(hwndDlg);
    TFlag=1;
    TCount=0;
    return 0;
}
int _move(int choice,HWND hwndDlg)
{
    TCount++;
    TTTArray[choice-1000]=TFlag;
    _ChangeTurn();
    _DrawUI(hwndDlg);
    hbn=GetDlgItem(hwndDlg,choice);
    EnableWindow(hbn,FALSE);
    CVResult=_CheckVictor(TTTArray);
    if(CVResult==1)
    {
        MessageBox(hwndDlg,"X wins","Result",MB_OK);
        _ResetUI(hwndDlg);
    }
    else if(CVResult==-1)
    {
        MessageBox(hwndDlg,"O wins","Result",MB_OK);
        _ResetUI(hwndDlg);
    }
    else if(TCount==9)
    {
        MessageBox(hwndDlg,"Match Drawn","Result",MB_OK);
        _ResetUI(hwndDlg);
    }
    return 0;

}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)//name suggests...The Great WinMain!!
{
    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(IDD_TICTAC), NULL, DLGPROC(DlgMain));
}
//SALUTE TO ASTYLE!!...
