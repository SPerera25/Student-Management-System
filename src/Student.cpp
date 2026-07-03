#include "Student.h"

vector<Student> students;

void addStudent() {

    int id,age;
    string name,course;
    bool ageValid = true,idValid = true;

    while(idValid){

        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();

        if(id<=0){
            cout << "Invalid id!" << endl;
        }
        else if(id>0){
            idValid = false;
        }
        else{
            cout << "Invalid id!" << endl;
        }

    }

    if(findStudentIndex(id) != -1){
        cout << "A student with this ID already exists!"<< endl;
        return;
    }

    cout << "Enter name: ";
    getline(cin,name);

    while(ageValid){

        cout << "Age: ";
        cin >> age;
        cin.ignore();

        if(age<=0){
            cout << "Invalid age!" << endl;
        }
        else if(age>0){
            ageValid = false;
        }
        else{
            cout << "Invalid age!" << endl;
        }
    }

    cout << "Course: ";
    getline(cin,course);

    Student newStudent;

    newStudent.id=id;
    newStudent.name=name;
    newStudent.age=age;
    newStudent.course=course;

    students.push_back(newStudent);
    saveToFile();

    cout << "Student added successfully!" << endl;
    cout << endl;

}

void viewStudents(){

    if(students.empty()){
        cout << "No students found." << endl;
        return;
    }
    cout << "===== Student List =====" << endl;

    for(int i=0; i<students.size(); i++){
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Course: " << students[i].course << endl;
        cout << "------------------------" << endl;
        cout << endl;
    }
    return;
}

void searchStudent(){
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    int i = findStudentIndex(id);

    if( i == -1 ){
        cout << "Student not found!" << endl;
        return;
    }
    
    cout << "\n===== Student Found =====" << endl;
    cout << "ID: " << students[i].id << endl;
    cout << "Name: " << students[i].name << endl;
    cout << "Age: " << students[i].age << endl;
    cout << "Course: " << students[i].course << endl;
    return;

}

void deleteStudent(){
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    int i = findStudentIndex(id);

    if( i == -1 ){
        cout << "Student not found!" << endl;
        return;
    }

    students.erase(students.begin() + i);
    saveToFile();

    cout << "Student deleted successfully." << endl;
    
}

void updateStudent(){

    int newId,newAge;
    string newName,newCourse;

    cout << "Enter ID to update: ";
    cin >> newId;
    cin.ignore();

    int index = findStudentIndex(newId);
    
    if(index == -1){
        cout << "Student not found!";
        return;
    }

    cout << "New name: ";
    getline(cin,newName);

    cout << "New age: ";
    cin >> newAge;
    cin.ignore();

    cout << "New course: ";
    getline(cin,newCourse);
   
    students[index].age=newAge;
    students[index].name=newName;
    students[index].course=newCourse;
        
    saveToFile();

    cout << "\n===== Student Updated =====" << endl;
    cout << "ID: " << students[index].id << endl;
    cout << "Name: " << students[index].name << endl;
    cout << "Age: " << students[index].age << endl;
    cout << "course: " << students[index].course << endl;
    
}

int findStudentIndex(int id){

    for(int i=0; i<students.size(); i++){
        if(students[i].id==id){
            return i;
        }
    }
    return -1;

}

void saveToFile(){

    ofstream file("students.txt");

    for(int i=0; i<students.size(); i++){
        file << students[i].id << "," 
        << students[i].name << "," 
        << students[i].age << "," 
        << students[i].course << endl;
    }

    file.close();
}

void loadFromFile(){

    ifstream file("students.txt");

    if (!file) {
        return;
    }

    string line;

    while (getline(file, line)){

        stringstream ss(line);

        string idStr, name, ageStr, course;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, ageStr, ',');
        getline(ss, course, ',');
        
        //file stores everything as text. So we convert string into int.
        int id = stoi(idStr);
        int age = stoi(ageStr);

        Student s;

        s.id = id;
        s.name = name;
        s.age = age;
        s.course = course;

        students.push_back(s);
    }
}