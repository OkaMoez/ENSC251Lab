#include <iostream>
#include <algorithm> // For string transform().
#include "functions.hpp"


// StudentList Constructor
StudentList::StudentList()
{
    head_ = nullptr;
    tail_ = nullptr;
    list_length_ = 0;
}

// StudentList Member Functions
void StudentList::NewStudent(Student* new_student)
{
    // '->' operator is synonymous to '.' on a pointer.
    // ie. 'temp -> a_student_' is same as '(*temp).a_student_'
    // Mainly to save typing brackets too often, since brackets are needed
    // to resolve the '*' before the '.' operator.
    Node *temp = new Node;
    temp -> a_student_ = new_student;
    temp -> next_ = nullptr;
    if(head_ == nullptr)
    {
        head_ = temp;
        tail_ = temp;
        temp = nullptr;
    }
    else
    {
        InsertOverall(new_student);
    }
    list_length_++;
}
void StudentList::InsertOverall(Student* new_student)
{
    CompareStudent comparator(kCgpa); // found in functions.hpp/cpp
    Node *temp = new Node;
    Node *current = new Node;
    Node *previous = new Node;
    current = head_;
    temp -> a_student_ = new_student;
    temp -> next_ = nullptr;

    bool sorted = false;
    if(comparator(*temp->a_student_,*current->a_student_)) // new first student case
    {

        //cout << "case0" << endl;
        temp -> next_ = head_;
        head_ = temp;
        sorted = true;
    }
    else // all other cases
    {
        while(sorted != true)
        {
            if(current != tail_){
                // go until a match
                if(comparator(*current->a_student_,*temp->a_student_))
                {
                    //cout << "case1 " << endl;
                    previous = current;
                    current = current -> next_;
                }
                // found match
                else //if(comparator(*temp->a_student_,*current->a_student_))
                {
                    //cout << "case2.0" << endl;
                    previous -> next_ = temp;
                    temp -> next_ = current;
                    sorted = true;
                }
            }
            else if(comparator(*temp->a_student_,*current->a_student_))
            {
                //cout << "case2.1" << endl;
                previous -> next_ = temp;
                temp -> next_ = current;
                sorted = true;
            }
            // reached end of list
            else
            {
                //cout << "case3" << endl;
                tail_ -> next_ = temp;
                tail_ = temp;
                sorted = true;
            }
        }
    }
}
void StudentList::InsertFirst(Student* new_student) // reduntant?
{
    Node *temp = new Node;
    temp -> a_student_ = new_student;
    temp -> next_ = head_;
    head_ = temp;
    list_length_++;
}
void StudentList::InsertLast(Student* new_student) // reduntant?
{
    NewStudent(new_student);
}
void StudentList::InsertStudent(int target, Student* new_student) // reduntant?
{
    if (target == 1) {InsertFirst(new_student);}
    else if (target == list_length_) {InsertLast(new_student);}
    else
    {
        Node *previous = new Node;
        Node *current = new Node;
        Node *temp = new Node;
        current = head_;

        for(int i=1; i<target; i++)
        {
            previous = current;
            current = current -> next_;
        }

        temp -> a_student_ = new_student;
        previous -> next_ = temp;
        temp -> next_ = current;
        list_length_++;
    }
}
void StudentList::DeleteFirst() // part 2
{
    Node *temp = new Node;
    temp = head_;
    head_ = head_ -> next_;
    delete temp;
    list_length_--;
}
void StudentList::DeleteLast() // part 2
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
void StudentList::DeleteStudent(int target) // part 2
{
    if(target == 1) {DeleteFirst();}
    else if(target == list_length_) {DeleteLast();}
    else
    {
        Node *previous = new Node;
        Node *current = new Node;
        current = head_;
        if(target == 0) {DeleteFirst();}
        else if(target == list_length_) {DeleteFirst();}
        else{
            for(int i=1; i<target; i++)
            {
                previous = current;
                current = current -> next_;
            }

            previous -> next_ = current -> next_;
            list_length_--;
        }
    }
}
/*
void StudentList::PrintTarget(int target){ // for testing specifically
    Node *previous = new Node;
    Node *current = new Node;
    current = head_;

    for(int i=1; i<target; i++){
        previous = current;
        current = current -> next_;
    }

    cout << current -> a_student_ << endl;
}
*/
void StudentList::PrintList(){
    Node *temp = new Node;
    temp = head_;

    cout << list_length_ << endl;

    for(int i=0; i<list_length_; i++){
        cout << i+1 << *temp -> a_student_ << endl;
        temp = temp -> next_;
    }
}
