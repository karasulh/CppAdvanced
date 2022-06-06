#include <iostream>

using namespace std;

int main()
{
    //Pass by value olduðu için bu lambda içinde cats'i deðiþtirmemize izin vermeyecekti,compile error olacaktý.
    //Biz compile error olmasýn ama gene pass by value olsun, cats'in gerçek deðeri deðiþmesin deðersek o zaman oraya mutable yazarýz.
    int cats=5;
    [cats]() mutable{
        cats=8;
        cout<<cats<<endl;
    }();

    cout << cats << endl; // Gene 5 kalýr.
    return 0;
}
