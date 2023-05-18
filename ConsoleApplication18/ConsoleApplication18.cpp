// ConsoleApplication18.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define n 14

float w[6]; // 各項係數
float h[n + 1]; // 隱藏解答
float h2[n + 1]; // 隱藏的內部額
float y[n]; // y目標
float y2[n]; // y2目標
float xx[n]; // 輸入
float o[n];//輸出Y1
float o2[n];//輸出Y2

void Vending_machine(float x[], float h[], float y1[], float y2[]) {
    int p = 0;
    for (int i = 0; i < n; i++) {
        y1[i] = 0;
        y2[i] = 0;
        if (x[i] == 0 && p < 3)
            p++;
        if (x[i] == 1 && p == 3) {
            p = p - 3;
            y2[i] = 1;
        }
        h[i + 1] = p;
        if (h[i + 1] == h[i] && h[i + 1] == 3)
            y1[i] = 1;
    }
}

float sigmoid(float y) {
    return 1.0 / (1 + exp(-y));
}

void sigmoidneuron(float xx[], float w[], int i) {
    o[i] = sigmoid(xx[i] * w[0] + w[1] * h[i] + w[2]);
    o2[i] = sigmoid(xx[i] * w[3] + w[4] * h[i] + w[5]);
    h2[i + 1] = h[i] + (-1 * o[i] + -3 * o2[i] + (1 - xx[i]));
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 1000; i++) {
        for (int i = 0; i < n; i++)
            xx[i] = round(rand() % 2);
        Vending_machine(xx, h, y, y2);
        for (int i = 0; i < n; i++)
            sigmoidneuron(xx, w, i);

        for (int j = 0; j < n; j++) {
            w[0] += (y[j] - o[j]) * xx[j];
            w[1] += (y[j] - o[j]) * h2[j];
            w[2] += (y[j] - o[j]) * 1.0;
            w[3] += (y2[j] - o2[j]) * xx[j];
            w[4] += (y2[j] - o2[j]) * h2[j];
            w[5] += (y2[j] - o2[j]) * 1.0;
        }
    }

    for (int i = 0; i < n; i++)
        xx[i] = round(rand() % 2);
    Vending_machine(xx, h, y, y2);
    for (int i = 0; i < n; i++)
        sigmoidneuron(xx, w, i);
    std::cout << "X  :";
    for (int i = 0; i < n; i++) std::cout << xx[i] << "|";
    std::cout << "\n";
    for (int i = 0; i < n; i++) std::cout << "___";
    std::cout << "輸出" << "\n" << "y1 :";
    for (int i = 0; i < n; i++)std::cout << round(o[i]) << "|";
    std::cout << "\n" << "y2 :";
    for (int i = 0; i < n; i++)std::cout << round(o2[i]) << "|";
    std::cout << "\n" << "H2 :";
    for (int i = 0; i <= n; i++)std::cout << round(h2[i]) << "|";
    std::cout << "\n";
    for (int i = 0; i < n; i++) std::cout << "___";
    std::cout << "目標" << "\n" << "y1 :";
    for (int i = 0; i < n; i++)std::cout << y[i] << "|";
    std::cout << "\n" << "y2 :";
    for (int i = 0; i < n; i++)std::cout << y2[i] << "|";
    std::cout << "\n" << "H  :";
    for (int i = 0; i <= n; i++)std::cout << h[i] << "|";


// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
