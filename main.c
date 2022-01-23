#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "gauss.h"



int newRandom(int, int);


int main()
{
    int stadt = 10;
    // Dateizeiger
    FILE * fp;
    fp = fopen("TestmengeNEU10k.csv", "w");

    if (fp == NULL)
    {
        printf_s("Dateifehler\n");
        return 1;
    }

    // fprintf lenkt Ausgabe in Datei um
    fprintf_s(fp, "y, x1, x2, x4, x5, x6, x7\n");
    /*
        y = Stadt
        x1 = Preis pro qm
        x2 = durchschnittl. Internetgeschwindigkeit in Mbit/s
        x3 = Bildungsindex Hochschulen / 100.000 Einwohner <--- gerade nicht drinne
        x4 = Distanz zum Flughafen in km
        x5 = Grünflächenanteil
        x6 = Preisentwicklung
        x7 = Luftbelastung (Stickstoffdioxidwert in Mirkrogramm pro Kubikmeter)
    */

    srand(time(0));

    for(int i = 1; i <= 10000; i++)
    {

        stadt = newRandom(0, 9);

        switch(stadt)
        {
            case 0: //München
                fprintf_s(fp, "%d, %d, %f, %d, %f, %f, %f\n", stadt, newRandom(6468, 11848), randn(49.63, 10), newRandom(24, 34), randn(49.9, 5), randn(4.3, 0.9), randn(54, 7));
                break;

            case 1: //Berlin
                fprintf_s(fp, "%d, %d, %f, %d, %f, %f, %f\n", stadt, newRandom(3654, 9067), randn(59.65, 10), newRandom(2, 10), randn(59.0, 5), randn(10.3, 0.9), randn(40, 7));
                break;

            case 2: //Hamburg
                fprintf_s(fp, "%d, %d, %f, %d, %f, %f, %f\n", stadt, newRandom(3169, 9598), randn(59.41, 10), newRandom(2, 14), randn(71.4, 5), randn(9.2, 0.9), randn(41, 7));
                break;

            case 3: //Köln
                fprintf_s(fp, "%d, %d, %f, %d, %f, %f, %f\n", stadt, newRandom(3127, 7507), randn(68.94, 10), newRandom(10, 20), randn(58.4, 5), randn(9.5, 0.9), randn(35, 7));
                break;

            case 4: //Stuttgart
                fprintf_s(fp, "%d, %d, %f, %d, %f, %f, %f\n", stadt, newRandom(3712, 7726), randn(73.44, 10), newRandom(7, 13), randn(69.9, 5), randn(14.7, 0.9), randn(43, 7));
                break;

            case 5: //Frankfurt
                fprintf_s(fp, "%d, %d, %f, %d, %f, %f, %f\n", stadt, newRandom(3847, 8830), randn(79.19, 10), newRandom(7, 20), randn(58.4, 5), randn(10, 0.9), randn(40, 7));
                break;

            case 6: //Leipzig
                fprintf_s(fp, "%d, %d, %f, %d, %f, %f, %f\n", stadt, newRandom(1655, 4227), randn(57.74, 10), newRandom(8, 18), randn(42.4, 5), randn(15.3, 0.9), randn(42, 7));
                break;

            case 7: //Düsseldorf
                fprintf_s(fp, "%d, %d, %f, %d, %f, %f, %f\n", stadt, newRandom(3307, 8910), randn(77.34, 10), newRandom(2, 16), randn(56.7, 5), randn(8.5, 0.9), randn(39, 7));
                break;

            case 8: //Dortmund
                fprintf_s(fp, "%d, %d, %f, %d, %f, %f, %f\n", stadt, newRandom(1533, 3615), randn(64.56, 10), newRandom(4, 20), randn(70.7, 5), randn(12.5, 0.9), randn(35, 7));
                break;

            case 9: //Bremen
                fprintf_s(fp, "%d, %d, %f, %d, %f, %f, %f\n", stadt, newRandom(1405, 5219), randn(53.19, 10), newRandom(1, 8), randn(68.2, 5), randn(13.4, 0.9), randn(40, 7));

                break;

            default: printf("Fehler! (Case)");
        }

    }

    // fclose trennt Verbindung zur Datei
    fclose(fp);

    // Augabe fertig
    printf("Datei fertig\n");
    return 0;
}

int newRandom(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}


