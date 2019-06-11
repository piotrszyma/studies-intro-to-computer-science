#include <stdio.h>

int czyPrzestepny(int rok);
int ilePrzestepnych(int rok_p, int rok_k);
int ileDniPier(int dzien, int miesiac, int rok);
int ileDniOst(int dzien, int miesiac, int rok);
int ileMinelo(int dzien_p, int miesiac_p, int rok_p, int dzien_k, int miesiac_k, int rok_k);

int main()
{

    printf("Program sprawdza ile dni (sekund) minelo miedzy dwiema datami.\nPodaj poszczegolne elementy daty zgodnie z instrukcja. \n");
    int dzien_p, miesiac_p, rok_p;
    printf("Najpierw wpisz date wczesniejsza. \nPodaj dzien (liczba calkowita z zakresu 1 - 31): ");
    scanf("%d", &dzien_p);
    while(dzien_p>31||dzien_p<1)
    {
        printf("Liczba calkowita z zakresu 1 - 31 \nPodaj dzien: ");
        scanf("%d", &dzien_p);
    }
    printf("Podaj miesiac (liczba calkowita z zakresu 1 - 12): ");
    scanf("%d", &miesiac_p);
    while(miesiac_p>12||miesiac_p<1)
    {
        printf("Podaj miesiac (liczba calkowita z zakresu 1 - 12): ");
        scanf("%d", &miesiac_p);
    }
    printf("Podaj rok (liczba calkowita wieksza od 0): ");
    scanf("%d", &rok_p);
    while(rok_p<1)
    {
        printf("Nie ma roku zerowego, podaj inny rok naszej ery (rok > 0)\n");
        scanf("%d", &rok_p);
    }


    int dzien_k, miesiac_k, rok_k;
    printf("Teraz wpisz date pozniejsza. \nPodaj dzien (liczba calkowita z zakresu 1 - 31): ");
    scanf("%d", &dzien_k);
    while(dzien_k>31||dzien_k<1)
    {
        printf("Liczba calkowita z zakresu 1 - 31 \nPodaj dzien: ");
        scanf("%d", &dzien_k);
    }
    printf("Podaj miesiac (liczba calkowita z zakresu 1 - 12): ");
    scanf("%d", &miesiac_k);
    while(miesiac_k>12||miesiac_k<1)
    {
        printf("Podaj miesiac (liczba calkowita z zakresu 1 - 12): ");
        scanf("%d", &miesiac_k);
    }
    printf("Podaj rok (liczba calkowita wieksza od 0): ");
    scanf("%d", &rok_k);
    while(rok_k<1)
    {
        printf("Nie ma roku zerowego, podaj inny rok naszej ery (rok > 0)\n");
        scanf("%d\n", &rok_k);
    }
    printf("Data poczatkowa: %d-%d-%d\n", dzien_p, miesiac_p, rok_p);
    printf("Data koncowa: %d-%d-%d\n", dzien_k, miesiac_k, rok_k);

    printf("Od tych dwoch dat minelo: ");

    int n = ileMinelo(dzien_p, miesiac_p, rok_p, dzien_k, miesiac_k, rok_k);

    printf("%d dni. (czyli %lu sekund)", n, n*86400);

    return 0;
}

/*********************************************************/

int ileMinelo(int dzien_p, int miesiac_p, int rok_p, int dzien_k, int miesiac_k, int rok_k)
{
    int iloscPrzest = ilePrzestepnych(rok_p+1, rok_k-1);
    int iloscLat = rok_k-rok_p-1;
    int suma = ileDniPier(dzien_p, miesiac_p, rok_p) + ileDniOst(dzien_k, miesiac_k, rok_k) + 365*(iloscLat - iloscPrzest) + 366*(iloscPrzest) - 1;
}

int czyPrzestepny(int rok)
{
    return ((rok%4==0)&&(rok%100!=0))||(rok%400==0);
}

int ilePrzestepnych(int rok_p, int rok_k)
{
    int ile=0;
    for(int i=rok_p; i<=rok_k; i++)
    {
        if(czyPrzestepny(i)==1)
        {
            ile++;
        }
    }

    return ile;
}

int ileDniPier(int dzien, int miesiac, int rok)
{
    int ile = 0;
    if(czyPrzestepny(rok))
    {
        int mies[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
        for(int i=miesiac; i<=11; i++)
        {
            ile+=mies[i];
        }
        return ile+mies[miesiac-1]-dzien+1;
    }
    else
    {
        int mies[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        for(int i=miesiac; i<=11; i++)
        {
            ile+=mies[i];
        }
        return ile+mies[miesiac-1]-dzien+1;
    }
}


int ileDniOst(int dzien, int miesiac, int rok)
{
    int ile=0;
    if(czyPrzestepny(rok))
    {
        int mies[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
        for(int i=miesiac-2; i>=0; i--)
        {
            ile+=mies[i];
        }
        return ile+dzien;
    }
    else
    {
        int mies[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        for(int i=miesiac-2; i>=0; i--)
        {
            ile+=mies[i];
        }
        return ile+dzien;
    }
}
