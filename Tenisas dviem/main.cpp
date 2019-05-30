#include <iostream>
 #include <stdlib.h>
 #include <time.h>
 #include <conio.h>
 #include <windows.h>

using namespace std;
enum eDir {STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};
class kamuoliukas
{
private:
    int x, y;
    int xo, yo;
    eDir kryptis;
public:
    kamuoliukas(int posX, int posY)
    {
        xo = posX;
        yo = posY;
        x = posX; y =posY;
        kryptis = STOP;
    }
    void Pradzia()
    {
       x = xo; y = yo;
       kryptis = STOP;
    }
    void keisk_krypti(eDir d)
    {
        kryptis = d;
    }
    void kryptis_rand()
    {
       kryptis = (eDir)((rand() % 6) + 1);
    }
    inline int getX() { return x; }
    inline int getY() { return y; }
    inline eDir getDirection() { return kryptis; }
    void judesys ()
    {
        switch(kryptis)
        {
            case STOP:
                break;
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case UPLEFT:
                x--; y--;
                break;
            case DOWNLEFT:
                x--; y++;
                break;
            case UPRIGHT:
                x++; y--;
                break;
            case DOWNRIGHT:
                x++; y++;
                break;
            default:
                break;
        }
    }
    friend ostream & operator<<(ostream & o, kamuoliukas c)
    {
        o <<"Kamuolys ["<<c.x<<","<<c.y<<"]["<<c.kryptis<<"]"<<endl;
        return o;
    }
};

class rakete
{
   private:
       int x, y;
       int xo, yo;
   public:
    rakete()
    {
        x=y=0;
    }
    rakete(int posX, int posY) : rakete()
    {
        xo = posX;
        yo = posY;
        x = posX;
        y = posY;
    }
    inline void Pradzia() {x = xo; y = yo;}
    inline int getX() {return x;}
    inline int getY() { return y;}
    inline void Aukstyn() {y--;}
    inline void Zemyn() {y++;}
    friend ostream & operator<<(ostream & o, rakete c)
    {
        o << "Rakete [" << c.x <<","<<c.y<< "]";
        return o;
    }

};

class Tvarkykle
{
   private:
       int plotis, aukstis;
       int suma1, suma2;
       char aukstyn1, zemyn1, aukstyn2, zemyn2;
       bool quit;
       kamuoliukas * kamuolys;
       rakete * zaidejas1;
       rakete * zaidejas2;
   public:
        Tvarkykle(int w, int h)
        {
            srand(time(NULL));
            quit = false;
            aukstyn1 = 'w'; aukstyn2 = 'i';
            zemyn1 = 's'; zemyn2 = 'k';
            suma1=suma2=0;
            plotis = w; aukstis = h;
            kamuolys = new kamuoliukas(w/2, h/2);
            zaidejas1 = new rakete(1, h/2 - 3);
            zaidejas2 = new rakete(w-2, h/2 - 3);
        }
        ~Tvarkykle()
        {
            delete kamuolys, zaidejas1, zaidejas2;
        }
        void taskai(rakete * zaidejas)
        {
            if(zaidejas == zaidejas1)
                suma1++;
            else if(zaidejas == zaidejas2)
                suma2++;

            kamuolys->Pradzia();
            zaidejas1->Pradzia();
            zaidejas2->Pradzia();
        }
        void Aikste()
        {
            system("cls");
            for(int i=0; i<plotis+2; i++)
                cout<<"\xB2";
                cout<<endl;

            for(int i=0; i<aukstis; i++)
            {
                for(int j=0; j<plotis; j++)
                {
                    int kamuolysx = kamuolys->getX();
                    int kamuolysy = kamuolys->getY();
                    int zaidejas1x = zaidejas1->getX();
                    int zaidejas2x = zaidejas2->getX();
                    int zaidejas1y = zaidejas1->getY();
                    int zaidejas2y = zaidejas2->getY();

                    if (j == 0)
                        cout<<"\xB2";

                    if(kamuolysx == j && kamuolysy == i)
                        cout<<"O"; //kamuplio ikona
                    else if (zaidejas1x == j && zaidejas1y == i)
                        cout<<"\xC9"; //raketes ikona
                    else if (zaidejas2x == j && zaidejas2y == i)
                        cout<<"\xBB"; //raketes ikona

                    else if (zaidejas1x == j && zaidejas1y +1 == i)
                        cout<<"\xDB"; //raketes ikona
                    else if (zaidejas1x == j && zaidejas1y +2 == i)
                        cout<<"\xDB"; //raketes ikona
                    else if (zaidejas1x == j && zaidejas1y +3 == i)
                        cout<<"\xDB"; //raketes ikona
                    else if (zaidejas1x == j && zaidejas1y +4 == i)
                        cout<<"\xC8"; //raketes ikona

                    else if (zaidejas2x == j && zaidejas2y +1 == i)
                        cout<<"\xDB"; //raketes ikona
                    else if (zaidejas2x == j && zaidejas2y +2 == i)
                        cout<<"\xDB"; //raketes ikona
                    else if (zaidejas2x == j && zaidejas2y +3 == i)
                        cout<<"\xDB"; //raketes ikona
                    else if (zaidejas2x == j && zaidejas2y +4 == i)
                        cout<<"\xBC"; //raketes ikona

                    else
                        cout<<" ";
                    if (j == plotis-1)
                        cout<<"\xB2";
                }
                cout<<endl;
            }

            for(int i=0; i<plotis+2; i++)
                cout<<"\xB2";
                cout<<endl;

            cout<<"Pirmas zaidejas surinko :"<<suma1<<endl;
            cout<<"Antras zaidejas surinko :"<<suma2<<endl;
        }
        void Ivedimas()
        {
            kamuolys->judesys();

            int kamuolysx = kamuolys->getX();
            int kamuolysy = kamuolys->getY();
            int zaidejas1x = zaidejas1->getX();
            int zaidejas2x = zaidejas2->getX();
            int zaidejas1y = zaidejas1->getY();
            int zaidejas2y = zaidejas2->getY();

            if(_kbhit())
            {
                    char dabartinis = _getch();
                    if (dabartinis==aukstyn1)
                        if (zaidejas1y > 0)
                        zaidejas1->Aukstyn();
                    if (dabartinis==aukstyn2)
                        if (zaidejas2 > 0)
                        zaidejas2->Aukstyn();
                    if (dabartinis==zemyn1)
                        if (zaidejas1y +4 < aukstis)
                        zaidejas1->Zemyn();
                    if (dabartinis==zemyn2)
                        if (zaidejas2y +4 < aukstis)
                        zaidejas2->Zemyn();

                    if(kamuolys->getDirection()==STOP)
                        kamuolys->kryptis_rand();

                    if (dabartinis == 'q')
                        quit = true;
            }
        }
        void Animacija()
        {
            int kamuolysx = kamuolys->getX();
            int kamuolysy = kamuolys->getY();
            int zaidejas1x = zaidejas1->getX();
            int zaidejas2x = zaidejas2->getX();
            int zaidejas1y = zaidejas1->getY();
            int zaidejas2y = zaidejas2->getY();

            //kaire rakete
            for(int i =0; i<4; i++)
                if(kamuolysx == zaidejas1x +1)
                    if(kamuolysy==zaidejas1y+i)
                        kamuolys->keisk_krypti((eDir)((rand()%3)+4));

             //kaire rakete
            for(int i =0; i<4; i++)
                if(kamuolysx == zaidejas2x -1)
                    if(kamuolysy==zaidejas2y +i)
                        kamuolys->keisk_krypti((eDir)((rand()%3)+1));

            //apatine siena
            if(kamuolysy == aukstis - 1)
                kamuolys->keisk_krypti(kamuolys->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);

            //virsutine siena
            if(kamuolysy == 0)
                kamuolys->keisk_krypti(kamuolys->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);

            //desine siena
            if(kamuolysx == plotis-1)
                taskai(zaidejas1);
            //kaire siena
            if(kamuolysx == 0)
                taskai(zaidejas2);
        }
        void Paleistis()
        {
            while (!quit)
            {
              Aikste();
              Ivedimas();
              Animacija();
              Sleep(50);
            }
        }
};
int main()
{
    Tvarkykle c(60, 30);
    c.Paleistis();
    return 0;
}
