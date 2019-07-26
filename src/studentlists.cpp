#include <iostream>
#include <algorithm> // For string transform().
#include "functions.hpp"


// StudentList Constructor
StudentList::StudentList(){
    head_ = nullptr;
    tail_ = nullptr;
    list_length_ = 0;
}
StudentList::StudentList(const StudentList &old_list)
{
    Node** new_tail = &head_;
    for(Node* old_ptr = old_list.head_; old_ptr; old_ptr = old_ptr->next_)
    {
        (*new_tail) = new Node(*old_ptr);
        this->tail_ = *new_tail;
        new_tail = &((*new_tail)->next_);
    }
    this->list_length_ = old_list.list_length_;
}

// StudentList Member Functions
void StudentList::NewStudent(Student* new_student){
    // '->' operator is synonymous to '.' on a pointer.
    // ie. 'temp -> a_student_' is same as '(*temp).a_student_'
    // Mainly to save typing brackets too often, since brackets are needed
    // to resolve the '*' before the '.' operator.
    Node *temp = new Node;
    if ((new_student != NULL) && (new_student != nullptr)) {
        temp -> a_student_ = new_student;
        temp -> next_ = nullptr;
        if(head_ == nullptr) {
            head_ = temp;
            tail_ = temp;
            temp = nullptr;
        }
        else {
            InsertOverall(new_student);
        }
        list_length_++;
    }
}
void StudentList::InsertOverall(Student* new_student){
    CompareStudent comparator(kOverall); // found in functions.hpp/cpp
    Node *temp = new Node;
    Node *current = new Node;
    Node *previous = new Node;
    current = head_;
    temp -> a_student_ = new_student;
    temp -> next_ = nullptr;

    bool sorted = false;
    if(comparator(*temp->a_student_,*current->a_student_)) { // new first student case
        temp -> next_ = head_;
        head_ = temp;
        sorted = true;
    }
    else { // all other cases
        while(sorted != true) {
            if(current != tail_) { // not a match (continue)
                if(comparator(*current->a_student_,*temp->a_student_)) {
                    previous = current;
                    current = current -> next_;
                }
                else { // found match
                    previous -> next_ = temp;
                    temp -> next_ = current;
                    sorted = true;
                }
            }
            else if(comparator(*temp->a_student_,*current->a_student_)) { // compare final position
                previous -> next_ = temp;
                temp -> next_ = current;
                sorted = true;
            }
            else { // reached end of list

                tail_ -> next_ = temp;
                tail_ = temp;
                sorted = true;
            }
        }
    }
}
void StudentList::DeleteStudent(int target){ // best case O(1), worst case O(N)
    if((target == 0)||(target == 1)) {DeleteFirst();} // O(1)
    else if(target == list_length_) {DeleteLast();} // O(N)
    else { // best case O(1), worst case O(N)
        Node *previous = new Node;
        Node *current = new Node;
        current = head_;
        for(int i=1; i<target; i++) {
            previous = current;
            current = current -> next_;
        }
        previous -> next_ = current -> next_;
        list_length_--;
    }
}
void StudentList::DeleteFirst()
{
    Node *temp = new Node;
    temp = head_;
    head_ = head_ -> next_;
    delete temp;
    list_length_--;
}
void StudentList::DeleteLast()
{
    Node *previous = new Node;
    Node *current = new Node;
    current = head_;

    while(current -> next_ != nullptr)
    {
      previous = current;
      current = current -> next_;
    }

    tail_ = previous;
    previous -> next_ = nullptr;
    delete current;
    list_length_--;
}
void StudentList::PrintList(){
    Node *temp = new Node;
    temp = head_;

    cout << list_length_ << endl;

    for(int i=0; i<list_length_; i++){
        cout << i+1 << *temp -> a_student_ << endl;
        temp = temp -> next_;
    }
}
