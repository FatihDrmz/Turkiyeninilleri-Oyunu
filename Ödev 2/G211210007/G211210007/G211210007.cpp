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
    string iller[MAX] = { "ADANA","ADIYAMAN","AFYONKARAH�SAR","A�RI","AMASYA","ANKARA","ANTALYA","ARTV�N","AYDIN","BALIKES�R","B�LEC�K","B�NG�L","B�TL�S","BOLU","BURDUR","BURSA","�ANAKKALE","�ANKIRI","�ORUM","DEN�ZL�","D�YARBAKIR","ED�RNE","ELAZI�","ERZ�NCAN","ERZURUM","ESK��EH�R","GAZ�ANTEP","G�RESUN","G�M��HANE",
        "HAKKAR�","HATAY","ISPARTA","MERS�N","�STANBUL","�ZM�R","KARS","KASTAMONU","KAYSER�","KIRKLAREL�","KIR�EH�R","KOCAEL�","KONYA","K�TAHYA","MALATYA","MAN�SA","KAHRAMANMARA�","MARD�N","MU�LA","MU�","NEV�EH�R","N��DE","ORDU","R�ZE","SAKARYA","SAMSUN","S��RT","S�NOP","S�VAS","TEK�RDA�","TOKAT","TRABZON","TUNCEL�",
        "�ANLIURFA","U�AK","VAN","YOZGAT","ZONGULDAK","AKSARAY","BAYBURT","KARAMAN","KIRIKKALE","BATMAN","�IRNAK","BARTIN","ARDAHAN","I�DIR","YALOVA","KARAB�K","K�L�S","OSMAN�YE","D�ZCE" };

    //�ller aras�nda en uzun karakter say�s�na sahip olan� ve uzunlu�unu bulduk.
    for (int i = 0; i < MAX; i++)
    {
        if (iller[i].length() > maxUzunluk)
        {
            maxUzunluk = iller[i].length();
            enUzunMetin = iller[i];
        }
    }

    minUzunluk = maxUzunluk;

    //�ller aras�nda en k�sa karakter say�s�na sahip olan� ve uzunlu�unu bulduk.
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
    cout << "En k�sa karakter sayili il : " << enKisaMetin << endl;
    cout << "Karakter sayisi : " << minUzunluk << endl << endl;


    cout << "*** Rastgele Illerden Yeni il Olusturma ***" << endl << endl;

    //En k�sa ilin harf say�s�ndan ba�lay�p en uzun ilin harf say�s�na kadar d�ng�ye girer.
    for (int i = minUzunluk; i <= maxUzunluk; i++)
    {
        if (kontrol == false && i != minUzunluk)
        {
            cout << "Harfli il bulunamad�." << endl << endl;
        }

        cout << i << ", ";

        //Random gelen illerin indislerinden olu�acak ili 100000 denemeye var�ncaya kadar arar.
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
            cout << "Harfli il bulunamad�." << endl;
        }
    }

    return 0;
}