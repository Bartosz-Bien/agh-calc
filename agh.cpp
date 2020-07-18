#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

char wybor;
vector <int> progi;
vector <string> nazwa;
int rok;

void import()
{
    progi.clear();
    nazwa.clear();

    int wejscieInt;
    string wejscieString;

    ifstream wejscie("dane_2019.txt");

    //wejscie >> wejscieInt;
    //rok = wejscieInt;
    bool t = true;

    while (!wejscie.eof())
    {
        if (t)
        {
            wejscie >> wejscieInt;
            rok = wejscieInt;
            t = false;
        }
        wejscie >> wejscieInt;
        wejscie >> wejscieString;
        nazwa.push_back(wejscieString);
        wejscie >> wejscieInt;
        progi.push_back(wejscieInt);
    }
}

int policzWynik(int pods, int rozsz)
{
    int suma = 0;

    pods *= 2;
    suma += pods;

    if (rozsz > 80)
    {
        rozsz += 100;
        rozsz *= 4;
        suma += rozsz;
        return suma;
    }
    else
    {
        if (rozsz < 30)
        {
            rozsz *= 4;
            suma += rozsz;
            return suma;
        }
        else
        {
            rozsz += 2 * (rozsz - 30);
            rozsz *= 4;
            suma += rozsz;
            return suma;
        }
    }

}

void poczatek()
{
    import();
    cout << "OSZACUJ SWOJ WYNIK PRZY REKRUTACJI NA AGH\nDane z " << rok << " roku.\n\nWybierz, czy chcesz wpisac szacowany wynik\nz podstawy - wpisz: p\nczy z rozszerzenia - wpisz: r\n";

    bool czyDobrzeWybral = true;

    while (czyDobrzeWybral)
    {
        cout << "\nPodaj literke: ";
        cin >> wybor;
        wybor = tolower(wybor);

        if (wybor == 'p' || wybor == 'r')
            czyDobrzeWybral = false;
        else
        {
            czyDobrzeWybral = true;
            cout << "Wpisz dobrze\n";
        }
    }
}

int main ()
{
    poczatek();

    int procent;

    if (wybor == 'p')
    {
        cout << "\nPodaj spodziewany wynik z podstawy: ";
        cin >> procent;

        bool czyLiczyc;

        for (int j = 0; j < nazwa.size(); j++)
        {
            czyLiczyc = true;
            for (int i = 0; czyLiczyc; i += 2)
            {
                if (policzWynik(procent, i) >= progi[j])
                {
                    cout << "Musisz zdobyc " << i << " procent lub wiecej z rozszerzenia\t";
                    czyLiczyc = false;
                }
            }
            cout << nazwa[j] << "\n";
        }

    }

    else
    {
        cout << "\nPodaj spodziewany wynik z rozszerzenia: ";
        cin >> procent;

        bool czyLiczyc;
        for (int j = 0; j < nazwa.size(); j++)
        {
            czyLiczyc = true;
            for (int i = 0; czyLiczyc; i += 2)
            {
                if (policzWynik(i, procent) >= progi[j])
                {
                    cout << "Musisz zdobyc " << i << " procent lub wiecej z podstawy\t";
                    czyLiczyc = false;
                }
            }
             cout << nazwa[j] << "\n";
        }
    }

    system("pause");
    return 0;
}
