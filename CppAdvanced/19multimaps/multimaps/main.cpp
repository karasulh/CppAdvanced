#include <iostream>
#include <map>

using namespace std;

int main()
{
    multimap <int,string> lookup;

    lookup.insert(make_pair(30,"Mike"));
    lookup.insert(make_pair(10,"Vicky"));
    lookup.insert(make_pair(30,"Roj")); //Key'i 30 olan ikinci bir elemaný ekleyebiliyoruz.
    lookup.insert(make_pair(20,"Bob"));
    lookup.insert(make_pair(30,"Bugra"));

    for(multimap<int, string>::iterator it=lookup.begin(); it!=lookup.end(); it++){
        cout<<it->first << ": " << it->second <<endl;
    }

    cout<<endl;

    //find() methodu ile baþlangýcý seçebiliyoruz iteratorun.
    for(multimap<int, string>::iterator it=lookup.find(20); it!=lookup.end(); it++){
        cout<<it->first << ": " << it->second <<endl;
    }

    cout<<endl;

    //Böyle yaparak sadece key=30 olanlarý seçip yazdýrabiliyoruz.
    pair<multimap<int,string>::iterator, multimap<int,string>::iterator> its = lookup.equal_range(30);
    // Burada first ve second oluyor buna dikkat. Çünkü pairdeki ilk map begin'e, ikincisi ise end'e denk oluyor.
    for(multimap<int, string>::iterator it=its.first; it!=its.second; it++){
        cout<<it->first << ": " << it->second <<endl;
    }

    cout<<endl;

    //Yeni cpp versiyonlarýnda "auto" diye bir þey var. Bu üstteki yapýlan pair eþlemesine denk oluyor.
    auto its2=lookup.equal_range(30);
    for(multimap<int, string>::iterator it=its2.first; it!=its2.second; it++){
        cout<<it->first << ": " << it->second <<endl;
    }

    cout<<endl;


    return 0;
}
