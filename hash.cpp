#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

template<typename K, typename V>
class HashTable
{
private:
    struct Element{
        K key;
        V value;
        Element(int k, int v):key(k), value(v){}
    };
 
    struct List{
        Element e;
        List* next;
        List(Element x):e(x), next(NULL){}
    };


    vector<List*> _table;
    
    int hash(K key){
        return key % 100;
    }
        
public:
    HashTable(int sz = 100){
        _table.resize(sz, 0);
    }

    void put(K key, V value){
        Element e(key, value);
        List* node = new List(e);
        node->next = _table[ hash(e.key) ];
        _table[ hash(e.key) ] = node;
    }
    
    void remove(K key ){
        List* head = _table[ hash(key) ];
        List* prev = NULL;
        while(head)
        {
            if(head->e.key == key)
            {
                // delete head
                if(prev == NULL)
                {
                    _table[ hash(key) ] = head->next;
                    delete head;
                }
                else
                {
                    List* temp = head->next;
                    head->next = temp->next;
                    delete temp;
                }
                return;                    
            }

            prev = head;
            head = head->next;
        }
    }

    V* get(K key){
        List* head = _table[ hash(key) ];
        while(head)
        {
            if(head->e.key == key) 
                return &(head->e.value);
            head = head->next;
        }
        
        return NULL;
    }

    void print(){
        for(auto e: _table)
        {
            List* head = e;
            while(head)
            {
                cout << "(" << head->e.key << ", "<< head->e.value << ") ";
                head = head->next;
            }
            if(e) cout << endl;
        }
    }
};

int main(int argc, char *argv[])
{
    HashTable<int, int> ht;

    srand(time(NULL));
    
    int count = 20;
    if(argc == 2)
        count = atoi(argv[1]);

    while(count--)
    {
        ht.put(rand() % 2000, rand() % 20);
    }

    ht.print();
    return 0;
}
