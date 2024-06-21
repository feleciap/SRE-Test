#include <iostream> 
#include <fstream> 
#include <vector> 
#include <algorithm> 
#include <limits> 
#include <stack> 
 
using namespace std; 

int parser(int argc, char* argv[]);
 
int main(int argc, char* argv[]) { 
    int res = parser(argc, argv);
    return res; 
}

int parser(int argc, char* argv[]){
    int res;
    if (argc != 2) { 
        cout << "Неверное количество аргументов. Должен быть указан 1 файл." << endl; 
        res = 1; 
    } 
 
    string file_path = argv[1]; 
    ifstream input_file(file_path); 
 
    if (!input_file.is_open()) { 
        cout << "Ошибка открытия файла: " << file_path << endl; 
        res = 1; 
    } 
 
    vector<int> nums; 
    int num; 
    while (input_file >> num) { 
        nums.push_back(num); 
    } 
 
    sort(nums.begin(), nums.end()); 
    int median = nums[nums.size() / 2]; 
 
    stack<int> moves; 
    for (int i = 0; i < nums.size(); i++) { 
        if (nums[i] > median) { 
            moves.push(nums[i] - median); 
        } else if (nums[i] < median) { 
            moves.push(median - nums[i]); 
        }  
    } 

    int total_moves = 0; 
    while (!moves.empty()) { 
        total_moves += moves.top(); 
        moves.pop(); 
    } 
 
    cout << "Минимальное количество ходов: " << total_moves << endl;
    res = 0; 
 
    return res; 

}