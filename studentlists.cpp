#include <iostream>
#include "studentlists.hpp"


// StudentList Constructor
DStudentList::DStudentList()
{
    head_ = nullptr;
    tail_ = nullptr;
    list_length_ = 0;
}

// StudentList Member Functions
void DStudentList::NewStudent(DomesticStudent new_student)
{
    // '->' operator is synonymous to '.' on a pointer.
    // ie. 'temp -> a_student_' is same as '(*temp).a_student_'
    // Mainly to save typing brackets too often, since brackets are needed
    // to resolve the '*' before the '.' operator.
    DNode *temp = new DNode;
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
        //tail_ -> next_ = temp;
        //tail_ = temp;
    }
    list_length_++;
}
void DStudentList::InsertOverall(DomesticStudent new_student)
{
    CompareStudent comparator(kOverall);
    DNode *temp = new DNode;
    DNode *current = new DNode;
    DNode *previous = new DNode;
    current = head_;
    temp -> a_student_ = new_student;
    temp -> next_ = nullptr;

    bool sorted = false;
    if(comparator(temp->a_student_,current->a_student_)) // new first student case
    {
        temp -> a_student_ = new_student;
        temp -> next_ = head_;
        head_ = temp;
        sorted = true;
    }
    // all other cases
    else
    {
        while(sorted != true)
        {
            // go until a match
            //if((current->a_student_.cgpa() >= temp->a_student_.cgpa())&&(current!=tail_))
            if(comparator(current->a_student_,temp->a_student_)&&(current!=tail_))
            {
                previous = current;
                current = current -> next_;
            }
            // found match
            //else if((current->a_student_.cgpa() < temp->a_student_.cgpa())&&(current!=tail_))
            else if(comparator(temp->a_student_,current->a_student_)&&(current!=tail_))
            {
                temp -> a_student_ = new_student;
                previous -> next_ = temp;
                temp -> next_ = current;
                sorted = true;
            }
            // reached end of list
            else //if(current == tail_)
            {
                tail_ -> next_ = temp;
                tail_ = temp;
                sorted = true;
            }
        }
    }
}
void DStudentList::InsertFirst(DomesticStudent new_student)
{
    DNode *temp = new DNode;
    temp -> a_student_ = new_student;
    temp -> next_ = head_;
    head_ = temp;
    list_length_++;
}
void DStudentList::InsertLast(DomesticStudent new_student)
{
    NewStudent(new_student);
}
void DStudentList::InsertStudent(int target, DomesticStudent new_student)
{
    if (target == 1) {InsertFirst(new_student);}
    else if (target == list_length_) {InsertLast(new_student);}
    else
    {
        DNode *previous = new DNode;
        DNode *current = new DNode;
        DNode *temp = new DNode;
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
void DStudentList::DeleteFirst()
{
    DNode *temp = new DNode;
    temp = head_;
    head_ = head_ -> next_;
    delete temp;
    list_length_--;
}
void DStudentList::DeleteLast()
{
    DNode *previous = new DNode;
    DNode *current = new DNode;
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
void DStudentList::DeleteStudent(int target)
{
    if(target == 1) {DeleteFirst();}
    else if(target == list_length_) {DeleteLast();}
    else
    {
        DNode *previous = new DNode;
        DNode *current = new DNode;
        current = head_;

        for(int i=1; i<target; i++)
        {
            previous = current;
            current = current -> next_;
        }

        previous -> next_ = current -> next_;
        list_length_--;
    }
}
void DStudentList::PrintTarget(int target)
{
    DNode *previous = new DNode;
    DNode *current = new DNode;
    current = head_;

    for(int i=1; i<target; i++)
    {
        previous = current;
        current = current -> next_;
    }

    cout << current -> a_student_ << endl;
}
void DStudentList::PrintList()
{
    DNode *temp = new DNode;
    temp = head_;
    int count = 1;

    cout << list_length_ << endl;

    bool idk = false;
    while(idk != true)
    {
        cout << count++ << temp -> a_student_ << endl;
        temp = temp -> next_;
        if (count == list_length_ +1) {cout << "done" << endl;; break;}
    }
}
