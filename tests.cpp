#include <assert.h>
#include "String.h"
#include "List.h"
#include "Map.h"
#include <iostream>
#include "log.h"

void testString(){
    String* s = new String();
    s->append("test");

    assert(s->size() == 4);

    char* x = s->c_str();

    assert(strlen(s->c_str()) == 4);


    assert(*s == "test");

    s->append('1');
    assert(s->size() == 5);
    assert(*s == "test1");
    assert(strlen(s->c_str()) == 5);
    delete s;

    String* s2 = new String("test2");

    assert(s2->size() == 5);
    assert(*s2 == "test2");

    delete s2;


    String* c = new String("moreComplicatedString");

    int pos = c->find("Complicated");
    assert(pos == 4);

    int pos2 = c->find("C");
    assert(pos2 == 4);

    pos2 = c->find("Stringg");
    assert(pos2 == -1);


    String t1 = c->substr(0, 4);
    String t2 = c->substr(4, 4);
    String t3 = c->substr(4);
    delete c;

    String str("There are two needles in this haystack with needles.");
    String str2 ("needle");

    // different member versions of find in the same order as above:
    size_t found = str.find(str2);
    assert(found == 14);

    found = str.find("needles",found+1);
    assert(found == 44);

    found=str.find("haystack");
    assert(found == 30);

    found=str.find(".");
    assert(found == 51);
}


void testList(){

    List<int> lista;

    assert(lista.size() == 0);

    lista.append(1);
    assert(lista.size() == 1);
    int t = lista.at(0);
    assert(lista.at(0) == 1);

    lista.append(2);
    assert(lista.size() == 2);
    assert(lista.at(0) == 1);
    assert(lista.at(1) == 2);

    lista.append(3);
    lista.append(4);
    assert(lista.size() == 4);

    assert(lista.at(0) == 1);
    assert(lista.at(1) == 2);
    assert(lista.at(2) == 3);
    assert(lista.at(3) == 4);
    lista.remove(2);

    assert(lista.size() == 3);
    assert(lista.at(0) == 1);
    assert(lista.at(1) == 2);
    assert(lista.at(2) == 4);


    lista.remove(0);
    assert(lista.size() == 2);
    assert(lista.at(0) == 2);
    assert(lista.at(1) == 4);

    lista.remove(1);
    assert(lista.at(0) == 2);


    lista.clear();
    assert(lista.size() == 0);


    List<int> l;
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);
    l.append(5);

    for ( auto i = l.begin(); i !=l.end(); i++ ) {
        int test = *i;
        std::cout << test << std::endl;

    }


    List<String> li;
    li.append("test1");
    li.append("test2");
    li.append("test3");
    li.append("test4");
    li.append("test5");
    for (String k: li) std::cout << k.c_str() << std::endl;

}

void testMap(){
    Map<String, int> map;

    map.insert("test1", 1);

    assert(map.get("test1") == 1);

   //map.remove("test1");

 //   assert(map.get("test1") == 0);

    map.insert("test2", 2);
    map.insert("test3", 3);
    map.insert("test4", 4);
    map.insert("test5", 5);

    int a = map.get("test1");
    a = map.get("test2");
    a = map.get("test3");
    a = map.get("test4");
    a = map.get("test5");

    for (String k: map){
        std::cout << k.c_str();
        std::cout << std::endl;
    }



    assert(map.get("test1") == 1);
    assert(map.get("test2") == 2);
    assert(map.get("test3") == 3);
    assert(map.get("test4") == 4);
    assert(map.get("test5") == 5);

}



int main()
{
   testString();
   testList();
   testMap();


    return 0;
}

