#include <iostream>
using namespace std;

const int table_size = 7;
const int R = 5; // prime number , less than table_size
int HashTable[table_size];

// Initialize hash table with -1 to indicate empty slots
void initializeTable(){
    for(int i = 0; i < table_size; i++){
        HashTable[i] = -1;
    }
}

// Primary Hash function
int Hash1(int key){
    return key % table_size;
}

// Secondary Hash function
int Hash2(int key){
    return 1 + (key % R);
}

// Insert key using double hashing
void insert(int key) {
    int index = Hash1(key);
    int stepSize = Hash2(key);
    int i = 0;

    while (HashTable[(index + i * stepSize) % table_size] != -1 && i < table_size) {
        i++;
    }

    if (i < table_size) {
        int newIndex = (index + i * stepSize) % table_size;
        HashTable[newIndex] = key;
        cout << "Inserted key " << key << " at index " << newIndex << endl;
    } else {
        cout << "Hash table is full! Cannot insert key " << key << endl;
    }
}

// Display the hash table
void displayTable(){
    cout << "\nHash Table(Double Hashing): "<< endl;
    for(int i = 0; i < table_size; i++){
        cout << i << " --> ";
        if(HashTable[i] == -1){
            cout << "empty" << endl;
        }else{
            cout << HashTable[i] << endl;
        }
    }
}

int main()
{
    initializeTable();
    int keys[] = {27, 43, 692, 72};
    int n = sizeof(keys) / sizeof(keys[0]);

    for(int i = 0; i < n; i++){
        insert(keys[i]);
    }

    
    displayTable();
    return 0;
}