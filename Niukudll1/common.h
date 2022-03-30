#pragma once 
#include "windows.h"
//×°ÔØNTÇý¶¯³ÌÐò
HANDLE drvhandle;
extern "C" __declspec(dllexport) void __cdecl SetHandle(HANDLE handle);
extern "C" __declspec(dllexport) void __cdecl KeyDown(USHORT VirtualKey);
extern "C" __declspec(dllexport) void __cdecl KeyUp(USHORT VirtualKey);
extern "C" __declspec(dllexport) void __cdecl MouseLeftButtonDown();
extern "C" __declspec(dllexport) void __cdecl MouseLeftButtonUp();
extern "C" __declspec(dllexport) void __cdecl MouseRightButtonDown();
extern "C" __declspec(dllexport) void __cdecl MouseRightButtonUp();
extern "C" __declspec(dllexport) void __cdecl MouseMiddleButtonDown();
extern "C" __declspec(dllexport) void __cdecl MouseMiddleButtonUp();
extern "C" __declspec(dllexport) void __cdecl MouseMoveRELATIVE(LONG dx, LONG dy);
extern "C" __declspec(dllexport) void __cdecl MouseMoveABSOLUTE(LONG dx, LONG dy);
extern "C" __declspec(dllexport) BOOL __cdecl LoadNTDriver(char* lpszDriverName, char* lpszDriverPath);
extern "C" __declspec(dllexport) BOOL __cdecl UnloadNTDriver(char* szSvrName);


