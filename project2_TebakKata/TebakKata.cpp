#include "TebakKata.h"

#include <cstdlib>
#include <ctime>
#include <cctype>

string daftarKata[15] =
{
    "indonesia",
    "komputer",
    "algoritma",
    "program",
    "kampus",
    "internet",
    "keyboard",
    "monitor",
    "printer",
    "semester",
    "mahasiswa",
    "database",
    "pointer",
    "struktur",
    "variabel"
};

void pilihKesulitan(KataGame *game)
{
    int pilihan;

    do
    {
        system("cls");

        cout << "===== PILIH KESULITAN =====\n";
        cout << "1. Easy (8 Nyawa)\n";
        cout << "2. Medium (6 Nyawa)\n";
        cout << "3. Hard (4 Nyawa)\n";
        cout << "Pilihan : ";
        cin >> pilihan;

    }
    while(pilihan < 1 || pilihan > 3);

    switch(pilihan)
    {
        case 1:
            game->nyawa = 8;
            game->level = 1;
            break;

        case 2:
            game->nyawa = 6;
            game->level = 2;
            break;

        case 3:
            game->nyawa = 4;
            game->level = 3;
            break;
    }
}

void inisialisasiGame(KataGame *game)
{
    int index = rand() % 15;

    game->kataAsli = daftarKata[index];

    game->statusTebakan = string(game->kataAsli.length(), '_');

    game->jumlahSalah = 0;
    game->skor = 0;

    for(int i = 0; i < 26; i++)
    {
        game->tebakanSalah[i] = '\0';
    }
}

void tampilkanGame(KataGame *game)
{
    cout << "===== GAME TEBAK KATA =====\n\n";

    cout << "Kata : ";

    for(char c : game->statusTebakan)
    {
        cout << c << ' ';
    }

    cout << "\n\nNyawa : " << game->nyawa;

    cout << "\n\nHuruf Salah : ";

    if(game->jumlahSalah == 0)
    {
        cout << "-";
    }
    else
    {
        for(int i = 0; i < game->jumlahSalah; i++)
        {
            cout
            << game->tebakanSalah[i] << ' ';
        }
    }

    cout << "\n";
}

bool hurufSudahDitebak( KataGame *game, char huruf)
{
    for(char c : game->statusTebakan)
    {
        if(c == huruf)
        {
            return true;
        }
    }

    for(int i = 0; i < game->jumlahSalah; i++)
    {
        if(game->tebakanSalah[i] == huruf)
        {
            return true;
        }
    }

    return false;
}

void prosesTebakan(KataGame *game, char huruf)
{
    bool ditemukan = false;

    for(int i = 0; i < game->kataAsli.length(); i++)
    {
        if(game->kataAsli[i] == huruf)
        {
            game->statusTebakan[i] = huruf;
            ditemukan = true;
        }
    }

    if(!ditemukan)
    {
        game->tebakanSalah[game->jumlahSalah] = huruf;
        game->jumlahSalah++;
        game->nyawa--;
    }
}

bool cekMenang(KataGame *game)
{
    return game->kataAsli == game->statusTebakan;
}

int hitungSkor(
        int nyawa,
        int level)
{
    switch(level)
    {
        case 1:
            return nyawa * 10;

        case 2:
            return nyawa * 20;

        case 3:
            return nyawa * 30;

        default:
            return 0;
    }
}

void mainkanGame()
{
    KataGame game;

    pilihKesulitan(&game);

    inisialisasiGame(&game);

    while(game.nyawa > 0)
    {
        system("cls");

        tampilkanGame(&game);

        char huruf;

        cout << "\nMasukkan huruf : ";
        cin >> huruf;

        huruf = tolower(huruf);

        if(!isalpha(huruf))
        {
            cout << "\nMasukkan huruf A-Z!\n";
            system("pause");
            continue;
        }

        if(hurufSudahDitebak(
                &game, huruf))
        {
            cout
            << "\nHuruf sudah pernah ditebak!\n";

            system("pause");

            continue;
        }

        prosesTebakan(
            &game, huruf);

        if(cekMenang(&game))
        {
            game.skor =
                hitungSkor(game.nyawa, game.level);

            system("cls");

            tampilkanGame(&game);

            cout
            << "\nSELAMAT ANDA MENANG!\n";

            cout << "Kata yang ditebak : " << game.kataAsli << endl;

            cout << "Skor Anda : " << game.skor << endl;

            return;
        }
    }

    system("cls");

    cout << "GAME OVER!\n\n";

    cout << "Kata yang benar adalah : " << game.kataAsli << endl;

    cout << "Skor Anda : 0\n";
}