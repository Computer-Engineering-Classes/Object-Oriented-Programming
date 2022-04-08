#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Point
{
private:
	float x;
	float y;
public:
	Point();
	Point(float x, float y);
	virtual ~Point();
	void Set_x(float m_x);
	void Set_y(float m_y);
	void Set_P(float m_x, float m_y);
	void Set_P(Point m_P);
	void Ask2Set_P(void);
	float Get_x(void) const { return x; }
	float Get_y(void) const { return y; }
	void ShowPoint(void);
	bool operator==(const Point ponto) const;
	bool operator!=(const Point ponto) const;
	void operator=(Point ponto);
	void Save(ofstream& os);
	void Read(ifstream& is);
};

