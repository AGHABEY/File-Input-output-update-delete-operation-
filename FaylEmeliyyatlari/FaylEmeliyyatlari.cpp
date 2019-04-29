// FaylEmeliyyatlari.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>// fayl emeliyyatlarin gormek ucun istifade etdiyimiz kitabxana
#include<iomanip>
#include <string>

using namespace std;// giris cixislar ucun istifade olunan funk

class Melumatlar
{
public:
	string _ad;
	string _soyad;
	string _telefonNomresi;


	void melumatDaxilEt();
	void melumatlariGoster();
};

void Melumatlar::melumatDaxilEt()
{
	cout.setf(ios::right);
	cout<<setw(20) << "Adi Daxil Edin: ";
	cin >> _ad;
	cout<<setw(20) << "Soyadi Daxil Edin: ";
	cin >> _soyad;
	cout << setw(20) << "Nomreni Daxil Edin: ";
	cin >> _telefonNomresi;

}

void Melumatlar::melumatlariGoster()
{
	cout.setf(ios::right);
	cout << setw(20) << "Ad: " << _ad << endl;
	cout << setw(20) << "Soyad: " << _soyad<< endl;
	cout << setw(20) << "Telefon Nomresi: " << _telefonNomresi<< endl;
}

class TelefonKitabcasi
{
public:
	Melumatlar melumat[100];
	int indexler;
	fstream fayl;
	fstream fayl2;
	fstream fayl3;

	TelefonKitabcasi()// 1 dene konstruktor qururuq  ve icetisine index-i 0 olaraq elave edirik.
	{
		indexler = 0;
		fayl.open("TelefonKitabcasi.txt", ios::out | ios::in | ios::app);
		fayl.setf(ios::left);//solda yerlessin.
	}

	void ElaveEt()
	{
		melumat[indexler].melumatDaxilEt();
		Melumatlar m = melumat[indexler];
		fayl << setw(20) << m._ad << setw(20) << m._soyad << setw(20) << m._telefonNomresi << endl;
	}
	void axtar(string nomre)
	{
		Melumatlar melumat;
		while (!fayl.eof())
		{
			fayl >> melumat._ad;
			fayl >> melumat._soyad;
			fayl >> melumat._telefonNomresi;
			if (melumat._telefonNomresi==nomre)
			{
				melumat.melumatlariGoster();
			}
		}
	}
	

	void yenile(string nomre)
	{
		Melumatlar melumat;
		fayl2.open("Temp.txt",ios::in|ios::out|ios::app);
		while (!fayl.eof())
		{
			fayl >> melumat._ad;
			fayl >> melumat._soyad;
			fayl >> melumat._telefonNomresi;
			if (melumat._telefonNomresi==nomre)
			{
				melumat.melumatlariGoster();
			}
			if (melumat._telefonNomresi != nomre)
			{
				cout.setf(ios::right);
				fayl2 << setw(20) << melumat._ad << setw(20) << melumat._soyad << setw(20) << melumat._telefonNomresi << endl;
			}
		}
			fayl.close();
			fayl2.close();
			remove("TelefonKitabcasi.txt");
		    rename("Temp.txt", "TelefonKitabcasi.txt");
			melumat.melumatDaxilEt();

			//fayl3.open("TelefonKitabcasi.txt", ios::app | ios::out);
			//fayl3 << setw(20) << melumat._ad << setw(20) << melumat._soyad << setw(20) << melumat._telefonNomresi << endl;
		
	}

	void sil(string nomre)
	{
		Melumatlar melumat;
		fayl2.open("Temp.txt", ios::in | ios::out | ios::app);
		while (!fayl.eof())
		{
			fayl >> melumat._ad;
			fayl >> melumat._soyad;
			fayl >> melumat._telefonNomresi;
			if (melumat._telefonNomresi == nomre)
			{
				melumat.melumatlariGoster();
			}
			if (melumat._telefonNomresi != nomre)
			{
				cout.setf(ios::right);
				fayl2 << setw(20) << melumat._ad << setw(20) << melumat._soyad << setw(20) << melumat._telefonNomresi << endl;
			}
		}
		fayl.close();
		fayl2.close();
		remove("TelefonKitabcasi.txt");
		rename("Temp.txt", "TelefonKitabcasi.txt");
	}
};




int main()
{
	TelefonKitabcasi T;
	Melumatlar M;
	int secim;
	string nomre;
	cout << "Menyu" << endl;
	
	cout << " 1.  Istifadecileri Elave edin: " << endl;
	cout << " 2.  Istifadecileri axtar: " << endl;
	cout << " 3.  Istifadecileri yenile: " << endl;
	cout << " 4.  Istifadecileri sil: " << endl;
	cout << " -------------------------------- " << endl;
	cout << " Seciminizi Daxil edin " << endl;
	cin >> secim;
	

		
	switch (secim)
	{
	case 1:
		T.ElaveEt();
		break;
	case 2:
		cout << "Axtarmaq istediyiniz istifadecinin nomresini daxil edin: "<<endl;
		cin >> nomre;
		T.axtar(nomre);
		break;
	case 3:
		cout << "Yenilemek istediyiniz istifadecinin nomresini daxil edin: " << endl;
		cin >> nomre;
		T.yenile(nomre);
		break;
	case 4:
		cout << "Silmek istediyiniz istifadecinin nomresini daxil edin: " << endl;
		cin >> nomre;
		T.sil(nomre);
		break;

	default:
		
		break;
	}
	
}

