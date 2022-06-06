#include <iostream>
#include <map>

using namespace std;

int main()
{
    multimap <int,string> lookup;

    lookup.insert(make_pair(30,"Mike"));
    lookup.insert(make_pair(10,"Vicky"));
    lookup.insert(make_pair(30,"Roj")); //Key'i 30 olan ikinci bir eleman� ekleyebiliyoruz.
    lookup.insert(make_pair(20,"Bob"));
    lookup.insert(make_pair(30,"Bugra"));

    for(multimap<int, string>::iterator it=lookup.begin(); it!=lookup.end(); it++){
        cout<<it->first << ": " << it->second <<endl;
    }

    cout<<endl;

    //find() methodu ile ba�lang�c� se�ebiliyoruz iteratorun.
    for(multimap<int, string>::iterator it=lookup.find(20); it!=lookup.end(); it++){
        cout<<it->first << ": " << it->second <<endl;
    }

    cout<<endl;

    //B�yle yaparak sadece key=30 olanlar� se�ip yazd�rabiliyoruz.
    pair<multimap<int,string>::iterator, multimap<int,string>::iterator> its = lookup.equal_range(30);
    // Burada first ve second oluyor buna dikkat. ��nk� pairdeki ilk map begin'e, ikincisi ise end'e denk oluyor.
    for(multimap<int, string>::iterator it=its.first; it!=its.second; it++){
        cout<<it->first << ": " << it->second <<endl;
    }

    cout<<endl;

    //Yeni cpp versiyonlar�nda "auto" diye bir �ey var. Bu �stteki yap�lan pair e�lemesine denk oluyor.
    auto its2=lookup.equal_range(30);
    for(multimap<int, string>::iterator it=its2.first; it!=its2.second; it++){
        cout<<it->first << ": " << it->second <<endl;
    }

    cout<<endl;


    return 0;
}
