#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>



using namespace std;
using namespace std::chrono;
ofstream output("SortedByName.txt");
class Student{
public:
    string id;
    string name;
    double gpa;
    Student(string ID,string n,double GPA){
        id = ID;
        name = n;
        gpa = GPA;
    }
    bool operator<(Student& other){ // To sort by name.
        return this->name < other.name;
    }
    // Overloading printing operator.
    friend ostream& operator<<(ostream& COUT,const Student& s){
        COUT << "Student Name: " << s.name << endl;
        COUT << "Student ID: " << s.id << endl;
        COUT << "Student GPA: " << s.gpa << endl;
        return COUT;
    }
};
template <typename T>
void insertionsort(vector<T>& data, int n) {
    auto start = high_resolution_clock::now();// Start the timer before implementation of algorithm
    output << "---INSERTION SORT---" << endl;
    int j;
    for (int i = 1; i < n; i++) {
        // We would start from the second position since we assumed that the first is sorted.
        T temp = data[i];
        j = i;
        for (j; j >= 0 && temp < data[j - 1]; j--) { // the loop condition.
            data[j] = data[j - 1]; // Shift.
        }
        data[j] = temp; // Put the current element in its correct position.
    }
    auto end = high_resolution_clock::now(); // Stop the timer.
    auto duration = duration_cast<milliseconds>(end - start);

    output << "Running time: "<< duration.count() << "ms" << endl << endl;
}
template <typename T>
void bubble_sort(vector<T>& data,int n){
    auto start = high_resolution_clock::now();
    output << "---BUBBLE SORT---" << endl;
    for(int i =0; i<n-1; i++){
        for(int j =0; j<n-i-1; j++ ){
            if(data[j+1] < data[j]){
                swap(data[j],data[j+1]);
            }
        }
    }
      auto end = high_resolution_clock::now(); // Stop the timer.
    auto duration = duration_cast<milliseconds>(end - start); // output timer in millisec.

    output << "Running time: "<< duration.count() << "ms" << endl << endl;
}
template <typename T>
void selectionsort(vector<T>& data,int n){
    auto start = high_resolution_clock::now();
    output << "---SELECTION SORT---" << endl;
    int minindx;
    for(int i =0; i<n-1; i++){
       T mn = data[i]; // every iteration we assume that current element is minimum and every element on the left is sorted.
        for(int j =i+1; j<n;j++){ // Compare it with its elements , check if its > any .
            if(data[j] < mn){
                mn = data[j]; // Then new min would be equal to that element
                minindx = j; // Index of minimum element
            }
        }
        swap(data[i],data[minindx]); // Swap places.
    }
     auto end = high_resolution_clock::now(); // Stop the timer.
    auto duration = duration_cast<milliseconds>(end - start); // output timer in millisec.

    output << "Running time: "<< duration.count() << "ms" << endl << endl;
}
template <typename T>
void shellsort(vector <T>& data,int n){
    auto start = high_resolution_clock::now();
    output << "---SHELL SORT---" << endl;
    int j;
    for(int gap = n/2; gap >0; gap/=2){
        for(int i =gap; i<n; i++){
           T temp = data[i];
           for(j = i; j>= gap && temp < data[j-gap]; j-=gap ){
            data[j] = data[j-gap];
           }
           data[j] = temp;
        }
    }
     auto end = high_resolution_clock::now(); // Stop the timer.
    auto duration = duration_cast<milliseconds>(end - start); // output timer in millisec.
    output << "Running time: "<< duration.count() << "ms" << endl << endl;
}
template <typename T>
void Merge(vector<T>& A, int left, int middle, int right){
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    vector<T> LeftArray(n1);
    vector<T> RightArray(n2);

    // Copy data to temporary arrays LeftArray[] and RightArray[]
    for (int i = 0; i < n1; ++i)
        LeftArray[i] = A[left + i];
    for (int j = 0; j < n2; ++j)
        RightArray[j] = A[middle + 1 + j];

    // Merge the temporary arrays back into A[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (LeftArray[i] <= RightArray[j]) {
            A[k] = LeftArray[i];
            ++i;
        } else {
            A[k] = RightArray[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of LeftArray[], if any
    while (i < n1) {
        A[k] = LeftArray[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of RightArray[], if any
    while (j < n2) {
        A[k] = RightArray[j];
        ++j;
        ++k;
    }
}

// Merge-Sort function
template <typename T>
void MergeSort(vector<T>& A, int left, int right) {
     auto start = high_resolution_clock::now();
    output << "---MERGE SORT---" << endl;
    if (left < right) {
        // Find the middle point
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        MergeSort(A, left, middle);
        MergeSort(A, middle + 1, right);

        // Merge the sorted halves
        Merge(A, left, middle, right);
    }
     auto end = high_resolution_clock::now(); // Stop the timer.
    auto duration = duration_cast<milliseconds>(end - start); // output timer in millisec.
    output << "Running time: "<< duration.count() << "ms" << endl << endl;

}
template<typename T>
int Partition(vector<T>& arr, int left, int right) {
    T x = arr[left]; // Pivot element
    int i = left;

    for (int j = left + 1; j <= right; j++) {
        if (arr[j] < x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i], arr[left]);
    return i;
}
template<typename T>
void quicksort(vector<T>& arr,int l,int h){
    output << "---QUICK SORT---" << endl;
    auto start = high_resolution_clock::now();
    if(l < h){
        int part = Partition(arr,l,h);
        quicksort(arr,l,part-1);
        quicksort(arr,part+1,h);
    }
     auto end = high_resolution_clock::now(); // Stop the timer.
    auto duration = duration_cast<milliseconds>(end - start); // output timer in millisec.
    output << "Running time: "<< duration.count() << "ms" << endl << endl;
}

int main()
{

    vector <Student> Students;
     string line;
    ifstream opfile("students.txt");
    if(opfile){
        int cnt =0;
        cout << "READING OPERATION STARTED" << endl;
        while(getline(opfile, line)){ // While I didnt reach end of file
          if(cnt !=  0){
            string n,id;
            double gpa;
            // Read the whole line then continue to the next line.
            n = line;
            // Read the whole line then continue to the next line.
            getline(opfile,id);
            opfile >>gpa; // Since there will be no spaces in gpa
            opfile.ignore();
            Students.push_back(Student(id,n,gpa));

          }
          cnt++;
        }

    }
    quicksort(Students,0,Students.size()-1);
    if(output.is_open()){
    for(int i =0; i<Students.size(); i++){
        output << Students[i] << endl; // Put sorted info of students into the file.
    }
    output.close();
    cout << "Sorted Students Successfully inserted into file." << endl;
    }
}
