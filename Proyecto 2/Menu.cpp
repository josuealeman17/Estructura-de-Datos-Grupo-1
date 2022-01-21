#include "Menu.h"

void Menu::imprimir() {

	cout << "Seleccione el tipo de notacion por la que quiere ingresar la expresion: " << endl;
	int opc;
	string expresion;

	do {
		cout << "1. IN-FIJA" << endl;
		cout << "2. PRE-FIJA" << endl;
		cout << "3. POST-FIJA" << endl;
		cout << "4. SALIR" << endl; cin >> opc;

		switch (opc) {
			case 1:
				system("cls");
				ingresarIn(expresion);

				break;
			case 2:
				system("cls");
				ingresarPre(expresion);

				break;
			case 3:
				system("cls");
				ingresarPost(expresion);

				break;
			case 4:
				system(0);
		}

	} while (opc != 4);
}

void Menu::ingresarIn(string expresion) {


	cout << "Ingresando en INFIJA" << endl; cin >> expresion;


	system("pause");
	system("cls");

}

void Menu::ingresarPre(string expresion) {
	cout << "Ingresando en PREFIJA" << endl; cin >> expresion;

	system("pause");
	system("cls");
}

void Menu::ingresarPost(string expresion) {

	cout << "Ingresando en POSTFIJA" << endl; cin >> expresion;
	system("pause");
	system("cls");
}
