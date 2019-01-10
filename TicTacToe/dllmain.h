#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>

#ifdef BUILD_DLL
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

void DLL_EXPORT xyz(const LPCSTR sometext);
int DLL_EXPORT _CheckVictor(int ttt[9]);
void DLL_EXPORT _check(int a[]);
int DLL_EXPORT _rfill(int a[]);
int DLL_EXPORT AI(int a[]);
#ifdef __cplusplus
}
#endif

#endif
