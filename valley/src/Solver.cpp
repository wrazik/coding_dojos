#include "Solver.h"
/*
Dla danej struktury gor znalezc najwieksza doline, ktora można wypelnic najwieksza
iloscia wody. Struktura gor jest zakodowana poprzez ciag nieujemnych liczb calkowitych.
Odpowiedzia jest pojedyncza nieujemna liczba calkowita, ktora jest rowna objetosci
wody mogacej wypelnic najwieksza doline. Przyklady

Dla danych wejsciowych

1 0 3 5 4 1 2 1 3 0 1 2 0 1
W wyniku powinnismy otrzymac wartosc 8, dla doliny pokazanej na rysunku poniżej.

      |T|
      |T|T|
    |T|T|T|- - - -|T|
    |T|T|T|- -|T|-|T| |T|
|T| |T|T|T|-|T|T|T|T| |T|T| |T|
TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT */

Solver::Solver(std::vector<int>&& vec): valley_(vec) {}

int Solver::Solve(const std::vector<int> &input) {
    if(input.size() < 3) return 0;


    return -1;
}

std::pair<int, bool> Solver::LoopOverPeaks(size_t start) {
    for(auto j=start; j<valley_.size()-1; j++)
    {
        if(valley_[j] != valley_[j+1])
        {

            if(valley_[j] > valley_[j+1]) {
                return {start, true};
            }
            start = j;
            break;
        }
    }
    return {start, false};
}

std::vector<int> Solver::FindPeaks() {
    std::vector<int> res;
    size_t start = 1;
    if(valley_[0] > valley_[1]) {
        res.push_back(0);
    }
    if(valley_[0] == valley_[1]) {
        auto[j, isPeak] = LoopOverPeaks(1);
        if(isPeak)
        {
            res.push_back(0);
            start=j;
        }
    }

    for(size_t i=start; i< valley_.size()-1; i++){
        if(valley_[i-1] < valley_[i] && valley_[i] > valley_[i+1]) {
            res.push_back(i);
        }
        else if(valley_[i-1] < valley_[i] && valley_[i] == valley_[i+1])
        {
            auto[j, isPeak] = LoopOverPeaks(i);
            if(isPeak)
            {
                res.push_back(i);
                i=j;
            }
        }
    }

    if(valley_[valley_.size()-2] < valley_[valley_.size()-1])
        res.push_back(valley_.size()-1);

    return res;
}

