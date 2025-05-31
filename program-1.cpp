#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>

class StudentData{
    protected:
        vector<T> std_id;
        vector<string> std_name;
    public:
       StudentData(){
        int size;
        cout << "Enter the number of students: ";
        cin >> size;
        std_id.resize(size);
        std_name.resize(size);
        for(int i = 0; i < size; i++){
            cout << "Enter Student Id :- " << i+1 << ": ";
            cin >> std_id[i];
            cout << "Enter Student Name :- " << i+1 << ": ";
            cin >> std_name[i];
        }
       }
};

class Tasks : public StudentData<int>
{
    public:
    void add(){
            int std_Id;
            string std_Name;

            cout << "Enter Student Id :- ";
            cin >> std_Id;
            cout << "Enter Student Name :- ";
            cin >> std_Name;

            std_id.push_back(std_Id);
            std_name.push_back(std_Name);
        }
        void display(){
            cout << "Student Id With Student Name :- " << endl;

            for(int i = 0; i < std_id.size(); i++){
                cout << std_id[i] << "   " << std_name[i] << endl;
            }

        }
        
        void search(int studentID){
            for(int i = 0; i < std_id.size(); i++){
                if(std_id[i] == studentID){
                    cout << "Student Id :- " << std_id[i] << endl << "Student Name :- " << std_name[i] << endl;
                    return;
                }
            }
            cout << "Student not found!" << endl;
        }
        
        void remove(int studentID){
            for(int i = 0; i < std_id.size(); i++){
                if(std_id[i] == studentID){
                    std_id.erase(std_id.begin() + i);
                    std_name.erase(std_name.begin() + i);
                    cout << "Student Removed Successfully !!" << endl;
                    return;
                }
            }
            cout << "Student not found!" << endl;
        }
};
int main()
{
    Tasks task;
    int choice;
    do{
        cout << endl << "---- Student Management System ----" << endl;
        cout << "Press 1 To Add Student." << endl;
        cout << "Press 2 To Display All Students." << endl;
        cout << "Press 3 To Search For Student." << endl;
        cout << "Press 4 To Remove Student." << endl;
        cout << "Press 0 To Exit The Program." << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                task.add();
                break;
            case 2:
                task.display();
                break;
            case 3:
                int search_id;
                cout << "Enter Student ID to search: ";
                cin >> search_id;
                task.search(search_id);
                break;
            case 4:
                int remove_id;
                cout << "Enter Student ID to remove: ";
                cin >> remove_id;
                task.remove(remove_id);
                break;
            case 0: 
                cout << endl << "---- Your Program Is Sucessfully Exited ----" << endl;
                break;
            default:
                cout << endl << "Wrong Choice !! Please try again." << endl;
                break;
        }

    }
    while(choice != 0);

    return 0;
}