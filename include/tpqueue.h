// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Item {
    T data;
    Item* next;
    Item(const T& value) : data(value), next(nullptr) {}
  };
  Item* head;

 public:
  TPQueue() : head(nullptr) {}
  ~TPQueue() {
    while (!isEmpty()) {
      pop();
    }
  }
  bool isEmpty() const {
    return head == nullptr;
  }
  void push(const T& value) {
    Item* newItem = new Item(value);
    if (!head || value.prior > head->data.prior) {
      newItem->next = head;
      head = newItem;
    } else {
      Item* current = head;
      while (current->next && current->next->data.prior >= value.prior) {
        current = current->next;
      }
      newItem->next = current->next;
      current->next = newItem;
    }
  }
  T pop() {
    if (!head) {
      throw "Queue is empty!";
    }
    Item* temp = head;
    T result = temp->data;
    head = head->next;
    delete temp;
    return result;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
