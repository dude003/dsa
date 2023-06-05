#include <iostream>
#include <string.h>

using namespace std;

struct data
{
    char name[30];
    long teleno;
};

class HashTable
{
    static const int tableSize = 10;
    data hashArray[tableSize];

public:
    HashTable()
    {
        for (int i = 0; i < tableSize; i++)
        {
            hashArray[i].teleno = 0;
        }
    }

    int hashFunction(const char *key)
    {
        int sum = 0;
        int len = strlen(key);
        for (int i = 0; i < len; i++)
        {
            sum += key[i];
        }
        return sum % tableSize;
    }

    void insert()
    {
        int n;
        cout << "Enter the number of clients: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "Enter the name of client " << i + 1 << ": ";
            cin >> hashArray[hashFunction(hashArray[i].name)].name;
            cout << "Enter the telephone number of client " << i + 1 << ": ";
            cin >> hashArray[hashFunction(hashArray[i].name)].teleno;
        }
    }

    void search()
    {
        char key[30];
        cout << "Enter the name to be searched: ";
        cin >> key;

        int hashValue = hashFunction(key);
        int originalHash = hashValue;

        while (hashArray[hashValue].name[0] != '\0')
        {
            if (strcmp(hashArray[hashValue].name, key) == 0)
            {
                cout << "Data found: Telephone number = " << hashArray[hashValue].teleno << endl;
                return;
            }

            hashValue = (hashValue + 1) % tableSize;

            if (hashValue == originalHash)
            {
                break;
            }
        }

        cout << "Data not found." << endl;
    }

    void display()
    {
        for (int i = 0; i < tableSize; i++)
        {
            if (hashArray[i].teleno != 0)
            {
                cout << "Index " << i << ": " << hashArray[i].name << " " << hashArray[i].teleno << endl;
            }
        }
    }
};

int main()
{
    HashTable hashTable;
    hashTable.insert();
    hashTable.display();
    hashTable.search();

    return 0;
}
