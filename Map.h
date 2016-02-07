#ifndef MAP_H
#define MAP_H

#include "List.h"

template <typename Key, typename Value> class Map{
public:
    Map(){

    }

    Value* get(Key k){
        for(unsigned int i = 0; i< m_keys.size(); i++){
            if (k == m_keys.at(i)){
                return &m_values.at(i);
            }
        }
        return 0;
    }

    void insert(Key k, Value v){
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

private:
    List<Key> m_keys;
    List<Value> m_values;
};



#endif
