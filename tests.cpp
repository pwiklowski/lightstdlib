#include <assert.h>
#include "String.h"
#include "List.h"
#include "Map.h"
#include <iostream>
#include "log.h"
#include "cbor.h"

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



    String splitTest("1,2,3,4");

    List<String> res = splitTest.split(",");

    assert(res.size() == 4);





}


void testList(){
    List<int> a;

    assert(a.size() == 0);
    a.append(1);
    assert(a.size() == 1);
    a.remove(0);
    assert(a.size() == 0);

    a.append(2);
    assert(a.size() == 1);

    a.append(3);
    assert(a.size() == 2);




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


    List<uint8_t> l;
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);
    l.append(5);

    unsigned int counter = 0;

    for (const auto &val :l){
        int a = val;
        std::cout << a << std::endl;
        counter ++;

    }

    assert(counter == l.size());

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



   List<uint8_t> l2;

   l2 = l;

   assert(l2.size() == 5);
   assert(l2.at(0) == 1);
   assert(l2.at(1) == 2);
   assert(l2.at(2) == 3);
   assert(l2.at(3) == 4);
   assert(l2.at(4) == 5);


   l2.remove(0);
   assert(l2.size() == 4);
   assert(l2.at(0) == 2);
   assert(l2.at(1) == 3);
   assert(l2.at(2) == 4);
   assert(l2.at(3) == 5);


   l2.remove(3);
   assert(l2.size() == 3);
   assert(l2.at(0) == 2);
   assert(l2.at(1) == 3);
   assert(l2.at(2) == 4);


   l2.remove(1);
   assert(l2.size() == 2);
   assert(l2.at(0) == 2);
   assert(l2.at(1) == 4);



   List<uint16_t> b;
   b.append(0);
   b.append(1);
    b.remove(1);
   b.append(2);
   b.append(3);

}

void testMap(){
    Map<String, int> map;

    map.insert("test1", 1);

    assert(map.get("test1") == 1);

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


    map.remove("test2");

    assert(map.get("test1") == 1);
    assert(map.get("test3") == 3);
    assert(map.get("test4") == 4);
    assert(map.get("test5") == 5);

    assert(map.has("test2") == false);




    map.insert("test3", 33);
    assert(map.get("test3") == 33);

    Map<String, int> test;

    test.insert("test1", 1);
    assert(test.get("test1") == 1);
    assert(test.size() == 1);

    test.insert("test1", 1);
    assert(test.get("test1") == 1);
    assert(test.size() == 1);

    test.insert("test2", 2);
    assert(test.get("test2") == 2);
    assert(test.size() == 2);

    test.insert("test2", 2);
    assert(test.get("test2") == 2);
    assert(test.size() == 2);


    test.insert("test2", 4);
    assert(test.get("test2") == 4);
    assert(test.size() == 2);

    Map<cbor, cbor> t;

    t.insert("test1",1);



    cbor aa = t.get("test1");

    assert(t.get("test1").toInt() == 1);
    assert(t.size() == 1);


    t.insert("test1", 4);

    assert(t.get("test1").toInt() == 4);
    assert(t.size() == 1);


}

void testCbor(){
    cbor trzy(3);

    cbor czt(4);

    assert(trzy == trzy);
    assert(trzy != czt);

    assert(*new cbor("sdf") != *new cbor(4));

    assert(*new cbor("dupa") != *new cbor("dupa2"));
    assert(*new cbor("dupa") == *new cbor("dupa"));

    cbor v(CBOR_TYPE_ARRAY);
    v.append("href");
    v.append("rt");


    cbor root(CBOR_TYPE_ARRAY);
    cbor device(CBOR_TYPE_MAP);

    device.append("di", "0685B960-736F-46F7-BEC0-9E6CBD61ADC1");
    device.append("n","name");
    device.append("test", 45);

    cbor links(CBOR_TYPE_ARRAY);

    cbor val(CBOR_TYPE_MAP);

    val.append("href", "href");
    val.append("rt", "rt");
    val.append("if", "if");
    val.append("type", "application/cbor");

    links.append(val);

    device.append("links", links);

    root.append(device);

    std::cout << cbor::toJsonString(&root).c_str() << std::endl;


    String str("{\"rt\": \"oic.r.light.dimming\", \"dimmingSetting\": 5, \"range\": \"0,255\"}");
    char* p = str.c_str();

    cbor obj1;
    obj1.parse_value(str.c_str());

    std::cout << cbor::toJsonString(&obj1).c_str() << std::endl;


    cbor n1;
    n1.parse_number("123");
    assert(123 == n1.toInt());

    n1.parse_number(" 123");
    assert(123 == n1.toInt());

    n1.parse_number("123 ");
    assert(123 == n1.toInt());

    cbor n2;
    n2.parse_number("-123");

    int a = n2.toInt();
    assert(-123 == n2.toInt());


    cbor s1;
    s1.parse_string("\"rt\"");


    cbor arr;
    arr.parse_array("[1,2,3,4,5,6]");

    assert(arr.toArray()->size() == 6);
    int i = arr.toArray()->at(0).toInt();
    assert(arr.toArray()->at(0).toInt() == 1);
    i = arr.toArray()->at(1).toInt();
    assert(arr.toArray()->at(1).toInt() == 2);
    assert(arr.toArray()->at(2).toInt() == 3);
    assert(arr.toArray()->at(3).toInt() == 4);
    assert(arr.toArray()->at(4).toInt() == 5);
    assert(arr.toArray()->at(5).toInt() == 6);


}

int main()
{
   testString();
   testList();
   testMap();
   testCbor();
////dodac cos na kopiowanie list

    return 0;
}

