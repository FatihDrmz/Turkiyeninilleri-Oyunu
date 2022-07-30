#include <iostream>
#include <conio.h>
#include <string>
#include <locale.h>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Turkish");
    srand(time(0));

    int maxUzunluk = 0;
    int minUzunluk = 0;

    bool kontrol = false;

    string enUzunMetin = "";
    string enKisaMetin = "";
    string bulunanIl = "";

    const int MAX = 81;

    string randomIl[MAX];
    string iller[MAX] = { "ADANA","ADIYAMAN","AFYONKARAHÝSAR","AÐRI","AMASYA","ANKARA","ANTALYA","ARTVÝN","AYDIN","BALIKESÝR","BÝLECÝK","BÝNGÖL","BÝTLÝS","BOLU","BURDUR","BURSA","ÇANAKKALE","ÇANKIRI","ÇORUM","DENÝZLÝ","DÝYARBAKIR","EDÝRNE","ELAZIÐ","ERZÝNCAN","ERZURUM","ESKÝÞEHÝR","GAZÝANTEP","GÝRESUN","GÜMÜÞHANE",
        "HAKKARÝ","HATAY","ISPARTA","MERSÝN","ÝSTANBUL","ÝZMÝR","KARS","KASTAMONU","KAYSERÝ","KIRKLARELÝ","KIRÞEHÝR","KOCAELÝ","KONYA","KÜTAHYA","MALATYA","MANÝSA","KAHRAMANMARAÞ","MARDÝN","MUÐLA","MUÞ","NEVÞEHÝR","NÝÐDE","ORDU","RÝZE","SAKARYA","SAMSUN","SÝÝRT","SÝNOP","SÝVAS","TEKÝRDAÐ","TOKAT","TRABZON","TUNCELÝ",
        "ÞANLIURFA","UÞAK","VAN","YOZGAT","ZONGULDAK","AKSARAY","BAYBURT","KARAMAN","KIRIKKALE","BATMAN","ÞIRNAK","BARTIN","ARDAHAN","IÐDIR","YALOVA","KARABÜK","KÝLÝS","OSMANÝYE","DÜZCE" };

    //Ýller arasýnda en uzun karakter sayýsýna sahip olaný ve uzunluðunu bulduk.
    for (int i = 0; i < MAX; i++)
    {
        if (iller[i].length() > maxUzunluk)
        {
            maxUzunluk = iller[i].length();
            enUzunMetin = iller[i];
        }
    }

    minUzunluk = maxUzunluk;

    //Ýller arasýnda en kýsa karakter sayýsýna sahip olaný ve uzunluðunu bulduk.
    for (int i = 0; i < MAX; i++)
    {
        if (iller[i].length() < minUzunluk)
        {
            minUzunluk = iller[i].length();
            enKisaMetin = iller[i];
        }
    }

    cout << "********** En Uzun ve En Kisa Il **********" << endl << endl;
    cout << "En uzun karakter sayili il : " << enUzunMetin << endl;
    cout << "Karakter sayisi : " << maxUzunluk << endl;
    cout << "En kýsa karakter sayili il : " << enKisaMetin << endl;
    cout << "Karakter sayisi : " << minUzunluk << endl << endl;


    cout << "*** Rastgele Illerden Yeni il Olusturma ***" << endl << endl;

    //En kýsa ilin harf sayýsýndan baþlayýp en uzun ilin harf sayýsýna kadar döngüye girer.
    for (int i = minUzunluk; i <= maxUzunluk; i++)
    {
        if (kontrol == false && i != minUzunluk)
        {
            cout << "Harfli il bulunamadý." << endl << endl;
        }

        cout << i << ", ";

        //Random gelen illerin indislerinden oluþacak ili 100000 denemeye varýncaya kadar arar.
        for (int j = 0; j < 100000; j++)
        {
            kontrol = false;

            for (int random = 0; random < i; random++)
            {
                randomIl[random] = iller[rand() % MAX];
            }

            int minGenislik = randomIl[0].length();

            for (int k = 0; k < i; k++)
            {
                if (minGenislik > randomIl[k].length())
                {
                    minGenislik = randomIl[k].length();
                }
            }

            for (int k = 0; k < minGenislik; k++)
            {
                bulunanIl = "";

                for (int t = 0; t < i; t++)
                {
                    bulunanIl += randomIl[t].at(k);
                }

                for (int x = 0; x < MAX; x++)
                {
                    if (iller[x] == bulunanIl)
                    {
                        cout << "Harfli bulunan il: " << bulunanIl << endl;

                        cout << "Rastegele secilen " << i << " ilin " << k + 1 << ". harflerinden olusturuldu :" << endl;
                        for (int y = 0; y < i; y++)
                        {
                            cout << randomIl[y] << endl;
                        }
                        cout << endl;
                        kontrol = true;
                    }
                }
            }
            if (kontrol == true)
            {
                break;
            }
        }

        if (kontrol == false && i == maxUzunluk)
        {
            cout << "Harfli il bulunamadý." << endl;
        }
    }

    return 0;
}