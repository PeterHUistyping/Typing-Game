#include <iostream>
#include <graphics.h>		// Reference graphics library header file
#include <conio.h>
#include<string>
#include<stdio.h>
#include"resource.h"
#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
char up(char  ps)//大小写
{
	if ('a' <= ps && ps <= 'z')
	{
		ps -= 32;		return ps;
	}
	else if (ps == '#')
		return ps = '3';
	else if (ps == '{')
		return ps = '[';
	else if (ps == '}')
		return ps = ']';
	else if (ps == '<')
		return ps = ',';
	else if (ps == '>')
		return ps = '.';
	else if (ps == '"')
		return ps = '\'';
	else if (ps == ':')
		return ps = ';';
	else
		return ps;
}
char line1[13] = { "1234567890-=" };
char line2[14] = { "QWERTYUIOP[]|" };
char line3[12] = { "ASDFGHJKL;'" };
char line4[11] = { "ZXCVBNM,./" };
char hello[52] = { "#include<stdio.h>intmain(void){printf(\"HelloXMU\");}" };
char plu[61] = { "#include<stdio.h>intmain(void){inta=8,b=9;printf(\"%d\",a+b);}" };
using namespace std;
int i, y, j, flag, t = 50, fall = 100;//sleep
int length = 1024, height = 768;
int st = 255;
int keys = 255 * 2;//键盘开始纵坐标j
int r = 18;
char ch, input;
int column = 4, row = 3;
void light1(char c)
{
	c = up(c);//大小写
	flag = 0;
	for (i = 1; i <= 12; i++)
	{
		if (c == line1[i - 1])
		{
			setfillcolor(WHITE), fillcircle(i * 4 * r, keys, r), Sleep(t);
			RECT a4 = { i * 4 * r - r, keys - 0.8 * r,  i * 4 * r + r, keys + 0.8 * r }; Sleep(t);
			setcolor(BLACK);
			setfillcolor(RED), fillcircle(i * 4 * r, keys, r), Sleep(t);
			drawtext(line1[i - 1], &a4, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
			flag = 1;
		}
		if (flag) break;
	}

	for (i = 1; i <= 13; i++)
	{
		if (c == line2[i - 1])
		{
			setfillcolor(WHITE), fillcircle(2 * r + i * 4 * r, keys + 3 * r, r), Sleep(t);
			RECT a5 = { 2 * r + i * 4 * r - r, keys + 3 * r - 0.8 * r,2 * r + i * 4 * r + r, keys + 3 * r + 0.8 * r }; Sleep(t);
			setcolor(BLACK);
			setfillcolor(BROWN), fillcircle(2 * r + i * 4 * r, keys + 3 * r, r), Sleep(t);
			drawtext(line2[i - 1], &a5, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
			flag = 1;
		}
		if (flag) break;
	}

	for (i = 1; i <= 11; i++)
	{
		if (c == line3[i - 1])
		{
			setfillcolor(WHITE);
			fillcircle(4 * r + i * 4 * r, keys + 6 * r, r), Sleep(t);
			setcolor(BLACK);

			RECT a6 = { 4 * r + i * 4 * r - r, keys + 6 * r - 0.8 * r,4 * r + i * 4 * r + r, keys + 6 * r + 0.8 * r }; Sleep(t);
			setfillcolor(GREEN);
			fillcircle(4 * r + i * 4 * r, keys + 6 * r, r), Sleep(t);
			drawtext(line3[i - 1], &a6, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);

		}
		if (flag) break;
	}
	for (i = 1; i <= 10; i++)
	{
		if (c == line4[i - 1])
		{
			setfillcolor(WHITE);
			fillcircle(6 * r + i * 4 * r, keys + 9 * r, r); Sleep(t);
			RECT a7 = { 6 * r + i * 4 * r - r, keys + 9 * r - 0.8 * r,6 * r + i * 4 * r + r, keys + 9 * r + 0.8 * r }; Sleep(t);
			setcolor(BLACK);
			setfillcolor(BLUE);
			fillcircle(6 * r + i * 4 * r, keys + 9 * r, r); Sleep(t);
			drawtext(line4[i - 1], &a7, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
		}
		if (flag) break;
	}
	if (c == 8)
	{
		setfillcolor(WHITE);
		fillrectangle(12.6 * 4 * r, keys - 0.8 * r, 13.8 * 4 * r, keys + 0.8 * r); Sleep(t);
		setcolor(BLACK); setfillcolor(MAGENTA);
		fillrectangle(12.6 * 4 * r, keys - 0.8 * r, 13.8 * 4 * r, keys + 0.8 * r); Sleep(t);
		RECT a1 = { 12.6 * 4 * r, keys - 0.8 * r, 13.8 * 4 * r, keys + 0.8 * r }; Sleep(t);
		drawtext(_T("Backspace"), &a1, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
	}
	else if (c == 13)
	{
		setfillcolor(WHITE);
		fillrectangle(12.5 * 4 * r, keys + 6 * r - 0.8 * r, 13.8 * 4 * r, keys + 6 * r + 0.8 * r); Sleep(t);
		setcolor(BLACK); setfillcolor(CYAN);
		fillrectangle(12.5 * 4 * r, keys + 6 * r - 0.8 * r, 13.8 * 4 * r, keys + 6 * r + 0.8 * r); Sleep(t);
		RECT a2 = { 12.5 * 4 * r, keys + 6 * r - 0.8 * r, 13.8 * 4 * r, keys + 6 * r + 0.8 * r }; Sleep(t);
		drawtext(_T("Enter"), &a2, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
	}
	else if (c == 9)
	{
		setfillcolor(WHITE);
		fillrectangle(12.22 * 4 * r, keys + 9 * r - 0.8 * r, 13.8 * 4 * r, keys + 9 * r + 0.8 * r); Sleep(t);
		setcolor(BLACK); setfillcolor(LIGHTCYAN);
		fillrectangle(12.22 * 4 * r, keys + 9 * r - 0.8 * r, 13.8 * 4 * r, keys + 9 * r + 0.8 * r); Sleep(t);
		RECT a3 = { 12.22 * 4 * r, keys + 9 * r - 0.8 * r, 13.8 * 4 * r, keys + 9 * r + 0.8 * r }; Sleep(t);
		drawtext(_T("Tab"), &a3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (c == 32)
	{
		setfillcolor(WHITE);
		fillrectangle(length * 2 / 5, keys + 11 * r, length * 3 / 5, keys + 13 * r); Sleep(t);
		setcolor(BLACK); setfillcolor(LIGHTBLUE);
		fillrectangle(length * 2 / 5, keys + 11 * r, length * 3 / 5, keys + 13 * r); Sleep(t);
		RECT b = { length * 2 / 5, keys + 11 * r,   length * 3 / 5 ,  keys + 13 * r }; Sleep(t);
		drawtext(_T("Space"), &b, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
	}
	else if (c == 27)
		closegraph();
}
int judge1(char input, char ans)
{
	if (ans != input)
	{
		light1(input);
		return 0;
	}
	else
	{
		light1(input);
		return 1;
	}
}
void light(char c)
{
	c = up(c);//大小写
	flag = 0;
	for (i = 1; i <= 12; i++)
	{
		if (c == line1[i - 1])
		{
			setfillcolor(RED), fillcircle(i * 4 * r, keys, r), Sleep(t);
			RECT a4 = { i * 4 * r - r, keys - 0.8 * r,  i * 4 * r + r, keys + 0.8 * r }; Sleep(t);
			setfillcolor(WHITE), fillcircle(i * 4 * r, keys, r), Sleep(t);
			setcolor(BLACK);
			drawtext(line1[i - 1], &a4, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
			flag = 1;
		}
		if (flag) break;
	}

	for (i = 1; i <= 13; i++)
	{
		if (c == line2[i - 1])
		{
			setfillcolor(BROWN), fillcircle(2 * r + i * 4 * r, keys + 3 * r, r), Sleep(t);
			RECT a5 = { 2 * r + i * 4 * r - r, keys + 3 * r - 0.8 * r,2 * r + i * 4 * r + r, keys + 3 * r + 0.8 * r }; Sleep(t);
			setfillcolor(WHITE), fillcircle(2 * r + i * 4 * r, keys + 3 * r, r), Sleep(t); setcolor(BLACK);
			drawtext(line2[i - 1], &a5, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
			flag = 1;
		}
		if (flag) break;
	}

	for (i = 1; i <= 11; i++)
	{
		if (c == line3[i - 1])
		{
			setfillcolor(GREEN);
			fillcircle(4 * r + i * 4 * r, keys + 6 * r, r), Sleep(t);
			RECT a6 = { 4 * r + i * 4 * r - r, keys + 6 * r - 0.8 * r,4 * r + i * 4 * r + r, keys + 6 * r + 0.8 * r }; Sleep(t);
			setfillcolor(WHITE);
			fillcircle(4 * r + i * 4 * r, keys + 6 * r, r), Sleep(t); setcolor(BLACK);
			drawtext(line3[i - 1], &a6, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);

		}
		if (flag) break;
	}
	for (i = 1; i <= 10; i++)
	{
		if (c == line4[i - 1])
		{
			setfillcolor(BLUE);

			fillcircle(6 * r + i * 4 * r, keys + 9 * r, r); Sleep(t);
			RECT a7 = { 6 * r + i * 4 * r - r, keys + 9 * r - 0.8 * r,6 * r + i * 4 * r + r, keys + 9 * r + 0.8 * r }; Sleep(t);
			setfillcolor(WHITE);

			fillcircle(6 * r + i * 4 * r, keys + 9 * r, r); Sleep(t); setcolor(BLACK);
			drawtext(line4[i - 1], &a7, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
		}
		if (flag) break;
	}
	if (c == 8)
	{
		setfillcolor(MAGENTA);
		fillrectangle(12.6 * 4 * r, keys - 0.8 * r, 13.8 * 4 * r, keys + 0.8 * r); Sleep(t);
		setfillcolor(WHITE);
		fillrectangle(12.6 * 4 * r, keys - 0.8 * r, 13.8 * 4 * r, keys + 0.8 * r); Sleep(t); setcolor(BLACK);
		RECT a1 = { 12.6 * 4 * r, keys - 0.8 * r, 13.8 * 4 * r, keys + 0.8 * r }; Sleep(t);
		drawtext(_T("Backspace"), &a1, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
	}
	else if (c == 13)
	{
		setfillcolor(CYAN);
		fillrectangle(12.5 * 4 * r, keys + 6 * r - 0.8 * r, 13.8 * 4 * r, keys + 6 * r + 0.8 * r); Sleep(t);
		setfillcolor(WHITE);
		fillrectangle(12.5 * 4 * r, keys + 6 * r - 0.8 * r, 13.8 * 4 * r, keys + 6 * r + 0.8 * r); Sleep(t); setcolor(BLACK);
		RECT a2 = { 12.5 * 4 * r, keys + 6 * r - 0.8 * r, 13.8 * 4 * r, keys + 6 * r + 0.8 * r }; Sleep(t);
		drawtext(_T("Enter"), &a2, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
	}
	else if (c == 9)
	{
		setfillcolor(LIGHTCYAN);
		fillrectangle(12.22 * 4 * r, keys + 9 * r - 0.8 * r, 13.8 * 4 * r, keys + 9 * r + 0.8 * r); Sleep(t);
		setfillcolor(WHITE);
		fillrectangle(12.22 * 4 * r, keys + 9 * r - 0.8 * r, 13.8 * 4 * r, keys + 9 * r + 0.8 * r); Sleep(t); setcolor(BLACK);
		RECT a3 = { 12.22 * 4 * r, keys + 9 * r - 0.8 * r, 13.8 * 4 * r, keys + 9 * r + 0.8 * r }; Sleep(t);
		drawtext(_T("Tab"), &a3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (c == 32)
	{
		setfillcolor(LIGHTBLUE);
		fillrectangle(length * 2 / 5, keys + 11 * r, length * 3 / 5, keys + 13 * r); Sleep(t);
		setfillcolor(WHITE);
		fillrectangle(length * 2 / 5, keys + 11 * r, length * 3 / 5, keys + 13 * r); Sleep(t); setcolor(BLACK);
		RECT b = { length * 2 / 5, keys + 11 * r,   length * 3 / 5 ,  keys + 13 * r }; Sleep(t);

		drawtext(_T("Space"), &b, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
	}
	else if (c == 27)
		closegraph();
}
void dark(int count)
{
	int j = (count - 1) / column + 1;
	int i = count - (j - 1) * 4;
	if (i <= column && j <= row)
	{
		setcolor(BLACK);
		setfillcolor(BLACK);
		fillrectangle(3 * r + i * 10 * r, st + j * st / 4 - 0.8 * r, 3 * r + i * 10 * r + 4 * r, st + j * st / 4 + 0.8 * r);
	}
}
int judge(char input, char ans)
{
	if (ans != input)
	{
		light(input);
		return 0;
	}
	else
	{
		light(input);
		return 1;
	}
}
int main()
{
	PlaySound(LPWSTR(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC | SND_LOOP);
	initgraph(length, height);
	MOUSEMSG m;
	initgraph(1024, 768);
	setbkcolor(WHITE);	// 设置背景色为白色
	cleardevice();// 用背景色清空屏幕
	IMAGE img;
	loadimage(&img, L"jpg", MAKEINTRESOURCE(IDB_BITMAP1), 1024, 768);

	putimage(0, 0, &img);//显示图片
	setfillcolor(GREEN);
	_getch();
	setbkmode(TRANSPARENT);
	fillrectangle(200, 16, 824, 240);
	RECT a11 = { 200, 16, 824, 240 }; setcolor(WHITE);
	drawtext(_T("超级程序员之打字游戏"), &a11, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	setfillcolor(BLUE);
	fillrectangle(300, 280, 724, 400);
	RECT a12 = { 300, 280, 724, 400 }; setcolor(WHITE);
	drawtext(_T("竞速模式 Racing Mode——输出Hello XMU →"), &a12, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	setfillcolor(LIGHTCYAN);
	fillrectangle(300, 430, 724, 550);
	RECT a13 = { 300, 430, 724, 550 }; setcolor(WHITE);
	drawtext(_T("竞速模式 Racing Mode——a+b问题 →"), &a13, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	setfillcolor(CYAN);
	fillrectangle(300, 580, 724, 700);

	RECT a14 = { 300, 580, 724, 700 }; setcolor(WHITE);
	drawtext(_T("变色键盘 Fabulous keyboard——输出Hello XMU →"), &a14, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	while (1) {
		m = GetMouseMsg();
		if (m.x >= 300 && m.x <= 724 && m.y >= 280 && m.y <= 400) {
			if (m.uMsg == WM_LBUTTONDOWN)
			{		//如果按下鼠标左键实现相应功能.
				closegraph();
				initgraph(length, height);


				int x1 = length / 2 - 10 * r, x2 = length / 2 + 10 * r;
				int y1 = height / 2 - 0.8 * r, y2 = height / 2 + 0.8 * r;
				RECT a77 = { x1,y1, x2, y2 }; setcolor(WHITE);
				drawtext(_T("竞速模式 Racing Mode"), &a77, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(5);
				_getch();
				setcolor(BLACK);
				setfillcolor(BLACK);
				fillrectangle(x1, y1, x2, y2);


				setbkmode(TRANSPARENT);
				//11.20 Speed mode completed.
				//11.19 keyboard structure completed
				for (int i = 1; i <= column; i++)
				{
					for (int j = 1; j <= row; j++)
					{
						setcolor(BLACK);
						setfillcolor(YELLOW);
						fillrectangle(3 * r + i * 10 * r, st + j * st / 4 - 0.8 * r, 3 * r + i * 10 * r + 4 * r, st + j * st / 4 + 0.8 * r);
					}
				}


				for (i = 1; i <= 12; i++)
				{
					setfillcolor(WHITE);
					fillcircle(i * 4 * r, keys, r);
					RECT a4 = { i * 4 * r - r, keys - 0.8 * r,  i * 4 * r + r, keys + 0.8 * r }; setcolor(BLACK);
					drawtext(line1[i - 1], &a4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}

				fillrectangle(12.6 * 4 * r, keys - 0.8 * r, 13.8 * 4 * r, keys + 0.8 * r);
				RECT a1 = { 12.6 * 4 * r, keys - 0.8 * r, 13.8 * 4 * r, keys + 0.8 * r }; setcolor(BLACK);
				drawtext(_T("Backspace"), &a1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

				for (i = 1; i <= 13; i++)
				{
					fillcircle(2 * r + i * 4 * r, keys + 3 * r, r);
					RECT a5 = { 2 * r + i * 4 * r - r, keys + 3 * r - 0.8 * r,2 * r + i * 4 * r + r, keys + 3 * r + 0.8 * r }; setcolor(BLACK);
					drawtext(line2[i - 1], &a5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}

				for (i = 1; i <= 11; i++)
				{
					fillcircle(4 * r + i * 4 * r, keys + 6 * r, r);
					RECT a6 = { 4 * r + i * 4 * r - r, keys + 6 * r - 0.8 * r,4 * r + i * 4 * r + r, keys + 6 * r + 0.8 * r }; setcolor(BLACK);
					drawtext(line3[i - 1], &a6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}

				fillrectangle(12.5 * 4 * r, keys + 6 * r - 0.8 * r, 13.8 * 4 * r, keys + 6 * r + 0.8 * r);
				RECT a2 = { 12.5 * 4 * r, keys + 6 * r - 0.8 * r, 13.8 * 4 * r, keys + 6 * r + 0.8 * r }; setcolor(BLACK);
				drawtext(_T("Enter"), &a2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

				for (i = 1; i <= 10; i++)
				{
					fillcircle(6 * r + i * 4 * r, keys + 9 * r, r);
					RECT a7 = { 6 * r + i * 4 * r - r, keys + 9 * r - 0.8 * r,6 * r + i * 4 * r + r, keys + 9 * r + 0.8 * r }; setcolor(BLACK);
					drawtext(line4[i - 1], &a7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}

				fillrectangle(12.22 * 4 * r, keys + 9 * r - 0.8 * r, 13.8 * 4 * r, keys + 9 * r + 0.8 * r);
				RECT a3 = { 12.22 * 4 * r, keys + 9 * r - 0.8 * r, 13.8 * 4 * r, keys + 9 * r + 0.8 * r }; setcolor(BLACK);
				drawtext(_T("Tab"), &a3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

				fillrectangle(length * 2 / 5, keys + 11 * r, length * 3 / 5, keys + 13 * r);
				RECT b = { length * 2 / 5, keys + 11 * r,   length * 3 / 5 ,  keys + 13 * r }; setcolor(BLACK);

				drawtext(_T("Space"), &b, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				int correct = 0, count = 0;

				for (int i = 0; i < 52; i++)
				{
					for (int y = 0; y <= height / 3; y += 20)
					{

						setcolor(WHITE);
						RECT c = { (30 + 100 * i) % length,y , (30 + 100 * i) % length + 50  , y + 50 }; Sleep(fall);
						drawtext(hello[i], &c, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(fall);
						setfillcolor(BLACK);
						setcolor(BLACK);
						fillrectangle((30 + 100 * i) % length, y, (30 + 100 * i) % length + 50, y + 50);
						input = hello[i];
						RECT d = { r, st + 64 - r,  r + 6 * r, st + 64 + r };
						setcolor(WHITE);
						drawtext(_T("按ESC退出游戏"), &d, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

						if (_kbhit())
						{
							ch = _getch();
							if (judge(ch, input))
							{
								correct++;
								break;
							}
							else
							{
								count++;
								dark(count);
								if (count == 12) break;
							}
						}

						if (count == 12) break;
					}
					if (count == 12) break;
					if (!judge(ch, input))
					{
						count++;
						dark(count);
						if (count == 12) break;
					}
				}
				if (count == 12)
				{
					RECT e = { r + 16 * r, st + 64 - r,  r + 36 * r, st + 64 + r };
					setcolor(WHITE);
					drawtext(_T("I am sorry to tell you:GAME OVER!!!!!!!!!!"), &e, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
					RECT f = { r + 16 * r, st + 88 - r,  r + 36 * r, st + 88 + r };
					setcolor(WHITE);
					drawtext(_T("继续加油！"), &f, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
				}
				else
				{
					RECT e = { r + 16 * r, st - r,  r + 36 * r, st + r };
					setcolor(WHITE);
					drawtext(_T("Congratulation:You win!!!!!!!"), &e, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
				}
				break;


			}
		}
		else if (m.x >= 300 && m.x <= 724 && m.y >= 430 && m.y <= 550)
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{		//如果按下鼠标左键实现相应功能.
				closegraph();
				initgraph(length, height);	// Create a graphics window with a size of 640x480 pixels 

				int x1 = length / 2 - 10 * r, x2 = length / 2 + 10 * r;
				int y1 = height / 2 - 0.8 * r, y2 = height / 2 + 0.8 * r;
				RECT a77 = { x1,y1, x2, y2 }; setcolor(WHITE);
				drawtext(_T("竞速模式 Racing Mode"), &a77, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(5);
				_getch();
				setcolor(BLACK);
				setfillcolor(BLACK);
				fillrectangle(x1, y1, x2, y2);


				setbkmode(TRANSPARENT);
				//11.20 Speed mode completed.
				//11.19 keyboard structure completed
				for (int i = 1; i <= column; i++)
				{
					for (int j = 1; j <= row; j++)
					{
						setcolor(BLACK);
						setfillcolor(YELLOW);
						fillrectangle(3 * r + i * 10 * r, st + j * st / 4 - 0.8 * r, 3 * r + i * 10 * r + 4 * r, st + j * st / 4 + 0.8 * r);
					}
				}


				for (i = 1; i <= 12; i++)
				{
					setfillcolor(WHITE);
					fillcircle(i * 4 * r, keys, r);
					RECT a4 = { i * 4 * r - r, keys - 0.8 * r,  i * 4 * r + r, keys + 0.8 * r }; setcolor(BLACK);
					drawtext(line1[i - 1], &a4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}

				fillrectangle(12.6 * 4 * r, keys - 0.8 * r, 13.8 * 4 * r, keys + 0.8 * r);
				RECT a1 = { 12.6 * 4 * r, keys - 0.8 * r, 13.8 * 4 * r, keys + 0.8 * r }; setcolor(BLACK);
				drawtext(_T("Backspace"), &a1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

				for (i = 1; i <= 13; i++)
				{
					fillcircle(2 * r + i * 4 * r, keys + 3 * r, r);
					RECT a5 = { 2 * r + i * 4 * r - r, keys + 3 * r - 0.8 * r,2 * r + i * 4 * r + r, keys + 3 * r + 0.8 * r }; setcolor(BLACK);
					drawtext(line2[i - 1], &a5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}

				for (i = 1; i <= 11; i++)
				{
					fillcircle(4 * r + i * 4 * r, keys + 6 * r, r);
					RECT a6 = { 4 * r + i * 4 * r - r, keys + 6 * r - 0.8 * r,4 * r + i * 4 * r + r, keys + 6 * r + 0.8 * r }; setcolor(BLACK);
					drawtext(line3[i - 1], &a6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}

				fillrectangle(12.5 * 4 * r, keys + 6 * r - 0.8 * r, 13.8 * 4 * r, keys + 6 * r + 0.8 * r);
				RECT a2 = { 12.5 * 4 * r, keys + 6 * r - 0.8 * r, 13.8 * 4 * r, keys + 6 * r + 0.8 * r }; setcolor(BLACK);
				drawtext(_T("Enter"), &a2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

				for (i = 1; i <= 10; i++)
				{
					fillcircle(6 * r + i * 4 * r, keys + 9 * r, r);
					RECT a7 = { 6 * r + i * 4 * r - r, keys + 9 * r - 0.8 * r,6 * r + i * 4 * r + r, keys + 9 * r + 0.8 * r }; setcolor(BLACK);
					drawtext(line4[i - 1], &a7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}

				fillrectangle(12.22 * 4 * r, keys + 9 * r - 0.8 * r, 13.8 * 4 * r, keys + 9 * r + 0.8 * r);
				RECT a3 = { 12.22 * 4 * r, keys + 9 * r - 0.8 * r, 13.8 * 4 * r, keys + 9 * r + 0.8 * r }; setcolor(BLACK);
				drawtext(_T("Tab"), &a3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

				fillrectangle(length * 2 / 5, keys + 11 * r, length * 3 / 5, keys + 13 * r);
				RECT b = { length * 2 / 5, keys + 11 * r,   length * 3 / 5 ,  keys + 13 * r }; setcolor(BLACK);

				drawtext(_T("Space"), &b, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				int correct = 0, count = 0;

				for (int i = 0; i < 61; i++)
				{
					for (int y = 0; y <= height / 3; y += 20)
					{
						//settextstyle(30,0,"宋体");
						setcolor(WHITE);
						RECT c = { (30 + 100 * i) % length,y , (30 + 100 * i) % length + 50  , y + 50 }; Sleep(fall);
						drawtext(plu[i], &c, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(fall);
						setfillcolor(BLACK);
						setcolor(BLACK);
						fillrectangle((30 + 100 * i) % length, y, (30 + 100 * i) % length + 50, y + 50);
						input = plu[i];
						RECT d = { r, st + 64 - r,  r + 6 * r, st + 64 + r };
						setcolor(WHITE);
						drawtext(_T("按ESC退出游戏"), &d, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

						if (_kbhit())
						{
							ch = _getch();
							if (judge(ch, input))
							{
								correct++;
								break;
							}
							else
							{
								count++;
								dark(count);
								if (count == 12) break;
							}
						}
						if (count == 12) break;
					}
					if (count == 12) break;
					if (!judge(ch, input))
					{
						count++;
						dark(count);
						if (count == 12) break;
					}
				}
				if (count == 12)
				{
					RECT e = { r + 16 * r, st + 64 - r,  r + 36 * r, st + 64 + r };
					setcolor(WHITE);
					drawtext(_T("I am sorry to tell you:GAME OVER!!!!!!!!!!"), &e, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
					RECT f = { r + 16 * r, st + 88 - r,  r + 36 * r, st + 88 + r };
					setcolor(WHITE);
					drawtext(_T("继续加油！"), &f, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
				}
				else
				{
					RECT e = { r + 16 * r, st - r,  r + 36 * r, st + r };
					setcolor(WHITE);
					drawtext(_T("Congratulation:You win!!!!!!!"), &e, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
				}
				break;
			}
		}
		else if (m.x >= 300 && m.x <= 724 && m.y >= 580 && m.y <= 700)
		{
			if (m.uMsg == WM_LBUTTONDOWN)
			{		//如果按下鼠标左键实现相应功能.
				closegraph();
				initgraph(length, height);	// Create a graphics window with a size of 640x480 pixels 

				int x1 = length / 2 - 10 * r, x2 = length / 2 + 10 * r;
				int y1 = height / 2 - 0.8 * r, y2 = height / 2 + 0.8 * r;
				RECT a77 = { x1,y1, x2, y2 }; setcolor(WHITE);
				drawtext(_T("竞速模式 Racing Mode"), &a77, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(5);
				_getch();
				setcolor(BLACK);
				setfillcolor(BLACK);
				fillrectangle(x1, y1, x2, y2);
				setbkmode(TRANSPARENT);
				for (int i = 1; i <= column; i++)
				{
					for (int j = 1; j <= row; j++)
					{
						setcolor(BLACK);
						setfillcolor(YELLOW);
						fillrectangle(3 * r + i * 10 * r, st + j * st / 4 - 0.8 * r, 3 * r + i * 10 * r + 4 * r, st + j * st / 4 + 0.8 * r);
					}
				}
				for (i = 1; i <= 12; i++)
				{
					setfillcolor(RED);
					fillcircle(i * 4 * r, keys, r);
					RECT a4 = { i * 4 * r - r, keys - 0.8 * r,  i * 4 * r + r, keys + 0.8 * r }; setcolor(BLACK);
					drawtext(line1[i - 1], &a4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}
				setfillcolor(MAGENTA);
				fillrectangle(12.6 * 4 * r, keys - 0.8 * r, 13.8 * 4 * r, keys + 0.8 * r);
				RECT a1 = { 12.6 * 4 * r, keys - 0.8 * r, 13.8 * 4 * r, keys + 0.8 * r }; setcolor(BLACK);
				drawtext(_T("Backspace"), &a1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

				for (i = 1; i <= 13; i++)
				{
					setfillcolor(BROWN);
					fillcircle(2 * r + i * 4 * r, keys + 3 * r, r);
					RECT a5 = { 2 * r + i * 4 * r - r, keys + 3 * r - 0.8 * r,2 * r + i * 4 * r + r, keys + 3 * r + 0.8 * r }; setcolor(BLACK);
					drawtext(line2[i - 1], &a5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}

				for (i = 1; i <= 11; i++)
				{
					setfillcolor(GREEN);
					fillcircle(4 * r + i * 4 * r, keys + 6 * r, r);
					RECT a6 = { 4 * r + i * 4 * r - r, keys + 6 * r - 0.8 * r,4 * r + i * 4 * r + r, keys + 6 * r + 0.8 * r }; setcolor(BLACK);
					drawtext(line3[i - 1], &a6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}
				setfillcolor(CYAN);
				fillrectangle(12.5 * 4 * r, keys + 6 * r - 0.8 * r, 13.8 * 4 * r, keys + 6 * r + 0.8 * r);
				RECT a2 = { 12.5 * 4 * r, keys + 6 * r - 0.8 * r, 13.8 * 4 * r, keys + 6 * r + 0.8 * r }; setcolor(BLACK);
				drawtext(_T("Enter"), &a2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

				for (i = 1; i <= 10; i++)
				{
					setfillcolor(BLUE);
					fillcircle(6 * r + i * 4 * r, keys + 9 * r, r);
					RECT a7 = { 6 * r + i * 4 * r - r, keys + 9 * r - 0.8 * r,6 * r + i * 4 * r + r, keys + 9 * r + 0.8 * r }; setcolor(BLACK);
					drawtext(line4[i - 1], &a7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				}
				setfillcolor(LIGHTCYAN);
				fillrectangle(12.22 * 4 * r, keys + 9 * r - 0.8 * r, 13.8 * 4 * r, keys + 9 * r + 0.8 * r);
				RECT a3 = { 12.22 * 4 * r, keys + 9 * r - 0.8 * r, 13.8 * 4 * r, keys + 9 * r + 0.8 * r }; setcolor(BLACK);
				drawtext(_T("Tab"), &a3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				setfillcolor(LIGHTBLUE);
				fillrectangle(length * 2 / 5, keys + 11 * r, length * 3 / 5, keys + 13 * r);
				RECT b = { length * 2 / 5, keys + 11 * r,   length * 3 / 5 ,  keys + 13 * r }; setcolor(BLACK);
				drawtext(_T("Space"), &b, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				int correct = 0, count = 0;
				for (int i = 0; i < 52; i++)
				{
					for (int y = 0; y <= height / 3; y += 20)
					{
						//settextstyle(30,0,"宋体");
						setcolor(WHITE);
						RECT c = { (30 + 100 * i) % length,y , (30 + 100 * i) % length + 50  , y + 50 }; Sleep(fall);
						drawtext(hello[i], &c, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(fall);
						setfillcolor(BLACK);
						setcolor(BLACK);
						fillrectangle((30 + 100 * i) % length, y, (30 + 100 * i) % length + 50, y + 50);
						input = hello[i];
						RECT d = { r, st + 64 - r,  r + 6 * r, st + 64 + r };
						setcolor(WHITE);
						drawtext(_T("按ESC退出游戏"), &d, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
						if (_kbhit())
						{
							ch = _getch();
							if (judge1(ch, input))
							{
								correct++;
								break;
							}
							else
							{
								count++;
								dark(count);
								if (count == 12) break;
							}
						}

						if (count == 12) break;
					}
					if (count == 12) break;
					if (!judge1(ch, input))
					{
						count++;
						dark(count);
						if (count == 12) break;
					}
				}
				if (count == 12)
				{
					RECT e = { r + 16 * r, st + 64 - r,  r + 36 * r, st + 64 + r };
					setcolor(WHITE);
					drawtext(_T("I am sorry to tell you:GAME OVER!!!!!!!!!!"), &e, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
					RECT f = { r + 16 * r, st + 88 - r,  r + 36 * r, st + 88 + r };
					setcolor(WHITE);
					drawtext(_T("继续加油！"), &f, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
				}
				else
				{
					RECT e = { r + 16 * r, st - r,  r + 36 * r, st + r };
					setcolor(WHITE);
					drawtext(_T("Congratulation:You win!!!!!!!"), &e, DT_CENTER | DT_VCENTER | DT_SINGLELINE); Sleep(t);
				}
				break;
			}
		}
	}
	_getch();
	if ((ch = _getch()) == 27)
		closegraph();			// Close the graphics window
	return 0;
}
