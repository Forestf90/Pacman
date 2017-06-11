


#ifndef gra_h
#define gra_h
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <windows.h>  //sleep
#include <conio.h>  //getch()
#include <cstdlib>
#include <cmath>

#include "MMSystem.h"

using namespace std;

int czas=100;

/*
 class element
{
public:
	int wartosc;
	void wypisz();

};


class pozycja_ducha
{
	public:
	int kolumna=0;
	int wiersz=0;
	int temp=3;
	int kierunek=1;
	int naprowadzanie_pierwszorzedne=1;
	int naprowadzanie_drugorzedne;
};


class plansza
{
	public:
void wypelnij_easy();
void wypelnij_normal();
void wypisz_plansze();
	int numer_planszy;
	int  wiersze;
	int kolumna;
element ** tablica = new element * [wiersze];



};

*/

 class element
{
public:
int wartosc;


void wypisz()
{
    char sciana =219;
    char kropka =250;
    char duch =258;

	HANDLE hOut;
	hOut = GetStdHandle( STD_OUTPUT_HANDLE );

	switch(wartosc){
        case 1:
 		SetConsoleTextAttribute( hOut, FOREGROUND_BLUE );
		cout << sciana ;
		SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
	break;

        case 2: // kropka
		cout << kropka ;
    break;

        case 3:// brak kropki
        cout<<" ";
	break;

        case 4:
		SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
		cout<<"<";
		SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
	break;

        case 5:

		SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
		cout<<">";
		SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
	break;

        case 6:
		SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
		cout<<"^";
		SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
	break;

        case 7:
		SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
		cout<<"v";
		SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
	break;

        case 8: //duch
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_BLUE | FOREGROUND_RED );
		cout << duch ;
		SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
	break;
}
}

};

class pozycja_ducha
{
	public:
	int kolumna=0;
	int wiersz=0;
	int temp=3;
	int kierunek=1;
	int naprowadzanie_pierwszorzedne=1;
	int naprowadzanie_drugorzedne;
};



class plansza
{

	public:
	int  wiersze=0;
	int kolumna=0;
	bool smierc=false;
	int zycia=3;
	//element ** tablica = new element * [wiersze];
	element **tablica;

	plansza()
{
 tablica = new element * [wiersze];
}


void wypelnij_easy()
{

	kolumna=15;
	wiersze =11;
	for( int i=0; i<=wiersze; i++ )
	 *(tablica+i) = new element [kolumna] ;


	int j=0;
int a=0;


int schemat[wiersze*kolumna]={
3,3,3,1,1,1,1,1,1,1,1,1,3,3,3,
3,1,1,1,1,1,2,2,2,1,1,1,1,1,3,
1,1,1,2,2,2,2,2,2,2,2,2,1,1,1,
1,1,2,2,1,2,2,2,2,2,1,2,2,1,1,
1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,
1,1,2,2,2,2,2,5,2,2,2,2,2,1,1,
1,1,2,2,1,2,2,2,2,2,1,2,2,1,1,
1,1,2,2,2,1,1,1,1,1,2,2,2,1,1,
1,1,1,2,2,2,2,2,2,2,2,2,1,1,1,
3,1,1,1,1,2,2,2,2,2,1,1,1,1,3,
3,3,3,1,1,1,1,1,1,1,1,1,3,3,3};


for(int i=0 ; i<=kolumna ; i++)
{


//cout<<schemat[a];

//cout<<zamiana<<endl;
(*(tablica+j)+i)->wartosc = schemat[a];
//	 cout<<(*(tablica+j)+i)->wartosc<<endl;

	if(i==kolumna-1)
{

if(j==wiersze) break;
	i=(-1);
	j++;
}
a++;
}




}

void wypelnij_normal()
{

	kolumna =19;
	wiersze =11;
	for( int i=0; i<=wiersze; i++ )
	*(tablica+i) = new element [kolumna] ;




	/*
string schemat=
	"1111111111111111111"
	"1222222221222222221"
	"1211211121211121121"
	"1222222222222222221"
	"1211211112111121121"
	"1221222223222221221"
	"1121212111112121211"
	"1222212221222122221"
	"1211111121211111121"
	"1222222222222222221"
	"1111111111111111111";
*/

int schemat[wiersze*kolumna]=
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1,
	1,2,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,2,1,
	1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
	1,2,1,1,2,1,1,1,1,2,1,1,1,1,2,1,1,2,1,
	1,2,2,1,2,2,2,2,2,5,2,2,2,2,2,1,2,2,1,
	1,1,2,1,2,1,2,1,1,1,1,1,2,1,2,1,2,1,1,
	1,2,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,2,1,
	1,2,1,1,1,1,1,1,2,1,2,1,1,1,1,1,1,2,1,
	1,2,2,2,2,2,2,2,2,8,2,2,2,2,2,2,2,2,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

int j=0;
int a=0;


for(int i=0 ; i<=kolumna ; i++)
{

(*(tablica+j)+i)->wartosc = schemat[a];


	if(i==kolumna-1)
{

if(j==wiersze) break;
	i=(-1);
	j++;
}
a++;
}

}






void wypelnij_hard()
{

	kolumna=20;
	wiersze =11;
	for( int i=0; i<=wiersze; i++ )
	 *(tablica+i) = new element [kolumna] ;


	int j=0;
int a=0;


int schemat[wiersze*kolumna]=
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,2,2,2,2,1,2,2,2,2,2,2,2,2,1,2,2,2,2,1,
	1,2,1,1,2,1,2,1,1,1,1,1,1,2,1,2,1,1,2,1,
	1,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1,
	1,2,1,2,1,1,2,1,1,3,3,1,1,2,1,1,2,1,2,1,
	1,2,2,2,2,2,2,1,8,3,3,8,1,2,2,2,2,2,2,1,
	1,2,1,2,1,1,2,1,1,1,1,1,1,2,1,1,2,1,2,1,
	1,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1,
	1,2,1,1,2,1,2,1,1,1,1,1,1,2,1,2,1,1,2,1,
	1,2,2,2,2,1,2,2,2,5,2,2,2,2,1,2,2,2,2,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};


for(int i=0 ; i<=kolumna ; i++)
{


//cout<<schemat[a];

//cout<<zamiana<<endl;
(*(tablica+j)+i)->wartosc = schemat[a];
//	 cout<<(*(tablica+j)+i)->wartosc<<endl;

	if(i==kolumna-1)
{

if(j==wiersze) break;
	i=(-1);
	j++;
}
a++;
}





}

void wypisz_plansze()
{

	int j=0;
	cout<<endl<<endl<<" \t \t";
for(int i=0 ; i<=kolumna ; i++)
	{

	(*(tablica+j)+i)->wypisz();

	if(i==kolumna)
		{
			cout<<endl<<" \t \t";
			if(j==wiersze) break;
			i=(-1);
			j++;
		}


	}


}

void wyczysc_tablice()
{


int j=0;
for(int i=0 ; i<=kolumna ; i++)
{


//cout<<schemat[a];

//cout<<zamiana<<endl;
(*(tablica+j)+i)->wartosc = 0;
//	 cout<<(*(tablica+j)+i)->wartosc<<endl;

	if(i==kolumna-1)
{

if(j==wiersze) break;
	i=(-1);
	j++;
}

}

/*
j=0;
for(int i=0 ; i<kolumna ; i++)
{
delete (*(tablica+j)+i);

	if(i==kolumna)
{

delete tablica[j];
if(j==wiersze) break;
	i=0;
	j++;
}


}
delete tablica;

*/


	for (int i = 0; i<wiersze; i++)
 delete [] tablica[i];

delete [] tablica;



}
};


	void wypisz();
void wypelnij_easy();
void wypelnij_normal();
void wypisz_plansze();
//definicje funkcji-----------
void menu();
void instrukcja();
void autorzy();
void ustawienia();
void gra();
void przegrana(plansza * pac_pac);
void zwyciestwo(plansza);
pozycja_ducha znajdz_i_wyeliminuj(plansza, pozycja_ducha , int ,int);
pozycja_ducha wyznacz_kierunek(pozycja_ducha  , plansza );
pozycja_ducha duch(plansza*, pozycja_ducha );
void rip(plansza);
void wybor();
//void gra2(); //³atwy

#endif
