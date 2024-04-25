#include "../external_libs/Linked_List/include/linked_list/linked_list.h"
#include <iostream>
#include <string>
#include <iomanip>

template <typename Object>
class Stack {
private:
    int size;

public:
    Linked_List<Object> stackList;

    Stack() : stackList() {
        size = 0;
    }

    int getSize() {
        return size;
    }

    void push(Object obj) {
        stackList.addNode(obj);
        size++;
    }

    void push(Object* obj) {
        stackList.addNode(obj);
        size++;
    }


    template <typename T = Object>
    typename std::enable_if<!std::is_pointer<T>::value, T>::type pop() {
        static_assert(!std::is_pointer<Object>::value, "Non-pointer type expected");
        if (size == 0) {
            throw std::out_of_range("Stack is empty");
        }
        Object* returnNode = stackList.getObjAtIndex(size - 1);
        stackList.deleteNode(returnNode);
        size--;

        return *returnNode;
    }


    template <typename T = Object>
    typename std::enable_if<std::is_pointer<T>::value, T>::type pop() {
        static_assert(std::is_pointer<Object>::value, "Pointer type expected");
        if (size == 0) {
            throw std::out_of_range("Stack is empty");
        }
        Object* returnNode = stackList.getObjAtIndex(size - 1);
        stackList.deleteNode(*returnNode);
        size--;

        return *returnNode;
    }

    
    template <typename T = Object, typename std::enable_if<!std::is_same<T, int>::value && 
    !std::is_same<T, char>::value && 
    !std::is_same<T, float>::value && 
    !std::is_same<T, double>::value && 
    !std::is_same<T, bool>::value && 
    !std::is_same<T, short>::value && 
    !std::is_same<T, long>::value && 
    !std::is_same<T, long long>::value && 
    !std::is_same<T, unsigned short>::value && 
    !std::is_same<T, unsigned int>::value && 
    !std::is_same<T, unsigned long>::value && 
    !std::is_same<T, unsigned long long>::value>::type* = nullptr>
    void printStack() {
        for(int i = size - 1; i >= 0; i--) {
            if (i == size - 1) {
                std::cout << "Stack Top:";
                std::cout << "\t" << *(stackList.getObjAtIndex(i)) << "\n";
            }
            else if (i == 0) {
                std::cout << "Stack Base:";
                std::cout << "\t"  << *(stackList.getObjAtIndex(i)) << "\n";
            }
            else {
                std::cout << "\t\t"  << *(stackList.getObjAtIndex(i)) << "\n";
            }
            

        }

        //std::cout << "----------" << "\n";
    }

    template <typename T = Object, typename std::enable_if<std::is_same<T, int>::value || 
    std::is_same<T, char>::value || 
    std::is_same<T, float>::value || 
    std::is_same<T, double>::value || 
    std::is_same<T, bool>::value || 
    std::is_same<T, short>::value || 
    std::is_same<T, long>::value || 
    std::is_same<T, long long>::value || 
    std::is_same<T, unsigned short>::value || 
    std::is_same<T, unsigned int>::value || 
    std::is_same<T, unsigned long>::value || 
    std::is_same<T, unsigned long long>::value>::type* = nullptr>
    void printStack() {
        for(int i = size - 1; i >= 0; i--) {
            if (i == size - 1) {
                std::cout << "Stack Top:";
                std::cout << "\t"  << stackList.getObjAtIndex(i) << "\n";
            }
            else if (i == 0) {
                std::cout << "Stack Base:";
                std::cout << "\t"  << stackList.getObjAtIndex(i) << "\n";
            }
            else {
                std::cout << "\t\t"  << stackList.getObjAtIndex(i) << "\n";
            }
            

        }

        //std::cout << "----------" << "\n";
    }
    



};