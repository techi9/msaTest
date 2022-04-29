#include "sign.h"
#include "convertation.h"
#include "tools.h"

#include <cstdlib>
#include <msa.h>

bool sign_bit_add(v4i32 rns1, v4i32 rns2, v4i32 basis, int basis_size){
    if (rns1[basis_size] == 0 && rns2[basis_size] == 0)
        return false;
    else if (rns1[basis_size] == 1 && rns2[basis_size] == 1)
        return true;
    else if (rns1[basis_size] == 1 && rns2[basis_size] == 0){
        int dec1 = Convertation::RNS2dec(rns1, basis, basis_size);
        int dec2 = Convertation::RNS2dec(rns2, basis, basis_size);
        return abs(dec1) > abs(dec2);
    }
    else if (rns1[basis_size] == 0 && rns2[basis_size] == 1){
        int dec1 = Convertation::RNS2dec(rns1, basis, basis_size);
        int dec2 = Convertation::RNS2dec(rns2, basis, basis_size);
        return abs(dec1) < abs(dec2);
    }
}

bool sign_bit_mult(v4i32 rns1, v4i32 rns2, int basis_size){
    if(rns1[basis_size] == 0 && rns2[basis_size] == 0)
        return false;
    else if (rns1[basis_size] == 1 && rns2[basis_size] == 1)
        return false;
    else
        return !(Tools::vec_sum(rns1, basis_size) == 0 || Tools::vec_sum(rns2, basis_size) == 0);
}