#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>



using namespace std;
using namespace std::chrono;
int comparsion_count_quicksort = 0;
int comparsion_count_mergesort = 0;
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
    int comparsions = 0;
    auto start = high_resolution_clock::now();// Start the timer before implementation of algorithm
    output << "---INSERTION SORT---" << endl;
    int j;
    for (int i = 1; i < n; i++) {
        // We would start from the second position since we assumed that the first is sorted.
        T temp = data[i];
        j = i;
        for (j; j >= 0 && temp < data[j - 1]; j--) { // the loop condition.
            data[j] = data[j - 1]; // Shift.
            comparsions++;
        }
        data[j] = temp; // Put the current element in its correct position.
    }
    auto end = high_resolution_clock::now(); // Stop the timer.
    auto duration = duration_cast<milliseconds>(end - start);
    output << "Number of comparsions: " << comparsions << endl;
    output << "Running time: "<< duration.count() << "ms" << endl << endl;
}
template <typename T>
void bubble_sort(vector<T>& data,int n){
    int comparsion =0;
    auto start = high_resolution_clock::now();
    output << "---BUBBLE SORT---" << endl;
    for(int i =0; i<n-1; i++){
        for(int j =0; j<n-i-1; j++ ){
            if(data[j+1] < data[j]){
                swap(data[j],data[j+1]);
            }
             comparsion++;
        }
    }
    auto end = high_resolution_clock::now(); // Stop the timer.
    auto duration = duration_cast<milliseconds>(end - start); // output timer in millisec.
    output << "Number of comparsions: " << comparsion << endl;
    output << "Running time: "<< duration.count() << "ms" << endl << endl;
}
template <typename T>
void selectionsort(vector<T>& data, int n) {
    int comparsion = 0; // Initialize comparison counter
    auto start = high_resolution_clock::now();
    output << "---SELECTION SORT---" << endl;
    for (int i = 0; i < n - 1; i++) {
        int minindx = i ;
        for (int j = i + 1; j < n; j++) { // Compare it with its elements, check if it's less than any.
            if (data[j] < data[minindx]) {
                minindx = j; // Index of minimum element
            }
            comparsion++; // Increment comparison counter.
        }
        swap(data[i], data[minindx]); // Swap places.
    }
    auto end = high_resolution_clock::now(); // Stop the timer.
    auto duration = duration_cast<milliseconds>(end - start); // Output timer in milliseconds.
    output << "Number of comparisons: " << comparsion << endl;
    output << "Running time: " << duration.count() << "ms" << endl << endl;
}

template <typename T>
void shellsort(vector <T>& data,int n){
    int comparsion = 0;
    auto start = high_resolution_clock::now();
    output << "---SHELL SORT---" << endl;
    int j;
    for(int gap = n/2; gap >0; gap/=2){
        for(int i =gap; i<n; i++){
           T temp = data[i];
           for(j = i; j>= gap && temp < data[j-gap]; j-=gap ){
            data[j] = data[j-gap];
           }
           comparsion++;
           data[j] = temp;
        }
    }
     auto end = high_resolution_clock::now(); // Stop the timer.
    auto duration = duration_cast<milliseconds>(end - start); // output timer in millisec.
    output << "Number of comparsions: " << comparsion << endl;
    output << "Running time: "<< duration.count() << "ms" << endl << endl;
}
template<typename T>
void Merge(vector<T>& A, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    vector<T> LeftArray;
    vector<T> RightArray;

    // Copy data to temporary arrays LeftArray[] and RightArray[]
    for (int i = 0; i < n1; ++i)
        LeftArray.push_back(A[left + i]);
    for (int j = 0; j < n2; ++j)
        RightArray.push_back(A[middle + 1 + j]);

    // Merge the temporary arrays back into A[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (LeftArray[i] < RightArray[j]) {
            A[k] = LeftArray[i];
            ++i;
        } else {
            A[k] = RightArray[j];
            ++j;
        }
        ++k;
        comparsion_count_mergesort++;
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
    if (left < right) {
        // Find the middle point
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        MergeSort(A, left, middle);
       MergeSort(A, middle + 1, right);

        // Merge the sorted halves
        Merge(A, left, middle, right);
    }
    else{
        return;
    }
}
template<typename T>
int Partition(vector<T>& arr, int left, int right) {
    T x = arr[left]; // Pivot element
    int i = left;

    for (int j = left + 1; j <= right; j++) {
            comparsion_count_quicksort++;
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
    if(l < h){
        int part = Partition(arr,l,h);
        quicksort(arr,l,part-1);
        quicksort(arr,part+1,h);
    }


}
void outputquicksort(){
    output << "--- QUICK SORT---" << endl;
    output << "Number of comparsions: " << comparsion_count_quicksort << endl;

}
void outputmergesort(){
    output << "---MERGE SORT---" << endl;
    output << "Number of comparsions: " << comparsion_count_mergesort << endl;

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
    bubble_sort(Students,Students.size());
    if(output.is_open()){
    for(int i =0; i<Students.size(); i++){
        output << Students[i] << endl; // Put sorted info of students into the file.
    }

    }
    insertionsort(Students,Students.size());
    if(output.is_open()){
    for(int i =0; i<Students.size(); i++){
        output << Students[i] << endl; // Put sorted info of students into the file.
    }

    }
    selectionsort(Students,Students.size());
    if(output.is_open()){
    for(int i =0; i<Students.size(); i++){
        output << Students[i] << endl; // Put sorted info of students into the file.
    }

    }
     shellsort(Students,Students.size());
    if(output.is_open()){
    for(int i =0; i<Students.size(); i++){
        output << Students[i] << endl; // Put sorted info of students into the file.
    }

    }
      auto start = high_resolution_clock::now();
     quicksort(Students,0,Students.size()-1);
     outputquicksort();
    auto end = high_resolution_clock::now(); // Stop the timer.
    auto duration = duration_cast<milliseconds>(end - start); // output timer in millisec.
    output << "Running time: "<< duration.count() << "ms" << endl << endl;
    if(output.is_open()){
    for(int i =0; i<Students.size(); i++){
        output << Students[i] << endl; // Put sorted info of students into the file.
    }

    }
    auto start2 = high_resolution_clock::now();
    MergeSort(Students,0,Students.size()-1);
    outputmergesort();
    auto end2 = high_resolution_clock::now(); // Stop the timer.
    auto duration2 = duration_cast<milliseconds>(end2 - start2); // output timer in millisec.
    output << "Running time: "<< duration2.count() << "ms" << endl << endl;
    if(output.is_open()){
    for(int i =0; i<Students.size(); i++){
        output << Students[i] << endl; // Put sorted info of students into the file.
    }

    }
     output.close();
}
