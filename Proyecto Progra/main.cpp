#include<stdio.h>
#include<windows.h>
#include<conio.h>

#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75

void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon, dwPos);
}

int main() {
    int x = 0, y = 0;
    gotoxy(x, y); printf("*");

    bool game_over = false;
    while (!game_over) {
        if (_kbhit()) {
            char tecla = _getch();
            gotoxy(x, y); printf(" ");
            switch (tecla) {
                case IZQUIERDA:
                    if (x > 0) x--;
                    else x = 79; // Si llega al l�mite izquierdo, vuelve al l�mite derecho
                    break;
                case DERECHA:
                    if (x < 79) x++;
                    else x = 0; // Si llega al l�mite derecho, vuelve al l�mite izquierdo
                    break;
                case ARRIBA:
                    if (y > 0) y--;
                    else y = 34; // Si llega al l�mite superior, vuelve al l�mite inferior
                    break;
                case ABAJO:
                    if (y < 34) y++;
                    else y = 0; // Si llega al l�mite inferior, vuelve al l�mite superior
                    break;
                case 'q': // Tecla para salir del juego
                    game_over = true;
                    break;
            }
            if (!game_over) {
                gotoxy(x, y); printf("*");
            }
        }
    }

    return 0;
}
