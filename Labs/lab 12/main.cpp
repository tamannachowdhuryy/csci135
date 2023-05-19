#include <iostream>
#include <vector> 
#include "funcs.h" 


int main(){
    //TASK A
    std::cout << "TASK A:" << std::endl;
    std::vector<int> newVector = makeVector(40);
    for(int y = 0; y < newVector.size(); y++){
        std::cout << newVector.at(y) << " ";
    }
    
    //TASK B
    std::cout << "\n \nTASK B:" << std::endl;
    std::vector<int> v{1,2,-1,3,4,-1,6};
    std::vector<int> newV = goodVibes(v);
    for(int i = 0; i < newV.size(); i++){
        std::cout << newV.at(i);
    } // returns [1,2,3,4,6]
   
    
    //TASK C
    std::cout << "\n\nTASK C:" << std::endl;
    std::vector<int> v1 = {1,2,3};
    std::vector<int> v2 = {4,5};

    gogeta(v1, v2); // v1 is now [1,2,3,4,5] and v2 is empty.
    for (int i = 0; i < v1.size(); i++){
        std::cout << v1.at(i) << " "; 

    }
    std::cout << std::endl;
    
    
    //TASK D
    std::cout << " \n \nTASK D:" << std::endl; 
    std::vector<int> v3{1,2,3};
    std::vector<int> v4{4,5};
    std::vector<int> resultD = sumPairWise(v3, v4);
    for (int i = 0; i < resultD.size(); i++){
        std::cout << resultD.at(i) << " "; // returns [5, 7, 3]
    }
    std::cout << std::endl; 



    return 0;   
}
