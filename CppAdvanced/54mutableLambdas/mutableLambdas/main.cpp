#include <iostream>

using namespace std;

int main()
{
    //Pass by value oldu�u i�in bu lambda i�inde cats'i de�i�tirmemize izin vermeyecekti,compile error olacakt�.
    //Biz compile error olmas�n ama gene pass by value olsun, cats'in ger�ek de�eri de�i�mesin de�ersek o zaman oraya mutable yazar�z.
    int cats=5;
    [cats]() mutable{
        cats=8;
        cout<<cats<<endl;
    }();

    cout << cats << endl; // Gene 5 kal�r.
    return 0;
}
