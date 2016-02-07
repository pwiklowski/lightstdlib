#ifndef string_H
#define string_H

#include <cstddef>
#include <cstring>

class String{

public:
    String(){
        m_size = 0;
    }
    String(const char* str){
        m_size = 0;
        unsigned int len = strlen(str);
        m_str = new char[len+1];
        for (unsigned int i=0; i<len; i++)
            m_str[i] = str[i];
        m_size = len;
    }

    String(const String& str){
        m_size = 0;
        unsigned int len = str.m_size;
        m_str = new char[len+1];
        for (unsigned int i=0; i<len; i++)
            m_str[i] = str.m_str[i];
        m_size = len;
    }


    void append(const String& str){
        unsigned int len = str.m_size;
        resize(m_size + len);

        for (unsigned int i=0; i<len; i++){
            m_str[m_size++] = str.m_str[i];
        }
    }
    void append(char* str){
        unsigned int len = strlen(str);
        resize(m_size + len);

        for (unsigned int i=0; i<len; i++){
            m_str[m_size++] = str[i];
        }
    }
    void append(char c){
        resize(m_size +1);
        m_str[m_size++] = c;
    }


    size_t size() { return m_size; }

    char at(size_t i) { return m_str[i]; }

    bool operator==(String a){
        if (a.size() != size()) return false;

        if (memcmp(a.m_str, m_str, m_size) != 0) return false;

        return true;
    }

    bool operator==(const char* a){
        if (strlen(a) != size()) return false;
        if (memcmp(a, m_str, m_size) != 0) return false;
        return true;
    }

    int find(String& str, unsigned int start=0){
        return find(str.c_str(), start);
    }

    int find(char* str, unsigned int start=0){
        unsigned int len = strlen(str);
        if (start + len > m_size) return -1;

        for (unsigned int i=start; i<m_size; i++){
            if (memcmp(m_str+i, str, len) == 0) return i;
        }
        return -1;
    }

    String substr(unsigned int start, unsigned int len){
        String s;
        for (unsigned int i=start; i<(start+len); i++){
            s.append(m_str[i]);
        }
        return s;
    }

    String substr(unsigned int start){
        String s;
        for (unsigned int i=start; i<m_size; i++){
            s.append(m_str[i]);
        }
        return s;
    }

    bool operator< (const String& a){
        return strcmp(m_str, a.m_str);
    }

    char* c_str(){
        m_str[m_size] = 0;
        return m_str;
    }

    void resize(unsigned int size){
        char * new_buf = new char[size];

        for (unsigned int i=0; i<m_size; i++){
            memcpy(new_buf, m_str, m_size);
        }
        if (m_size>0)
            delete[] m_str;
        m_str = new_buf;
    }

private:
    char* m_str;
    size_t m_size;

};



#endif // string_H

