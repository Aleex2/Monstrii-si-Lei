//Matei Mihaela-ALexandra , 322AC
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int numarPersoane = 0;
int numarActori = 0;

class Cast
{
public:
    string nume;
    string ocupatie;
    ~Cast() {};

};

Cast persoane[1000];//vector de obiecte din clasa Cast

void preiaInfo() // se preiau informatiile din fisierul cu cast initial si se introduc in vectorul creat anterior de obiecte din clasa Cast
{
    vector<vector<string>> info;
    vector<string> rand;
    string linie, cuvant;

    ifstream fisierCast;
    fisierCast.open("wednesday.csv");


    if(fisierCast.is_open())
    {
        while(getline(fisierCast,linie))
        {
            rand.clear();

            stringstream str(linie);

            while(getline(str, cuvant, ','))
                rand.push_back(cuvant);
            info.push_back(rand);
        }
    }
    else
        cout<<"Fisierul nu a putut fi deschis\n";

    numarPersoane = info.size();

    int i;
    for( i = 0; i < numarPersoane; i++)
    {
        persoane[i].nume = info[i][0];
        persoane[i].ocupatie = info[i][1];
    }


};

void adaugaFiguratie() //adauga figuratia random la vectorul de obiecte din clasa Cast
{

    ifstream f;
    f.open("names_figurant.csv");//se deschide fisierul cu nume random pentru figuratie

    string linie;

    if(f.is_open())
    {
        while(getline(f,linie))
        {
            persoane[numarPersoane].nume = linie;
            persoane[numarPersoane].ocupatie = "extra";
            numarPersoane++;
        }
    }
    else
        cout<<"Fisierul nu a putut fi deschis\n";
}

void scriereFisierNou() // se creaza noul fisier cu castul extins si figuratie
{
    ofstream g;
    g.open("wednesday2.csv");

    int i;
    for(i = 0 ; i < numarPersoane ; i++)
    {
        g << persoane[i].nume << "," << persoane[i].ocupatie << endl;
    }

}

class Roluri : public Cast
{
public:
    string rol;
    float pretMakeUp;

    Roluri()
    {
        //atribuire random a rolurilor
        int random = rand()%5;
        switch(random)
        {
        case 0:
            rol = "vampir";
            pretMakeUp = 230;
            break;
        case 1:
            rol = "varcolac";
            pretMakeUp = 555;
            break;
        case 2:
            rol = "sirena";
            pretMakeUp = 345;
            break;
        case 3:
            rol = "clarvazator";
            pretMakeUp = 157;
            break;
        case 4:
            rol = "om";
            pretMakeUp = 55;
            break;
        }
    }


};

Roluri persRoluri[1000]; //vector de obiecte din clasa Roluri ce va contine actorii si figuratia, fiecare cu rolul sau atribuit random


void atribuireRoluriActori() //se copiaza din vectorul de cast extins doar actorii si figuratia(nume si ocupatie)
//( rolul si pretul machiajului fiind deja stabilite in mod aleator la crearea obiectului)
{

    int i;

    for(i = 0; i<numarPersoane; i++)
    {
        if( (persoane[i].ocupatie == "actor/actress") || (persoane[i].ocupatie == "extra") )
        {
            persRoluri[numarActori].nume = persoane[i].nume;
            persRoluri[numarActori].ocupatie = persoane[i].ocupatie;
            numarActori++;
        }
    }



};


class Diete : public Cast
{
public:
    string tipDieta;
    float pretMeniuDieta;

    Diete()
    {
        //atribuire random a tipului de dieta
        int random = rand()%3;
        switch(random)
        {
        case 0:
            tipDieta = "mananca orice";
            pretMeniuDieta = 40;
            break;
        case 1:
            tipDieta = "vegetarian";
            pretMeniuDieta = 33;
            break;
        case 2:
            tipDieta = "flexitarian";
            pretMeniuDieta = 46;
            break;
        }
    }


};

Diete persDiete[1000]; //vector de obiecte din clasa Diete ce va contine cast-ul extins , fiecare cu un tip de dieta atribuit in mod aleator

void atribuireDiete()//se copiaza din vectorul de cast extins informatiile despre fiecare persoana (nume si ocupatie)
//(tipul si pretul meniului fiind deja stabilite in mod aleator la crearea obiectului din clasa Diete)
{

    int i;
    for(i = 0; i < numarPersoane; i++)
    {
        persDiete[i].nume = persoane[i].nume;
        persDiete[i].ocupatie = persoane[i].ocupatie;

    }

};

class Meniu //clasa abstracta(interfata) pentru meniu
{
public:
    string supaCiorba;
    string felPrincipal;
    string desert;

    string soup;
    string mainCourse;
    string dessert;

    virtual void alegereSupaCiorba() = 0;
    virtual void alegereFelPrincipal() = 0;
    virtual void alegereDesert() = 0;
    ~Meniu() {};
};

//in continuare se vor stabili in mod aleator cele 3 componente ale meniului pentru fiecare dintre cele 3 categorii de diete


class ManancaOrice : public Meniu
{

public:
    void alegereSupaCiorba()
    {
        int random = rand()%4;
        switch(random)
        {
        case 0:
            supaCiorba = "supa de pui";
            soup = "chicken soup";
            break;
        case 1:
            supaCiorba = "ciorba de vacuta";
            soup = "beef soup";
            break;
        case 2:
            supaCiorba = "ciorba de legume";
            soup = "vegetable soup";
            break;
        case 3:
            supaCiorba = "supa crema de ciuperci";
            soup = "creamy mushroom soup";
            break;
        }
    }


    virtual void alegereFelPrincipal()
    {
        int random = rand()%3;
        switch(random)
        {
        case 0:
            felPrincipal = "muschi de vita cu legume la gratar";
            mainCourse = "grilled beef fillet with vegetables";
            break;
        case 1:
            felPrincipal = "piept de pui la gratar cu broccoli sote";
            mainCourse = "grilled chicken breast with broccoli sote";
            break;
        case 2:
            felPrincipal = "piept de pui cu sos gorgonzola";
            mainCourse = "chicken breast with gorgonzola sauce";
            break;
        }
    }

    virtual void alegereDesert()
    {
        int random = rand()%4;
        switch(random)
        {
        case 0:
            desert = "crumble";
            dessert = "crumble";
            break;
        case 1:
            desert = "inghetata asortata";
            dessert = "assorted ice cream";
            break;
        case 2:
            desert = "clatite";
            dessert = "crepes";
            break;
        case 3:
            desert = "tiramisu";
            dessert = "tiramisu";
            break;
        }
    }
} ;

class Vegetarian : public Meniu
{
public:
    void alegereSupaCiorba()
    {
        int random = rand()%3;
        switch(random)
        {
        case 0:
            supaCiorba = "supa crema de ardei";
            soup = "creamy red pepper soup";
            break;
        case 1:
            supaCiorba = "supa de rosii";
            soup = "tomato soup";
            break;
        case 2:
            supaCiorba = "supa cream de sparanghel";
            soup = "creamy asparagus soup";
            break;
        }
    }


    virtual void alegereFelPrincipal()
    {
        int random = rand()%3;
        switch(random)
        {
        case 0:
            felPrincipal = "salata greceasca cu tofu";
            mainCourse = "greek salad with tofu";
            break;
        case 1:
            felPrincipal = "ciuperci la cuptor";
            mainCourse = "roasted mushrooms";
            break;
        case 2:
            felPrincipal = "cartofi gratinati cu telemea";
            mainCourse = "cheesy au gratin potatoes";
            break;
        }
    }

    virtual void alegereDesert()
    {
        int random = rand()%3;
        switch(random)
        {
        case 0:
            desert = "prajitura cu banane";
            dessert = "banana cake";
            break;
        case 1:
            desert = "placinta de mere";
            dessert = "apple pie";
            break;
        case 2:
            desert = "budinca de chia cu capsuni";
            dessert = "chia seed pudding with strawberries";
            break;

        }
    }
} ;

class Flexitarian : public Meniu
{
public:
    void alegereSupaCiorba()
    {
        int random = rand()%7;
        switch(random)
        {
        case 0:
            supaCiorba = "supa de pui";
            soup = "chicken soup";
            break;
        case 1:
            supaCiorba = "ciorba de vacuta";
            soup = "beef soup";
            break;
        case 2:
            supaCiorba = "ciorba de legume";
            soup = "vegetable soup";
            break;
        case 3:
            supaCiorba = "supa crema de ardei";
            soup = "creamy red pepper soup";
            break;
        case 4:
            supaCiorba = "supa de rosii";
            soup = "tomato soup";
            break;
        case 5:
            supaCiorba = "supa cream de sparanghel";
            soup = "creamy asparagus soup";
            break;
        case 6:
            supaCiorba = "supa crema de ciuperci";
            soup = "creamy mushroom soup";
            break;
        }
    }


    virtual void alegereFelPrincipal()
    {
        int random = rand()%5;
        switch(random)
        {
        case 0:
            felPrincipal = "muschi de vita cu legume la gratar";
            mainCourse = "grilled beef fillet with vegetables";
            break;
        case 1:
            felPrincipal = "piept de pui la gratar cu broccoli sote";
            mainCourse = "grilled chicken breast with broccoli sote";
            break;
        case 2:
            felPrincipal = "salata greceasca cu tofu";
            mainCourse = "greek salad with tofu";
            break;
        case 3:
            felPrincipal = "ciuperci la cuptor";
            mainCourse = "roasted mushrooms";
            break;
        case 4:
            felPrincipal = "cartofi gratibati cu telemea";
            mainCourse = "cheesy au gratin potatoes";
            break;
        }
    }

    virtual void alegereDesert()
    {
        int random = rand()%7;
        switch(random)
        {
        case 0:
            desert = "crambel";
            dessert = "crumble";
            break;
        case 1:
            desert = "inghetata asortata";
            dessert = "assorted ice cream";
            break;
        case 2:
            desert = "clatite";
            dessert = "crepes";
            break;
        case 3:
            desert = "tiramisu";
            dessert = "tiramisu";
            break;
        case 4:
            desert = "prajitura cu banane";
            dessert = "banana cake";
            break;
        case 5:
            desert = "placinta de mere";
            dessert = "apple pie";
            break;
        case 6:
            desert = "budinca de chia cu capsuni";
            dessert = "chia seed pudding with strawberries";
            break;
        }
    }
} ;

void scriereMeniu() // se creaza fisierul cu meniul aleator pe 3 zile (romana r si engleza e)
{
    ofstream r;
    ofstream e;
    r.open("meniu.csv");
    e.open("menu.csv");


    r<<"   Tip Dieta   "<<" , "<<"  Supa/Ciorba  "<<" , "<<"  Fel Principal  "<<" , "<<"  Desert  "<<endl;
    e<<"   Type of Diet   "<<" , "<<"  Soup  "<<" , "<<"  Main Course  "<<" , "<<"  Dessert  "<<endl;

    int i;
    for(i = 1 ; i < 4 ; i++)
    {
        r<<"************************************ Ziua "<<i<< " ********************************************"<<endl<<endl;
        e<<"************************************ Day "<<i<< " ********************************************"<<endl<<endl;


        ManancaOrice meniuMO;
        Vegetarian meniuV;
        Flexitarian meniuF;

        meniuMO.alegereSupaCiorba();
        meniuMO.alegereFelPrincipal();
        meniuMO.alegereDesert();

        meniuV.alegereSupaCiorba();
        meniuV.alegereFelPrincipal();
        meniuV.alegereDesert();

        meniuF.alegereSupaCiorba();
        meniuF.alegereFelPrincipal();
        meniuF.alegereDesert();

        r<< " Mananca orice " <<"  ,  " << meniuMO.supaCiorba <<"   ,   "<<meniuMO.felPrincipal<<"   ,   "<<meniuMO.desert<<endl;
        r<< " Vegetarian    " <<"  ,  " << meniuV.supaCiorba <<"   ,   "<<meniuV.felPrincipal<<"   ,   "<<meniuV.desert<<endl;
        r<< " Flexitarian   " <<"  ,  " << meniuF.supaCiorba <<"   ,   "<<meniuF.felPrincipal<<"   ,   "<<meniuF.desert<<endl<<endl;

        e<< " Without restrictions " <<"  ,  " << meniuMO.soup <<"   ,   "<<meniuMO.mainCourse<<"   ,   "<<meniuMO.dessert<<endl;
        e<< " Vegetarian           " <<"  ,  " << meniuV.soup <<"   ,   "<<meniuV.mainCourse<<"   ,   "<<meniuV.dessert<<endl;
        e<< " Flexitarian          " <<"  ,  " << meniuF.soup <<"   ,   "<<meniuF.mainCourse<<"   ,   "<<meniuF.dessert<<endl<<endl;

    }



}

template <class T> //template pentru a ajuta la calcularea costului castelului pe diferite perioade de timp
float costCastel(T zile)
{
    float castel;
    castel = (zile * 10000)-((zile*2*10000*10)/1000) ;//pret intreg - de cate ori avem 10 zile*procent reducere *pret pe zece zile pe care se aplica reducere
    return castel;
}


class Cheltuieli
{
private :

    long int transport;
    long int cazare;
    long int mancareSiApa;
    long int castel;
    long int machiaj;
    int numarZile;
    long long int costTotal;

public:

    Cheltuieli()
    {
        //calculare cheluieli transport(ptr toata durata)

        int nrAutocare;

        try //se verifica daca numarul de persoane se imparte exact pentru locurile dintr-un autocar, daca nu se adauga un autocar in plus pentru cei care nu au loc
        {
            nrAutocare = numarPersoane / 50;
            if ((numarPersoane % 50) != 0)
                throw numarPersoane;

        }
        catch (int numarPersoane)
        {
            nrAutocare = (numarPersoane/50) +1;
        };

        transport = nrAutocare * 5680 * 2;  //*2 pentru dus-intors

        ////////////////////////////////////////////////////////////////////////////////////////

        //calculare cheltuieli cazare (pe zi)

        int nrCamereCast;

        try
        {
            nrCamereCast = numarPersoane/2;
            if((numarPersoane - 132) % 2 != 0) //se verifica daca numarul de persoane din cast-ul initial se imparte exact la numarul de locuri dintr-o camera
                throw numarPersoane;
        }
        catch (int numarPersoane)
        {
            nrCamereCast = ((numarPersoane - 132)/2) +1;// caz contrar : se adauga o camera de o persoana
        };


        int nrCamereFiguranti, nrFiguratie = 132;//pentru figuratie;
        try
        {
            nrCamereFiguranti = nrFiguratie/3; //se verifica daca numarul de persoane din figuratie se imparte exact la numarul de locuri dintr-o camera
            if((nrFiguratie  % 3) != 0)
                throw nrFiguratie;
        }
        catch (int nrFiguratie)
        {
            nrCamereFiguranti = (nrFiguratie / 3) +1; // caz contrar : se adauga o camera in care vor sta 1-2 persoane
        };

        cazare = nrCamereCast * 350 + nrCamereFiguranti * 420;

        ////////////////////////////////////////////////////////////////////////////////////////

        //calculare cheltuieli bautura (pe zi)

        float apa,suc,cafea,apaPret,cafeaPret,sucPret,bauturaTotal,fractPart,intPart;

        //calcularea cantitatilor de lichide consumate intr-o zi(litri)
        apa = numarPersoane;
        cafea = numarPersoane * 0.5;
        suc = numarPersoane * 0.8;

        apa = apa / 2; //calcul numar de sticle corelat cu cantitea in litri
        fractPart = modf(apa, &intPart);
        try
        {
            apaPret = intPart * 6; //calcul pret pe sticla
            if(fractPart != 0) throw intPart; //se verifica daca numarul de litri consumati intr-o zi se imparte intr-un numar exact de sticle
        }
        catch (float intPart)
        {
            apaPret = (intPart + 1) * 6;
        };


        //la cafea nu se mai calculeaza pe "sticle" pentru ca nu se modifica variabila cafea = cafea / 1;
        fractPart = modf(cafea, &intPart);
        try
        {
            cafeaPret = intPart * 30;
            if(fractPart != 0) throw intPart;
        }
        catch(float intPart)
        {
            cafeaPret = (intPart + 1) * 30;
        };

        suc = suc / 2; //calcul cantitatea in sticle
        fractPart = modf(suc, &intPart);
        try
        {
            sucPret = intPart * 8;
            if(fractPart != 0) throw intPart;
        }
        catch(float intPart)
        {
            sucPret = (intPart + 1) * 8;
        };

        bauturaTotal = apaPret + cafeaPret + sucPret;

        mancareSiApa = bauturaTotal;

        ///////////////////////////////////////////////////////////////////////////////////////////

        //calculare cheltuieli machiaj (pe zi)

        machiaj = 0;

        int i;

        for(i = 0; i < numarActori; i++)
            machiaj = machiaj + persRoluri[i].pretMakeUp;

        ////////////////////////////////////////////////////////////////////////////////////////////

        //calculare costuri totale apa(bautura) si mancarea (pe zi)

        for(i = 0; i < numarPersoane; i++)
            mancareSiApa = mancareSiApa + persDiete[i].pretMeniuDieta;


    }

    long int getTransport()//returneaza cheltuielile totale pentru transport (nu depinde de numarul de zile)
    {
        return transport;
    }

    long int getCazare(int zile)//returneaza cheltuielile de cazare in functie de numarul de zile
    {
        return cazare*zile;
    }
    long int getMancareSiApa(int zile)
    {
        return  mancareSiApa*zile;
    }
    long int getMachiaj(int zile)
    {
        return  machiaj*zile;
    }
    long int getCastel(int zile)
    {
        castel = costCastel<int>(zile);
        return  castel;
    }


    void cheltui(int zile)// se calculeaza costul total in functie de numarul de zile
    {
        castel = costCastel<int>(zile);
        costTotal = transport + castel + (zile * (machiaj+mancareSiApa+cazare));
    }

    long int getCostTotal()
    {
        return costTotal;
    }

    void cheltui(string fisier)//se genereaza fisierul cu costuri (romana)
    {

        ofstream g;
        g.open(fisier);

        g<<"*********************************Pentru 30 zile************************"<<endl;
        cheltui(30);
        g<<"Cheltuiele totale "<< getCostTotal()<<" RON dintre care:"<<endl;
        g<<" ^Transportul(dus-intors aeroport) "<<" , "<<getTransport()<<endl;
        g<<" ^Cazarea                          "<<" , "<<getCazare(30)<<endl;
        g<<" ^Machiaj                          "<<" , "<<getMachiaj(30)<<endl;
        g<<" ^Mancare si apa(bauturi)          "<<" , "<<getMancareSiApa(30)<<endl;
        g<<" ^Inchiriere castel                "<<" , "<<getCastel(30)<<endl<<endl<<endl;

        g<<"*********************************Pentru 45 zile************************"<<endl;
        cheltui(45);
        g<<"Cheltuiele totale "<< getCostTotal()<<" RON dintre care:"<<endl;
        g<<" ^Transportul(dus-intors aeroport) "<<" , "<<getTransport()<<endl;
        g<<" ^Cazarea                          "<<" , "<<getCazare(45)<<endl;
        g<<" ^Machiaj                          "<<" , "<<getMachiaj(45)<<endl;
        g<<" ^Mancare si apa(bauturi)          "<<" , "<<getMancareSiApa(45)<<endl;
        g<<" ^Inchiriere castel                "<<" , "<<getCastel(45)<<endl<<endl<<endl;

        g<<"*********************************Pentru 60 zile************************"<<endl;
        cheltui(60);
        g<<"Cheltuiele totale "<< getCostTotal()<<" RON dintre care:"<<endl;
        g<<" ^Transportul(dus-intors aeroport) "<<" , "<<getTransport()<<endl;
        g<<" ^Cazarea                          "<<" , "<<getCazare(60)<<endl;
        g<<" ^Machiaj                          "<<" , "<<getMachiaj(60)<<endl;
        g<<" ^Mancare si apa(bauturi)          "<<" , "<<getMancareSiApa(60)<<endl;
        g<<" ^Inchiriere castel                "<<" , "<<getCastel(60)<<endl<<endl<<endl;

        g<<"*********************************Pentru 100 zile ************************"<<endl;
        cheltui(100);
        g<<"Cheltuiele totale "<< getCostTotal()<<" RON dintre care:"<<endl;
        g<<" ^Transportul(dus-intors aeroport) "<<" , "<<getTransport()<<endl;
        g<<" ^Cazarea                          "<<" , "<<getCazare(100)<<endl;
        g<<" ^Machiaj                          "<<" , "<<getMachiaj(100)<<endl;
        g<<" ^Mancare si apa(bauturi)          "<<" , "<<getMancareSiApa(100)<<endl;
        g<<" ^Inchiriere castel                "<<" , "<<getCastel(100)<<endl<<endl<<endl;

    }
    void cheltui(string fisier,string engleza)//se genereaza fisierul cu costuri (engleza si moneda schimbata)
    {

        ofstream g;
        g.open(fisier);

        g<<"********************************* 30 days************************"<<endl;
        cheltui(30);
        g<<"Total costs: "<< getCostTotal()*0.21<<" $ ,consist of:"<<endl;
        g<<" ^Transport            "<<" , "<<getTransport()*0.21<<endl;
        g<<" ^Accommodation        "<<" , "<<getCazare(30)*0.21<<endl;
        g<<" ^Makeup               "<<" , "<<getMachiaj(30)*0.21<<endl;
        g<<" ^Food and water       "<<" , "<<getMancareSiApa(30)*0.21<<endl;
        g<<" ^Castle rent          "<<" , "<<getCastel(30)*0.21<<endl<<endl<<endl;

        g<<"*********************************Pentru 45 zile************************"<<endl;
        cheltui(45);
        g<<"Total costs: "<< getCostTotal()*0.21<<" $ ,consist of:"<<endl;
        g<<" ^Transport           "<<" , "<<getTransport()*0.21<<endl;
        g<<" ^Accommodation       "<<" , "<<getCazare(45)*0.21<<endl;
        g<<" ^Makeup              "<<" , "<<getMachiaj(45)*0.21<<endl;
        g<<" ^Food and water      "<<" , "<<getMancareSiApa(45)*0.21<<endl;
        g<<" ^Castle rent         "<<" , "<<getCastel(45)*0.21<<endl<<endl<<endl;

        g<<"*********************************Pentru 60 zile************************"<<endl;
        cheltui(60);
        g<<"Total costs: "<< getCostTotal()*0.21<<" $ ,consist of:"<<endl;
        g<<" ^Transport          "<<" , "<<getTransport()*0.21<<endl;
        g<<" ^Accommodation      "<<" , "<<getCazare(60)*0.21<<endl;
        g<<" ^Makeup             "<<" , "<<getMachiaj(60)*0.21<<endl;
        g<<" ^Food and water     "<<" , "<<getMancareSiApa(60)*0.21<<endl;
        g<<" ^Castle rent        "<<" , "<<getCastel(60)*0.21<<endl<<endl<<endl;

        g<<"*********************************Pentru 100 zile ************************"<<endl;
        cheltui(100);
        g<<"Total costs: "<< getCostTotal()*0.21<<" $ ,consist of:"<<endl;
        g<<" ^Transport         "<<" , "<<getTransport()*0.21<<endl;
        g<<" ^Accommodation     "<<" , "<<getCazare(100)*0.21<<endl;
        g<<" ^Makeup            "<<" , "<<getMachiaj(100)*0.21<<endl;
        g<<" ^Food and water    "<<" , "<<getMancareSiApa(100)*0.21<<endl;
        g<<" ^Castle rent       "<<" , "<<getCastel(100)*0.21<<endl<<endl<<endl;

    }


    ~Cheltuieli() {};

};




int main()
{

    preiaInfo(); //preluare informatii din fisierul cu cast-ul initial
    adaugaFiguratie(); //adaugare figuratie
    scriereFisierNou(); //generare fisier cu cast-ul extins

    atribuireRoluriActori(); //atribuire random a  rolurilor pentru actori si figuratie
    atribuireDiete(); //atribuire random a tipurilor de dieta pentru intregul cast

    Cheltuieli cost;
    cost.cheltui("costuri.csv"); //generare fisier costuri (romana)
    cost.cheltui("costs.csv","engleza"); //generare fisier costuri (engleza)
    scriereMeniu(); //generare meniuri (romana si engleza)

    return 0;
}
