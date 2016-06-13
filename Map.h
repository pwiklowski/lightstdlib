#ifndef MAP_H
#define MAP_H

#include "List.h"
#include "log.h"

template <typename Key, typename Value> class Map{
public:
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

    size_t size(){
        return m_keys.size();
    }

    Key* begin() {
        return &m_keys.at(0);
    }

    Key* end() {
        return &m_keys.at(size());
    }

    Key* last() {
        return &m_keys.at(size()-1);
    }
private:
    List<Key> m_keys;
    List<Value> m_values;
};



#endif
