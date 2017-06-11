


#include "gra.h"
#include "MMSystem.h"

void gra_easy()
{
	system ("CLS");
plansza pac_pac;

pac_pac.wypelnij_easy();

pac_pac.wypisz_plansze();

PlaySound(0, NULL ,0);
PlaySound(TEXT("pacman_beginning.wav"), NULL , SND_SYNC);

/*
		string tekst="3...2...1...0";
		for (int i = 0; i < tekst.length(); i++)
	    {
	        cout << tekst[i];
	        Sleep(100);
	    }

*/


	int ster_liczba=0;
	char ster ='w';
	int wiersz=5;
	int kolumna =7;
	int tracking;




	element *pac_polozenie;
	element *pac_polozenie_nastepne;
//	pac_polozenie=pac_pac.tablica[5]+9;
	pac_polozenie=pac_pac.tablica[wiersz]+kolumna;
	pac_polozenie_nastepne = pac_polozenie;





	do
	{
		if(pac_polozenie_nastepne->wartosc!=1) pac_polozenie = pac_polozenie_nastepne;




		while(kbhit())
		{

		ster_liczba= getch();

		switch(ster_liczba)
		{

		case 72:
			ster='n';
			pac_polozenie->wartosc=7;

			break;

		case 80:
			ster='s';
			pac_polozenie->wartosc=6;
			break;

		case 75:
			ster='w';
			pac_polozenie->wartosc=5;
			break;

		case 77:
			ster='e';
			pac_polozenie->wartosc=4;
			break;

		}
			Sleep(3);
		}


		switch(ster)
		{
			case 's':
				wiersz = wiersz+1;
				pac_polozenie_nastepne=pac_pac.tablica[wiersz]+kolumna;

				if(pac_polozenie_nastepne->wartosc!=1)
				{
				    if(pac_polozenie_nastepne->wartosc==2) PlaySound(TEXT("pacman_chomp.wav"), NULL ,SND_ASYNC| SND_NOSTOP);
				    else PlaySound(0, NULL ,0);
					pac_polozenie_nastepne->wartosc = pac_polozenie->wartosc;
					pac_polozenie->wartosc=3;
				}
				else
                {
                wiersz =wiersz -1;
				PlaySound(0, NULL ,0);
                }
				break;

			case 'w':

				pac_polozenie_nastepne = pac_polozenie-1;

				if(pac_polozenie_nastepne->wartosc!=1)
				{
				    if(pac_polozenie_nastepne->wartosc==2) PlaySound(TEXT("pacman_chomp.wav"), NULL ,SND_ASYNC| SND_NOSTOP);
				    else PlaySound(0, NULL ,0);
					kolumna = kolumna -1;
					pac_polozenie_nastepne->wartosc =pac_polozenie->wartosc;
					pac_polozenie->wartosc=3;
				}
				else PlaySound(0, NULL ,0);
				break;



			case 'n':
				wiersz = wiersz-1;
				pac_polozenie_nastepne=pac_pac.tablica[wiersz]+kolumna;

				if(pac_polozenie_nastepne->wartosc!=1)
				{
				    if(pac_polozenie_nastepne->wartosc==2) PlaySound(TEXT("pacman_chomp.wav"), NULL ,SND_ASYNC| SND_NOSTOP);
				    else PlaySound(0, NULL ,0);
					pac_polozenie_nastepne->wartosc = pac_polozenie->wartosc;
					pac_polozenie->wartosc=3;
				}
				else
                {
                wiersz +=1;
                PlaySound(0, NULL ,0);
                }
				break;



			case 'e':
				pac_polozenie_nastepne = pac_polozenie+1;

				if(pac_polozenie_nastepne->wartosc!=1)
				{
				    if(pac_polozenie_nastepne->wartosc==2) PlaySound(TEXT("pacman_chomp.wav"), NULL ,SND_ASYNC| SND_NOSTOP);
				    else PlaySound(0, NULL ,0);
					kolumna = kolumna +1;
					pac_polozenie_nastepne->wartosc = pac_polozenie->wartosc;
					pac_polozenie->wartosc=3;
				}
				else PlaySound(0, NULL ,0);
				break;
		}




		system ("CLS");
		pac_pac.wypisz_plansze();
		Sleep(czas);

		zwyciestwo(pac_pac);


		//system("CLS");
	}while(ster_liczba!=27);
    pac_pac.wyczysc_tablice();
	menu();





}

void gra_normal()
{
	system ("CLS");
plansza pac_pac;

pac_pac.wypelnij_normal();

pac_pac.wypisz_plansze();
plansza * wsk_pac_pac =&pac_pac;

PlaySound(0, NULL ,0);
PlaySound(TEXT("pacman_beginning.wav"), NULL , SND_SYNC);

/*
		string tekst="3...2...1...0";
		for (int i = 0; i < tekst.length(); i++)
	    {
	        cout << tekst[i];
	        Sleep(100);
	    }


*/

	int ster_liczba=0;
	char ster ='w';
	int wiersz=5;
	int kolumna =9;
	int tracking;




	element *pac_polozenie;
	element *pac_polozenie_nastepne;
//	pac_polozenie=pac_pac.tablica[5]+9;
	pac_polozenie=pac_pac.tablica[wiersz]+kolumna;
	pac_polozenie_nastepne = pac_polozenie;



	//Duch
	element *duch_polozenie;
	element *duch_polozenie_nastepne;
	//	pac_polozenie=pac_pac.tablica[5]+9;
		pozycja_ducha duszek;

	duszek.kolumna=9;
	duszek.wiersz=9;
	duch_polozenie=pac_pac.tablica[duszek.wiersz]+duszek.kolumna;
	duch_polozenie_nastepne = duch_polozenie;


	do
	{
		if(pac_polozenie_nastepne->wartosc!=1) pac_polozenie = pac_polozenie_nastepne;


		duch_polozenie=pac_pac.tablica[duszek.wiersz]+duszek.kolumna;
		tracking=abs(duszek.wiersz -wiersz) +abs(duszek.kolumna - kolumna);

		while(kbhit())
		{

		ster_liczba= getch();

		switch(ster_liczba)
		{

		case 72:
			ster='n';
			pac_polozenie->wartosc=7;

			break;

		case 80:
			ster='s';
			pac_polozenie->wartosc=6;
			break;

		case 75:
			ster='w';
			pac_polozenie->wartosc=5;
			break;

		case 77:
			ster='e';
			pac_polozenie->wartosc=4;
			break;

		}
			Sleep(3);
		}


		switch(ster)
		{
			case 's':
				wiersz = wiersz+1;
				pac_polozenie_nastepne=pac_pac.tablica[wiersz]+kolumna;

				if(pac_polozenie_nastepne->wartosc!=1)
				{
				    if(pac_polozenie_nastepne->wartosc==2) PlaySound(TEXT("pacman_chomp.wav"), NULL ,SND_ASYNC| SND_NOSTOP);
				    else PlaySound(0, NULL ,0);
					pac_polozenie_nastepne->wartosc = pac_polozenie->wartosc;
					if(pac_polozenie_nastepne->wartosc==8) przegrana(wsk_pac_pac);//przegrana
					pac_polozenie->wartosc=3;
				}
				else
                {
                    wiersz =wiersz -1;
                    PlaySound(0, NULL ,0);
                }
				break;

			case 'w':

				pac_polozenie_nastepne = pac_polozenie-1;

				if(pac_polozenie_nastepne->wartosc!=1)
				{
				    if(pac_polozenie_nastepne->wartosc==2) PlaySound(TEXT("pacman_chomp.wav"), NULL ,SND_ASYNC| SND_NOSTOP);
				    else PlaySound(0, NULL ,0);
					kolumna = kolumna -1;
					pac_polozenie_nastepne->wartosc =pac_polozenie->wartosc;
					if(pac_polozenie_nastepne->wartosc==8) przegrana(wsk_pac_pac);//przegrana
					pac_polozenie->wartosc=3;
				}
				else PlaySound(0, NULL ,0);
				break;



			case 'n':
				wiersz = wiersz-1;
				pac_polozenie_nastepne=pac_pac.tablica[wiersz]+kolumna;

				if(pac_polozenie_nastepne->wartosc!=1)
				{
				    if(pac_polozenie_nastepne->wartosc==2) PlaySound(TEXT("pacman_chomp.wav"), NULL ,SND_ASYNC| SND_NOSTOP);
				    else PlaySound(0, NULL ,0);
					pac_polozenie_nastepne->wartosc = pac_polozenie->wartosc;
					if(pac_polozenie_nastepne->wartosc==8) przegrana(wsk_pac_pac);//przegrana
					pac_polozenie->wartosc=3;
				}
				else
                {
                    wiersz +=1;
                    PlaySound(0, NULL ,0);
                }
				break;



			case 'e':
				pac_polozenie_nastepne = pac_polozenie+1;

				if(pac_polozenie_nastepne->wartosc!=1)
				{
				    if(pac_polozenie_nastepne->wartosc==2) PlaySound(TEXT("pacman_chomp.wav"), NULL ,SND_ASYNC| SND_NOSTOP);
				    else PlaySound(0, NULL ,0);
					kolumna = kolumna +1;
					pac_polozenie_nastepne->wartosc = pac_polozenie->wartosc;
					if(pac_polozenie_nastepne->wartosc==8) przegrana(wsk_pac_pac);//przegrana
					pac_polozenie->wartosc=3;
				}
				else PlaySound(0, NULL ,0);
				break;
		}



	if(tracking<=3) duszek=znajdz_i_wyeliminuj(pac_pac, duszek , kolumna , wiersz);
	else
	{
		duszek.naprowadzanie_pierwszorzedne=10;
		duszek.naprowadzanie_drugorzedne=10;
	}



	duszek=wyznacz_kierunek( duszek , pac_pac);
	duszek=	duch(wsk_pac_pac  , duszek);

			if(pac_pac.smierc)
	{
		if(duszek.temp>=4 && duszek.temp<=7) duszek.temp=3;
		(pac_pac.tablica[duszek.wiersz]+duszek.kolumna)->wartosc=duszek.temp;
		pac_polozenie->wartosc=3;
	}
	//	if(duch_polozenie->wartosc!=8) przegrana(pac_pac);
		system ("CLS");


	if(pac_pac.smierc)
		{

	pac_pac.smierc=false;
	ster_liczba=0;
	ster ='w';
	wiersz=5;
	kolumna =9;

//	pac_polozenie=pac_pac.tablica[5]+9;
	pac_polozenie=pac_pac.tablica[wiersz]+kolumna;
	pac_polozenie_nastepne = pac_polozenie;
	pac_polozenie->wartosc=5;
	duszek.kolumna=9;
	duszek.wiersz=9;
	duch_polozenie=pac_pac.tablica[duszek.wiersz]+duszek.kolumna;
	duch_polozenie_nastepne = duch_polozenie;
	duch_polozenie->wartosc=8;
	duszek.temp=3;


		}





		pac_pac.wypisz_plansze();

	for(int i=0 ; i<pac_pac.zycia;i++)
	{
	HANDLE hOut;
	hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
	cout<<"<";
	SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
	}


		Sleep(czas);

			if (duszek.temp!=2)zwyciestwo(pac_pac);


		//system("CLS");
	}while(ster_liczba!=27);

	pac_pac.wyczysc_tablice();
	menu();





}






void gra_hard()
{
	system ("CLS");
plansza pac_pac;

pac_pac.wypelnij_hard();

pac_pac.wypisz_plansze();

plansza *wsk_pac_pac;
wsk_pac_pac= &pac_pac;

PlaySound(0, NULL ,0);
PlaySound(TEXT("pacman_beginning.wav"), NULL , SND_SYNC);
/*
		string tekst="3...2...1...0";
		for (int i = 0; i < tekst.length(); i++)
	    {
	        cout << tekst[i];
	        Sleep(100);
	    }

*/


	int ster_liczba=0;
	char ster ='w';
	int wiersz=9;
	int kolumna =9;
	int tracking , tracking2;




	element *pac_polozenie;
	element *pac_polozenie_nastepne;
//	pac_polozenie=pac_pac.tablica[5]+9;
	pac_polozenie=pac_pac.tablica[wiersz]+kolumna;
	pac_polozenie_nastepne = pac_polozenie;



	//Duch
	element *duch_polozenie;
	element *duch_polozenie_nastepne;
	//	pac_polozenie=pac_pac.tablica[5]+9;
		pozycja_ducha duszek;

	duszek.kolumna=8;
	duszek.wiersz=5;
	duch_polozenie=pac_pac.tablica[duszek.wiersz]+duszek.kolumna;
	duch_polozenie_nastepne = duch_polozenie;



	//Duch2
	element *duch_polozenie2;
	element *duch_polozenie_nastepne2;
	//	pac_polozenie=pac_pac.tablica[5]+9;
		pozycja_ducha duszek2;

	duszek2.kolumna=11;
	duszek2.wiersz=5;
	duch_polozenie2=pac_pac.tablica[duszek2.wiersz]+duszek2.kolumna;
	duch_polozenie_nastepne2 = duch_polozenie2;

	do
	{
		if(pac_polozenie_nastepne->wartosc!=1) pac_polozenie = pac_polozenie_nastepne;


		duch_polozenie=pac_pac.tablica[duszek.wiersz]+duszek.kolumna;
		duch_polozenie2=pac_pac.tablica[duszek2.wiersz]+duszek2.kolumna;

		tracking=abs(duszek.wiersz -wiersz) +abs(duszek.kolumna - kolumna);
		tracking2=abs(duszek2.wiersz -wiersz) +abs(duszek2.kolumna - kolumna);
		while(kbhit())
		{

		ster_liczba= getch();

		switch(ster_liczba)
		{

		case 72:
			ster='n';
			pac_polozenie->wartosc=7;

			break;

		case 80:
			ster='s';
			pac_polozenie->wartosc=6;
			break;

		case 75:
			ster='w';
			pac_polozenie->wartosc=5;
			break;

		case 77:
			ster='e';
			pac_polozenie->wartosc=4;
			break;

		}
			Sleep(3);
		}


		switch(ster)
		{
			case 's':
				wiersz = wiersz+1;
				pac_polozenie_nastepne=pac_pac.tablica[wiersz]+kolumna;

				if(pac_polozenie_nastepne->wartosc!=1)
				{
                    if(pac_polozenie_nastepne->wartosc==2) PlaySound(TEXT("pacman_chomp.wav"), NULL ,SND_ASYNC| SND_NOSTOP);
                    else PlaySound(0, NULL ,0);
					pac_polozenie_nastepne->wartosc = pac_polozenie->wartosc;
					if(pac_polozenie_nastepne->wartosc==8) przegrana(wsk_pac_pac);//przegrana
					pac_polozenie->wartosc=3;
				}
				else
                {
                    wiersz =wiersz -1;
                    PlaySound(0, NULL ,0);
                }
				break;

			case 'w':

				pac_polozenie_nastepne = pac_polozenie-1;

				if(pac_polozenie_nastepne->wartosc!=1)
				{
					if(pac_polozenie_nastepne->wartosc==2) PlaySound(TEXT("pacman_chomp.wav"), NULL ,SND_ASYNC| SND_NOSTOP);
					else PlaySound(0, NULL ,0);
					kolumna = kolumna -1;
					pac_polozenie_nastepne->wartosc =pac_polozenie->wartosc;
					if(pac_polozenie_nastepne->wartosc==8) przegrana(wsk_pac_pac);//przegrana
					pac_polozenie->wartosc=3;
				}
				else PlaySound(0, NULL ,0);
				break;



			case 'n':
				wiersz = wiersz-1;
				pac_polozenie_nastepne=pac_pac.tablica[wiersz]+kolumna;

				if(pac_polozenie_nastepne->wartosc!=1)
				{
				    if(pac_polozenie_nastepne->wartosc==2) PlaySound(TEXT("pacman_chomp.wav"), NULL ,SND_ASYNC| SND_NOSTOP);
				    else PlaySound(0, NULL ,0);
					pac_polozenie_nastepne->wartosc = pac_polozenie->wartosc;
					if(pac_polozenie_nastepne->wartosc==8) przegrana(wsk_pac_pac);//przegrana
					pac_polozenie->wartosc=3;
				}
				else
                {
                    wiersz +=1;
                    PlaySound(0, NULL ,0);
                }
				break;



			case 'e':
				pac_polozenie_nastepne = pac_polozenie+1;
				if(pac_polozenie_nastepne->wartosc!=1)
				{
				    if(pac_polozenie_nastepne->wartosc==2) PlaySound(TEXT("pacman_chomp.wav"), NULL ,SND_ASYNC| SND_NOSTOP);
				    else PlaySound(0, NULL ,0);
					kolumna = kolumna +1;
					pac_polozenie_nastepne->wartosc = pac_polozenie->wartosc;
					if(pac_polozenie_nastepne->wartosc==8) przegrana(wsk_pac_pac);//przegrana
					pac_polozenie->wartosc=3;
				}
				else PlaySound(0, NULL ,0);
				break;
		}



	if(tracking<=3) duszek=znajdz_i_wyeliminuj(pac_pac, duszek , kolumna , wiersz);
	else
	{
		duszek.naprowadzanie_pierwszorzedne=10;
		duszek.naprowadzanie_drugorzedne=10;
	}

	if(tracking2<=3) duszek2=znajdz_i_wyeliminuj(pac_pac, duszek2 , kolumna , wiersz);
	else
	{
		duszek2.naprowadzanie_pierwszorzedne=10;
		duszek2.naprowadzanie_drugorzedne=10;
	}

 	if(!pac_pac.smierc)
	{
	duszek=wyznacz_kierunek( duszek , pac_pac);
	duszek=	duch(wsk_pac_pac, duszek);
	}

	if(!pac_pac.smierc)
	{
	duszek2=wyznacz_kierunek( duszek2 ,pac_pac);
	duszek2=duch(wsk_pac_pac, duszek2);
	}

		if(pac_pac.smierc)
	{


		if(duszek.temp>=4 && duszek.temp<=7) duszek.temp=3;
		if(duszek2.temp>=4 && duszek2.temp<=7) duszek2.temp=3;
		//duch_polozenie_nastepne->wartosc=duszek.temp;
		(pac_pac.tablica[duszek.wiersz]+duszek.kolumna)->wartosc=duszek.temp;
		(pac_pac.tablica[duszek2.wiersz]+duszek2.kolumna)->wartosc=duszek2.temp;
		//duch_polozenie_nastepne2->wartosc=duszek2.temp;
		pac_polozenie->wartosc=3;
		if(pac_polozenie_nastepne->wartosc<=8 && pac_polozenie_nastepne->wartosc>=4) pac_polozenie_nastepne->wartosc=3;
		//if(pac_polozenie->wartosc==8) pac_polozenie_nastepne->wartosc=3;

	}






	//	if(duch_polozenie->wartosc!=8) przegrana(pac_pac);
		system ("CLS");
		pac_pac.wypisz_plansze();


		if(pac_pac.smierc)
		{

	pac_pac.smierc=false;
	ster_liczba=0;
	ster ='w';
	wiersz=9;
	kolumna =9;

//	pac_polozenie=pac_pac.tablica[5]+9;
	pac_polozenie=pac_pac.tablica[wiersz]+kolumna;
	pac_polozenie_nastepne = pac_polozenie;
	pac_polozenie->wartosc=5;
	duszek.kolumna=8;
	duszek.wiersz=5;
	duch_polozenie=pac_pac.tablica[duszek.wiersz]+duszek.kolumna;
	duch_polozenie_nastepne = duch_polozenie;
	duch_polozenie->wartosc=8;
	duszek.temp=3;
	//duch2
	duszek2.kolumna=11;
	duszek2.wiersz=5;
	duch_polozenie2=pac_pac.tablica[duszek2.wiersz]+duszek2.kolumna;
	duch_polozenie_nastepne2 = duch_polozenie2;
	duch_polozenie2->wartosc=8;
	duszek2.temp=3;


		}




	for(int i=0 ; i<pac_pac.zycia;i++)
	{
	HANDLE hOut;
	hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
	cout<<"<";
	SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
	}


		Sleep(czas);

		if (duszek.temp!=2 && duszek2.temp!=2)zwyciestwo(pac_pac);


		//system("CLS");



		}while(ster_liczba!=27);

	pac_pac.wyczysc_tablice();
	menu();





}
