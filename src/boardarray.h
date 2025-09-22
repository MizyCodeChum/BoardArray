#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

            void add(Entry* entry) {
        
            if (index == SIZE) {
                if (!entry->compare(&array[SIZE - 1])) {
                    cout << entry->name << "'s score is too low to be added!" << endl;
                    return;
                }
            }
            
            int i;
            for (i = 0; i < index; i++) {
                
                if (entry->compare(&array[i])) {
                
                    int shiftUntil = (index == SIZE) ? SIZE - 1 : index;
                    for (int j = shiftUntil; j > i; j--) {
                        array[j] = array[j - 1];
                    }
                    
                  
                    array[i] = *entry;
                    
                
                    if (index < SIZE) {
                        index++;
                    }
                    return;
                }
            }
            
          
            if (index < SIZE) {
                array[index] = *entry;
                index++;
            }
    }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};