#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

int datos[2] = { 1, -1 };

class Asteroide {
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
public:
	Asteroide() {
		x = rand() % (135 - 3 + 1) + 3;
		y = 2;
		dx = datos[rand() % 2];
		dy = 1;
		ancho = 2;
		alto = 2;
	}

	~Asteroide() {}

	void aleatorio() {
		dx = rand() % 5 - 1;
		dy = dx;
	}

	void borrar() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void mover() {
		if (x < 2 || x + ancho >= 148) {
			dx *= -1;
		}
		if (y < 2 || y + alto >= 33) {
			dy *= -1;
		}
		x += dx;
		y += dy;
	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Blue;
		Console::SetCursorPosition(x, y); cout << char(220);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};