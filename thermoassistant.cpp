#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <math.h>

using namespace std;

char constantParameter;
double constantValue;
double XY[256][2] = {0};
int N = 0;
char experimentName;
char experimentNames[512][20];

void getData();
void saveData();
void readData(char[]);
double calculateA();
double calculateAlphaA(double);
double calculateN(double, double);
void saveResult(char[]);
void saveFileName(char[]);
void menu();
void showlist();

int main()
{
    menu();
    cout << "\n\npress Enter to Exit...";
    cin.get();
    return 0;
}

void showlist()
{
    system("CLS");
    cout << "Please choose one of these items: \n\n";
    ifstream fin;
    fin.open("experiments.txt");
    int i = 0;
    while (!fin.eof())
    {
        fin >> experimentNames[i];
        cout << i + 1 << ". " << experimentNames[i] << "\n";
        i++;
    }
    fin.close();
    cout << "\n: ";
}

void menu()
{
    system("CLS");
    cout << "Hi,\nplease select one of these items:\n1. Enter data\n2. Show data list to choose\n3. Exit\n";
    int choice = 0;
    cin >> choice;
    if (choice == 1)
    {
        getData();
        saveData();
        cout << "\n\nPress Enter to back to menu...";
        cin.get();
        menu();
    }
    else if (choice == 2)
    {
        showlist();
        int thisChoice = 0;
        cin >> thisChoice;
        readData(experimentNames[thisChoice - 1]);
        saveResult(experimentNames[thisChoice - 1]);
        cout << "\n\nPress Enter to back to menu...";
        cin.get();
        cin.get();
        menu();
    }
    else
    {
        return;
    }
}

void getData()
{
    cout << "first determine experiment type, enter P for constant Pressure and V for constant Volume:";
    cin >> constantParameter;
    cout << "Now Please enter it's constant value:";
    cin >> constantValue;
    while (true)
    {
        cout << "Please enter Temperature in celcius degrees and value of the other parameter \"temperature value\": ";
        cin >> XY[N][0];
        cin >> XY[N][1];
        N += 1;
        cout << "continue? (y/n)";
        char whatToDo;
        cin >> whatToDo;
        if (whatToDo == 'n')
        {
            break;
        }
    }
}

void saveFileName(char name[20])
{
    fstream fout;
    fout.open("experiments.txt", ios::app);
    fout << name << "\n";
    fout.close();
}

void saveData()
{
    ofstream fout;
    time_t thisTime = time(nullptr);
    char fileName[40] = "data_";
    char timeChar[16];
    itoa(thisTime, timeChar, 10);
    experimentName = thisTime;
    saveFileName(timeChar);
    strcat(fileName, timeChar);
    strcat(fileName, ".txt");
    fout.open(fileName);
    fout << asctime(localtime(&thisTime));
    fout << "N: " << N << "\n";
    fout << "constant_parameter: " << constantParameter << "\n";
    if (constantParameter == 'P')
    {
        fout << "constant_value: " << constantValue << " (Pa)\n";
        fout << "Temperature(C deg) V(lit)\n";
    }
    else if (constantParameter == 'V')
    {
        fout << "constant_value: " << constantValue << " (lit)\n";
        fout << "Temperature(C deg) P (Pa)\n";
    }
    for (int i = 0; i < N; i++)
    {
        fout << XY[i][0] << " " << XY[i][1] << "\n";
    }
    fout.close();
}

void readData(char timeChar[20])
{
    ifstream fin;
    char fileName[40] = "data_";
    strcat(fileName, timeChar);
    strcat(fileName, ".txt");
    fin.open(fileName);
    char temporary[100];
    fin.getline(temporary, 100);
    fin >> temporary >> N;
    fin >> temporary >> constantParameter;
    fin >> temporary >> constantValue >> temporary;
    fin >> temporary >> temporary >> temporary >> temporary;
    for (int i = 0; i < N; i++)
    {
        fin >> XY[i][0] >> XY[i][1];
    }
    fin.close();
}

double calculateA()
{
    double brXY = 0;
    double brXX = 0;
    for (int i = 0; i < N; i++)
    {
        brXY += XY[i][0] * XY[i][1];
    }
    for (int i = 0; i < N; i++)
    {
        brXX += XY[i][0] * XY[i][0];
    }
    return (brXY / brXX);
}

double calculateAlphaA(double a)
{
    double d[256];
    double brDD = 0;
    for (int i = 0; i < N; i++)
    {
        d[i] = (a + XY[i][0] - XY[i][1]);
    }
    for (int i = 0; i < N; i++)
    {
        brDD += d[i] * d[i];
    }
    double brX = 0;
    double brXX = 0;
    for (int i = 0; i < N; i++)
    {
        brX += XY[i][0];
    }
    for (int i = 0; i < N; i++)
    {
        brXX = XY[i][0] * XY[i][0];
    }
    double alpha2 = brDD / (N - 2);
    double delta = brX * brX - brXX * N;
    double alphaA = sqrt(N * alpha2 / delta);
    return alphaA;
}

double calculateN(double R, double a)
{
    return constantValue * a / R;
}

void saveResult(char timeChar[20])
{
    system("CLS");
    ofstream fout;
    char fileName[60] = "experiment_";
    time_t thisTime = time(nullptr);
    strcat(fileName, timeChar);
    strcat(fileName, ".txt");
    fout.open(fileName);
    fout << asctime(localtime(&thisTime));
    fout << "N: " << N << "\n";
    cout << "N: " << N << "\n";
    fout << "constant_parameter: " << constantParameter << "\n";
    cout << "constant_parameter: " << constantParameter << "\n";
    if (constantParameter == 'P')
    {
        fout << "constant_value: " << constantValue << " (Pa)\n";
        cout << "constant_value: " << constantValue << " (Pa)\n";
        fout << "Temperature(C deg) V(lit)\n";
        cout << "Temperature(C deg) V(lit)\n";
    }
    else if (constantParameter == 'V')
    {
        fout << "constant_value: " << constantValue << " (lit)\n";
        cout << "constant_value: " << constantValue << " (lit)\n";
        fout << "Temperature(C deg) P (Pa)\n";
        cout << "Temperature(C deg) P (Pa)\n";
    }
    for (int i = 0; i < N; i++)
    {
        fout << XY[i][0] << " " << XY[i][1] << "\n";
        cout << XY[i][0] << " " << XY[i][1] << "\n";
    }
    fout << "---\n";
    cout << "---\n";
    double a = calculateA();
    double alphaA = calculateAlphaA(a);
    fout << "a: " << a << "\n";
    cout << "a: " << a << "\n";
    fout << "alpha_a: " << alphaA << "\n";
    cout << "alpha_a: " << alphaA << "\n";
    if (constantParameter == 'P')
    {
        fout << "V=(" << a << (char)241 << ")T\n";
        cout << "V=(" << a << (char)241 << ")T\n";
    }
    else if (constantParameter == 'V')
    {
        fout << "P=(" << a << (char)241 << ")T\n";
        cout << "P=(" << a << (char)241 << ")T\n";
    }
    double R = 8.314;
    fout << "R: " << R << "\n";
    cout << "R: " << R << "\n";
    fout << "n: " << calculateN(R, a) << " (mol)\n";
    cout << "n: " << calculateN(R, a) << " (mol)\n";
    fout.close();
    cout << "\nResults Saved!";
}
