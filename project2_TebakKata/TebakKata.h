#ifndef TEBAKKATA_H
#define TEBAKKATA_H

#include <iostream>
#include <string>

using namespace std;

struct KataGame
{
    string kataAsli;
    string statusTebakan;

    int nyawa;

    char tebakanSalah[26];
    int jumlahSalah;

    int level;
    int skor;
};

extern string daftarKata[15];

void pilihKesulitan(KataGame *game);
void inisialisasiGame(KataGame *game);
void tampilkanGame(KataGame *game);

bool hurufSudahDitebak(
    KataGame *game,
    char huruf);

void prosesTebakan(
    KataGame *game,
    char huruf);

bool cekMenang(
    KataGame *game);

int hitungSkor(
    int nyawa,
    int level);

void mainkanGame();

#endif
