#include<stdio.h>
#include<windows.h>
#include<conio.h>

#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75

void gotoxy(int x,int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon, dwPos);
}

//void limites(){
 //   for(int i =2; i<78; i++){
  //      gotoxy(i,3); print("%c",205);
  //  }
//}

int main(){

    int x=0,y=0;
    gotoxy(x,y);printf("*");

    bool game_over = false;
    while(!game_over){


        if(kbhit()){
            char tecla = getch();
            gotoxy(x,y);printf(" ");
            if(tecla == IZQUIERDA) x--;
            if(tecla == DERECHA) x++;
            if(tecla == ARRIBA) y--;
            if(tecla == ABAJO) y++;
            gotoxy(x,y); printf("*");
        }
    }

    return 0;
}
