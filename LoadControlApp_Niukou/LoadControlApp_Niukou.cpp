// LoadControlApp_Niukou.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <windows.h>
#include <stdio.h>



//鼠标
typedef void(__cdecl* YtyMouseLeftButtonDown)();
typedef void(__cdecl* YtyMouseLeftButtonUp)();
//鼠标左键双击
typedef void(__cdecl* YtyMousedoubleclick)();
//鼠标左键长按
typedef void(__cdecl* YtyMouseLeftLongPress)(time_t end_time_ms, UINT_PTR TimeLapse);
//鼠标左键按住弹起
typedef void(__cdecl* YtyMouseLeftLongUp)();
//鼠标右键长按
typedef void(__cdecl* YtyMouseRightLongPress)(time_t end_time_ms, UINT_PTR TimeLapse);
//鼠标右键长按弹起
typedef void(__cdecl* YtyMouseRightLongUp)();
typedef void(__cdecl* YtyRightButtonDown)();
typedef void(__cdecl* YtyRightButtonUp)();
typedef void(__cdecl* YtyMouseMiddleButtonDown)();
typedef void(__cdecl* YtyMouseMiddleButtonUp)();
typedef void(__cdecl* YtyMouseMoveTo)(LONG dx, LONG dy);
typedef void(__cdecl* YtyMouseMoveR)(LONG dx, LONG dy);
//键盘短按
typedef int(__cdecl* YtyKeyDown)(USHORT VirtualKey);
typedef int(__cdecl* YtyKeyUp)(USHORT VirtualKey);
//键盘长按按下
typedef void(__cdecl* YtyKeyDownLongPress)(USHORT VirtualKey);
//按键长按弹起
typedef void(__cdecl* YtyKeyLongUp)(USHORT VirtualKey);
//typedef int (*export_fun1)(int x, int y);

YtyMouseLeftButtonDown _ytyMouseLeftButtonDown;
YtyMouseLeftButtonUp _ytyMouseLeftButtonUp;
YtyMouseMoveTo _ytyMouseMoveTo;
YtyMouseMoveR _ytyMouseMoveR;
YtyMousedoubleclick _ytyMousedoubleclick;
YtyKeyDown _ytyKeyDown;
YtyKeyUp _ytyKeyUp;
YtyKeyDownLongPress _ytyKeyDownLongPress;
YtyKeyLongUp _ytyKeyLongUp;



EXTERN_C typedef  void(__cdecl* KeyDownLongPress2)(USHORT VirtualKey);


EXTERN_C void __cdecl KeyDownLongPress(_In_ USHORT VirtualKey);

int main()
{
 /*
	//HMODULE hModule = LoadLibrary(L"C:\\Users\\admin\\source\\repos\\LoadControlApp_Niukou\\Debug\\kmclassdll.dll");
	HMODULE hModule = LoadLibraryW(L"kmclassdll.dll");
	
	
	int error_code = GetLastError();

	KeyDown2 KeyDown2Function = (KeyDown2)GetProcAddress(hModule,"KeyDown2");
	//MouseLeftButtonDown MouseDown = (MouseLeftButtonDown)GetProcAddress(hModule,"KeyDown2");
	int i = 0;
	

	while (i<100)
	{
		//KeyDownFunction(2);
	Sleep(2000);
	KeyDown2Function(0x1f);
		i++;
	}
	
	FreeLibrary(hModule);
	*/

	
	HMODULE _hDllInst = LoadLibraryW(L"kmclassdll.dll");
	int error_code = GetLastError();
	//printf("Error::%d\n", &error_code);
	printf(":%p\n",_hDllInst);
	KeyDownLongPress2 s= (KeyDownLongPress2)GetProcAddress(_hDllInst, "KeyDownLongPress");
	printf(":%p\n", s);

	s(87);
	//int ret = GetLastError();
	//printf(":%d\n", ret);
	

	
	
	_ytyKeyLongUp = (YtyKeyLongUp)GetProcAddress(_hDllInst, "KeyDownLongPressUp");


	YtyKeyUp YtyKeyUpFunction = (YtyKeyUp)GetProcAddress(_hDllInst, "KeyUp");
	Sleep(20000);
	_ytyKeyLongUp(87);
	//YtyKeyUpFunction(87);

	FreeLibrary(_hDllInst);
}


