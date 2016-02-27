#ifndef LIST_H
#define LIST_H

#include <cstddef>
#include <vector>

template <class T> class List{
public:
    List<T>(){
        m_size = 0;
        m_items = nullptr;
    }
    List<T>& operator = (const List<T> & v) {
        if (m_size > 0)
            delete m_items;
        m_size = v.m_size;
        m_items = new T [v.m_size];
        for (unsigned int i = 0; i < m_size; i++)
            m_items[i] = v.m_items[i];
        return *this;
    }
    ~List<T>(){
        if (m_size>0)
            delete[] m_items;
    }

    bool operator == (List l){
        if (l.size() != size()) return false;

        for (unsigned int i=0; i<size(); i++){
            if (at(i) != l.at(i)) return false;
        }

        return true;
    }

    void append(const T item){
        reserve(m_size+1);
        m_items[m_size] = item;
        m_size++;
    }
    void reserve(unsigned int capacity) {
        T* newBuffer = new T[capacity];

        for (unsigned int i = 0; i < m_size; i++){
            newBuffer[i] = m_items[i];
        }
        if(m_size >0)
            delete[] m_items;
        m_items = newBuffer;
    }

    void clear(){
        if (m_size >0)
            delete[] m_items;
        m_size = 0;
    }

    void remove(unsigned int item){
        T* newBuffer = nullptr;
        if (m_size >0){
            newBuffer = new T[m_size -1];

            for (unsigned int i = 0; i <item; i++)
                newBuffer[i] = m_items[i];

            for (unsigned int i = item +1; i <m_size; i++)
                newBuffer[i-1] = m_items[i];

        }
        if (m_size > 0)
            delete[] m_items;
        m_items = newBuffer;
        m_size--;

    }


    T* begin() {
        return m_items;
    }

    T* end() {
        return  m_items + size();
    }

    size_t size(){
        return m_size;
    }

    T& at(unsigned int i){
        return m_items[i];
    }

private:
    T* m_items; //TODO: replce with something that does not have a constructor
    size_t m_size;



};



#endif
