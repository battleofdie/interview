#include <iostream>

using namespace std;

class Singletone
{
public:
    static Singletone* getInstance(){
        if(_instance == NULL)
        {
            _instance = new Singletone();
        }

        return _instance;
    }
    virtual ~Singletone(){
        delete _instance;
    }

    void increase(){
        count ++;
    }
    
    void decrease(){
        count --;
    }

    int counting(){
        return count;
    }
private: 
    static Singletone* _instance;
    int count;
protected:
    Singletone(){ /* ... */ 
        count = 0;
    }
};


Singletone* Singletone::_instance = NULL;

int main(int argc, char *argv[])
{
    Singletone* p = Singletone::getInstance();

    p->increase();
    p->increase();
    cout << p->counting() << endl;

    Singletone* q = Singletone::getInstance();
    q->decrease();
    cout << p->counting() << endl;
    return 0;
}
