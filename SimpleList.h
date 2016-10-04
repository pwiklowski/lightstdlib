#ifndef SIMPLELIST_H
#define LIMPLELIST_H

#include <cstddef>

template <class T> class SimpleList{
public:
    SimpleList<T>(){
        m_size = 0;
        m_items = nullptr;
    }

    SimpleList<T>(const SimpleList<T>& l){
        m_size = l.m_size;
        if (m_size >0)
            m_items = new T [l.m_size];
        for (unsigned int i = 0; i < m_size; i++)
            m_items[i] = l.m_items[i];
    }



    SimpleList<T>& operator = (const SimpleList<T> & v) {
       if (m_size>0)
            delete[] m_items;
        m_size = v.m_size;


        if (m_size >0)
            m_items = new T [v.m_size];
        for (unsigned int i = 0; i < m_size; i++)
            m_items[i] = v.m_items[i];
        return *this;
    }
    ~SimpleList<T>(){
       if (m_size>0)
            delete[] m_items;
    }

    bool operator == (const SimpleList<T> l) const {
        if (l.m_size != m_size) return false;

        for (unsigned int i=0; i<m_size; i++){
            if (m_items[i] != l.m_items[i]) return false;
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

    void replace(size_t item, T value){
        if (item<m_size){
            m_items[item] = value;
        }
    }


    void remove(unsigned int item){
        T* newBuffer = nullptr;
        if (m_size >1){
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

    T* last() {
        return &m_items[m_size - 1];
    }

    T* end() {
        return  m_items + size();
    }

    size_t size() const{
        return m_size;
    }

    T& at(unsigned int i) const{
        return m_items[i];
    }

private:
    T* m_items; //TODO: replce with something that does not have a constructor
    size_t m_size;



};



#endif
