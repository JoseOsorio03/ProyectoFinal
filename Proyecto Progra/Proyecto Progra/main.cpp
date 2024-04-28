#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <vector>

#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75
#define FILAS 35
#define COLUMNAS 80

using namespace std;

int x = 0, y = 0;

void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

//Plantillas de las figuras
struct Cuadrado {
    COORD coord;
    int lado;
};

struct Triangulo {
    COORD coord;
    int base;
};

struct Rectangulo {
    COORD coord;
    int base;
    int altura;
};

struct Circulo {
    COORD coord;
    int radio;
};

//Vectores donde Almaceno cada Figura
vector<Cuadrado> almacenCuadrado;
vector<Triangulo> almacenTriangulo;
vector<Rectangulo> almacenRectangulo;
vector<Circulo> almacenCirculo;

void cuadrado(Cuadrado cuadrado) {
    int lado = cuadrado.lado;
    int x = cuadrado.coord.X;
    int y = cuadrado.coord.Y;

    for (int i = 0; i < lado; i++) {
        int x1 = (x + i + COLUMNAS) % COLUMNAS;
        int x2 = (x + i + COLUMNAS) % COLUMNAS;
        int y1 = (y + FILAS) % FILAS;
        int y2 = (y + lado - 1 + FILAS) % FILAS;

        gotoxy(x1, y1); printf("x");
        gotoxy(x2, y2); printf("x");
    }

    for (int i = 0; i < lado; i++) {
        int x1 = (x + COLUMNAS) % COLUMNAS;
        int x2 = (x + lado - 1 + COLUMNAS) % COLUMNAS;
        int y1 = (y + i + FILAS) % FILAS;

        gotoxy(x1, y1); printf("x");
        gotoxy(x2, y1); printf("x");
    }
}

void rectangulo(Rectangulo rectangulo) {
    int base = rectangulo.base;
    int altura = rectangulo.altura;
    int x = rectangulo.coord.X;
    int y = rectangulo.coord.Y;

    for (int i = 0; i < base; i++) {
        int x1 = (x + i + COLUMNAS) % COLUMNAS;
        int x2 = (x + i + COLUMNAS) % COLUMNAS;
        int y1 = (y + FILAS) % FILAS;
        int y2 = (y + altura - 1 + FILAS) % FILAS;

        gotoxy(x1, y1); printf("x");
        gotoxy(x2, y2); printf("x");
    }

    for (int i = 0; i < altura; i++) {
        int x1 = (x + COLUMNAS) % COLUMNAS;
        int x2 = (x + base - 1 + COLUMNAS) % COLUMNAS;
        int y1 = (y + i + FILAS) % FILAS;

        gotoxy(x1, y1); printf("x");
        gotoxy(x2, y1); printf("x");
    }
}

void triangulo(Triangulo triangulo) {
    int base = triangulo.base;
    int x = triangulo.coord.X;
    int y = triangulo.coord.Y;


    x = (x + COLUMNAS) % COLUMNAS;
    y = (y + FILAS) % FILAS;


    for (int i = 0; i < base; i++) {
        gotoxy((x - i + COLUMNAS) % COLUMNAS, (y + i + FILAS) % FILAS);
        printf("x");
        if (i != 0) {
            for (int j = 0; j < 2 * i - 1; j++) {
                printf(" ");
            }
            printf("x");
        }
    }

    gotoxy((x - base + COLUMNAS) % COLUMNAS, (y + base + FILAS) % FILAS);
    for (int i = 0; i < 2 * base - 1; i++) {
        printf("x");
    }
}


void circulo(Circulo circulo) {
    int radio = circulo.radio;
    int x = circulo.coord.X;
    int y = circulo.coord.Y;

    for (int i = -radio; i <= radio; i++) {
        for (int j = -radio; j <= radio; j++) {
            if (i * i + j * j <= radio * radio) {
                int x1 = (x + i + COLUMNAS) % COLUMNAS;
                int y1 = (y + j + FILAS) % FILAS;
                gotoxy(x1, y1); printf("x");
            }
        }
    }
}


void cargarCuadrados() {
    for (const auto& Cuadrado : almacenCuadrado) {
        cuadrado(Cuadrado);
    }
}

void cargarTriangulos() {
    for (const auto& Triangulo : almacenTriangulo) {
        triangulo(Triangulo);
    }
}

void cargarRectangulos() {
    for (const auto& Rectangulo : almacenRectangulo) {
        rectangulo(Rectangulo);
    }
}

void cargarCirculo() {
    for (const auto& Circulo : almacenCirculo) {
        circulo(Circulo);
    }
}

void cargarFiguras() {
    cargarCuadrados();
    cargarTriangulos();
    cargarRectangulos();
    cargarCirculo();
}

void limpiar(){
    almacenCirculo.clear();
    almacenCuadrado.clear();
    almacenTriangulo.clear();
    almacenRectangulo.clear();
}


int main() {
    gotoxy(x, y);

    bool game_over = false;
    bool f12_pressed = false;

    while (!game_over) {
            system("cls");
            cargarFiguras();
            gotoxy(x, y); printf("x");

        if (GetAsyncKeyState(VK_F12) & 0x8000 && !f12_pressed) {
            printf("\nSelecciona la opcion:\n1 para Triangulo\n2 para cuadrado\n3 para rectangulo\n4 para circulo\n5 Para Limpiar la pantalla\n ");

            f12_pressed = true;
            int opcion;
            scanf("%d", &opcion);
switch (opcion) {
    case 1:
        system("cls");
        printf("Ingrese la base del Triangulo: ");
        int base;
        scanf("%d", &base);
        Triangulo nuevoTriangulo;
        nuevoTriangulo.base = base;
        nuevoTriangulo.coord.X = x;
        nuevoTriangulo.coord.Y = y;
        almacenTriangulo.push_back(nuevoTriangulo);
        break;
    case 2:
        system("cls");
        printf("Ingrese el lado del cuadrado: ");
        int lado;
        scanf("%d", &lado);
        Cuadrado nuevoCuadrado;
        nuevoCuadrado.lado = lado;
        nuevoCuadrado.coord.X = x;
        nuevoCuadrado.coord.Y = y;
        almacenCuadrado.push_back(nuevoCuadrado);
        break;
    case 3:
        system("cls");
        printf("Ingrese la base del Rectangulo: ");
        int baseRect;
        scanf("%d", &baseRect);
        printf("Ingrese la altura del Rectangulo: ");
        int alturaRect;
        scanf("%d", &alturaRect);
        Rectangulo nuevoRectangulo;
        nuevoRectangulo.base = baseRect;
        nuevoRectangulo.altura = alturaRect;
        nuevoRectangulo.coord.X = x;
        nuevoRectangulo.coord.Y = y;
        almacenRectangulo.push_back(nuevoRectangulo);
        break;
    case 4:
        system("cls");
        printf("Ingrese el radio del Circulo: ");
        int radio;
        scanf("%d", &radio);
        Circulo nuevoCirculo;
        nuevoCirculo.radio = radio;
        nuevoCirculo.coord.X = x;
        nuevoCirculo.coord.Y = y;
        almacenCirculo.push_back(nuevoCirculo);
        break;
    case 5:
        system("cls");
        printf("Limpia pantalla...");
        limpiar();
        break;
    default:
        printf("Opcion no valida\n");
        break;
}


        }

        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == 'q') {
                game_over = true;
            } else if (tecla == IZQUIERDA) {
                x = (x - 1 + COLUMNAS) % COLUMNAS;
                f12_pressed = false;
                gotoxy(x, y);
            } else if (tecla == DERECHA) {
                x = (x + 1) % COLUMNAS;
                f12_pressed = false;
                gotoxy(x, y);
            } else if (tecla == ARRIBA) {
                y = (y - 1 + FILAS) % FILAS;
                f12_pressed = false;
                gotoxy(x, y);
            } else if (tecla == ABAJO) {
                y = (y + 1) % FILAS;
                f12_pressed = false;
                gotoxy(x, y);
            }
        }

        Sleep(10);
    }

    return 0;
}
