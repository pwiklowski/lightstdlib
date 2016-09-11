#ifndef MAP_H
#define MAP_H

#include "List.h"
#include "log.h"

template <typename Key, typename Value> class Map{
public:
    typedef ListIterator<Node<Key> > iterator;
    typedef ListIterator<const Node<Key> > const_iterator;


    Map(){

    }
    Map(const Map& m){
        m_keys = m.m_keys;
        m_values = m.m_values;
    }
    ~Map(){
        m_keys.clear();
        m_values.clear();
    }

    Map& operator = (const Map& m){
        m_keys.clear();
        m_values.clear();

        m_keys = m.m_keys;
        m_values = m.m_values;
        return *this;
    }




    void clear(){
        m_keys.clear();
        m_values.clear();
    }


    Value get(Key k){
        for(unsigned int i = 0; i< m_keys.size(); i++){
            if (k == m_keys.at(i)){
                return m_values.at(i);
            }
        }

    }

    bool has(Key k){
        for(unsigned int i = 0; i< m_keys.size(); i++){
            if (k == m_keys.at(i)){
                return true;
            }
        }
        return false;
    }

    void insert(Key k, Value v){
        for(unsigned int i = 0; i< m_keys.size(); i++){
            if (k == m_keys.at(i)){
                m_values.replace(i, v);
                return;
            }
        }
        m_keys.append(k);
        m_values.append(v);
    }

    void remove(Key k){
        for(unsigned int i = 0; i< m_keys.size(); i++){
            if (k == m_keys.at(i)){
                m_keys.remove(i);
                m_values.remove(i);
            }
        }
    }

    List<Key>& keys(){
        return m_keys;
    }

    size_t size() const{
        return m_keys.size();
    }
    iterator begin() const{
        return m_keys.begin();
    }

    iterator end() const{
        return m_keys.end();
    }

    iterator begin() {
        return m_keys.begin();
    }

    iterator end() {
        return m_keys.end();
    }



private:
    List<Key> m_keys;
    List<Value> m_values;
};



#endif
