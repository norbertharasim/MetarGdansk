#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;
void menu(char& wybor) {
    cout << endl;
    cout << "WITAJ NORBERT HARASIM NR. 203151" << endl;
    cout << "---------------------" << endl;
    cout << "\tMENU " << endl;
    cout << "WPISZ 'o' ABY POBRAC DANE Z PLIKU Metar_Gdansk.txt, WYSWIETLIC TE DANE I ZAPISAC DO PLIKU pogoda_gd.txt" << endl;
    cout << "WPISZ 'q' ABY ZAMKNAC PROGRAM " << endl;
    cin >> wybor;
}

void wyswietlenie_i_zapisanie() {
    char wybor;
    while (true)
    {
        menu(wybor);

        switch (wybor)
        {
        case 'o':
        {
            ifstream plikIn("C:/Users/norbe/Desktop/Metar_Gdansk.txt");
            if (!plikIn) {
                cout << "BLAD PLIK SIE NIE OTWORZYL!" << endl;
                return;
            
}

            ofstream plikOut("C:/Users/norbe/Desktop/pogoda_gd.txt");
            if (!plikOut) {
                cout << "BLAD PLIK SIE NIE UTWORZYL!" << endl;
                return;
            
}

            char c[200];
            int ile_lini_start = 0;
            int ile_lini = 0;
            while (plikIn.getline(c, 200)) //to tylko liczy ile jest lini w pliku
            {
                ile_lini_start++;
            
}
            plikIn.clear();
            plikIn.seekg(0, ios::beg);  //wraca wskaznik na poczatku pliku


            while (plikIn.getline(c, 200))
            {
                if (strstr(c, "EPGD") == NULL)
                    continue;
                if (ile_lini >= 0 && ile_lini < 3)
                    cout << endl << c << endl;
                plikOut << c << endl;
                char* wsk;
                wsk = strtok(c, " ");
                int ktory_token = 0;

                while (wsk != NULL)
                {
                    if (ktory_token == 1)
                    {
                        if (ile_lini >= 0 && ile_lini < 3)
                        {
                            cout << " DZIEN: " << wsk[0] << wsk[1] << " " << endl;
                            cout << " CZAS UTC: " << wsk[2] << wsk[3] << ":" << wsk[4] << wsk[5] << endl;
                        
}
                        plikOut << " DZIEN: " << wsk[0] << wsk[1] << " " << endl;
                        plikOut << " CZAS UTC: " << wsk[2] << wsk[3] << ":" << wsk[4] << wsk[5] << endl;
                    
}

                    if (ktory_token == 2)
                    {
                        if (wsk[0] == '0' && wsk[3] == '0')
                        {
                            if (ile_lini >= 0 && ile_lini < 3)
                                cout << " WIATR Z KIERUNKU: " << wsk[1] << wsk[2] << " STOPNI, PREDKOSC: " << wsk[4] << " WEZLOW" << endl;
                            plikOut << " WIATR Z KIERUNKU: " << wsk[1] << wsk[2] << " STOPNI, PREDKOSC: " << wsk[4] << " WEZLOW" << endl;
                        
}

                        else if (wsk[0] == '0' && wsk[3] != '0')
                        {
                            if (ile_lini >= 0 && ile_lini < 3)
                                cout << " WIATR Z KIERUNKU: " << wsk[1] << wsk[2] << " STOPNI, PREDKOSC: " << wsk[3] << wsk[4] << " WEZLOW" << endl;
                            plikOut << " WIATR Z KIERUNKU: " << wsk[1] << wsk[2] << " STOPNI, PREDKOSC: " << wsk[3] << wsk[4] << " WEZLOW" << endl;
                        
}
                        else if (isdigit(wsk[0]) == true && wsk[3] == '0')
                        {
                            if (ile_lini >= 0 && ile_lini < 3)
                                cout << " WIATR Z KIERUNKU: " << wsk[0] << wsk[1] << wsk[2] << " STOPNI, PREDKOS: " << wsk[4] << " WEZLOW" << endl;
                            plikOut << " WIATR Z KIERUNKU: " << wsk[0] << wsk[1] << wsk[2] << " STOPNI, PREDKOSC: " << wsk[4] << " WEZLOW" << endl;
                        
}
                        else if (wsk[0] == 'V')
                        {
                            if (ile_lini >= 0 && ile_lini < 3)
                                cout << " WIATR ZMIENNY PREDKOSC: " << wsk[3] << wsk[4] << " WEZLOW " << endl;
                            plikOut << " WIATR ZMIENNY PREDKOSC: " << wsk[3] << wsk[4] << " WEZLOW " << endl;
                        
}
                        else
                        {
                            if (ile_lini >= 0 && ile_lini < 3)
                                cout << " WIATR Z KIERUNKU: " << wsk[0] << wsk[1] << wsk[2] << " STOPNI, PREDKOSC: " << wsk[3] << wsk[4] << " WEZLOW " << endl;
                            plikOut << " WIATR Z KIERUNKU: " << wsk[0] << wsk[1] << wsk[2] << " STOPNI, PREDKOSC: " << wsk[3] << wsk[4] << " WEZLOW " << endl;
                        
}
                    
}

                    if (strlen(wsk) == 7 && wsk[3] == 'V')
                    {
                        plikOut << " ZMIENNOSC WIATRU OD: " << wsk[0] << wsk[1] << wsk[2] << " STOPNI DO: " << wsk[4] << wsk[5] << wsk[6] << " STOPNI " << endl;
                    
}


                    if ((wsk[2] == '/' || wsk[3] == '/') && strlen(wsk) >= 5 && strlen(wsk) <= 7)
                    {
                        if (wsk[0] == 'M')
                        {
                            if (wsk[4] == 'M')
                            {
                                if (ile_lini >= 0 && ile_lini < 3)
                                    cout << " TEMPERATURA: -" << wsk[1] << wsk[2] << " STOPNI CELSJUSZA \n TEMPERATURA PUNKTU ROSY -" << wsk[5] << wsk[6] << " STOPNI CELSJUSZA" << endl;
                                plikOut << " TEMPERATURA: -" << wsk[1] << wsk[2] << " STOPNI CELSJUSZA  \n TEMPERATURA PUNKTU ROSY -" << wsk[5] << wsk[6] << " STOPNI CELSJUSZA" << endl;
                            
}
                            else
                            {
                                if (ile_lini >= 0 && ile_lini < 3)
                                    cout << " TEMPERATURA: -" << wsk[1] << wsk[2] << " STOPNI CELSJUSZA \n TEMPERATURA PUNKTU ROSY " << wsk[4] << wsk[5] << " STOPNI CELSJUSZA" << endl;
                                plikOut << " TEMPERATURA: -" << wsk[1] << wsk[2] << " STOPNI CELSJUSZA  \n TEMPERATURA PUNKTU ROSY " << wsk[4] << wsk[5] << " STOPNI CELSJUSZA" << endl;
                            
}
                        
}

                        else
                        {
                            if (wsk[3] == 'M')
                            {
                                if (ile_lini >= 0 && ile_lini < 3)
                                    cout << " TEMPERATURA: " << wsk[0] << wsk[1] << " STOPNI CELSJUSZA \n TEMPERATURA PUNKTU ROSY -" << wsk[4] << wsk[5] << " STOPNI CELSJUSZA" << endl;
                                plikOut << " TEMPERATURA: " << wsk[0] << wsk[1] << " STOPNI CELSJUSZA  \n TEMPERATURA PUNKTU ROSY -" << wsk[4] << wsk[5] << " STOPNI CELSJUSZA" << endl;
                            
}
                            else
                            {
                                if (ile_lini >= 0 && ile_lini < 3)
                                    cout << " TEMPERATURA: " << wsk[0] << wsk[1] << " STOPNI CELSJUSZA \n TEMPERATURA PUNKTU ROSY " << wsk[3] << wsk[4] << " STOPNI CELSJUSZA" << endl;
                                plikOut << " TEMPERATURA: " << wsk[0] << wsk[1] << " STOPNI CELSJUSZA  \n TEMPERATURA PUNKTU ROSY " << wsk[3] << wsk[4] << " STOPNI CELSJUSZA" << endl;
                            
}
                        
}
                    
}

                    if (wsk[0] == 'Q')
                    {
                        if (wsk[1] == '0')
                        {
                            if (ile_lini >= 0 && ile_lini < 3)
                                cout << " -CISNIENIE AMTOSFERYCZNE: " << wsk[2] << wsk[3] << wsk[4] << " hPa" << endl;
                            plikOut << " -CISNIENIE AMTOSFERYCZNE: " << wsk[2] << wsk[3] << wsk[4] << " hPa" << endl;
                            plikOut << endl;
                        
}
                        else
                        {
                            if (ile_lini >= 0 && ile_lini < 3)
                            {
                                cout << " -CISNIENIE AMTOSFERYCZNE: " << wsk[1] << wsk[2] << wsk[3] << wsk[4] << " hPa" << endl;
                            
}
                            plikOut << " -CISNIENIE AMTOSFERYCZNE: " << wsk[1] << wsk[2] << wsk[3] << wsk[4] << " hPa" << endl;
                        
}
                    
}

                    if (((ktory_token == 3 || ktory_token == 4) && (strlen(wsk) == 4) && (wsk[0] >= '1' && wsk[0] <= '9')))
                    {
                        if (wsk[0] == '9' && wsk[1] == '9' && wsk[2] == '9' && wsk[3] == '9')
                        {
                            if (ile_lini >= 0 && ile_lini < 3)
                                cout << " WIDZIALNOSC 10000 METROW I WIECEJ " << endl;
                            plikOut << " WIDZIALNOSC 10000 METROW I WIECEJ " << endl;
                        
}
                        else
                        {
                            if (ile_lini >= 0 && ile_lini < 3)
                                cout << " WIDZIALNOSC: " << wsk << " METROW " << endl;
                            plikOut << " WIDZIALNOSC: " << wsk << " METROW " << endl;
                        
}
                    
}
                    else if (strlen(wsk) == 5 && (wsk[0] == 'C' && wsk[1] == 'A'))
                    {
                        if (ile_lini >= 0 && ile_lini < 3)
                            cout << " WIDZIALNOŚĆ 10 KM LUB WIĘCEJ, BRAK CHMUR PONIŻEJ 1500M\n BRAK CHMUR CB, BRAK OPADÓW, BURZ, ITP. " << endl;
                        plikOut << " WIDZIALNOŚĆ 10 KM LUB WIĘCEJ,\n BRAK CHMUR PONIŻEJ 1500M\n BRAK CHMUR CB, BRAK OPADÓW, BURZ, ITP. " << endl;
                    
}

                    if (((ktory_token == 4 || ktory_token == 5) && (strlen(wsk) >= 2 && strlen(wsk) <= 5)))
                    {
                        if (ile_lini >= 0 && ile_lini < 3)
                        {
                            char* temp = wsk;
                            if (temp[0] == '-')
                            {
                                cout << " SLABE(BY) ";
                                temp++;
                            
}
                            else if (temp[0] == '+')
                            {
                                cout << " SILNE ";
                                temp++;
                            
}
                            else if (strncmp(temp, "VC", 2) == 0)
                            {
                                cout << " W POBLIŻU ";
                                temp += 2;
                            
}

                            if (strstr(wsk, "SH") != NULL)cout << " PRZELOTNY(NE) ";
                            if (strstr(wsk, "FZ") != NULL)cout << " MARZNĄCE " << endl;
                            if (strstr(wsk, "RA") != NULL)cout << " DESZCZ " << endl;
                            if (strstr(wsk, "SN") != NULL)cout << " ŚNIEG " << endl;
                            if (strstr(wsk, "DZ") != NULL)cout << "MŻAWKA " << endl;
                            if (strstr(wsk, "SG") != NULL)cout << " ŚNIEG ZIARNISTY " << endl;
                            if (strstr(wsk, "IC") != NULL)cout << " SLUPKI LODOWE " << endl;
                            if (strstr(wsk, "PE") != NULL)cout << " DESZCZ LODOWY " << endl;
                            if (strstr(wsk, "GR") != NULL)cout << " GRAD " << endl;
                            if (strstr(wsk, "GS") != NULL)cout << " KRUPA ŚNIEŻNA/LODOWA " << endl;
                            if (strstr(wsk, "BR") != NULL)cout << " ZAMGLENIE " << endl;
                            if (strstr(wsk, "FG") != NULL)cout << " MGLA " << endl;
                            if (strstr(wsk, "FU") != NULL)cout << " DYMY " << endl;
                            if (strstr(wsk, "VA") != NULL)cout << " POPIÓL WULKANICZNY " << endl;
                            if (strstr(wsk, "DU") != NULL)cout << " PYL " << endl;
                            if (strstr(wsk, "SA") != NULL)cout << " PIASEK " << endl;
                            if (strstr(wsk, "HZ") != NULL)cout << " ZAMGLAWIANIE " << endl;
                            if (strstr(wsk, "PO") != NULL)cout << " SILNIE ROZWINIĘTE WIRY PYLOWE " << endl;
                            if (strstr(wsk, "SQ") != NULL)cout << " NAWALNICA " << endl;
                            if (strstr(wsk, "FC") != NULL)cout << " TRĄBA POWIETRZNA/WODNA/TORNADO " << endl;
                            if (strstr(wsk, "SS") != NULL)cout << " BURZA PIASKOWA " << endl;
                            if (strstr(wsk, "DS") != NULL)cout << " BURZA PYŁOWA " << endl;
                        
}

                        char* temp = wsk;
                        if (temp[0] == '-')
                        {
                            plikOut << " SŁABE(BY) ";
                            temp++;
                        
}
                        else if (temp[0] == '+')
                        {
                            plikOut << " SILNE ";
                            temp++;
                        
}
                        else if (strncmp(temp, "VC", 2) == 0)
                        {
                            plikOut << " W POBLIŻU ";
                            temp += 2;
                        
}
                        if (strstr(wsk, "SH") != NULL)plikOut << " PRZELOTNY(NE) ";
                        if (strstr(wsk, "FZ") != NULL)plikOut << " MARZNĄCE " << endl;
                        if (strstr(wsk, "RA") != NULL)plikOut << " DESZCZ " << endl;
                        if (strstr(wsk, "SN") != NULL)plikOut << " ŚNIEG " << endl;
                        if (strstr(wsk, "DZ") != NULL)plikOut << " MŻAWKA " << endl;
                        if (strstr(wsk, "SG") != NULL)plikOut << " ŚNIEG ZIARNISTY " << endl;
                        if (strstr(wsk, "IC") != NULL)plikOut << " SŁUPKI LODOWE " << endl;
                        if (strstr(wsk, "PE") != NULL)plikOut << " DESZCZ LODOWY " << endl;
                        if (strstr(wsk, "GR") != NULL)plikOut << " GRAD " << endl;
                        if (strstr(wsk, "GS") != NULL)plikOut << " KRUPA ŚNIEŻNA/LODOWA " << endl;
                        if (strstr(wsk, "BR") != NULL)plikOut << " ZAMGLENIE " << endl;
                        if (strstr(wsk, "FG") != NULL)plikOut << " MGŁA " << endl;
                        if (strstr(wsk, "FU") != NULL)plikOut << " DYMY " << endl;
                        if (strstr(wsk, "VA") != NULL)plikOut << " POPIÓŁ WULKANICZNY " << endl;
                        if (strstr(wsk, "DU") != NULL)plikOut << " PYŁ " << endl;
                        if (strstr(wsk, "SA") != NULL)plikOut << " PIASEK " << endl;
                        if (strstr(wsk, "HZ") != NULL)plikOut << " ZAMGŁAWIANIE " << endl;
                        if (strstr(wsk, "PO") != NULL)plikOut << " SILNIE ROZWINIĘTE WIRY PYŁOWE " << endl;
                        if (strstr(wsk, "SQ") != NULL)plikOut << " NAWAŁNICA " << endl;
                        if (strstr(wsk, "FC") != NULL)plikOut << " TRĄBA POWIETRZNA/WODNA/TORNADO " << endl;
                        if (strstr(wsk, "SS") != NULL)plikOut << " BURZA PIASKOWA " << endl;
                        if (strstr(wsk, "DS") != NULL)plikOut << " BURZA PYŁOWA " << endl;

                    
}
                    if (isdigit(wsk[0]) == false && (strlen(wsk) == 6 || strlen(wsk) == 8))
                    {
                        if (ile_lini >= 0 && ile_lini < 3)
                        {
                            int wysokosc = (wsk[3] - '0') * 10000 + (wsk[4] - '0') * 1000 + (wsk[5] - '0') * 100;
                            if (strstr(wsk, "FEW") != NULL)
                            {
                                cout << " NIELICZNE CHMURY: 1/8 LUB 2/8 POKRYCIA." << "NA WYSOKOSCI " << wysokosc << " STOP" << endl;
                            
}
                            if (strstr(wsk, "SCT") != NULL) cout << " ROZPROSZONE CHMURY: 3/8 LUB 4/8 POKRYCIA " << "NA WYSOKOSCI " << wysokosc << " STOP" << endl;
                            if (strstr(wsk, "BKN") != NULL) cout << " CHMURY KLEBIASTE: POKRYCIE OD 5/8 DO 7/8 " << "NA WYSOKOSCI " << wysokosc << " STOP" << endl;
                            if (strstr(wsk, "OVC") != NULL) cout << " ZACHMURZENIE CALKOWITE: 8/8 POKRYCIA " << "NA WYSOKOSCI " << wysokosc << " STOP" << endl;
                        
}
                        int wysokosc = (wsk[3] - '0') * 10000 + (wsk[4] - '0') * 1000 + (wsk[5] - '0') * 100;
                        if (strstr(wsk, "FEW") != NULL)
                        {
                            plikOut << " NIELICZNE CHMURY: 1/8 LUB 2/8 POKRYCIA." << "NA WYSOKOSCI " << wysokosc << " STOP" << endl;
                        
}
                        if (strstr(wsk, "SCT") != NULL) plikOut << " ROZPROSZONE CHMURY: 3/8 LUB 4/8 POKRYCIA " << "NA WYSOKOSCI " << wysokosc << " STOP" << endl;
                        if (strstr(wsk, "BKN") != NULL) plikOut << " CHMURY KLEBIASTE: POKRYCIE OD 5/8 DO 7/8 " << "NA WYSOKOSCI " << wysokosc << " STOP" << endl;
                        if (strstr(wsk, "OVC") != NULL) plikOut << " ZACHMURZENIE CALKOWITE: 8/8 POKRYCIA  " << "NA WYSOKOSCI " << wysokosc << " STOP" << endl;
                    
}
                    wsk = strtok(NULL, " ");
                    ktory_token++;
                
}
                ile_lini++;
            
}
            plikOut.close();
            plikIn.close();
            break;
        
}
        case 'q':
            return;

        default:
        {
            cout << "PODALES ZLA OPCJE" << endl;
        
}
        
}
    
}
}
int main()
{
    wyswietlenie_i_zapisanie();
    system("pause");
    return 0;
}
