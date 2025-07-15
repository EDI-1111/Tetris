#include "Funktionen.h"




void EdiTag()
{
    int abstandRand = 2;

    system("chcp 437");
    system("cls");
    cout << "\n\n\n\n\n";
    cout << "powerd by\n";
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(6) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(4) << "" << setfill(' ') << setw(5) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(6) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(5) << "" << setfill(' ') << setw(4) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(7) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(2) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(7) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(2) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(6) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(2) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(6) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(2) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(7) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(2) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(7) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(2) << "" << setfill('\xDB') << setw(2) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(6) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(5) << "" << setfill(' ') << setw(4) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << setfill(' ') << setw(abstandRand) << "" << setfill('\xDB') << setw(6) << "" << setfill(' ') << setw(3) << "" << setfill('\xDB') << setw(4) << "" << setfill(' ') << setw(5) << "" << setfill('\xDB') << setw(2) << "" << endl;
    cout << "\n\n\n\n\n";
    system("Pause");
}

void FensterGroesse()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFOEX csbi;
    csbi.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

    HWND console = GetConsoleWindow();
    RECT r;

    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 350, 500, TRUE);

    if (!GetConsoleScreenBufferInfoEx(hConsole, &csbi))
    {
        cout << "Fehler beim Abrufen der Konsoleninformationen." << endl;
        return;
    }

    COORD coord = { 40, 32 };

    if (!SetConsoleScreenBufferSize(hConsole, coord))
    {
        cout << "Fehler beim Setzen der Puffergröße." << endl;
        return;
    }


    SMALL_RECT rect;
    rect.Left = 0;
    rect.Right = 39;
    rect.Top = 0;
    rect.Bottom = 31;

    if (!SetConsoleWindowInfo(hConsole, TRUE, &rect))
    {
        cout << "Fehler bei der Fenstergrößenanpassung!" << endl;
    }
}

void FixiereFensterGroesse()
{
    HWND console = GetConsoleWindow();
    if (console == NULL)
    {
        cout << "Fehler: Konsole nicht gefunden!" << endl;
        return;
    }

    // Aktuelle Größe abrufen
    RECT rect;
    GetWindowRect(console, &rect);

    // Fenstergröße festlegen
    SetWindowLong(console, GWL_STYLE,
        GetWindowLong(console, GWL_STYLE) &
        ~(WS_SIZEBOX | WS_MAXIMIZEBOX | WS_THICKFRAME));
}

void GenerateSpielfeld(string spielfeld[31][40], int Hoehe, int Breite)
{
    for (int i = 0; i < Hoehe; i++)
    {
        for (int j = 0; j < Breite; j++)
        {
            spielfeld[i][j] = " ";
        }
    }
}

void ErzeugeRahmen(string spielfeld[31][40], int Hoehe, int Breite)
{
    for (int i = 0; i < Hoehe; i++)
    {
        for (int j = 0; j < Breite; j++)
        {
            if (j == 0 || j == 39 || i == 30)
            {
                spielfeld[i][j] = "#";
            }
        }
    }
}

void SpielfeldAnzeigen(string spielfeld[31][40], int Hoehe, int Breite)
{
    for (int i = 0; i < Hoehe; i++)
    {
        for (int j = 0; j < Breite; j++)
        {
            cout << spielfeld[i][j];
        }
        cout << endl;
    }
}

void DeleteBlock(vector<Position>& Stein)
{
    for (int i = 0; i < Stein.size(); i++)
    {
        // Zu Position (y,x)
        printf("\033[%d;%dH", Stein[i].x + 1, Stein[i].y + 1);
        //Zeichen in der Console überschreiben
        cout << " ";
    }
}

void MoveBlock(vector<Position>& Stein, Position& richtung)
{
    for (size_t i = 0; i < Stein.size(); i++)
    {
        DeleteBlock(Stein);

        //Dauerhafte Bewegung nach unten
        Stein[i].x += richtung.x;

        // Falls Links oder Rechts gedrückt wird -1 oder 1   wird die y Achse bewegt 
        Stein[i].y += richtung.y;
    }

    // Zurücksetzen der Richtung Y Achse
    richtung.y = 0;
}

void PrintBlock(vector<Position> Stein)
{
    //Schleife zum schreiben der Neuen Position in der Console
    for (int i = 0; i < Stein.size(); i++)
    {
        // Zu Position (y,x)
        printf("\033[%d;%dH", Stein[i].x + 1, Stein[i].y + 1);
        //Zeichen in der Console überschreiben
        cout << "█";
    }
}

void Rotate(vector<Position>& Stein)
{
    // Die Rotation der Steine erfolgt um den Mittelpunkt des jeweiligen Steines
    // 
    //      X = Position X Achse (Momentane Position)
    //      Y = Position Y Achse (Momentane Position)
    //
    //      dx = Differenz zur Start Position X   ( dx = x - cx )
    //      dy = Differenz zur Start Position Y   ( dy = y - cy )
    // 
    //      cx = Mittelpunkt X
    //      cy = Mittelpunkt Y
    // 
    //      rx = Fertig gedrehte Koordinaten
    //      ry = Fertig gedrehte Koordinaten


    // cx ,cy  für center/ Pivot Position
    Position pivot;

    // dx, dy 
    Position differenz;

    // count zum überprüfen ob ein Mittelpunkt vorhanden ist
    int Zcount = 0;
    // Mittelpunkt des jeweiligen steines wird ermittelt Z = 1 
    for (int i = 0; i < Stein.size(); i++)
    {

        // Koordinaten vom Mittelpunkt werden in pivot gespeichert
        if (Stein[i].z == 1)
        {
            pivot.x = Stein[i].x;
            pivot.y = Stein[i].y;
            Zcount++;
        }

    }
    // Überprüfung ob Mittelpunkt vorhanden wenn nicht  wird einfach die funktion Beendet
    if (Zcount == 0)
    {
        return;
    }
    DeleteBlock(Stein);

    // Berechnen der Differenz und Setzen der Neuen Koordinaten
    for (int i = 0; i < Stein.size(); i++)
    {
        // Differenz für jede Position wird errechnet
        differenz.x = Stein[i].x - pivot.x;
        differenz.y = Stein[i].y - pivot.y;

        // Vertauschen der Werte für eine 90° Drehung
        Stein[i].x = pivot.x + differenz.y;
        Stein[i].y = pivot.y - differenz.x;

    }

    PrintBlock(Stein);
}

void Score(int& Points)
{
    Points += 100;
    printf("\033[%d;%dH", 32, 1);
    cout << "Punkte: " << Points;
}

int MenuEingabe()
{

    int auswahl = _getch();

    while (auswahl < '1' || auswahl > '2') {
        auswahl = _getch();
    }

    return auswahl - '0';  // ASCII-Wert in Zahl umwandeln
}

void GameOver()
{
    printf("\033[%d;%dH", 15, 20);
    cout << "Game Over\n";
    printf("\033[%d;%dH", 17, 7);
    system("PAUSE");
    EdiTag();
    MenuAnzeigen();
}

bool CheckCollision(string spielfeld[31][40], vector<Position> Stein, Position& richtung, int Hoehe, int Breite)
{

    //Schleife für den jeweiligen Stein
    for (int i = 0; i < Stein.size(); i++)
    {
        if (richtung.x == 2)
        {
            if (spielfeld[Stein[i].x + 2][Stein[i].y] == "█" || spielfeld[Stein[i].x + 2][Stein[i].y] == "#")
            {
                richtung.x = 1;
            }
        }
        // Abfrage ob Wand oder Stein auf dem nächsten feld liegt.
        if (spielfeld[Stein[i].x + 1][Stein[i].y] == "█" || spielfeld[Stein[i].x + 1][Stein[i].y] == "#")
        {
            // Wenn etwas im weg ist wird der Stein in das Spielfeld gezeichnet.
            for (int i = 0; i < Stein.size(); i++)
            {
                if (spielfeld[Stein[i].x][Stein[i].y] == "█")
                {
                    //Game Over
                    GameOver();
                    return false;
                }
                richtung.x = 0;
                spielfeld[Stein[i].x][Stein[i].y] = "█";
                // Zu Position (y,x)
                printf("\033[%d;%dH", Stein[i].x + 1, Stein[i].y + 1);
                //Zeichen in der Console überschreiben
                cout << "█";
            }
            return false;
        }
        // Begrenzung der Richtung für Links und Rechts
        if (spielfeld[Stein[i].x][Stein[i].y + 1] == "#" || spielfeld[Stein[i].x][Stein[i].y - 1] == "#" ||
            spielfeld[Stein[i].x][Stein[i].y + 1] == "█" || spielfeld[Stein[i].x][Stein[i].y - 1] == "█" ||
            spielfeld[Stein[i].x + 1][Stein[i].y + 1] == "#" || spielfeld[Stein[i].x + 1][Stein[i].y - 1] == "#" ||
            spielfeld[Stein[i].x + 1][Stein[i].y + 1] == "█" || spielfeld[Stein[i].x + 1][Stein[i].y - 1] == "█")
        {
            richtung.y = 0;
        }
    }
}

void Blockgenerator(vector<Position>& Stein)
{
    // initialisierung des seeds und befüllung des zufallsgenerators
    random_device x;
    mt19937 gen1(x());
    uniform_real_distribution<> distrib1(1, 8);
    // Generiere eine Zufallszahl
    int auswahl = distrib1(gen1);

    Stein.clear();

    switch (auswahl)
    {
    case 1:
        Stein.push_back({ 1,19,0 });    // Links
        Stein.push_back({ 1,20,1 });    // Mittel punkt
        Stein.push_back({ 1,21,0 });    // Rechts
        Stein.push_back({ 0,20,0 });    // oberer stein
        break;
    case 2:
        Stein.push_back({ 0,20,0 });
        Stein.push_back({ 1,20,0 });
        Stein.push_back({ 2,20,1 });
        Stein.push_back({ 3,20,0 });
        Stein.push_back({ 4,20,0 });
        Stein.push_back({ 4,21,0 });
        break;
    case 3:
        Stein.push_back({ 0,20,0 });
        Stein.push_back({ 1,20,0 });
        Stein.push_back({ 2,20,1 });
        Stein.push_back({ 3,20,0 });
        Stein.push_back({ 4,20,0 });
        Stein.push_back({ 4,19,0 });
        break;
    case 4:
        Stein.push_back({ 0,18,0 });
        Stein.push_back({ 0,19,0 });
        Stein.push_back({ 0,20,1 });
        Stein.push_back({ 0,21,0 });
        Stein.push_back({ 0,22,0 });
        break;
    case 5:
        Stein.push_back({ 0,20,0 });
        Stein.push_back({ 0,21,0 });
        Stein.push_back({ 1,20,0 });
        Stein.push_back({ 1,21,0 });
        break;
    case 6:
        Stein.push_back({ 0,20,0 });
        Stein.push_back({ 1,20,1 });
        Stein.push_back({ 1,21,0 });
        break;
    case 7:
        Stein.push_back({ 0,20,0 });
        Stein.push_back({ 1,20,1 });
        Stein.push_back({ 1,19,0 });
        break;
    default:
        break;
    }
}

void checkArrowKeys(Position& richtung, vector<Position>& Stein)
{
    if (_kbhit())
    {
        int eingabe = _getch();


        if (eingabe == 0 || eingabe == 224 || eingabe == 32) {
            // Sondertasten wie Pfeiltasten liefern zwei Werte
            if (eingabe != 32)
            {
                eingabe = _getch();
            }


            switch (eingabe)
            {
                //Bewegung Nach Links
            case 75:
                richtung.y = -1;
                break;

                //Bewegung Nach Rechts
            case 77:
                richtung.y = 1;
                break;

                // Nach Unten
            case 80:
                richtung.x = 2;
                break;
            case 32:
                Rotate(Stein);
                break;
            }
        }
    }
}

void DeleteLine(string spielfeld[31][40], int i, int Breite)
{
    for (int j = 1; j < Breite - 1; j++)
    {
        // Löschen der Zeichen aus dem Spielfeld
        spielfeld[i][j] = " ";
        // Zu Position (x,y)
        printf("\033[%d;%dH", i + 1, j + 1);
        //Zeichen in der Console überschreiben
        cout << " ";
    }
}

void MoveLine(string spielfeld[31][40], int i, int j, int Breite)
{
    // Löschen der Zeichen aus dem Spielfeld
    spielfeld[i][j] = " ";
    // Zu Position (x,y)
    printf("\033[%d;%dH", i + 1, j + 1);
    //Zeichen in der Console überschreiben
    cout << " ";


    //Neue Position Setzen

    // Löschen der Zeichen aus dem Spielfeld
    spielfeld[i + 1][j] = "█";
    // Zu Position (x,y)
    printf("\033[%d;%dH", i + 2, j + 1);
    //Zeichen in der Console überschreiben
    cout << "█";

}

void checkFullLine(string spielfeld[31][40], int Hoehe, int Breite, int Points)
{
    for (int i = 0; i < Hoehe; i++)
    {
        int Linecount = 0;
        for (int j = 0; j < Breite; j++)
        {
            //Abfrage wieviele in einer Reihe belegt sind  (49 = alle)
            if (spielfeld[i][j] == "█")
            {
                Linecount++;
            }
        }
        if (Linecount == 38)
        {
            //wenn Reihe Voll dann Löschen
            DeleteLine(spielfeld, i, Breite);

            Score(Points);

            //alles was dadrüber ist muss eine Zeile runter x +1

            // i wird in Index gespeichert damit die neue schleife wei bis wohin sie kopieren soll
            // Zurücksetzen des zählers i damit die schleife vonvorne beginnt
            int index = i;

            for (index; index > 0; --index)
            {
                for (int j = 1; j < Breite; j++)
                {
                    if (spielfeld[index][j] == "█")
                    {
                        //Alte Position Löschen 
                        //Neue Position Setzen
                        MoveLine(spielfeld, index, j, Breite);
                    }
                }
            }
        }
    }
}

void hideConsoleCursor(bool hide = true)
{
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = !hide;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void Game()
{
    int Points = 0;
    bool collision = true;

    //Variablen für die Spielfeldgröße
    const int Hoehe = 31;  // X Achse
    const int Breite = 40; // Y Achse

    string spielfeld[Hoehe][Breite];

    // Leere Behälter für die Steine
    vector<Position> Stein;

    //Behälter für die Richtungen X u. Y Achsen
    Position richtung;
    //Standart werte für die Richtungen
    richtung.x = 1;
    richtung.y = 0;

    system("cls");
    GenerateSpielfeld(spielfeld, Hoehe, Breite);
    ErzeugeRahmen(spielfeld, Hoehe, Breite);
    SpielfeldAnzeigen(spielfeld, Hoehe, Breite);

    do
    {
        Blockgenerator(Stein);

        do
        {
            checkArrowKeys(richtung, Stein);
            collision = CheckCollision(spielfeld, Stein, richtung, Hoehe, Breite);

            if (collision == false)
            {
                Blockgenerator(Stein);
                collision = true;
                richtung.x = 1;
            }
            MoveBlock(Stein, richtung);
            PrintBlock(Stein);
            if (richtung.x == 2)
            {
                richtung.x = 1;
            }

            checkFullLine(spielfeld, Hoehe, Breite, Points);
            Sleep(350);
        } while (collision);

    } while (true);
}

void MenuAnzeigen()
{
    system("cls");
    //Spielfeld Rahmen
    for (int i = 0; i < 31; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            if (i == 0 || i == 30 || j == 0 || j == 39)
            {
                //Position Setzen
                printf("\033[%d;%dH", i + 1, j + 1);

                //Zeichen setzen
                cout << "#";
            }
        }
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i == 0 || i == 19 || j == 0 || j == 8)
            {
                //Position Setzen
                printf("\033[%d;%dH", j + 10, i + 11);

                //Zeichen setzen
                cout << "#";
            }
        }
    }

    //Position Setzen
    printf("\033[%d;%dH", 12, 18);
    //Zeichen setzen
    cout << "Tetris";

    //Position Setzen
    printf("\033[%d;%dH", 14, 16);
    //Zeichen setzen
    cout << "1. Spielen";

    //Position Setzen
    printf("\033[%d;%dH", 16, 16);
    //Zeichen setzen
    cout << "2. Beenden";

    switch (MenuEingabe())
    {
    case 1:
        Game();
        break;
    case 2:
        EdiTag();
        return;
    }
}

int main()
{
    FensterGroesse();
    FixiereFensterGroesse();

    // in und output werden auf codepage 65001 gesetzt UTF-8 
    system("chcp 65001");

    //Verstekt Cursor
    hideConsoleCursor(true);

    //Löscht gesamtes Bild
    system("cls");

    //Menu wird Aufgerufen
    MenuAnzeigen();

}







