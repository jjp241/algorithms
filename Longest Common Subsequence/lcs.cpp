#include <bits/stdc++.h>

std::string findLCS(std::string first, std::string second){
    // variables and arrays
    int n = first.length();
    int m = second.length();
    int **array = new int*[m+1];
    for (int i = 0; i <= m; i++)
        array[i] = new int[n+1];

    // clearing the array
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++)
            array[i][j] = 0;
    }

    // main algorithm
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (second[i-1] == first[j-1])
                array[i][j] = array[i-1][j-1] + 1;
            else
                array[i][j] = std::max(array[i][j-1], array[i-1][j]);
        }
    }

    // recovering the string
    std::string result = "";
    int x = m;
    int y = n;
    while (m != 0 || n != 0){
        if (m > 0 && array[m-1][n] == array[m][n])
            m--;
        else if (n > 0 && array[m][n-1] == array[m][n])
            n--;
        else{
            result = second[m-1] + result;
            n--;
            m--;
        }
    }
    return result;
}

int main(){
    // initialization and input
    std::string first, second; // the string to compare
    std::cout << "Input the first word: ";
    std::cin >> first;
    std::cout << "Input the second word: ";
    std::cin >> second;

    std::string result = findLCS(first, second);
    std::cout << "The longest common subsequence is: " << result << "\n";
}
