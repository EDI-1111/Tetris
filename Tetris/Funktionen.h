#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#define NOMINMAX
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <random>
#include <vector>
#include <thread>
#include <future>
#include <chrono>
using namespace std;

struct Position
{
    int x, y, z;
};


void FensterGroesse();

void FixiereFensterGroesse();

void EdiTag();

void GenerateSpielfeld(string spielfeld[31][40], int Hoehe, int Breite);

void ErzeugeRahmen(string spielfeld[31][40], int Hoehe, int Breite);

void SpielfeldAnzeigen(string spielfeld[31][40], int Hoehe, int Breite);

void DeleteBlock(vector<Position>& Stein);

void MoveBlock(vector<Position>& Stein, Position& richtung);

void PrintBlock(vector<Position> Stein);

void Rotate(vector<Position>& Stein);

void Score(int& Points);

int MenuEingabe();

void GameOver();

bool CheckCollision(string spielfeld[31][40], vector<Position> Stein, Position& richtung, int Hoehe, int Breite);

void Blockgenerator(vector<Position>& Stein);

void checkArrowKeys(Position& richtung, vector<Position>& Stein);

void DeleteLine(string spielfeld[31][40], int i, int Breite);

void MoveLine(string spielfeld[31][40], int i, int j, int Breite);

void checkFullLine(string spielfeld[31][40], int Hoehe, int Breite, int Points);

void hideConsoleCursor(bool hide);

void Game();

void MenuAnzeigen();
