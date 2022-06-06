#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    map<string,vector<int>> scores;//map value'su bir vector!

    scores["Mike"].push_back(10);
    scores["Mike"].push_back(15);
    scores["Tyson"].push_back(20);

    for(map<string,vector<int>>::iterator it=scores.begin(); it!=scores.end(); it++){
        string name= it->first;
        vector<int> scoreList= it->second;

        cout<<name<<": "<<flush;

        for(int i=0;i<scoreList.size();i++){
            cout<<scoreList[i]<<" "<<flush;
        }

        cout<<endl;
    }

    return 0;
}
