#include "Point.h"

Point::Point()
	:x(0.0), y(0.0)
{
}

Point::Point(float x, float y)
	:x(x), y(y)
{
}

Point::~Point()
{
}

void Point::Set_x(float m_x)
{
	x = m_x;
}

void Point::Set_y(float m_y)
{
	y = m_y;
}

void Point::Set_P(float m_x, float m_y)
{
	x = m_x;
	y = m_y;
}

void Point::Set_P(Point m_P)
{
	x = m_P.x;
	y = m_P.y;
}

void Point::Ask2Set_P(void)
{
	float x, y;
	cout << endl << " X: ";
	cin >> x;
	cout << endl << " Y: ";
	cin >> y;
	Set_P(x, y);
}

void Point::ShowPoint(void)
{
	cout << "(x,y)" << '=' << '(' << x << ',' << y << ')';
}

bool Point::operator==(const Point ponto) const
{
	 return (x == ponto.x) ? (y == ponto.y) ? 1 : 0 : 0;
}

bool Point::operator!=(const Point ponto) const
{
	return (x == ponto.x) ? (y == ponto.y) ? 0 : 1 : 1;
}

void Point::operator=(Point ponto)
{
	Set_P(ponto.x, ponto.y);
}
void Point::Save(ofstream& os)
{
	os << x << ' ' << y;
}

void Point::Read(ifstream& is)
{
	float x, y;
	is >> x >> y;
	Set_P(x,y);
}