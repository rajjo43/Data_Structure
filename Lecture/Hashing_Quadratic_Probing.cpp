#include <iostream>
using namespace std;

const int table_size = 7;
int HashTable[table_size];

// Initialize hash table with -1 to indicate empty slots
void initializeTable(){
    for(int i = 0; i < table_size; i++){
        HashTable[i] = -1;
    }
}

// Hash function
int HashFunction(int key){
    return key % table_size;
}

// Insert key using quadratic probing
void insert(int key){
    int index = HashFunction(key);
    int i = 0;

    // Quadratic Probing
    while(HashTable[(index + i * i) % table_size] != -1 && i < table_size){
        i++;
    }

    if(i < table_size){
        int newIndex = (index + i * i) % table_size;
        HashTable[newIndex] = key;
        cout << "Inserted key " << key << " at index " << newIndex << endl;
    }else{
        cout << "Hash table is full . Cannot insert key " << key << endl;
    }
}

// Display the hash table
void displayTable(){
    cout << "\nHash Table(Quadratic Probing): "<< endl;
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
    int keys[] = {22,  30, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    for(int i = 0; i < n; i++){
        insert(keys[i]);
    }

    
    displayTable();
    return 0;
}