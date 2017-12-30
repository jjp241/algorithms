#include <iostream>

// <! Basic (dangerous) hash function !>

#define A 54059 //some primes
#define B 76963
#define C 1315423911
#define D 86969

unsigned hash_str(std::string s) //hash function
{
   unsigned h = D;
   for(int i = 0; i < s.size(); i++){
     h = (h * A) ^ (s[i] * B); //xor for smaller collision
     h = h << 2; //aditional bit shift
    }
   return h % C;
}

int main(){
  while(true){
    std::string s;
    std::cin >> s;
    unsigned int hash = hash_str(s);
    std::cout << hash << std::endl;
  }
}
