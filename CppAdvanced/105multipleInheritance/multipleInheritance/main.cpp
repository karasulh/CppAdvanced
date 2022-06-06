#include <iostream>
using namespace std;

class MusicalInstrument{
public:
    void play(){cout<<"Playing instrument"<<endl;}
    void reset(){cout<<"Resetting instrument"<<endl;}
    virtual ~MusicalInstrument(){};
};

class Machine{
public:
    void start(){cout<<"Playing instrument"<<endl;}
    void reset(){cout<<"Resetting machine"<<endl;}
    virtual ~Machine(){};
};

class Synthesizer : public Machine, public MusicalInstrument{ //Ortak inheritance yap�labiliyor.
public:
    virtual ~ Synthesizer(){};
};

int main(){

Synthesizer *pSynth= new Synthesizer();

pSynth->play();
pSynth->start();
//Farkl� methodlarda s�k�nt� yok ama ayn� isimli methodlarda class'� belirtmek gerekiyor.
pSynth->MusicalInstrument::reset();
pSynth->Machine::reset();

delete pSynth;
return 0;
}
