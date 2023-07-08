#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class student
{
    protected:
        string nume, grupa;
        int nota_lab, nota_ex, nr_abs, nota_finala;
    public:
        student();
        student(string nume, string grupa, int nota_lab, int nota_ex, int nr_abs);
        ~student();
        friend ostream& operator<< (ostream& os, student &s);
        virtual ostream& afisare(ostream& os);
        friend bool operator< (const student& s1, const student& s2);
        bool cautare(vector<student*> v, string nume);

        string get_nume()
        {
            return nume;
        }

        int get_nr_abs()
        {
            return nr_abs;
        }

        int get_nota_finala()
        {
            return nota_finala;
        }

        string get_grupa()
        {
            return grupa;
        }

        int cautare_absente(vector<student*> v, int nr_absente);
        void afisare_studenti_interval(vector<student*> v, int x, int y);
        float medie_studenti(vector<student*> v);
};


float student::medie_studenti(vector<student*> v)
{
    int suma=0;
    for(int i=0;i<v.size();i++)suma=suma+v[i]->get_nota_finala();
    return (float)suma/v.size();
}


int student::cautare_absente(vector<student*> v, int nr_absente)
{
    int nr=0;
    for(student* st:v)
        if(st->get_nr_abs()<nr_absente)nr++;
    return nr;
}


bool student::cautare(vector<student*> v, string nume)
{
    bool gasit=false;
    for(student* st:v)
        if(st->get_nume()==nume)gasit=true;
    return gasit;
}


void student::afisare_studenti_interval(vector<student*> v, int x, int y)
{
   cout<<"Numele"<<"\t\t"<<"grupa"<<"\t"<<"nota laborator"<<"\t"<<"nota examen"<<"\t"<<"numar absente"<<"\t"<<"nota finala"<<endl;
    for(student* st:v)
        if(st->get_nota_finala()>=x && st->get_nota_finala()<=y)
            cout<<*st<<endl;
}


student::student()
{
    nume="";
    grupa="";
    nota_lab=0;
    nota_ex=0;
    nr_abs=0;
    nota_finala=0;
}

student::student(string nume, string grupa, int nota_lab, int nota_ex, int nr_abs)
{
    this->nume=nume;
    this->grupa=grupa;
    this->nota_lab=nota_lab;
    this->nota_ex=nota_ex;
    this->nr_abs=nr_abs;
    this->nota_finala=1+0.05*min(10,14-this->nr_abs)+0.55*this->nota_ex+0.3*this->nota_lab;
}

ostream& student::afisare(ostream& os)
{
    //os<<"Nume "<<nume<<" "<<"grupa = "<<grupa<<" "<<"nota laborator = "<<nota_lab<<" "<<"nota examen = "<<nota_ex<<" "<<" numar absente = "<<nr_abs<<" nota finala = "<<this->nota_finala;
     os<<nume<<"\t"<<grupa<<"\t"<<nota_lab<<"\t\t"<<nota_ex<<"\t\t"<<nr_abs<<"\t\t"<<nota_finala;
    return os;
}

ostream& operator<< (ostream& os, student &s)
{
    return s.afisare(os);
}

student::~student()
{
    cout<<"Apel destructor student "<<endl;
}

bool operator< (const student& s1, const student& s2)
{
    return s1.nume<s2.nume;
}


int main()
{
    int n;

    //definirea studentilor
    student s1("Ionescu Ion","gr2",9,9,1);
    student s2("Popescu Vasile","gr1",9,6,4);
    student s3("Avram Adela","gr2",9,7,5);
    student s4("Enache Rodica","gr4",8,6,6);
    student s5("Pop Tiberiu","gr3",8,8,8);
    student s6("Pana Elvira","gr3",7,7,10);
    student s7("Sandru Rodica","gr1",9,10,1);
    student s8("Fekete Adela","gr2",7,9,4);
    student s9("Adrian Enache","gr1",9,7,5);
    student s10("Grig Edith","gr4",9,9,6);

    //crearea vectorului de studenti si a grupului
    vector <student*> v;
    vector <student*> vector_grup;

    v.push_back(new student(s1));
    v.push_back(new student(s2));
    v.push_back(new student(s3));
    v.push_back(new student(s4));
    v.push_back(new student(s5));
    v.push_back(new student(s6));
    v.push_back(new student(s7));
    v.push_back(new student(s8));
    v.push_back(new student(s9));
    v.push_back(new student(s10));

    // os<<"Nume "<<nume<<" "<<"grupa = "<<grupa<<" "<<"nota laborator = "<<nota_lab<<" "<<"nota examen = "<<nota_ex<<" "<<" numar absente = "<<nr_abs<<" nota finala = "<<this->nota_finala;
    //afisarea studentilor inainte de sortare
    cout<<"Numele"<<"\t\t"<<"grupa"<<"\t"<<"nota laborator"<<"\t"<<"nota examen"<<"\t"<<"numar absente"<<"\t"<<"nota finala"<<endl;
    for(student* s:v)cout<<*s<<endl;
    cout<<endl;

    //cout<<"Sortarea studentilor "<<endl;
    //sort(v.begin(), v.end());

    //afisarea studentilor  dupa sortare
    //cout<<"Numele"<<"\t\t"<<"grupa"<<"\t"<<"nota laborator"<<"\t"<<"nota examen"<<"\t"<<"numar absente"<<"\t"<<"nota finala"<<endl;
   // for(student* s:v)cout<<*s<<endl;
   // cout<<endl;

    student ST; //definesc un student temporar folosit la apelul functiilor membru
    string nume_student="Avram Adela";
    if(ST.cautare(v,nume_student)==true)
        cout<<"Persoana "<<nume_student<<" exista !";
    else
        cout<<"Persoana "<<nume_student<<" nu exista !";
    cout<<endl;

   int nr_studenti_7=ST.cautare_absente(v,7);
   cout<<"Numarul de studenti cu mai putin de 7 absente = "<<nr_studenti_7<<endl;

    int x,y;
    cout<<"Dati prima nota din intervalul [x,y] = "; cin>>x;
    cout<<"Dati a doua nota din intervalul [x,y] = "; cin>>y;

    ST.afisare_studenti_interval(v,x,y);
    cout<<endl;
    cout<<"Studentii din Grupa 2 sunt : "<<endl;
    for(int i=0;i<v.size();++i)
        if(v[i]->get_grupa()=="gr2")
            vector_grup.push_back(v[i]); // formarea grupei

    cout<<"Numele"<<"\t\t"<<"grupa"<<"\t"<<"nota laborator"<<"\t"<<"nota examen"<<"\t"<<"numar absente"<<"\t"<<"nota finala"<<endl;
    for(student* s1:vector_grup) // afisarea grupei
        cout<<*s1<<endl;
    cout<<endl;
    cout<<"Media studentilor este "<<ST.medie_studenti(v)<<endl;
    cout<<endl;
    return 0;
}
