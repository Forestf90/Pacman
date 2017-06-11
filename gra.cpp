
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <windows.h>  //sleep
#include <conio.h>  //getch()
#include <cstdlib>
#include <cmath>
#include <MMSystem.h>

#include "gra.h"
#include "gra2.cpp"






void zwyciestwo(plansza  pac_pac)
{
		int j=0;

for(int i=0 ; i<19 ; i++)
	{

if(	(pac_pac.tablica[j]+i)->wartosc==2) return;

	if(i==18)
		{

			if(j==pac_pac.wiersze) break;
			i=(-1);
			j++;
		}

	}

pac_pac.wyczysc_tablice();
PlaySound(TEXT("pacman_intermission.wav"), NULL , SND_ASYNC);
	cout<<endl<<endl<<"Brawo !Wygrales !"<<endl;
	cout<<"Wcisnij ESC wrocic do menu";
		char x;
		while (true)
		{
			x=getch();
			if(x==27) menu();

		}

}

void przegrana(plansza * pac_pac)
{
	int kolumna =pac_pac->kolumna;
	int wiersz=pac_pac->wiersze;
	system("CLS");

	bool czy_duch_zyje[2]={false , false};

		int j=0;
		int numer_ducha=0;

for(int i=0 ; i<=kolumna ; i++)
	{
if (	(pac_pac->tablica[j]+i)->wartosc==8)
{


  czy_duch_zyje[numer_ducha]=true;
  if((pac_pac->tablica[10]+19)->wartosc==true)
  {
  czy_duch_zyje[1]=true;
  break;
  }
  numer_ducha++;

}

	if(i==kolumna)
		{

			if(j==wiersz) break;
			i=(-1);
			j++;
		}
	}

j=0;
for(int i=0 ; i<=kolumna ; i++)
	{
if(	(pac_pac->tablica[j]+i)->wartosc<=7 &&((pac_pac->tablica[j]+i)->wartosc>=4) && czy_duch_zyje[1]) (pac_pac->tablica[j]+i)->wartosc=8;
else if((pac_pac->tablica[j]+i)->wartosc<=7 &&((pac_pac->tablica[j]+i)->wartosc>=4)) (pac_pac->tablica[j]+i)->wartosc=8;
	if(i==kolumna)
		{

			if(j==wiersz) break;
			i=(-1);
			j++;
		}
	}


pac_pac->zycia -=1;
PlaySound(TEXT("pacman_death.wav"), NULL , SND_ASYNC);
if(pac_pac->zycia==0) rip(*pac_pac);

pac_pac->wypisz_plansze();


Sleep(1500);
system("CLS");

pac_pac->smierc=true;

/*
j=0;
for(int i=0 ; i<=kolumna ; i++)
	{
//if(	(pac_pac.tablica[j]+i)->wartosc<=7 &&((pac_pac.tablica[j]+i)->wartosc>=4) && czy_duch_zyje[numer_ducha]) (pac_pac.tablica[j]+i)->wartosc=3;
//else if ( (pac_pac.tablica[j]+i)->wartosc==8) (pac_pac.tablica[j]+i)->wartosc=3;
 if((pac_pac.tablica[j]+i)->wartosc<=7 &&((pac_pac.tablica[j]+i)->wartosc>=4)) (pac_pac.tablica[j]+i)->wartosc=3;

numer_ducha++;
	if(i==kolumna)
		{

			if(j==wiersz) break;
			i=(-1);
			j++;
		}
	}

*/
}

void rip(plansza  pac_pac)
{





	pac_pac.wypisz_plansze();


	cout<<endl<<endl<<"Przegrales!"<<endl;
	cout<<"Wcisnij ESC wrocic do menu";
	pac_pac.wyczysc_tablice();
		char x;
		while (true)
		{
			x=getch();
			if(x==27) menu();

		}

}

pozycja_ducha znajdz_i_wyeliminuj(plansza pac_pac , pozycja_ducha duszek , int kolumna ,int wiersz)
{
	cout<<endl<<"Zostales namierzony !";
	int roznica_kolumn;
	int roznica_wierszy;
	int temp;
	element *duch_polozenie_nastepne;

	roznica_kolumn = duszek.kolumna -kolumna;
	roznica_wierszy =duszek.wiersz - wiersz;



		if(roznica_wierszy>0)
		{
			duszek.naprowadzanie_pierwszorzedne=2;

		}
		else
		{
			duszek.naprowadzanie_pierwszorzedne=0;

		}


		if(roznica_kolumn>0)
		{
			duszek.naprowadzanie_drugorzedne=1;

		}
		else
		{
			duszek.naprowadzanie_drugorzedne=3;

		}


			if(abs(roznica_wierszy)< abs(roznica_kolumn))
			{
				temp=duszek.naprowadzanie_pierwszorzedne;
				duszek.naprowadzanie_pierwszorzedne=duszek.naprowadzanie_drugorzedne;
				duszek.naprowadzanie_drugorzedne=temp;
			}


	return duszek;


}

pozycja_ducha wyznacz_kierunek(pozycja_ducha duszek , plansza pac_pac)
{
	bool mozliwosci[4] ={false, false ,false ,false};
	element *pac_polozenie=pac_pac.tablica[duszek.wiersz]+duszek.kolumna;
	element *pac_polozenie_nastepne;
	int losowanie;

//	int ani_kroku_w_tyl;


		duszek.wiersz+=1;
		pac_polozenie_nastepne=pac_pac.tablica[duszek.wiersz]+duszek.kolumna;
		if(pac_polozenie_nastepne->wartosc!=1 && pac_polozenie_nastepne->wartosc!=8) mozliwosci[0]=true;
		duszek.wiersz-=1;

		duszek.kolumna-=1;
		pac_polozenie_nastepne=pac_pac.tablica[duszek.wiersz]+duszek.kolumna;
		if(pac_polozenie_nastepne->wartosc!=1 && pac_polozenie_nastepne->wartosc!=8) mozliwosci[1]=true;
		duszek.kolumna+=1;

		duszek.wiersz-=1;
		pac_polozenie_nastepne=pac_pac.tablica[duszek.wiersz]+duszek.kolumna;
		if(pac_polozenie_nastepne->wartosc!=1 && pac_polozenie_nastepne->wartosc!=8 ) mozliwosci[2]=true;
		duszek.wiersz+=1;

		duszek.kolumna+=1;
		pac_polozenie_nastepne=pac_pac.tablica[duszek.wiersz]+duszek.kolumna;
		if(pac_polozenie_nastepne->wartosc!=1 && pac_polozenie_nastepne->wartosc!=8) mozliwosci[3]=true;
		duszek.kolumna -=1;


		if(duszek.naprowadzanie_pierwszorzedne!=10 &&mozliwosci[duszek.naprowadzanie_pierwszorzedne])
		{
			duszek.kierunek=duszek.naprowadzanie_pierwszorzedne;
			return duszek;

		}
		else if(duszek.naprowadzanie_drugorzedne!=10 && mozliwosci[duszek.naprowadzanie_drugorzedne])
		{
			duszek.kierunek=duszek.naprowadzanie_drugorzedne;
			return duszek;

		}


		if(mozliwosci[duszek.kierunek])   //Ani kroku w ty� !!!
		{
			if(duszek.kierunek>=2) mozliwosci[duszek.kierunek-2]=false;
			else mozliwosci[duszek.kierunek+2]=false;
			// (duszek.kierunek<2)
		};


		int kierunek[4];
		bool zostalem_zablokowany=true;
		for(int i=0 ; i<=3 ;i++)
		{
			if(mozliwosci[i])
			{
			kierunek[i]=i;
			zostalem_zablokowany=false;
			}
			else kierunek[i]=10; // bo tak


		}

		if(zostalem_zablokowany)
		{
			duszek.kierunek= 5;
			return duszek;
		}
		do{

		losowanie=rand() % 4;


		}while(kierunek[losowanie]==10);

	duszek.kierunek= losowanie;

	return duszek;
}


 pozycja_ducha duch(plansza * pac_pac, pozycja_ducha duszek )
 {



 	int random, temp2;
	char ster ;
	element *pac_polozenie=pac_pac->tablica[duszek.wiersz]+duszek.kolumna;
	element *pac_polozenie_nastepne;

	if(pac_polozenie->wartosc!=8) przegrana(pac_pac);
	element *temp_ducha;

//	random = rand() % 4;
	random= duszek.kierunek;


	char kierunek[5]={'s','w','n','e','h'};
//	ster=kierunek[random-1];

	pac_polozenie_nastepne=pac_polozenie;

	ster=kierunek[random];

 			switch(ster)
		{
			case 's':
				duszek.wiersz +=1;
				pac_polozenie_nastepne=pac_pac->tablica[duszek.wiersz]+duszek.kolumna;

					temp2=pac_polozenie_nastepne->wartosc;
					pac_polozenie_nastepne->wartosc = pac_polozenie->wartosc;
					pac_polozenie->wartosc=duszek.temp;
					duszek.temp=temp2;
					if(temp2<=7 &&temp2>=4) przegrana(pac_pac);//przegrana
					duszek.kierunek=random;
					return duszek;

				break;

			case 'w':

				pac_polozenie_nastepne = pac_polozenie-1;


					temp2=pac_polozenie_nastepne->wartosc;
					duszek.kolumna = duszek.kolumna -1;
					pac_polozenie_nastepne->wartosc =pac_polozenie->wartosc;
					pac_polozenie->wartosc=duszek.temp;
					duszek.temp=temp2;
					if(temp2<=7 &&temp2>=4) przegrana(pac_pac);//przegrana
					duszek.kierunek=random;
					return duszek;


				break;

			case 'n':
				duszek.wiersz = duszek.wiersz-1;
				pac_polozenie_nastepne=pac_pac->tablica[duszek.wiersz]+duszek.kolumna;



					temp2=pac_polozenie_nastepne->wartosc;
					pac_polozenie_nastepne->wartosc = pac_polozenie->wartosc;
					pac_polozenie->wartosc=duszek.temp;
					duszek.temp=temp2;
					if(temp2<=7 &&temp2>=4) przegrana(pac_pac);//przegrana
					duszek.kierunek=random;
					return duszek;

				break;

			case 'e':
				pac_polozenie_nastepne = pac_polozenie+1;

					temp2=pac_polozenie_nastepne->wartosc;
					duszek.kolumna = duszek.kolumna +1;
					pac_polozenie_nastepne->wartosc = pac_polozenie->wartosc;
					pac_polozenie->wartosc=duszek.temp;
					duszek.temp=temp2;
					if(temp2<=7 &&temp2>=4) przegrana(pac_pac);//przegrana
					duszek.kierunek=random;
					return duszek;

			case 'h':
				return duszek;
				break;


		}






 	return duszek;
 }






void menu()
{

	system("CLS");
PlaySound("pacman_ringtone.wav", NULL , SND_ASYNC);

int c=0;
string wiersz[5];
wiersz[0]="<-";
while(true)
{
HANDLE hOut;
hOut = GetStdHandle( STD_OUTPUT_HANDLE );

SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
cout<<"\t########     ###     ######  ##     ##    ###    ##    ## "<<endl;
cout<<"\t##     ##   ## ##   ##    ## ###   ###   ## ##   ###   ## "<<endl;
cout<<"\t##     ##  ##   ##  ##       #### ####  ##   ##  ####  ## "<<endl;
cout<<"\t########  ##     ## ##       ## ### ## ##     ## ## ## ## "<<endl;
cout<<"\t##        ######### ##       ##     ## ######### ##  #### "<<endl;
cout<<"\t##        ##     ## ##    ## ##     ## ##     ## ##   ### "<<endl;
cout<<"\t##        ##     ##  ######  ##     ## ##     ## ##    ## "<<endl<<endl;
SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
cout<<" \t \t \t Menu glowne:"<<endl;
cout<<""<<endl;
cout<<" \t \t \t  Zagraj    "<<wiersz[0]<<endl;
cout<<" \t \t \t  Jak grac? "<<wiersz[1]<<endl;
cout<<" \t \t \t  Tworcy    "<<wiersz[2]<<endl;
cout<<" \t \t \t  Ustawienia"<<wiersz[3]<<endl;
cout<<" \t \t \t  Wyjdz     "<<wiersz[4]<<endl;

char a;
a=getch();
switch(a){


case 72:


	if(c>0)
	{

	wiersz[c]="";
	c=c-1;
	}
	break;

case 80:


	if(c<4)
	{

	wiersz[c]="";
	c=c+1;
	}
	break;

case 13:
if(c==0)
{
system("CLS") ;
wybor();
}
if(c==1)
{
system("CLS") ;
instrukcja();
}
if(c==2)
{

system("CLS") ;
autorzy();
}
if(c==3) ustawienia();

if(c==4) exit(0);
break;
}




wiersz[c]="<-";
system("CLS");
};


}


void autorzy()
{
    string tekst = "Autorzy: \nMichal Sliwa\nRobert Spiewak  \nNacisnij esc aby wrocic do menu"; //wprowadŸ dowolny tekst
    for (int i = 0; i < tekst.length(); i++)  //pêtla wykonuje sie od 0 do d³ugosci tekstu wprowadzonego w zmiennej tekst
    {
        cout << tekst[i]; //wyœwietlanie na ekranie po kolei ka¿dej litery
        Sleep(50); //tym regulujesz szybkoœæ pisania, wartoœæ w ms
    }
        cout << endl; //znak koñca linii




	char x;
	while (true)
	{
		x=getch();
		if(x==27){ //powrót na ESC
		menu();
	;
		}
	}

}

void instrukcja()
{

	string tekst = "PACMAN \n Warunkiem zwyciestwa jest zjedzenie wszystkich kropek."
					"\n Gdy zostaniesz zlapany przez ducha stracisz zycie."
					"\n Przegrasz gdy stracisz wszystkie trzy zycia."
					"\n Sterowanie na strzalkach."
					"\n \n Aby wrocic do menu nacisnij klawisz esc";
	for (int i = 0; i < tekst.length(); i++)  //pêtla wykonuje sie od 0 do d³ugosci tekstu wprowadzonego w zmiennej tekst
    {
        cout << tekst[i]; //wyœwietlanie na ekranie po kolei ka¿dej litery
        Sleep(25); //tym regulujesz szybkoœæ pisania, wartoœæ w ms
    }
        cout << endl; //znak koñca linii

		char x;
		while (true)
	{
		x=getch();
		if(x==27) // powrót na ESC
		menu();
	;
	}

}


void ustawienia()
{
	system("CLS");


	int c=1;
	char a;
	string wiersz[4];
	wiersz[1]="<-";
do
{
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<" \t \t \t";
	cout<<" Predkosc gry"<<endl;
	cout<<""<<endl;
	cout<<" \t \t \t  Wolna    "<<wiersz[0]<<endl;
	cout<<" \t \t \t  Normalna "<<wiersz[1]<<endl;
	cout<<" \t \t \t  Szybka   "<<wiersz[2]<<endl;


	char a;
	a=getch();
	switch(a){

	case 72:

		if(c>0)
		{

		wiersz[c]="";
		c=c-1;
		}
		break;

	case 80:

		if(c<2)
		{

		wiersz[c]="";
		c=c+1;
		}
		break;
		case 13:
			if(c==0)
			{
				czas=147;
				menu();
			}
			if(c==1)
			{
				czas=97;
				menu();
			}
			if(c==2)
			{
				czas=47;
				menu();
			}
	break;
	}

		wiersz[c]="<-";
		system("CLS");

}while(true);
menu();

}

void wybor()
{
	system("CLS");


	int c=1;
	char a;
	string wiersz[4];
	wiersz[1]="<-";
do
{
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<" \t \t \t";
	cout<<" Poziom trudnosci"<<endl;
	cout<<""<<endl;
	cout<<" \t \t \t  Brak    "<<wiersz[0]<<endl;
	cout<<" \t \t \t  Normalny "<<wiersz[1]<<endl;
	cout<<" \t \t \t  Trudny   "<<wiersz[2]<<endl;


	char a;
	a=getch();
	switch(a){

	case 72:

		if(c>0)
		{

		wiersz[c]="";
		c=c-1;
		}
		break;

	case 80:

		if(c<2)
		{

		wiersz[c]="";
		c=c+1;
		}
		break;
		case 13:
			if(c==0)	gra_easy();
			if(c==1)	gra_normal();
			if(c==2)	gra_hard();
	break;
	}


		wiersz[c]="<-";
		system("CLS");

}while(true);
menu();

}





int main()
{

	menu();




//gra();

	return 0;

}





