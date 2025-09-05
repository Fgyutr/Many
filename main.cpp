#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

class SetOperations {
private:
    set<string> setA, setB, setU;
    
    void printSet(const set<string>& s, const string& name) const {
        cout << name << " = {";
        if (!s.empty()) {
            auto it = s.begin();
            cout << *it;
            for (++it; it != s.end(); ++it) {
                cout << ", " << *it;
            }
        }
        cout << "}" << endl;
    }
    
    void printCartesianProduct(const set<string>& s1, const set<string>& s2, 
                              const string& operation) const {
        cout << operation << " = {";
        bool first = true;
        for (const auto& elem1 : s1) {
            for (const auto& elem2 : s2) {
                if (!first) cout << ", ";
                cout << "(" << elem1 << "," << elem2 << ")";
                first = false;
            }
        }
        cout << "}" << endl;
    }
    
    void printPowerSet(const set<string>& s, const string& name) const {
        vector<string> elements(s.begin(), s.end());
        int size = elements.size();
        int powerSetSize = pow(2, size);
        
        cout << "Булеан " << name << " = {";
        for (int i = 0; i < powerSetSize; i++) {
            cout << "{";
            bool first = true;
            for (int j = 0; j < size; j++) {
                if (i & (1 << j)) {
                    if (!first) cout << ", ";
                    cout << elements[j];
                    first = false;
                }
            }
            cout << "}";
            if (i < powerSetSize - 1) cout << ", ";
        }
        cout << "}" << endl;
    }

public:
    void inputSet(set<string>& targetSet, const string& setName) {
        int size;
        string element;
        
        cout << "Введите количество элементов множества " << setName << ": ";
        cin >> size;
        
        targetSet.clear();
        for (int i = 0; i < size; i++) {
            cout << "Введите элемент [" << i << "]: ";
            cin >> element;
            targetSet.insert(element);
        }
    }
    
    void initialize() {
        inputSet(setA, "A");
        system("clear");
        inputSet(setB, "B");
        system("clear");
        inputSet(setU, "U");
        system("clear");
    }
    
    void performAllOperations() {
        // Вывод исходных множеств
        printSet(setA, "Множество A");
        printSet(setB, "Множество B");
        printSet(setU, "Универсальное множество U");
        cout << endl;
        
        // Объединение
        set<string> unionSet;
        unionSet.insert(setA.begin(), setA.end());
        unionSet.insert(setB.begin(), setB.end());
        printSet(unionSet, "Объединение A ∪ B");
        
        // Пересечение
        set<string> intersectionSet;
        set_intersection(setA.begin(), setA.end(),
                        setB.begin(), setB.end(),
                        inserter(intersectionSet, intersectionSet.begin()));
        if (intersectionSet.empty()) {
            cout << "Пересечение A ∩ B = {empty}" << endl;
        } else {
            printSet(intersectionSet, "Пересечение A ∩ B");
        }
        
        // Дополнение A
        set<string> complementA;
        set_difference(setU.begin(), setU.end(),
                      setA.begin(), setA.end(),
                      inserter(complementA, complementA.begin()));
        printSet(complementA, "Дополнение A̅");
        
        // Дополнение B
        set<string> complementB;
        set_difference(setU.begin(), setU.end(),
                      setB.begin(), setB.end(),
                      inserter(complementB, complementB.begin()));
        printSet(complementB, "Дополнение B̅");
        
        // Разность A \ B
        set<string> differenceAB;
        set_difference(setA.begin(), setA.end(),
                      setB.begin(), setB.end(),
                      inserter(differenceAB, differenceAB.begin()));
        printSet(differenceAB, "Разность A \\ B");
        
        // Разность B \ A
        set<string> differenceBA;
        set_difference(setB.begin(), setB.end(),
                      setA.begin(), setA.end(),
                      inserter(differenceBA, differenceBA.begin()));
        printSet(differenceBA, "Разность B \\ A");
        
        // Симметрическая разность
        set<string> symmetricDiff;
        set_symmetric_difference(setA.begin(), setA.end(),
                               setB.begin(), setB.end(),
                               inserter(symmetricDiff, symmetricDiff.begin()));
        printSet(symmetricDiff, "Симметрическая разность A △ B");
        
        cout << "\n--- Декартовы произведения ---" << endl;
        // Декартовы произведения
        printCartesianProduct(setA, setB, "A × B");
        printCartesianProduct(setB, setA, "B × A");
        printCartesianProduct(setA, setA, "A²");
        printCartesianProduct(setB, setB, "B²");
        
        cout << "\n--- Булеаны (множества всех подмножеств) ---" << endl;
        // Булеаны
        printPowerSet(setA, "множества A");
        printPowerSet(setB, "множества B");
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    
    SetOperations operations;
    
    cout << "=== Операции над множествами ===" << endl;
    operations.initialize();
    operations.performAllOperations();
    
    return 0;
}