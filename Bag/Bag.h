#ifndef BAG_H
#define BAG_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template<typename T>
class Bag
{
public:
    Bag();
    Bag(const Bag<T>& other);
    Bag<T>& operator=(const Bag&);
    ~Bag();
    string toString() const;
    void grow();
    void addItem(const T &item);
    bool contains(T item);
    bool removeItem(T item);
    bool isEmpty();
    void dump();
    int numberOf(T item);
    void removeAll(T item);
    T pickRandom();
    void dumpInto(Bag<T>& other);
    Bag<T> extractAll(T item);

private:
    T* elements;
    int size;
    int capacity;
};

template<typename T>
Bag<T>::Bag()
:size(0), capacity(10)
{
elements = new T[capacity];
}


template <class T>
Bag<T>::Bag (const Bag<T>& other)
{
    //Copy basic information
    size = other.size;
    capacity = other.capacity;
    //Allocate new storage for the copy and copy data
    elements = new T[capacity];
    for(int i = 0; i < capacity; i++)
        elements[i] = other.elements[i];
}
template<typename T>
Bag<T>& Bag<T>::operator=(const Bag& other){
    if(this != &other)
    {
        size = other.size;
        capacity = other.capacity;

        delete [] elements;

        elements = new T[other.capacity];
        for(int i = 0; i < size; i++){
            elements[i] = other.elements[i];
        }
    }
    return *this;
}
template<typename T>
Bag<T>::~Bag()
{
    delete [] elements;
}

template <class T>
void Bag<T>::grow()
{
    int newSize = capacity * 2;
    T* tempList = new T[newSize];
    for(int i = 0; i < capacity; i++)
        tempList[i] = elements[i];
    capacity = newSize;
    delete [] elements;
    elements = tempList;
}

template<typename T>
void Bag<T>::addItem(const T& item){
    if(size == capacity){
        grow();
}

    elements[size] = item;
    size++;
}

template<typename T>
bool Bag<T>::contains(T item){
    for(int i= 0; i<= size;i++){
        if(elements[i]==item){
            return true;
        }

    }
    return false;
}
template<typename T>
string Bag<T>::toString() const
{
    stringstream output;
    output << "{";
    for(int i = 0; i < size - 1; i++) {
        output << elements[i] << ", ";
    }
    if(size > 0)
        output << elements[size - 1];

    output << "}";

    return output.str();
}
template<typename T>
bool Bag<T>::removeItem(T item){
    for(int i =0;i <=size;i++){
        if(elements[i]== item){
            elements[i]=elements[size];
            size--;
            return true;
        }
    }
    return false;
}
template<typename T>
bool Bag<T>::isEmpty(){
    if(size ==0)
        return true;
    else
        return false;
}

template<typename T>
void Bag<T>::dump(){
    size=0;
    delete [] elements;
    elements = new T[capacity];
}

template<typename T>
int Bag<T>::numberOf(T item){
    int count= 0;
    for(int i = 0;i<=size;i++){
        if(elements[i]==item){
            count++;
        }
    }
    return count;
}

template<typename T>
void Bag<T>::removeAll(T item){
    for(int i=size-1; i !=-1; i--){
        if(elements[i]== item){
            elements[i]=elements[size];
            size--;
        }
    }
}

template<typename T>
T Bag<T>::pickRandom(){
    if(this->isEmpty())
        return 0;
    int randomNum= rand() % size;
    T random = elements[randomNum];
    removeItem(random);
    return random;
}

template<typename T>
void Bag<T>::dumpInto(Bag<T>& other){
    for(int i=0; i< size;i++){
        other.addItem(elements[i]);
    }
    this->dump();
}

template<typename T>
Bag<T> Bag<T>::extractAll(T item){
    int newSize =this->numberOf(item);
    this->removeAll(item);

    Bag<T> b;
    for(int i =0;i<newSize;i++){
        b.addItem(item);
    }
    return b;
}


#endif // BAG_H
