class linked_list {
public:
    linked_list() : head(nullptr) {}
    ~linked_list() {
        node *p = head;
        while (p != nullptr) {
            node *tmp = p;
            p = p->next;
            delete tmp;
        }
    }
    void add(int data) {
        node *new_node = new node{data, nullptr};
        if (head == nullptr) {
            head = new_node;
        } else {
            node *p = head;
            while (p->next != nullptr) {
                p = p->next;
            }
            p->next = new_node;
        }
    }
    int operator[](int index) {
        node *p = head;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        return p->data;
    }
    bool is_found(int value)  {
        node *p = head;
        while (p != nullptr) {
            if (p->data == value) {
                return true;
            }
            p = p->next;
        }
        return false;
    }
    void remove(int value) {
        node *p = head, *prev = nullptr;
        while (p != nullptr) {
            if (p->data == value) {
                if (prev == nullptr) { 
                    head = p->next;
                    delete p;
                    p = head;
                } else { 
                    prev->next = p->next;
                    node *tmp = p;
                    p = p->next;
                    delete tmp;
                }
            } else {
                prev = p;
                p = p->next;
            }
        }
    }
    void update(int old_value, int new_value) {
        node *p = head;
        while (p != nullptr) {
            if (p->data == old_value) {
                p->data = new_value;
            }
            p = p->next;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, linked_list& list) {
    node *p = list.head;
    while (p != nullptr) {
        os << p->data << " "; 
        p = p->next;
    }
    return os;
}

    friend std::istream& operator>>(std::istream& is, linked_list& list) {
        int data;
        while (is >> data) {
            list.add(data);
            if (is.peek() == '\n') { 
                break;
            }
        }
    return is;
    }

private:
    struct node {
        int data;
        node *next;
    };
    node *head;
};
