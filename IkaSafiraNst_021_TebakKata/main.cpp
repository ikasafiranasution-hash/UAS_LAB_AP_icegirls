#include "TebakKata.h"

#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));

    char ulang;

    do
    {
        mainkanGame();

        cout
        << "\n\nApakah Anda ingin bermain lagi? (Y/N) : ";

        cin >> ulang;

    }
    while(
        ulang == 'Y' ||
        ulang == 'y');

    cout
    << "\nTerima kasih telah bermain!\n";

    return 0;
}