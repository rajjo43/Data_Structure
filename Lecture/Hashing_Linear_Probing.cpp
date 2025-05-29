#include <iostream>
using namespace std;

const int table_size = 11;
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

// Insert key using linear probing
void insert(int key){
    int index = HashFunction(key);
    int startIndex = index;

    // Linear probing to find next available slot
    while (HashTable[index] != -1)
    {
        index = (index + 1) % table_size;

        // Check if table is full(looped around to start)
        if(index == startIndex){
            cout << "Hash table is full ! Cannot insert keys " << key << endl;
        }
    }

    HashTable[index] = key;
    cout << "Inserted key " << key << " at index " << index << endl;
}

// Display the hash table
void displayTable(){
    cout << "\nHash Table: "<< endl;
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
    int keys[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
    int n = sizeof(keys) / sizeof(keys[0]);

    for(int i = 0; i < n; i++){
        insert(keys[i]);
    }

    
    displayTable();
    return 0;
}