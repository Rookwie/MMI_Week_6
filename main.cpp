#include "MaxNVector.h"
#include <iostream>

int main() {
    try {

        // MaxNVector-Klasse erzeugung
        MaxNVector<int, 2> maxNVec;

        // Hinzufügen von Elementen
        maxNVec.add(1);
        maxNVec.add(2);
        maxNVec.add(3);

        // Lesender Zugriff auf Elemente
        std::cout << "maxNVec[1]: " << maxNVec[1] << std::endl;

        // Ausnahme bei > N wiederholungen
        // maxNVec.add(1);
        maxNVec.add(1);

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        // Test der removeAt-Funktion
        MaxNVector<char, 1> charVec;

        charVec.add('a'); // index 0
        charVec.add('b'); // index 1
        charVec.add('c'); // index 2

        // Löschen des Elements an Index 1 ('b')
        charVec.removeAt(1);

        // ungültigem Index löschen
        // charVec.removeAt(5);

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        // Test der getRarestElement-Funktion
        int arr[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 4};
        size_t size = sizeof(arr) / sizeof(arr[0]);

        int rarest = getRarestElement(arr, size);
        std::cout << "Rarest element: " << rarest << std::endl;

        // leeres Array
        int emptyArr[] = {};
        size_t emptySize = sizeof(emptyArr) / sizeof(emptyArr[0]);
        int rarestEmpty = getRarestElement(emptyArr, emptySize);
        std::cout << "Rarest element: " << rarestEmpty << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
