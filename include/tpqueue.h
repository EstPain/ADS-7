// Copyright 2022 NNTU-CS
#include <string>
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>

class TPQueue {
 private:
    struct structItem {
     T data;
     structItem *next;
     structItem *prev;
    };
    TPQueue::structItem *create(const T &data) {
     structItem * item = new structItem;
     item->data = data;
     item->next = nullptr;
     item->prev = nullptr;
     return item;
    }
    structItem *head;
    structItem *tail;
    structItem *current;

 public:
    T pop() {
     if (head) {
       structItem *temp = head->next;
       if (temp)
         temp->prev = nullptr;
       T data = head->data;
       delete head;
       head = temp;
       return data;
     } else {
         throw std::string("Empty!");
       }
    }
    void push(const T& data) {
     structItem *temp = head;
     structItem *item = create(data);
     while (temp && temp->data.prior >= data.prior)
       temp = temp->next;
     if (!temp && head) {
       tail->next = item;
       tail->next->prev = tail;
       tail = item;
     } else if (!temp && !head) {
         head = tail = item;
       } else if (!temp->prev) {
           temp->prev = item;
           item->next = temp;
           head = item;
         } else {
             temp->prev->next = item;
             item->prev = temp->prev;
             item->next = temp;
             temp->prev = item;
           }
    }
struct SYM {
  char ch;
  int prior;
};

explicit SYM(char _ch = '0', int _prior = 0) : ch(_ch), prior(_prior) {}
#endif  // INCLUDE_TPQUEUE_H_
