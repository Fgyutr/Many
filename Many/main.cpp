#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    setlocale (LC_ALL, "Russian");
    int LenA, LenB, LenU;
    string TempString, Ss, Rr;
    vector <pair<string,string>> dec;
    set<string> SetA, SetB, SetC, SetU, TempSet;
    cout << "Введите количество элементов множества А: ";
    cin >> LenA;
    for(int i(0);i<LenA;i++)
    {
        cout << "Введите элемент [" << i <<"] :";
        cin >> TempString;
        SetA.insert(TempString);
    }
    system("clear");
    cout << "Введите количество элементов множества B: ";
    cin >> LenB;
    for(int i(0);i<LenB;i++)
    {
        cout << "Введите элемент [" << i <<"] :";
        cin >> TempString;
        SetB.insert(TempString);
    }
    system("clear");
    cout << "Введите количество элементов множества U: ";
    cin >> LenU;
    for(int i(0);i<LenU;i++)
    {
        cout << "Введите элемент [" << i <<"] :";
        cin >> TempString;
        SetU.insert(TempString);
    }
    system("clear");
    cout << "Ваше множество А :{";
    copy(SetA.begin(),SetA.end(), ostream_iterator<string>(cout,","));
    cout << "}"<<endl;
    cout << "Ваше множество B :{";
    copy(SetB.begin(),SetB.end(), ostream_iterator<string>(cout,","));
    cout << "}"<<endl;
    cout << "Ваше множество U :{";
    copy(SetU.begin(), SetU.end(),ostream_iterator<string>(cout,","));
    cout << "}"<<endl;
    cout << "Объединение множеств А и B = С; {";
    TempSet.insert(SetA.begin(),SetA.end());
    TempSet.insert(SetB.begin(),SetB.end());
    copy(TempSet.begin(),TempSet.end(), ostream_iterator<string> (cout, ","));
    cout << "}" << endl;
    TempSet.clear();
    cout << "Пересечение множеств А и В = С; {";
    set_intersection(SetA.begin(),SetA.end(),SetB.begin(),SetB.end(),inserter(TempSet, TempSet.begin()));
    if(TempSet.empty())
    cout << "empty";
    else
    {
    copy(TempSet.begin(), TempSet.end(),ostream_iterator<string>(cout, ","));
    }
    cout << "}" << endl;
    TempSet.clear();
    cout << "Инверсия множества А; {";
    set_difference(SetU.begin(), SetU.end(), SetA.begin(), SetA.end(), inserter(TempSet, TempSet.begin()));
    copy(TempSet.begin(), TempSet.end(), ostream_iterator<string>(cout,","));
    cout << "}" << endl;
    TempSet.clear();
    cout << "Инверсия множества B; {";
    set_difference(SetU.begin(), SetU.end(), SetB.begin(), SetB.end(), inserter(TempSet, TempSet.begin()));
    copy(TempSet.begin(), TempSet.end(), ostream_iterator<string>(cout,","));
    cout << "}" << endl;
    TempSet.clear();
    cout << "Разность множеств А и В = С; {";
    set_difference(SetA.begin(), SetA.end(), SetB.begin(), SetB.end(), inserter(TempSet, TempSet.begin()));
    copy(TempSet.begin(), TempSet.end(), ostream_iterator<string>(cout,","));
    cout << "}" << endl;
    TempSet.clear();
    cout << "Разность множеств В и А = С; {";
    set_difference(SetB.begin(), SetB.end(), SetA.begin(), SetA.end(), inserter(TempSet, TempSet.begin()));
    copy(TempSet.begin(), TempSet.end(), ostream_iterator<string>(cout,","));
    cout << "}" << endl;
    TempSet.clear();
    cout << "Симетричная разность А и В = С; {";
    set_symmetric_difference(SetA.begin(),SetA.end(),SetB.begin(),SetB.end(), inserter (TempSet, TempSet.begin()));
    copy(TempSet.begin(), TempSet.end(), ostream_iterator<string>(cout, ","));
    cout << "}" << endl;
    TempSet.clear();
    cout << "Декардовое произведение А и В = С; {";
    set<string>::iterator i1;
    set<string>::iterator i2;
    for (i1=SetA.begin();i1!=SetA.end();i1++)
    {
        for (i2=SetB.begin();i2!=SetB.end();i2++)
        {
            cout<<"("<<*i1<<","<<*i2<<")";
            dec.push_back(pair<string,string> (*i1,*i2));
        }
    }
    cout << "}" << endl;
    TempSet.clear();
    cout << "Декардовое произведение B и A = С; {";
    for (i1=SetB.begin();i1!=SetB.end();i1++)
    {
        for (i2=SetA.begin();i2!=SetA.end();i2++)
        {
            cout<<"("<<*i1<<","<<*i2<<")";
        }
    }
    cout << "}" << endl;
    TempSet.clear();
    cout << "Декардовое произведение A^2 = С; {";
    for (i1=SetA.begin();i1!=SetA.end();i1++)
    {
        for (i2=SetA.begin();i2!=SetA.end();i2++)
        {
            cout<<"("<<*i1<<","<<*i2<<")";
        }
    }
    cout << "}" << endl;
    TempSet.clear();
    cout << "Декардовое произведение B^2 = С; {";
    for (i1=SetB.begin();i1!=SetB.end();i1++)
    {
        for (i2=SetB.begin();i2!=SetB.end();i2++)
        {
            cout<<"("<<*i1<<","<<*i2<<")";
        }
    }
    cout << "}" << endl;
    TempSet.clear();
    
    TempSet.insert(SetA.begin(),SetA.end());
    cout << "Булеан множества А = {";
    int nos = pow(2,LenA);
    vector <string> MySet(TempSet.begin(), TempSet.end());
    for (int i = 0; i < nos; i++)
    {
        cout <<"(";
        for (int j = 0; j < LenA; j++)
            if (i & (1 << j))
            {
                cout << MySet[j] << ",";
            }
        cout << ")";
    }
    cout<<"}"<<endl;
    TempSet.clear();
    TempSet.insert(SetB.begin(),SetB.end());
    cout << "Булеан множества В = {";
    int nos1 = pow(2,LenB);
    vector <string> MySet1(TempSet.begin(), TempSet.end());
    for (int i = 0; i < nos1; i++)
    {
        cout <<"(";
        for (int j = 0; j < LenB; j++)
            if (i & (1 << j))
            {
                cout << MySet1[j] << ",";
            }
        cout << ")";
    }
    cout<<"}"<< endl;
    TempSet.clear();
    cout << endl;
    return 0;
}

