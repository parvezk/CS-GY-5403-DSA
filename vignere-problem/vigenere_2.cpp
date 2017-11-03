#include <iostream>
#include <string>

int main(){
    constexpr std::size_t N = 26 ;
    std::string alpha[N] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" } ;

    for( std::size_t i = 1 ; i < N ; ++i )
        alpha[i] = alpha[i-1].substr(1) + alpha[i-1][0] ;

    for( const auto& row : alpha ) std::cout << row << '\n' ;
}