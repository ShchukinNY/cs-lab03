#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <windows.h>

using namespace std;

vector<double>
input_numbers(size_t count){
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}





vector <size_t> make_histogram(vector<double> numbers,size_t bin_count){
        double max;
        double min;
        find_minmax(numbers, min, max);
         vector<size_t> bins(bin_count);
    for (double number : numbers) {
        size_t bin = (size_t)((number - min) / (max - min) * bin_count);
        if (bin == bin_count) {
            bin--;
        }
        bins[bin]++;
    }
    return bins;
}


 void show_histogram_text(vector<size_t> bins){
         const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;

    size_t max_count = 0;
    for (size_t count : bins) {
        if (count > max_count) {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > MAX_ASTERISK;

    for (size_t bin : bins) {
        if (bin < 100) {
            cout << ' ';
        }
        if (bin < 10) {
            cout << ' ';
        }
        cout << bin << "|";

        size_t height = bin;
        if (scaling_needed) {
            const double scaling_factor = (double)MAX_ASTERISK / max_count;
            height = (size_t)(bin * scaling_factor);
        }

        for (size_t i = 0; i < height; i++) {
            cout << '*';
        }
        cout << '\n';
    }
       return;
}




int
main(){
    // ���� ������
    /*size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(number_count);
    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;

    // ��������� ������
     const auto bins = make_histogram(numbers, bin_count);

    // ����� ������
    show_histogram_svg(bins); */
    DWORD info = GetVersion();
    DWORD mask = 0x0000ffff;
    DWORD version = info & mask;
    DWORD platform = info >> 16;
    DWORD mask_2 = 0x0000ff;
   if ((info & 0x80000000) == 0)
    {
        DWORD version_major = version & mask_2;
        DWORD version_minor = version >> 8;
        DWORD build = platform;
        printf("Windows v%u.%u (build %u)\n", version_major, version_minor, build);
    }
    char computer_name[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = MAX_COMPUTERNAME_LENGTH+1;
    GetComputerNameA(computer_name, &size);
    printf("Computer name: %s\n", computer_name);

    return 0;
}
