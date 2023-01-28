#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

void convp(vector<double> y)
{
    double time = 0;
    ofstream write;
    write.open("output.txt");

    for (int i = 0; i < y.size(); i++)
    {
        if (i < (y.size() / 2) + 1)
        {
            time += .001;
            write << time << " " << y[i] << '\n';
        }
        cout << y[i];
        if (i != y.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
    write.close();
}

/*k upper limit always == size of both arrays - 2
m lower limit == zero till k= sliding array size +1 is greater than k.
this will cause the lower limit to become the lagging edge of the sliding
function.
m upper limit == k till sliding array is greater than k, then goes to leading edge of non sliding array */
void conv(vector<double> a1, vector<double> a2)
{
    double sum = 0;
    vector<double> y;
    for (int k = 0; k <= a1.size() + a2.size() - 2; k++)
    {
        sum = 0;
        for (unsigned int m = max(0, (int)(k - a2.size() + 1)); m <= min((int)a1.size() - 1, k); m++)
        {
            sum += a1[m] * a2[k - m];
        }
        y.push_back(sum);
    }
    convp(y);
}

void read()
{
    vector<double> fk;
    cout << "enter file name for first convolution variable ";
    string file;
    cin >> file;
    ifstream readfile(file);
    while (getline(readfile, file))
    {
        fk.push_back(stof(file));
    }

    vector<double> hk;
    cout << "enter file name for second convolution variable ";
    cin >> file;
    ifstream readfile2(file);
    while (getline(readfile2, file))
    {
        hk.push_back(stof(file));
    }
    conv(fk, hk);
}

int main()
{
    int run = 1;
    while (run)
    {
        cout << "press 1 to enter array numbers. Press 0 to exit. Press anything else to read from a file: ";
        short int a;
        cin >> a;
        if (a != 1 && a != 0)
        {
            read();
        }
        else if (a == 0)
        {
            run = 0;
        }
        else
        {
            cout << "Enter array number for both arrays to be convolved, ";
            int one, two = 0;
            cin >> one >> two;

            vector<double> f1 = {0, 1, 2, 3, 2, 1};
            vector<double> f2 = {-2, -2, -2, -2, -2, -2, -2};
            vector<double> f3 = {1, -1, 1, -1};
            vector<double> f4 = {0, 0, 0, -3, -3};
            if (one == 1)
            {
                switch (two)
                {
                case 1:
                    conv(f1, f1);
                    break;
                case 2:
                    conv(f1, f2);
                    break;
                case 3:
                    conv(f1, f3);
                    break;
                case 4:
                    conv(f1, f4);
                    break;
                }
            }
            else if (one == 2)
            {
                switch (two)
                {
                case 1:
                    conv(f2, f1);
                    break;
                case 2:
                    conv(f2, f2);
                    break;
                case 3:
                    conv(f2, f3);
                    break;
                case 4:
                    conv(f2, f4);
                    break;
                }
            }
            else if (one == 3)
            {
                switch (two)
                {
                case 1:
                    conv(f3, f1);
                    break;
                case 2:
                    conv(f3, f2);
                    break;
                case 3:
                    conv(f3, f3);
                    break;
                case 4:
                    conv(f3, f4);
                    break;
                }
            }
            else if (one == 4)
            {
                switch (two)
                {
                case 1:
                    conv(f4, f1);
                    break;
                case 2:
                    conv(f4, f2);
                    break;
                case 3:
                    conv(f4, f3);
                    break;
                case 4:
                    conv(f4, f4);
                    break;
                }
            }
        }
    }
    return (0);
}
