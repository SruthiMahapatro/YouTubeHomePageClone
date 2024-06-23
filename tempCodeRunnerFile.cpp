#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int numberofrows;
    int rowlength;
    vector<vector<char>> house;
    cin >> numberofrows >> rowlength;

    for (int i = 0; i < numberofrows; i++) {
        vector<char> add;
        house.push_back(add);
        for (int k = 0; k < rowlength; k++) {
            char mychar;
            cin >> mychar;
            house.back().push_back(mychar);
        }
    }

    int counter = 0;

    for (int row = 0; row < numberofrows; row++) {
        for (int column = 0; column < rowlength; column++) {

            if (house[row][column] != '.') {
                continue;
            }

            vector<vector<int>> visit = {};
            house[row][column] = (char)counter;

            if (row != 0 && house[row - 1][column] == '.') {
                house[row - 1][column] = (char)counter;
                visit.push_back({ row - 1, column });
            }

            if (row != numberofrows - 1 && house[row + 1][column] == '.') {
                house[row + 1][column] = (char)counter;
                visit.push_back({ row + 1, column });
            }

            if (column != 0 && house[row][column - 1] == '.') {
                house[row][column - 1] = (char)counter;
                visit.push_back({ row, column - 1 });
            }

            if (column != rowlength - 1 && house[row][column + 1] == '.') {
                house[row][column + 1] = (char)counter;
                visit.push_back({ row, column + 1 });
            }

            for (int i = 0; i < (int)visit.size(); i++) {


                if (visit[i][0] != numberofrows - 1 && house[visit[i][0] + 1][visit[i][1]] == '.') { //Add the square down from the current square
                    house[visit[i][0] + 1][visit[i][1]] = (char)counter;
                    visit.push_back({ visit[i][0] + 1, visit[i][1] });
                }

                if (visit[i][0] != 0 && house[visit[i][0] - 1][visit[i][1]] == '.') { //Add the square on top of the current square to visit
                    house[visit[i][0] - 1][visit[i][1]] = (char)counter;
                    visit.push_back({ visit[i][0] - 1, visit[i][1] });
                }

                if (visit[i][1] != rowlength - 1 && house[visit[i][0]][visit[i][1] + 1] == '.') { //Add the square on the right of the current square to visit
                    house[visit[i][0]][visit[i][1] + 1] = (char)counter;
                    visit.push_back({ visit[i][0], visit[i][1] + 1 });
                }

                if (visit[i][1] != 0 && house[visit[i][0]][visit[i][1] - 1] == '.') { //Add the square on the left of the current square to visit
                    house[visit[i][0]][visit[i][1] - 1] = (char)counter;
                    visit.push_back({ visit[i][0], visit[i][1] - 1 });
                }

            }
            counter += 1;
        }
    }
    cout << counter;
    return 0;
}