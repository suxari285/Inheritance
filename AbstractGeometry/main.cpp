#include<Windows.H>
#include<iostream>

using namespace std;

enum Colour
{
	Red = 0x000000FF,
	Green = 0x0000FF00,
	Blue = 0x00FF0000,
	Yellow = 0x0000FFFF,
	Purple = 0x00800080,
};

class Shape
{
	Colour colour;
public:
	Shape(Colour colour) : colour(colour){}
	virtual ~Shape() {}
	virtual double get_area() const = 0;
	virtual double get_perimetr() const = 0;
	virtual void draw() const = 0;
	virtual void info()const
	{
		cout << "Площадь фигуры: " << get_area() << endl;
		cout << "Площадь фигуры: " << get_perimetr() << endl;
		draw();
	}
};

class Square:public Shape
{
	double side;
public:
	Square(double side, Colour colour) :Shape(colour)
	{
		this->side = side;
	}
	~Square(){}
	void set_side(double side)
	{
		this->side = side;
	}
	double get_side()const
	{
		return side;
	}
	double get_area()const override
	{
		return side * side;
	}
	double get_perimetr()const override
	{
		return side * 4;
	}
	void draw() const override
	{
		/*for (int i = 0; i < side; i++)
		{
			for (int i = 0; i < side; i++)
			{
				cout << "* ";
			}
			cout << endl;
		}*/

		HWND hwnd = GetConsoleWindow(); //1)Получаем окно консоли
		HDC hdc = GetDC(hwnd); //получаем контекст окна консоли
		//3)создаём чем и на чём мы будем рисовать
		HPEN hPen = CreatePen(PS_SOLID, 5, Colour::Red);//контур фигуры
		HBRUSH hBrush = CreateSolidBrush(Colour::Red); //заливка фигуры

		//вышесозданный инструмент нужно выбрать
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);
		
		//Рисуем фигуру
		Rectangle(hdc, 300, 300, 500, 500);

		//удаляем инструменты для того что бы освободить ресурсы
		DeleteObject(hBrush);
		DeleteObject(hPen);
		ReleaseDC(hwnd, hdc);
	}

	void info()const override
	{
		cout << typeid(*this).name() << endl;
		cout << "Длина стороны: " << get_side() << endl;
		Shape::info();
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Shape shape = Colour::Red;

	Square square(5, Colour::Red);
	//cout << "Сторона квадрата: " << square.get_side() << endl;`
	//cout << "Площадь фигуры: " << square.get_area() << endl;
	//cout << "Площадь фигуры: " << square.get_perimetr() << endl;
	//square.draw();
	square.info();
}