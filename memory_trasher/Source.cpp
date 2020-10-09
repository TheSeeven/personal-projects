#include <stdio.h>
#include <windows.h>


int main()
{
    void* x;

    for (int i = 0; i < 1024 * 1024 * 1024; i++)
    {
        x = (void*)malloc(16000);
        switch (i) {
        case 1024:
            printf("Starting the game...");
            break;
        case 800000:
            system("cls");
            printf("Welcome to world of Minions!\nPress enter 10 times and wait 10 seconds (suprise)");
        case 1500000:
            system("cls");
            printf("Cool, guess what am I thinking now?");
        case 3500000:
            system("cls");
            printf("I am waiting...");
        }
    }
    Sleep(2000);
    printf("Well, you won! :)");
    while (true) {}
}
