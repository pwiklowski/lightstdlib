#ifndef LISTA_H
#define LISTA_H

#include <cstddef>

template <class T> class List;



template <class T> class Node
{
public:
    Node(T val, Node<T>* next){
        this->val = val;
        this->next = next;
    }
    T val;
    Node<T> *next;
    typedef T value_type;
};

template <typename Node> class ListIterator
{
    friend class List<typename Node::value_type>;
    Node* p;
public:
    ListIterator(Node* p) : p(p) {}
    ListIterator(const ListIterator& other) : p(other.p) {}
    //ListIterator& operator=(ListIterator other) { std::swap(p, other.p); return *this; }
    ListIterator& operator++() { p = p->next; return *this;}
    ListIterator& operator++(int) { p = p->next; return *this;}
    bool operator==(const ListIterator& other) { return p == other.p; }
    bool operator!=(const ListIterator& other) { return p != other.p; }
    typename Node::value_type& operator*() const { return p->val; }


};


template <class T> class List{
public:
    typedef ListIterator<Node<T> > iterator;
    typedef ListIterator<const Node<T> > const_iterator;


    List<T>(){
        first = 0;
        m_last = 0;
        m_size = 0;
    }

    List<T>(const List<T>& l){
        first = 0;
        m_last = 0;
        m_size = 0;
        Node<T>* current = l.first;
        while (current != NULL) {
            this->append(current->val);
            current = current->next;
        }
    }



    List<T>& operator = (const List<T> & l) {
        first = 0;
        m_last = 0;
        Node<T>* current = l.first;
        while (current != NULL) {
            this->append(current->val);
            current = current->next;
        }
        m_size = l.m_size;

        return *this;
    }
    ~List<T>(){
        Node<T>* temp = first;
        while(temp != NULL)
        {
            temp = temp->next;
            delete first;
            first = temp;
        }
        first = 0;
        m_last = 0;
    }

    bool operator == (const List<T>& l) const {
        if (l.m_size != m_size) return false;

        Node<T>* temp1 = first;
        Node<T>* temp2 = l.first;
        while(temp1 != NULL)
        {
            if (temp1->val != temp2->val) return false;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }


        return true;
    }

    void append(const T item){
        Node<T>* new_last = new Node<T>(item, 0);


        if (isEmpty()) {
            first = new_last;
        }
        else {
            m_last->next = new_last;
        }

        m_last = new_last;
        m_size++;
    }

    bool isEmpty(){
        return m_size == 0;
    }

    void clear(){
        Node<T>* temp = first;
        while(temp != 0)
        {
            Node<T>* node = temp;
            temp = temp->next;
            delete node;
        }
        m_size = 0;
        first = 0;
        m_last = 0;
    }


    void replace(size_t item, T value){

        Node<T>* temp = first;

        unsigned int counter = 0;
        while(temp != 0)
        {
            if (counter == item){
                temp->val = value;
                return;
            }
            temp = temp->next;
            counter++;
        }
    }


    void remove(unsigned int item){
        if (item > m_size) return;

        Node<T>* temp = first;


        if (item == 0){
            first = temp->next;
            delete temp;
            m_size--;
        }else if (item == (m_size -1)){
            Node<T>* node = getNode(item -1);
            node->next = 0;
            delete m_last;
            m_last = node;
            m_size--;

        }else{
            unsigned int counter = 0;
            while(temp != 0)
            {
                if (counter == (item-1)){
                    Node<T>* node = temp->next;
                    temp->next = node->next;

                    delete node;
                    m_size--;
                    return;
                }
                temp = temp->next;
                counter++;
            }
        }



    }

    Node<T>* getNode(unsigned int item){
        Node<T>* temp = first;
        unsigned int counter = 0;
        while(temp != NULL)
        {
            if (counter == item){
                return temp;
            }
            temp = temp->next;
            counter++;
        }
        return nullptr;
    }


    const_iterator begin() const{
        return const_iterator(first);
    }


    const_iterator end() const{
        return 0;//const_iterator(last);
    }

    iterator begin() {
        return iterator(first);
    }


    iterator end() {
        return 0;//iterator(last);
    }

    size_t size() const{
        return m_size;
    }

    bool has(T value){
        Node<T>* temp = first;

        while(temp != NULL)
        {
            if (temp->val == value) return true;
            temp = temp->next;
        }
        return false;
    }

    T& at(unsigned int i) const{
        Node<T>* temp = first;

        unsigned int counter = 0;
        while(temp != NULL)
        {
            if (counter == i){
                return  temp->val;
            }
            temp = temp->next;
            counter++;
        }
    }

private:
    Node<T> *first;
    Node<T> *m_last;
    size_t m_size;
};



#endif
