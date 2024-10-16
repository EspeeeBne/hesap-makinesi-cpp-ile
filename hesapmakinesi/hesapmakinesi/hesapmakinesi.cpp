#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <sstream>
#include <locale>

using namespace std;

void toplama();
void cikarma();
void carpma();
void bolme();
void us_alma();
void karekok();
void ortalama();
void faktoriyel();
void gecmis_islemleri_goster(const vector<string>&);

vector<string> islemGecmisi;

string double_to_string(double value) {
    ostringstream strs;
    strs << value;
    return strs.str();
}

string int_to_string(int value) {
    ostringstream strs;
    strs << value;
    return strs.str();
}

int main() {
    setlocale(LC_ALL, "Turkish");
    bool devam = true;
    string secim;

    while (devam) {
        cout << "\nHesap Makinesi\n";
        cout << "1. Toplama\n";
        cout << "2. Çıkarma\n";
        cout << "3. Çarpma\n";
        cout << "4. Bölme\n";
        cout << "5. Üs Alma\n";
        cout << "6. Karekök Alma\n";
        cout << "7. Ortalama Hesaplama\n";
        cout << "8. Faktoriyel Hesaplama\n";
        cout << "9. Geçmiş İşlemleri Görüntüle\n";
        cout << "Çıkmak için 'q' ya basın\n";
        cout << "Seçiminizi yapın: ";
        getline(cin, secim);

        if (secim.empty()) {
            cout << "Hata: Boş giriş yaptınız, lütfen geçerli bir işlem seçin.\n";
            continue;
        }

        if (secim == "q" || secim == "Q") {
            devam = false;
        }
        else {
            switch (secim[0]) {
            case '1': toplama(); break;
            case '2': cikarma(); break;
            case '3': carpma(); break;
            case '4': bolme(); break;
            case '5': us_alma(); break;
            case '6': karekok(); break;
            case '7': ortalama(); break;
            case '8': faktoriyel(); break;
            case '9': gecmis_islemleri_goster(islemGecmisi); break;
            default:
                cout << "Geçersiz seçim, lütfen tekrar deneyin.\n";
                break;
            }
        }
    }

    cout << "Programdan çıkılıyor. Görüşürüz!\n";
    return 0;
}

void toplama() {
    double sayi1, sayi2;
    cout << "Birinci sayıyı girin: ";
    cin >> sayi1;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "İkinci sayıyı girin: ";
    cin >> sayi2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    double sonuc = sayi1 + sayi2;
    cout << "Sonuç: " << sonuc << "\n";
    islemGecmisi.push_back(double_to_string(sayi1) + " + " + double_to_string(sayi2) + " = " + double_to_string(sonuc));
}

void cikarma() {
    double sayi1, sayi2;
    cout << "Birinci sayıyı girin: ";
    cin >> sayi1;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "İkinci sayıyı girin: ";
    cin >> sayi2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    double sonuc = sayi1 - sayi2;
    cout << "Sonuç: " << sonuc << "\n";
    islemGecmisi.push_back(double_to_string(sayi1) + " - " + double_to_string(sayi2) + " = " + double_to_string(sonuc));
}

void carpma() {
    double sayi1, sayi2;
    cout << "Birinci sayıyı girin: ";
    cin >> sayi1;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "İkinci sayıyı girin: ";
    cin >> sayi2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    double sonuc = sayi1 * sayi2;
    cout << "Sonuç: " << sonuc << "\n";
    islemGecmisi.push_back(double_to_string(sayi1) + " * " + double_to_string(sayi2) + " = " + double_to_string(sonuc));
}

void bolme() {
    double sayi1, sayi2;
    cout << "Birinci sayıyı girin: ";
    cin >> sayi1;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "İkinci sayıyı girin: ";
    cin >> sayi2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (sayi2 != 0) {
        double sonuc = sayi1 / sayi2;
        cout << "Sonuç: " << sonuc << "\n";
        islemGecmisi.push_back(double_to_string(sayi1) + " / " + double_to_string(sayi2) + " = " + double_to_string(sonuc));
    }
    else {
        cout << "Hata: Bir sayı sıfıra bölünemez!\n";
    }
}

void us_alma() {
    double taban, us;
    cout << "Taban sayıyı girin: ";
    cin >> taban;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Üssü girin: ";
    cin >> us;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    double sonuc = pow(taban, us);
    cout << "Sonuç: " << sonuc << "\n";
    islemGecmisi.push_back(double_to_string(taban) + " ^ " + double_to_string(us) + " = " + double_to_string(sonuc));
}

void karekok() {
    double sayi;
    cout << "Sayıyı girin: ";
    cin >> sayi;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (sayi >= 0) {
        double sonuc = sqrt(sayi);
        cout << "Sonuç: " << sonuc << "\n";
        islemGecmisi.push_back("√" + double_to_string(sayi) + " = " + double_to_string(sonuc));
    }
    else {
        cout << "Hata: Negatif bir sayının karekökü alınamaz!\n";
    }
}

void ortalama() {
    int adet;
    cout << "Kaç sayı gireceksiniz?: ";
    cin >> adet;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (adet <= 0) {
        cout << "Hata: Geçerli bir sayı girin!\n";
        return;
    }
    double toplam = 0, sayi;
    for (int i = 0; i < adet; ++i) {
        cout << i + 1 << ". sayıyı girin: ";
        cin >> sayi;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        toplam += sayi;
    }
    double sonuc = toplam / adet;
    cout << "Ortalama: " << sonuc << "\n";
    islemGecmisi.push_back("Ortalama = " + double_to_string(sonuc));
}

void faktoriyel() {
    int sayi;
    cout << "Faktoriyelini almak istediğiniz sayıyı girin: ";
    cin >> sayi;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (sayi < 0) {
        cout << "Hata: Negatif bir sayının faktoriyeli hesaplanamaz!\n";
        return;
    }
    unsigned long long sonuc = 1;
    for (int i = 1; i <= sayi; ++i) {
        sonuc *= i;
    }
    cout << sayi << "! = " << sonuc << "\n";
    islemGecmisi.push_back(int_to_string(sayi) + "! = " + int_to_string(sonuc));
}

void gecmis_islemleri_goster(const vector<string>& gecmis) {
    if (gecmis.empty()) {
        cout << "Geçmiş işlemler bulunmuyor.\n";
    }
    else {
        cout << "Geçmiş İşlemler:\n";
        for (const string& islem : gecmis) {
            cout << islem << "\n";
        }
    }
}