#include <iostream> //cout cin vb. icin
#include<fstream>   //dosya kutuphanesi
#include<string>    //string kutuphanesi
#include<ctime>     //zaman kutuphanesi
#include<windows.h> //ekran renklendirmesi
#include <stdlib.h> // atoi ve system(); için
#include <sstream>  //ostringstream icin
#include<conio.h>   //getch(); icin Not:linux de hata verebilir..

using namespace std;
int year,moon,day;
class Akademisyen {
  public:
    int sicilno;
    string ad;
    string soyad;
    string anabilimdali;
    string eposta;
    string tel;
    string unvan;
};
class Ogrenci {
  public:
    int no;
    string ad;
    string soyad;
    string bolum;
    int yil;
    string eposta;
    string tel;
};
class Randevu{
  public:
    Ogrenci ogr;
    Akademisyen akd;
    string tarih;
    string baslangicsaati;
    string bitissaati;
};
class RandevuSistemi:public Randevu{
  public:
    void menu();
  private:
    int ogr_sorgulama(int numara);
    int akd_sorgulama(int sicil);
    void ogr_ekle();
    void akd_ekle();
    void rnd_ekle();
    void ogr_print();
    void akd_print();
    void rnd_print();
    void ogr_sil();
    void akd_sil();
    void rnd_sil();
};
void RandevuSistemi::menu(){
    system("cls");
        int sec;
        menu:
      cout<<endl<<endl;
      cout<<"       *--*--*--*--*--*--*--*--*--*--*--*--*--*--*"<<endl;
      cout<<"       |                                         |"<<endl;
      cout<<"       *  Yapmak istediginiz islemi seciniz:     *"<<endl;
      cout<<"       |  [1]. Ogrenci Ekle                      |"<<endl;
      cout<<"       *  [2]. Akademisyen Ekle                  *"<<endl;
      cout<<"       |  [3]. Randevu Ekle                      |"<<endl;
      cout<<"       *  [4]. Ogrenci Randevu Listele           *"<<endl;
      cout<<"       |  [5]. Akademisyen Randevu Listele       |"<<endl;
      cout<<"       *  [6]. Randevu listele                   *"<<endl;
      cout<<"       |  [7]. Ogrenci sil                       |"<<endl;
      cout<<"       *  [8]. Akademisyen sil                   *"<<endl;
      cout<<"       |  [9]. Randevu sil                       |"<<endl;
      cout<<"       *  [0].Cikis                              *"<<endl;
      cout<<"       |                                         |"<<endl;
      cout<<"       *--*--*--*--*--*--*--*--*--*--*--*--*--*--*"<<endl;
      cin>>sec;
      switch(sec){
  case 0:
      exit(1);
     break;
  case 1:
      ogr_ekle();
    break;
  case 2:
      akd_ekle();
    break;
  case 3:
      rnd_ekle();
    break;
  case 4:
      ogr_print();
    break;
  case 5:
      akd_print();
    break;
  case 6:
      rnd_print();
    break;
  case 7:
      ogr_sil();
    break;
  case 8:
      akd_sil();
    break;
  case 9:
      rnd_sil();
    break;
  default:
      system("cls");
      cout<<endl<<"       Hatali bir tuslama yaptiniz!."<<endl;
      cout<<"       Lutfen yeniden deneyiniz.."<<endl;
    goto menu;
    }
}
int RandevuSistemi::ogr_sorgulama(int numara){
    ifstream oku;
    Ogrenci ogr1;
    int k=0;
    oku.open("ogrenci.txt",ios::in);
    while(!oku.eof()){
       oku>>ogr1.no>>ogr1.ad>>ogr1.soyad>>ogr1.bolum>>ogr1.yil>>ogr1.eposta>>ogr1.tel;
        if(ogr1.no==numara){
            k=1;
        }
    }
    oku.close();
    if(k==0){
        return 0;
    }
return 1;
}
int RandevuSistemi::akd_sorgulama(int sicil){
    ifstream oku;
   Akademisyen akd1;
    int j=0;
    oku.open("akademisyen.txt",ios::in);
   while(!oku.eof()){
    oku>>akd1.sicilno>>akd1.ad>>akd1.soyad>>akd1.anabilimdali>>akd1.eposta>>akd1.tel>>akd1.unvan;
    if(sicil==akd1.sicilno){
        j=1;
    }
   }
   oku.close();
   if(j==0){
    return 0;
}
return 1;
}
void RandevuSistemi::ogr_ekle(){
    system("cls");
    int k=0;
    ofstream dosya;
    cout<<"Eklemek istediginiz ogrencinin;"<<endl;
    cout<<"Okul numarasi: "; cin>>ogr.no;
    if(ogr.no<0){
        cout<<"Hata! 0'dan kucuk bir sayi girdiniz.."<<endl;
        exit(1);
    }
    k=ogr_sorgulama(ogr.no);
    if(k==1){
        cout<<endl<<"Hata! Ogrencinin kaydi sistemde mevcut.."<<endl;
    }else{
    cout<<endl<<"Adi: "; cin>>ogr.ad;
    cout<<endl<<"Soyadi: "; cin>>ogr.soyad;
    cout<<endl<<"Bolumu: "; cin>>ogr.bolum;
    cout<<endl<<"Kayit yili: "; cin>>ogr.yil;
    cout<<endl<<"Mail adresi: "; cin>>ogr.eposta;
    cout<<endl<<"Telefon numarasi: "; cin>>ogr.tel;

    dosya.open("ogrenci.txt",ios::app);
    dosya<<ogr.no<<" "<<ogr.ad<<" "<<ogr.soyad<<" "<<ogr.bolum<<" "<<ogr.yil<<" "<<ogr.eposta<<" "<<ogr.tel<<endl;
    dosya.close();
    system("cls");
    cout<<endl<<"       Ogrenci kaydiniz yapilmistir.."<<endl;
        }
    cout<<endl<<"Menuye donmek icin herhangi bir tusa basiniz."<<endl;
    getch();
    menu();
}
void RandevuSistemi::akd_ekle(){
    system("cls");
    int k=0;
    ofstream dosya;
    cout<<"Eklemek istediginiz akademisyenin;"<<endl;
    cout<<"Sicil numarasi: "; cin>>akd.sicilno;
    if(akd.sicilno<0){
        cout<<"Hata! 0'dan kucuk bir sayi girdiniz.."<<endl;
        exit(1);
    }
    k=akd_sorgulama(akd.sicilno);
    if(k==1){
        cout<<endl<<"Hata! Akademisyenin kaydi sistemde mevcut.."<<endl;
        }else{
        cout<<endl<<"Adi: "; cin>>akd.ad;
        cout<<endl<<"Soyadi: "; cin>>akd.soyad;
        cout<<endl<<"Anabilim dali: "; cin>>akd.anabilimdali;
        cout<<endl<<"Mail adresi: "; cin>>akd.eposta;
        cout<<endl<<"Telefon numarasi: "; cin>>akd.tel;
        cout<<endl<<"Unvani: "; cin>>akd.unvan;
        dosya.open("akademisyen.txt",ios::app);
        dosya<<akd.sicilno<<" "<<akd.ad<<" "<<akd.soyad<<" "<<akd.anabilimdali<<" "<<akd.eposta<<" "<<akd.tel<<" "<<akd.unvan<<endl;
        dosya.close();
        system("cls");
        cout<<endl<<"       Akademisyen kaydiniz yapilmistir.."<<endl;
    }
    cout<<endl<<"Menuye donmek icin herhangi bir tusa basiniz."<<endl;
    getch(); menu();
}
void RandevuSistemi::rnd_ekle(){
   system("cls");
   Randevu rnd;
   int k=0,i=0,j=0;
   ofstream dosya;
   ifstream oku;
   git: cout<<endl<<"Ogrenci numaranizi giriniz: "; cin>>ogr.no;
    i=ogr_sorgulama(ogr.no);
   if(i==0){
    cout<<endl<<"Girilen ogrenci numarasi sistemde kayitli degil..."<<endl;
    cout<<"Tekrar deneyiniz.."<<endl;
    goto git;
   }
   go: cout<<endl<<"Randevu almak istediginiz akademisyenin sicil numarasini giriniz: "; cin>>akd.sicilno;
   j=akd_sorgulama(akd.sicilno);
   if(j==0){
    cout<<endl<<"Girilen akademisyen sicil numarasi sistemde kayitli degil..."<<endl;
    cout<<"Tekrar deneyiniz.."<<endl;
    goto go;
   }
   x: cout<<endl<<"Randevu almak istediginiz tarihi giriniz (gg.aa.yyyy): "; cin>>tarih;
   int gun=atoi(tarih.substr(0,2).c_str());
   int ay=atoi(tarih.substr(3,2).c_str());
   int yil=atoi(tarih.substr(6,4).c_str());

   if(ay==2){
    int artikyil=0;
    artikyil=yil%4;
        if(artikyil==0){
            if(gun<0 || gun>29){
                cout<<endl<<"Hatali bir tarih girdiniz..";
                exit(1);
            }
        }else{
            if(gun<0 || gun>28){
                cout<<endl<<"Hatali bir tarih girdiniz..";
                exit(1);
            }
        }

   }
   else if(ay==1 || ay==3 || ay==5 || ay==7 || ay==8 || ay==10 || ay==12){
        if(gun<0 || gun>31){
             cout<<endl<<"Hatali bir tarih girdiniz..";
             exit(1);
        }
   }
   else if(ay==4 || ay==6 || ay==9 || ay==11){
        if(gun<0 || gun>30){
             cout<<endl<<"Hatali bir tarih girdiniz..";
             exit(1);

        }
   }
   if((yil==year && ay==moon && gun> day) || (yil==year && ay>moon) || (yil>year)){
   y: cout<<endl<<"Randevu almak istediginiz saati giriniz (ss:dd): "; cin>>baslangicsaati;
   int saat = atoi(baslangicsaati.substr(0,2).c_str());
   int dakika= atoi(baslangicsaati.substr(3,2).c_str());
   if(saat<0 || saat>=25){
    cout<<"Hatali tuslama yaptiniz. Lutfen tekrar deneyiniz..."<<endl;
    goto y;
   }
   if(8>saat||saat==12||saat>=17){
    cout<<"Girdiginiz saat mesai saatleri disindadir. Lutfen farkli bir saat dilimi giriniz.."<<endl;
    goto y;
   }
    if(dakika+30>=60){
        saat=saat+1;
        dakika=dakika-30;
    }else{
    dakika=dakika+30;
    }
    dosya.open("randevu.txt",ios::app);
    oku.open("randevu.txt",ios::in);
    while(!oku.eof()){
        oku>>rnd.ogr.no>>rnd.akd.sicilno>>rnd.tarih>>rnd.baslangicsaati>>rnd.bitissaati;
        if( akd.sicilno==rnd.akd.sicilno && tarih==rnd.tarih && baslangicsaati==rnd.baslangicsaati && ogr.no!=rnd.ogr.no){
            k=1;
        }
        if(ogr.no==rnd.ogr.no && tarih==rnd.tarih && baslangicsaati==rnd.baslangicsaati && akd.sicilno!=rnd.akd.sicilno){
                k=2;
       }
       if(ogr.no==rnd.ogr.no && tarih==rnd.tarih && baslangicsaati==rnd.baslangicsaati && akd.sicilno==rnd.akd.sicilno){
        k=3;
       }
    }
    oku.close();
    if(k==1){
        cout<<endl<<"Hata! Randevu olusturulamadi.."<<endl;
        cout<<"Girilen saatte akademisyenin baska bir randevusu mevcut..."<<endl;
    }
    else if(k==2){
        cout<<endl<<"Hata! Randevu olusturulamadi.."<<endl;
        cout<<"Girilen saatte ogrencinin baska bir randevusu mevcut..."<<endl;
        }
    else if(k==3){
        cout<<endl<<"Hata! Randevu olusturulamadi.."<<endl;
        cout<<"Girilen saatte boyle bir randevu zaten mevcut..."<<endl;
    }
    else if(k==0){
        dosya<<endl<<ogr.no<<" "<<akd.sicilno<<" "<<tarih<<" "<<baslangicsaati<<" "<<saat<<":"<<dakika;
        dosya.close();
        system("cls");
        cout<<endl<<"       Randevu kaydiniz yapilmistir.."<<endl;
        }
   }else{
   cout<<endl<<"Yanlis veya gecmis zamana ait bir tuslama yaptiniz."<<endl;
   cout<<"Lutfen tekrar deneyiniz..."<<endl;
   goto x;
   }

    cout<<endl<<"Menuye donmek icin herhangi bir tusa basiniz."<<endl;
    getch();
    menu();
}
void RandevuSistemi::ogr_print(){
     system("cls");
    ifstream oku;
    int numara, i=0,j=0;
   git: cout<<"Randevu bilgilerini sorgulamak istediginiz ogrencinin ogrenci numarasini giriniz: "; cin>>numara;
   if(numara<0){
        cout<<"Hata! 0'dan kucuk bir sayi girdiniz.."<<endl;
        exit(1);
    }
   j=ogr_sorgulama(numara);
   if(j==0){
    cout<<endl<<"Girilen ogrenci numarasi sistemde kayitli degil..."<<endl;
    cout<<"Lutfen tekrar deneyiniz.."<<endl<<endl;
    goto git;
    }
    cout<<endl<<numara<<" nolu ogrencinin:"<<endl;
    oku.open("randevu.txt",ios::app);
    while(!oku.eof()){
        oku>>ogr.no>>akd.sicilno>>tarih>>baslangicsaati>>bitissaati;
        if(ogr.no==numara){
                i=1;
            cout<<endl<<akd.sicilno<<" sicil nolu akademisyen ile "<<tarih;
            cout<<" tarihinde "<<baslangicsaati<<" da randevunuz bulunmaktadir. "<<endl;
        }
    }
    oku.close();
    if(i==0){
        cout<<"Kayitli randevusu bulunmamaktadir."<<endl;
    }
    cout<<"Menuye donmek icin herhangi bir tusa basiniz."<<endl;
    getch();
    menu();
}
void RandevuSistemi::akd_print(){
    system("cls");
    int sicil, i=0,j=0;
    ifstream oku;
    git: cout<<"Randevu bilgilerini sorgulamak istediginiz akademisyenin sicil numarasini giriniz: "; cin>>sicil;
    j=akd_sorgulama(sicil);
   if(j==0){
    cout<<endl<<"Girilen akademisyen sicil numarasi sistemde kayitli degil..."<<endl;
    cout<<"Lutfen tekrar deneyiniz.."<<endl<<endl;
    goto git;
   }
    cout<<endl<<sicil<<" sicil nolu akademisyenin:"<<endl;
    oku.open("randevu.txt",ios::app);
    while(!oku.eof()){
        oku>>ogr.no>>akd.sicilno>>tarih>>baslangicsaati>>bitissaati;

        if(akd.sicilno==sicil){
                i=1;
            cout<<endl<<ogr.no<<" nolu ogrenci ile "<<tarih;
            cout<<" tarihinde "<<baslangicsaati<<" da randevunuz bulunmaktadir. "<<endl;
        }
    }
    oku.close();
    if(i==0){
        cout<<"Kayitli randevusu bulunmamaktadir."<<endl;
    }
    cout<<endl<<"Menuye donmek icin herhangi bir tusa basiniz."<<endl;
    getch();
    menu();
}
void RandevuSistemi::rnd_print(){
     system("cls");
    ifstream oku;
    int k=0;
    oku.open("randevu.txt",ios::in);
    while(!oku.eof()){
        oku>>ogr.no>>akd.sicilno>>tarih>>baslangicsaati>>bitissaati;
    if(tarih.empty()){
        break;
    }else{
        cout<<endl<<ogr.no<<" nolu ogrencinin "<<akd.sicilno<<" sicil nolu akademisyen ile "<<tarih;
        cout<<" tarihinde "<<baslangicsaati<<" da randevusu bulunmaktadir."<<endl;
        k=1;
         }
    }
    oku.close();
    if(k==0){
        cout<<endl<<"Kayitli randevu bulunmamaktadir.."<<endl;
    }
    cout<<endl<<"Menuye donmek icin herhangi bir tusa basiniz."<<endl;
    getch();
    menu();
}
void RandevuSistemi::ogr_sil(){
    system("cls");
    ofstream dosya;
    ifstream oku;
    Randevu rnd;
    int numara,j=0;
    git: cout<<endl<<"Kaydini silmek istediginiz ogrencinin numarasini giriniz: "; cin>>numara;
    if(numara<0){
        cout<<"Hata! 0'dan kucuk bir sayi girdiniz.."<<endl;
        exit(1);
    }
    j=ogr_sorgulama(numara);
    if(j==0){
    cout<<endl<<"Girilen ogrenci numarasi sistemde kayitli degil..."<<endl;
    cout<<"Lutfen tekrar deneyiniz.."<<endl;
    goto git;
    }
    oku.open("ogrenci.txt",ios::in); dosya.open("ogr.txt",ios::app);
    while(!oku.eof()){
    oku>>ogr.no>>ogr.ad>>ogr.soyad>>ogr.bolum>>ogr.yil>>ogr.eposta>>ogr.tel;
    if(numara!=ogr.no){
        dosya<<ogr.no<<" "<<ogr.ad<<" "<<ogr.soyad<<" "<<ogr.bolum<<" "<<ogr.yil<<" "<<ogr.eposta<<" "<<ogr.tel<<endl;
        }
    }
    oku.close(); dosya.close();
    remove("ogrenci.txt");
    rename("ogr.txt","ogrenci.txt");
    cout<<endl<<numara<<" nolu ogrencinin kaydi basari ile silindi.."<<endl;
    cout<<"Menuye donmek icin herhangi bir tusa basiniz."<<endl;
    getch();
    menu();
}
void RandevuSistemi::akd_sil(){
      system("cls");
    ofstream dosya;
    ifstream oku;
    int sicil,j=0;
   git: cout<<endl<<"Kaydini silmek istediginiz akademisyenin sicil numarasini giriniz: "; cin>>sicil;
   j=akd_sorgulama(sicil);
   if(j==0){
    cout<<endl<<"Girilen akademisyen sicil numarasi sistemde kayitli degil..."<<endl;
    cout<<"Tekrar deneyiniz.."<<endl;
    goto git;
   }
    oku.open("akademisyen.txt",ios::in); dosya.open("akd.txt",ios::app);
    while(!oku.eof()){
    oku>>akd.sicilno>>akd.ad>>akd.soyad>>akd.anabilimdali>>akd.eposta>>akd.tel>>akd.unvan;
    if(sicil!=akd.sicilno){
        dosya<<akd.sicilno<<" "<<akd.ad<<" "<<akd.soyad<<" "<<akd.anabilimdali<<" "<<akd.eposta<<" "<<akd.tel<<" "<<akd.unvan<<endl;
        }
    }
    oku.close(); dosya.close();
    remove("akademisyen.txt");
    rename("akd.txt","akademisyen.txt");
    cout<<endl<<sicil<<" sicil nolu akademisyenin kaydi basari ile silindi.."<<endl;
    cout<<"Menuye donmek icin herhangi bir tusa basiniz."<<endl;
    getch();
    menu();

}
void RandevuSistemi::rnd_sil(){
    system("cls");
    ifstream oku; ofstream dosya;
    int i=0,j=0,k=0;
    Randevu rnd;
    cout<<"Randevusunu sildirmek istediginiz :"<<endl;
    git: cout<<"Ogrencinin numarasi: "; cin>>ogr.no;
    i=ogr_sorgulama(ogr.no);
    if(i==0){
    cout<<endl<<"Girilen ogrenci numarasi sistemde kayitli degil..."<<endl;
    cout<<"Tekrar deneyiniz.."<<endl;
    goto git;
    }
    go: cout<<endl<<"Akademisyenin sicil numarasi: "; cin>>akd.sicilno;
    j=akd_sorgulama(akd.sicilno);
   if(j==0){
    cout<<endl<<"Girilen akademisyen sicil numarasi sistemde kayitli degil..."<<endl;
    cout<<"Tekrar deneyiniz.."<<endl;
    goto go;
   }
    cout<<endl<<"Randevu tarihi (gg.aa.yyyy): ";  cin>>tarih;
    cout<<endl<<"Randevu saati(ss:dd): ";         cin>>baslangicsaati;
    oku.open("randevu.txt",ios::in); dosya.open("rnd.txt",ios::out);
    while(!oku.eof()){
        oku>>rnd.ogr.no>>rnd.akd.sicilno>>rnd.tarih>>rnd.baslangicsaati>>rnd.bitissaati;
        if(rnd.ogr.no==ogr.no && rnd.akd.sicilno==akd.sicilno && rnd.tarih==tarih && rnd.baslangicsaati==baslangicsaati){
         k=1;
        }else{
              dosya<<rnd.ogr.no<<" "<<rnd.akd.sicilno<<" "<<rnd.tarih<<" "<<rnd.baslangicsaati<<" "<<rnd.bitissaati<<endl;
        }
    }
    oku.close(); dosya.close();

    if(k==0){
        remove("rnd.txt");
        cout<<endl<<"Hata! Randevu sistemde kayitli degil.."<<endl;
    }else{
        remove("randevu.txt");
        rename("rnd.txt","randevu.txt");
        cout<<endl<<"Randevu basari ile silindi..."<<endl;
    }

}

int main() {
    system("color F0");
   time_t tarih = time(NULL);
   cout << ctime(&tarih)<<endl;
   ostringstream s1;
   s1<<ctime(&tarih);
   string s2=s1.str();
   cout<<s2;
   string yil = s2.substr(20,4);
   string ay = s2.substr(4,3);
   string gun   = s2.substr(8,2);
   year = atoi(yil.substr(0,4).c_str());
   day  = atoi(gun.substr(0,2).c_str());

if(ay=="Jan"){
    moon=1;
}
else if(ay=="Feb"){
    moon=2;
}
else if(ay=="Mar"){
     moon=3;
}
else if(ay=="Apr"){
    moon=4;
}
else if(ay=="May"){
    moon=5;
}
else if(ay=="Jun"){
    moon=6;
}
else if(ay=="Jul"){
    moon=7;
}
else if(ay=="Aug"){
    moon =8;
}
else if(ay=="Sep"){
    moon=9;
}
else if(ay=="Oct"){
    moon=10;
}
else if(ay=="Nov"){
    moon=11;
}
else if(ay=="Dec"){
    moon=12;
}
  RandevuSistemi rs;
   rs.menu();
}
