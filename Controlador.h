#pragma once
#include "Plutonio.h"
#include "Enemigo.h"
#include "Asteroide.h"
#include "Nave.h"
#include "Alien.h"

using namespace System::Drawing;

class Controlador {
private:
	Alien* a; //Objeto alien
	Nave* objNave; //Objeto nave
	Plutonio** arrP; //Plutonio
	int nP;
	Asteroide** arrA; //Asteroide
	int nA;
	Enemigo** arrE; //Enemigos
	int nE;
	int n;
	int cont;
	int contTotal;
	bool victoria;
	bool victoriaFinal;
public:
	Controlador() {
		victoria = true;
		victoriaFinal = false;
		a = new Alien();
		objNave = new Nave();
		contTotal = 100;
		cont = 0;
		n = 0;
		nP = 0; nA = 0; nE = 0;
		for (int i = 0; i < 100; i++) {
			agregarPlutonio();
		}
		for (int i = 0; i < 10; i++) {
			agregarAsteroide();
		}
		for (int i = 0; i < 5; i++) {
			agregarEnemigo();
		}
	}

	~Controlador() {}



	bool getVictoria() {
		return victoria;
	}

	int getCont() {
		return cont;
	}

	bool getVictoriaFinal() {
		return victoriaFinal;
	}

	//Inicializar arreglo de plutonio
	void agregarPlutonio() {
		Plutonio* p = new Plutonio();
		Plutonio** aux = new Plutonio * [nP + 1];
		for (int i = 0; i < nP; i++) {
			aux[i] = arrP[i];
		}
		aux[nP] = p;
		nP++;
		arrP = aux;
	}

	//Inicializar arreglo de asteroide
	void agregarAsteroide() {
		Asteroide* a = new Asteroide();
		Asteroide** aux = new Asteroide * [nA + 1];
		for (int i = 0; i < nA; i++) {
			aux[i] = arrA[i];
		}
		aux[nA] = a;
		nA++;
		arrA = aux;
	}

	//inicializar arreglo de enemigo
	void agregarEnemigo() {
		Enemigo* e = new Enemigo();
		Enemigo** aux = new Enemigo * [nE + 1];
		for (int i = 0; i < nE; i++) {
			aux[i] = arrE[i];
		}
		aux[nE] = e;
		nE++;
		arrE = aux;
	}

	void datos() {
		int z; int l;
		z = a->getDX();
		l = a->getDY();
	}

	void borrarTodo() {
		//Objeto de Alien
		a->borrar();
		//Arreglo de Plutonio
		for (int i = 0; i < nP; i++) {
			arrP[i]->borrar();
		}
		//Arreglo de Asteroide
		for (int i = 0; i < nA; i++) {
			arrA[i]->borrar();
		}
		//Arreglo de Enemigo
		for (int i = 0; i < nE; i++) {
			arrE[i]->borrar();
		}
	}

	void moverTodo() {
		//Arreglo de Asteroide
		for (int i = 0; i < nA; i++) {
			arrA[i]->mover();
		}
		//Arreglo de Enemigo
		for (int i = 0; i < nE; i++) {
			arrE[i]->mover();
		}
	}

	void dibujarTodo() {

		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(151, 5); cout << "Vidas: " << a->getVidas();
		Console::SetCursorPosition(151, 7); cout << "Plutonios: " << contTotal;
		//Objeto de Alien
		a->dibujar();
		//Objeto de Nave
		objNave->dibujar();
		//Arreglo de Plutonio
		for (int i = 0; i < nP; i++) {
			if (arrP[i]->getVisibilidad() == true) {
				arrP[i]->dibujar();
			}
		}
		//Arreglo de Asteroide
		for (int i = 0; i < nA; i++) {
			arrA[i]->dibujar();
		}
		//Arreglo de Enemigo
		for (int i = 0; i < nE; i++) {
			arrE[i]->dibujar();
		}
	}

	void Colision_Alien_Nave() {
		if (a->getRectangle().IntersectsWith(objNave->getRectangle())) {
			if (cont = 100) {
				victoriaFinal = true;
			}
		}
	}

	void Colision_Alien_Enemigo() { 
		for (int i = 0; i < nE; i++) {
			if (a->getRectangle().IntersectsWith(arrE[i]->getRectangle())) {
				a->restarVidas();
				a->posicionInicial();
			}
		}
	}

	void Victoria() {
		if (a->getVidas() <= 0) {
			victoria = false;
		}
	}

	
	void Colision_Alien_Asteroide() { 
		for (int i = 0; i < nA; i++) {
			if (a->getRectangle().IntersectsWith(arrA[i]->getRectangle())) {
				a->setDX(2);
				a->setDY(1);
			}
		}
	}

	
	void Colision_Alien_Plutonio() { //no me sale
		for (int i = 0; i < nP; i++) {
			if (a->getRectangle().IntersectsWith(arrP[i]->getRectangle())) {
				contTotal--;
				arrP[i]->borrar();
			}
		}
	}

	int getcont() { return cont; }
	int getContTotal() { return contTotal; }

	Alien* getAlien() {
		return a;
	}

	Nave* getNave() {
		return objNave;
	}
};
