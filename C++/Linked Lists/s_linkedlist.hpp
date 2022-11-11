/*

    s_linkedlist.hpp

    Created by Arturo Olivares on 11/11/2022.
    Copyright © 2022 Arturo Olivares. All rights reserved.

*/

#ifndef  SLINKEDLIST_HPP
#define SLINKEDLIST_HPP

#include <iostream>

template <typename T>
class sll_node{
    private:
        T datum;
        sll_node<T>* next;
    public:
        sll_node(T datum){
            this -> datum = datum;
            next = nullptr;
        }
        sll_node(T datum, sll_node<T>* next){
            this -> datum = datum;
            this -> next = next;
        }
        T get_datum(){
            return datum;
        }
        sll_node<T>* get_next(){
            return next;
        }
        void set_datum(T datum){
            this -> datum = datum;
        }
        void set_next(sll_node<T>* next){
            this -> next = next;
        }
};

template <typename T>
class s_linkedlist{
    private:
        size_t size;
        sll_node<T>* head;
    public:
        s_linkedlist(){
            size = 0;
            head = nullptr;
        }
        void add(T datum, size_t pos){
            pos--;
            if (pos > size){
                std::cout << "[ERROR]: Error index out of bonds.\n";
                return;
            }else if (pos == 0){
                add_first(datum);
            }else if (pos == size){
                add_last(datum);
            }else{
                sll_node<T>* traversal = head;
                for(int i = 1; i<pos; i++){
                    traversal = traversal->get_next();
                }
                traversal->set_next(new sll_node<T>(datum, traversal->get_next()));
                size++;
            }
        }
        void add_first(T datum){
            head = new sll_node<T>(datum, head);
            size++;
        }
        void add_last(T datum){
            if(size == 0){
                add_first(datum);
            }else{
                sll_node<T>* traversal = head;
                while(traversal->get_next() != nullptr){
                    traversal = traversal->get_next();
                }
                traversal->set_next(new sll_node<T>(datum));
                size++;
            }
        }
        void del(size_t pos){
            if (pos > size){
                std::cout << "[ERROR]: Error index out of bonds.\n";
                return;
            }
            else if(pos == 1){
                delete_first();
            }else if(pos == size){
                delete_last();
            }else{
                sll_node<T>* traversal = head;
                for(size_t i = 1; i<pos-1; i++){
                    traversal = traversal->get_next();
                }
                sll_node<T>* aux = traversal->get_next();
                traversal->set_next(traversal->get_next()->get_next());
                delete aux;
                size--;
            }
        }
        void delete_all(){
            sll_node<T>* aux = head;
            while(head!=nullptr){
                head = head->get_next();
                delete aux;
                size--;
                aux = head;
            }
            head = nullptr;
        }
        void delete_first(){
            if(size!=0){
                sll_node<T>* temp = head;
                head = temp->get_next();
                delete temp;
                size--;
            }
        }
        void delete_last(){
            if(size == 1){
                delete_first();
            }else{
                sll_node<T>* traversal = head;
                while(traversal->get_next()->get_next()!=nullptr){
                    traversal = traversal->get_next();
                }
                delete traversal->get_next();
                traversal->set_next(nullptr);
                size--;
            }
        }
        T get_at(size_t pos){
            if (pos > size){
                std::cout << "[ERROR]: Error index out of bonds.\n";
                return;
            }
            sll_node<T>* traversal = head;
            for(size_t i=1; i<size;i++){
                traversal = traversal->get_next();
            }
            return traversal->get_datum();
        }
        size_t get_size(){
            return size;
        }
        bool is_empty(){
            return (size == 0) ? true : false;
        }
        void modify_at(T datum, size_t pos){
            if (pos > size){
                std::cout << "[ERROR]: Error index out of bonds.\n";
                return;
            }
            sll_node<T>* traversal = head;
            for(size_t i=1; i<size; i++){
                traversal = traversal->get_next();
            }
            traversal->set_datum(datum);
        }
        void print(){
            sll_node<T>* traversal = head;
            for(size_t i = 0; i<size; i++){
                std::cout << traversal->get_datum() << " -> ";
                traversal = traversal->get_next();
            }
            std::cout << "null\n";
        }
        void swap(size_t pos, size_t pos2){
            if (pos > size || pos2 > size){
                std::cout << "[ERROR]: Error index out of bonds.\n";
                return;
            }
            sll_node<T> *traversal = head, *traversal2 = head;
            for(size_t i=1; i<pos; i++){
                traversal = traversal->get_next();
            }
            for(size_t i=1; i<pos2; i++){
                traversal2 = traversal2->get_next();
            }
            T temp = traversal->get_datum();
            traversal->set_datum(traversal2->get_datum());
            traversal2->set_datum(temp);
        }
};


#endif
