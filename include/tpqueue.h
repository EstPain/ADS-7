// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  private:
    struct st1 {
     T data;
     st1 *next;
     st1 *prev;
    };
    TPQueue::st1 *create(const T &data) {
     st1 * itm = new st1;
     itm->data = data;
     itm->next = nullptr;
     itm->prev = nullptr;
     return itm;
    }
    st1 *head;
    st1 *tail;
    st1 *current;

 public:
    T pop() {
     if (head) {
       st1 *temp = head->next;
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
     st1 *t = head;
     st1 *item = create(data);
     while (t && t->data.prior >= data.prior)
       t = t->next;
     if (!t && head) {
       tail->next = item;
       tail->next->prev = tail;
       tail = item;
     } else if (!t && !head) {
         head = tail = item;
       } else if (!t->prev) {
           t->prev = item;
           item->next = t;
           head = item;
         } else {
             t->prev->next = item;
             item->prev = t->prev;
             item->next = t;
             t->prev = item;
           }
    }
};

struct SYM {
  char ch;
  int prior;
};

explicit SYM(char _ch = '0', int _prior = 0) : ch(_ch), prior(_prior) {}
#endif  // INCLUDE_TPQUEUE_H_
