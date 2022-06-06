#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool match(string test){
    return test.size() ==3;
}

int countStrings(vector<string>& texts, bool (*match)(string test)){ //ikinci parametre function pointer'd�r.
    int tally=0;
    for(int i=0;i<texts.size();i++){
        if(match(texts[i])) //Fonksiyon pointer'� normal fonksiyon gibi kullan�yoruz.
            tally++;
    }
    return tally;
}

int main()
{
    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("four");
    texts.push_back("two");
    texts.push_back("six");
    texts.push_back("seven");

    cout<<match("one")<<endl;

    cout<< count_if(texts.begin(),texts.end(),match)<<endl; //"count_if" ile istedi�imiz fonksiyona return denen vector eleman say�s�n� bulabiliriz.

    cout<<countStrings(texts,match)<<endl; //match yerine &match 'de yaz�labilir.


    return 0;
}
