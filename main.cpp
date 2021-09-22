#include <conio.h>
#include "Controlador.h"
#include <stdlib.h> 
#include <Windows.h>

int main() {
	srand(time(NULL));
	Console::ForegroundColor = ConsoleColor::DarkGreen;
	char tecla;
	int op;
	Console::SetWindowSize(60, 40);
	Console::SetCursorPosition(27, 0);
	Console::ForegroundColor = ConsoleColor::Green;
	cout << "ALIENS";
	Console::ForegroundColor = ConsoleColor::White;
	Console::SetCursorPosition(25, 3);
	cout << "MENU";
	Console::SetCursorPosition(25, 4);
	cout << "===============" << endl;
	cout << "1. Iniciar el juego" << endl;
	cout << "2. Salir" << endl << endl;

	do {
		cout << "Elija una opcion del menu: "; cin >> op;
	} while (op < 1 || op > 2);
	system("cls");

	if (op == 1) {
		/*int  m = 2, s = 0;
		timer(m, s);
		for (int i = 100; ; i = i + 50)
			Beep(i, 1000);*/
		Console::BackgroundColor = ConsoleColor::Black;
		Console::CursorVisible = false;
		Console::SetWindowSize(165, 35);
		Controlador* c = new Controlador();
		while (true) {
			Console::CursorVisible = false;
			c->borrarTodo();

			c->Colision_Alien_Enemigo();
			if (_kbhit()) {
				tecla = _getch();
				tecla = toupper(tecla);
				c->getAlien()->mover(tecla);
			}

			c->moverTodo();
			c->dibujarTodo();
			c->Victoria();

			if (c->getVictoria() == false) {
				system("cls");
				Console::BackgroundColor = ConsoleColor::Black;
				Console::ForegroundColor = ConsoleColor::Green;
				Console::SetWindowSize(60, 40);
				Console::SetCursorPosition(23, 1); cout << "Te quedaste sin vidas\n";
				Console::SetCursorPosition(23, 3); cout << "Muchas gracias por jugar!\n";
				system("pause");
				cout << endl;
				Console::CursorVisible = false;
				exit(0);
			}
			
			if (c->getVictoriaFinal() == true) {
				system("cls");
				Console::BackgroundColor = ConsoleColor::Black;
				Console::ForegroundColor = ConsoleColor::Green;
				Console::SetWindowSize(60, 40);
				Console::SetCursorPosition(23, 1); cout << "La victoria es tuya!\n";
				Console::SetCursorPosition(23, 3); cout << "Muchas gracias por jugar!\n";
				system("pause");
				cout << endl;
				Console::CursorVisible = false;
				exit(0);
			}
						

			_sleep(150);
		}
	}

	if (op == 2) {
		exit(0);
	}

	_getch();
	return 0;
}