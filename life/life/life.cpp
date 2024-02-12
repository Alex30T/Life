#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>


const int n = 20;
char drp[n][n];
int drp2[n][n];

int get(int i) {
    if (i < 0)
        return n - 1;
    if (i > n - 1)
        return 0;
    return i;
}


void show() {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {


            std::cout << drp[i][j];

        }
        std::cout << "\n";
    }

}

void live_count()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {


            if (drp[get(i - 1)][get(j - 1)] == 'X') {
                drp2[i][j]++;
            }

            if (drp[get(i)][get(j - 1)] == 'X') {
                drp2[i][j]++;
            }

            if (drp[get(i + 1)][get(j - 1)] == 'X') {
                drp2[i][j]++;
            }

            if (drp[get(i + 1)][get(j)] == 'X') {
                drp2[i][j]++;
            }

            if (drp[get(i + 1)][get(j + 1)] == 'X') {
                drp2[i][j]++;
            }

            if (drp[get(i)][get(j + 1)] == 'X') {
                drp2[i][j]++;
            }

            if (drp[get(i - 1)][get(j + 1)] == 'X') {
                drp2[i][j]++;
            }

            if (drp[get(i - 1)][get(j)] == 'X') {
                drp2[i][j]++;
            }

        }
    }

}


void check() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (drp2[i][j] == 3) {
                drp[i][j] = 'X';
            }


            if (drp2[i][j] < 2 || drp2[i][j] > 3) {
                drp[i][j] = '-';
            }

        }
    }
}

void drp2null() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            drp2[i][j] = 0;


        }
    }
}

int main(int argc, char* argv[])
{
    std::string filename;

    std::ifstream f;
    f.open(filename);

    if (argc > 1) {
        filename = argv[1];
        f.open(filename);
    }
    else {

        std::cout << "Enter file name:";
        std::cin >> filename;
        f.open(filename);
    }

    if (f.is_open())
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                f >> drp[i][j];

                if (drp[i][j] == '0') {
                    drp[i][j] = 45;

                }

                if (drp[i][j] == '1') {
                    drp[i][j] = 88;

                }
            }
        }
    }
    else
    {
        std::cout << "File not found" << std::endl;
        return 0;
    }
    f.close();

    show();

    while (_getch() != 27) {
        drp2null();
        live_count();
        check();
        std::cout << "\n\n";
        show();

    };



    return 0;
}

