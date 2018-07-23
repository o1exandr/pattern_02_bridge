/*
Завдання 2. Виконати на вибір одне із завдань з використанням патерну Міст.
Створити програму для обчислення вартості праці програміста. 
Програміст може працювати на фрілансі чи(і) бути працівником  компанії.
Програміст може виконувати завдання на певній мові програмування(С++, C#  та ін.). 
Кожна година роботи оплачується залежно від мови програмування.
Працівник компанії додатково із заробленої суми платить податки.
*/


#include "stdafx.h"
#include <iostream> 
#include <string>

using namespace std;

class PaintApi
{
public:

	PaintApi()
	{
	}

	virtual ~PaintApi()
	{
	}
public:
	virtual void DrawRectangle(int x, int y, int endx, int endy) = 0;
};

class Figure
{
protected:
	PaintApi * api;
public:

	Figure(PaintApi* pApi)
	{
		api = pApi;
	}

	virtual ~Figure()
	{
		if (api)
			delete api;
	}
	virtual void DrawFigure() const = 0;
};

class Rectangle :
	public Figure
{
private:
	int x;
	int y;
	int endx;
	int endy;
public:

	Rectangle(int pX, int pY, int pEndX, int pEndY, PaintApi* pApi) :Figure(pApi)
	{
		x = pX;
		y = pY;
		endx = pEndX;
		endy = pEndY;
	}

	virtual ~Rectangle()
	{
	}

	void DrawFigure() const
	{
		api->DrawRectangle(x, y, endx, endy);
	}

};

class BlackRectangle : public PaintApi
{
public:

	BlackRectangle()
	{
	}

	virtual ~BlackRectangle()
	{
	}
public:
	virtual void DrawRectangle(int x, int y, int endx, int endy)
	{
		cout << "Draw Black Rectangle\n x = " << x << " y = " << y << " endx = " << endx << " endy = " << endy << endl;
	}
};

class BlueRectangle :public PaintApi
{

public:

	BlueRectangle()
	{
	}

	virtual ~BlueRectangle()
	{
	}
public:
	virtual void DrawRectangle(int x, int y, int endx, int endy)
	{
		cout << "Draw Blue Rectangle\n x = " << x << " y = " << y << " endx = " << endx << " endy = " << endy << endl;
	}
};

int main()
{
	Figure* blackRectangle = new Rectangle(10, 10, 100, 100, new BlackRectangle());
	Figure* blueRectangle = new Rectangle(20, 20, 200, 200, new BlueRectangle());

	blackRectangle->DrawFigure();
	blueRectangle->DrawFigure();

	delete blackRectangle;
	delete blueRectangle;


	cout << endl;
	system("pause");
	return 0;
}