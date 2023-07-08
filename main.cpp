#EXERCITIUL 1





#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Machiaj{
private:
    string tip;
    int nr_bucati;
    string marca;
    int pret;

public:
    Machiaj();
    Machiaj(string tip,int nr_bucati,string marca,int pret);
    friend ostream& operator<< (ostream &a,Machiaj &b);
    virtual ostream& afisare(ostream &a);

};
Machiaj::Machiaj()
{
    this->tip="";
    this->marca="";
    this->pret=0;
    this->nr_bucati=0;
}
Machiaj::Machiaj(string tip,int nr_bucati,string marca,int pret)
{
    this->tip=tip;
    this->nr_bucati=nr_bucati;
    this->marca=marca;
    this->pret=pret;

}
ostream& Machiaj::afisare(ostream &a)
{

    a<<"  "<<tip<<"\t\t"<<nr_bucati<<" bucati"<<"\t\t"<<marca<<"\t\t"<<pret<<" lei"<<endl;
}
ostream& operator<<(ostream &a,Machiaj &b)
{
    b.afisare(a);
}
int main()
{

    Machiaj m1(" Set rujuri mate",15,"      CHANEL",120);
    Machiaj m2("  Creion de ochi",30,"     L’OREAL",30);
    Machiaj m3("      Iluminator", 9,"     CLARINS",50);
    Machiaj m4("         Mascara",50,"ESTEE LAUDER",60);
    Machiaj m5("           Gloss",18,"  MAYBELLINE",8);
    Machiaj m6("Creion-sprancene",17,"      CHANEL",13);
    Machiaj m7("   Gel-sprancene",29,"         MAC",32);
    Machiaj m8("          Primer",37,"     L’OREAL",12);
    Machiaj m9("           Blush",29,"ESTEE LAUDER",50);
    Machiaj m10(" Creion de buze",60,"     LANCOME",20);


    vector <Machiaj*> m;


    m.push_back(new Machiaj (m1));
    m.push_back(new Machiaj (m2));
    m.push_back(new Machiaj (m3));
    m.push_back(new Machiaj (m4));
    m.push_back(new Machiaj (m5));
    m.push_back(new Machiaj (m6));
    m.push_back(new Machiaj (m7));
    m.push_back(new Machiaj (m8));
    m.push_back(new Machiaj (m9));
    m.push_back(new Machiaj (m10));

 cout<<"                                 ========Magazin Online========"<<endl;

    cout<<"   Nume produs"<<"\t\t"<<"    Numar bucati"<<"\t\t"<<"      Marca"<<"\t\t"<<"Pretul"<<endl;
    for(Machiaj* ob:m)
        cout<<*ob<<endl;
    cout<<endl;
    return 0;
}
