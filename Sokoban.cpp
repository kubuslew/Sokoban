//Created by Jakub Lewandowski

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void instrukcja()
{
    cout <<"\t Witaj w grze SOKOBAN" << endl;
    cout <<"Poruszasz sie za pomoca klawiszy W(gora) S(dol) A(lewo) D(prawo). Kazdy ruch zatwierdz enterem" << endl;
    cout <<"W kazdej chwili mozesz wyjsc naciskajac q" << endl;
    cout <<"Aby wygrac przesun wszystkie znaki 'x' na pola 'o' popychajac je postacia M (magazynier - to ty!)" << endl << endl;
}

char porusz(char mapa[10][10], int &x,int &y,int &koniec)
{
    char ruch;
    cout<<"Zrob ruch: ";
    cin>>ruch;
    if (ruch == 'w' || ruch == 'W')
    {
        if (mapa[y - 1][x] == (char)32)
        {
            mapa[y - 1][x] = 'M';
            mapa[y][x] = (char)32;
            y--;
        }
        else if (mapa[y - 1][x] == (char)120)
        {
            if (mapa[y - 2][x] == (char)32 || mapa[y - 2][x] == (char)111)
            {
                mapa[y - 2][x] = (char)120;
                mapa[y - 1][x] = 'M';
                mapa[y][x] = (char)32;
                y--;
            }

        }
        else
        {
            cout << endl << "Nie mozna przechodzic przez sciane!" << endl;
            Sleep(500);
        }
    }
    else if (ruch == 's' || ruch == 'S')
    {
        if (mapa[y + 1][x] == (char)32)
        {
            mapa[y + 1][x] = 'M';
            mapa[y][x] = (char)32;
            y++;

        }
        else if (mapa[y + 1][x] == (char)120)
        {
            if (mapa[y + 2][x] == (char)32 || mapa[y + 2][x] == (char)111)
            {
                mapa[y + 2][x] = (char)120;
                mapa[y + 1][x] = 'M';
                mapa[y][x] = (char)32;
                y++;
            }
        }
        else
        {
            cout << endl << "Nie mozna przechodzic przez sciane!" << endl;
            Sleep(500);
        }
    }

    else if (ruch == 'a' || ruch == 'A')
    {
        if (mapa[y][x - 1] == (char)32)
        {
            mapa[y][x - 1] = 'M';
            mapa[y][x] = (char)32;
            x--;
        }
        else if (mapa[y][x - 1] == (char)120)
        {
            if (mapa[y][x - 2] == (char)32 || mapa[y][x - 2] == (char)111)
            {
                mapa[y][x - 2] = (char)120;
                mapa[y][x - 1] = 'M';
                mapa[y][x] = (char)32;
                x--;
            }
        }
        else
        {
            cout << endl << "Nie mozna przechodzic przez sciane!" << endl;
            Sleep(500);
        }
    }
    else if (ruch == 'd' || ruch== 'D')
    {
        if (mapa[y][x + 1] == (char)32)
        {
            mapa[y][x + 1] = 'M';
            mapa[y][x] = (char)32;
            x++;
        }
        else if (mapa[y][x + 1] == (char)120)
        {
            if (mapa[y][x + 2] == (char)32 || mapa[y][x + 2] == (char)111)
            {
                mapa[y][x + 2] = (char)120;
                mapa[y][x + 1] = 'M';
                mapa[y][x] = (char)32;
                x++;
            }
        }
        else
        {
            cout << endl << "Nie mozna przechodzic przez sciane!" << endl;
            Sleep(500);
        }
    }
    else if (ruch == 'q' || ruch == 'Q')
    {
        system("cls");
        cout << "KONIEC\n"<< endl;
        koniec = 0;
    }

    else
    {
        cout << "zly klawisz" << endl;
        Sleep(500);
    }
    return mapa, x, y, koniec;
}

int wygranie(char mapa[10][10], int &licz_wygrana)
{
    licz_wygrana = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (mapa[i][j] == 'o')
            {
                licz_wygrana++;
            }
        }
    }
    return licz_wygrana;
}

void pobranie(char mapa[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << mapa[i][j];
        }
        cout << endl;
    }
}

char pierwsza[10][10]
        {
                {(char)218,(char)196,(char)196,(char)196,(char)191},
                {(char)179,'M',' ',' ',(char)179},
                {(char)179,' ','x',' ',(char)179},
                {(char)195,(char)196,(char)196,' ',(char)179},
                {(char)179,'o','x',' ',(char)179},
                {(char)179,' ',' ','o',(char)179},
                {(char)192,(char)196,(char)196,(char)196,(char)217},

        };
char druga[10][10]
        {
                {(char)218,(char)196,(char)196,(char)196,(char)191,' '},
                {(char)179,'o',' ',' ',(char)192,(char)191},
                {(char)179,'M','x','x',' ',(char)179},
                {(char)179,' ',' ',' ',' ',(char)179},
                {(char)192,(char)191,' ',' ',' ',(char)179},
                {' ',(char)192,(char)191,' ',' ',(char)179},
                {' ',' ',(char)192,(char)191,'o',(char)179},
                {' ',' ',' ',(char)192,(char)196,(char)217}
        };
char trzecia[10][10]
        {
                {(char)218,(char)196,(char)196,(char)196,(char)196,(char)191},
                {(char)179,' ',' ',' ','o',(char)179},
                {(char)179,' ','x','x','M',(char)179},
                {(char)179,' ',' ',(char)254,' ',(char)179},
                {(char)179,'o',' ',' ',' ',(char)179},
                {(char)192,(char)196,(char)196,(char)196,(char)196,(char)217}
        };
int koniec_gry(int &wygrana, int &koniec)
{

    if (wygrana == 0)
    {
        system("cls");
        cout << "Skonczyles poziom" << endl;
        koniec = 0;
    }
    return koniec;
}
int main()
{
    cout<<" _______ _______ ___   _ _______ _______ _______ __    _ \n";
    cout<<"|       |       |   | | |       |  _    |   _   |  |  | |\n";
    cout<<"|  _____|   _   |   |_| |   _   | |_|   |  |_|  |   |_| |\n";
    cout<<"| |_____|  | |  |      _|  | |  |       |       |       |\n";
    cout<<"|_____  |  |_|  |     |_|  |_|  |  _   ||       |  _    |\n";
    cout<<" _____| |       |    _  |       | |_|   |   _   | | |   |\n";
    cout<<"|_______|_______|___| |_|_______|_______|__| |__|_|  |__|\n\n";
    cout<<right<<setw(41)<<"Jakub Lewandowski\n\n";
    int koniec = 1;
    int x, y;
    char tablica[10][10];
    int wygrana;
    int wybor;
    while(true){
        cout << "1 - Zagraj" << endl;
        cout << "2 - Zasady" << endl;
        cout << "3 - Wyjscie" << endl;
        cin>>wybor;
        switch (wybor)
        {
            case 1:
                system("cls");
                int poziom;
                cout<<"Wybierz poziom:"<<endl<<"1."<<endl<<"2."<<endl<<"3."<<endl;
                cin>>poziom;
                switch(poziom)
                {
                    case 1:
                        system("cls");
                        wygrana = 2;
                        x = 1;
                        y = 1;
                        for (int i = 0; i < 10; i++)
                        {
                            for (int j = 0; j < 10; j++)
                            {
                                tablica[i][j] = pierwsza[i][j];
                            }
                            cout << endl;
                        }
                        system("cls");
                        while (koniec != 0)
                        {
                            system("cls");
                            cout << "x nie wstawione: " << wygrana << endl;
                            pobranie(tablica);
                            porusz(tablica, x, y, koniec);
                            wygranie(tablica, wygrana);
                            koniec_gry(wygrana, koniec);
                        }
                        koniec = 1;
                        break;
                    case 2:
                        wygrana = 2;
                        x = 1;
                        y = 2;
                        for (int i = 0; i < 10; i++)
                        {
                            for (int j = 0; j < 10; j++)
                            {
                                tablica[i][j] = druga[i][j];
                            }
                            cout << endl;
                        }
                        system("cls");
                        while (!(koniec == 0))
                        {
                            system("cls");
                            cout << "x nie wstawione: " << wygrana << endl;
                            pobranie(tablica);
                            porusz(tablica, x, y, koniec);
                            wygranie(tablica, wygrana);
                            koniec_gry(wygrana, koniec);
                        }
                        koniec = 1;
                        break;
                    case 3:
                        system("cls");
                        wygrana = 2;
                        x = 4;
                        y = 2;
                        for (int i = 0; i < 10; i++)
                        {
                            for (int j = 0; j < 10; j++)
                            {
                                tablica[i][j] = trzecia[i][j];
                            }
                            cout << endl;
                        }
                        system("cls");
                        while (!(koniec == 0))
                        {
                            system("cls");
                            cout << "x nie wstawione: " << wygrana << endl;
                            pobranie(tablica);
                            porusz(tablica, x, y, koniec);
                            wygranie(tablica, wygrana);
                            koniec_gry(wygrana, koniec);
                        }
                        koniec = 1;
                        break;
                }
                break;

            case 2:
                system("cls");
                instrukcja();
                break;

            case 3:
                system("cls");
                koniec = 0;
                cout << "Koniec gry." << endl;
                exit(0);
                break;
        }
    }
}