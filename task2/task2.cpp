#include <iostream> 
#include <fstream> 
#include <cmath> 
 
using namespace std; 
 
int calculate_point_position(double x, double y, double center_x, double center_y, double radius); 
int creat(int argc, char* argv[]); 
 
int main(int argc, char* argv[]) {  
    int result = creat(argc, argv); 
    return result;  
} 
 
int creat(int argc, char* argv[]) { 
    int res;
    if (argc != 3) { 
        cout << "Неверное количество аргументов. Должны быть указаны 2 файла." << endl; 
        res = 1; 
    } 
 
    ifstream circle_file(argv[1]); 
    ifstream points_file(argv[2]); 
 
    double center_x, center_y, radius; 
    circle_file >> center_x >> center_y >> radius; 
 
    double x, y; 
    while (points_file >> x >> y) { 
        int position = calculate_point_position(x, y, center_x, center_y, radius); 
        cout << position << endl; 
    } 
 
    circle_file.close(); 
    points_file.close();

    res = 0;
    return res;  
} 
 
int calculate_point_position(double x, double y, double center_x, double center_y, double radius) { 
    double distance = sqrt((x - center_x) * (x - center_x) + (y - center_y) * (y - center_y));
    int res; 
 
    if (abs(distance - radius) < 1e-6) { 
        res = 0; 
    } else if (distance < radius) { 
        res = 1; 
    } else { 
        res = 2; 
    } 
    return res;  
}

