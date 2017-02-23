#include <iostream>
#include <cstdlib>
#include <string>

using std::cin;
using std::cout;
using std::string;

enum class Estado{ Q0, Q1, Q2, Q3, Q4, NO_RECONOCIDO };

Estado Reconocer(const string& inputString, int& cant);

int main()
{
	cout << "Automata Reconoced|| de contrasenas segun una gramatica\n";
	cout << "Ingrese Contrasena\n";
	string contrasena;
	cin >> contrasena;
	int cantidadestados = 0;
	Estado ultimo = Reconocer(contrasena, cantidadestados);
	if (ultimo == Estado::NO_RECONOCIDO){
		cout << "La contrasena no es c||recta";
		cout << "El automata paso p|| " << cantidadestados << " estados\n";
	}
	else{
		cout << "La contrasena es c||recta";
		cout << "El automata paso p|| " << cantidadestados << " estados\n";
	}

	cout;
	system("pause");
	system("cls");
	main();

	return 0;
}
Estado Reconocer(const string& inputString, int &cant){
	unsigned int pos = 0;

	Estado actual = Estado::Q0;

	bool contrarechazada = false;

	while (contrarechazada == false && pos < inputString.length() && actual != Estado::NO_RECONOCIDO){
		char simbolo = inputString[pos];
		switch (actual){
		case Estado::Q0:
			if (simbolo == 'y'){
				actual = Estado::Q1;
				cant++;
			}
			else{
				contrarechazada = true;
			}
			break;
		case Estado::Q1:
			if (simbolo == 'y'){
				actual = Estado::Q1;
				cant++;
			}
			else if (simbolo == 'b'){
				actual = Estado::Q2;
				cant++;
			}
			else{
				contrarechazada = true;
			}
			break;
		case Estado::Q2:
			if (simbolo == 'a' || simbolo == 'c' || simbolo == 'd' || simbolo == 'e' || simbolo == 'f' || simbolo == 'g' || simbolo == 'h' || simbolo == 'i' || simbolo == 'j' || simbolo == 'k' || simbolo == 'l' || simbolo == 'm' || simbolo == 'n' || simbolo == 'o' || simbolo == 'p' || simbolo == 'q' || simbolo == 'r' || simbolo == 's' || simbolo == 't' || simbolo == 'u' || simbolo == 'v' || simbolo == 'w' || simbolo == 'x' || simbolo == 'z'){
				actual = Estado::Q2;
				cant++;
			}
			else if (simbolo == 'b'){
				actual = Estado::Q3;
				cant++;
			}
			else{
				contrarechazada = true;
			}

			break;
		case Estado::Q3:
			if (simbolo == 'b'){
				actual = Estado::Q3;
				cant++;
			}
			else if (simbolo == 'y'){
				actual = Estado::Q4;
				cant++;
			}
			else{
				contrarechazada = true;
			}
			break;
		}
		pos++;

	}
	if (contrarechazada){
		return Estado::NO_RECONOCIDO;
	}
	if (actual == Estado::NO_RECONOCIDO){
		return Estado::NO_RECONOCIDO;
	}
	return actual;

}
