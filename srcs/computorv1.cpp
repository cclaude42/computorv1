#include "computorv1.hpp"

POLY generate_poly (std::string input)
{
    if (input.find("=") == std::string::npos)
        throw std::invalid_argument("no = sign");
    input.erase(std::remove_if(input.begin(), input.end(), isspace), input.end());
    
    POLY poly;

    std::vector<std::string> before = split_expr(input.substr(0, input.find("=")));
    for (auto it = before.begin() ; it != before.end() ; it++) {
        parse_expr(poly, *it);
    } 

    std::vector<std::string> after = split_expr(input.substr(input.find("=") + 1));
    for (auto it = after.begin() ; it != after.end() ; it++) {
        (*it)[0] = ((*it)[0] == '-') ? '+' : '-';
        parse_expr(poly, *it);
    }
    
    return (poly);
}

void computorv1 (std::string input)
{
    POLY poly = generate_poly(input);

    for (auto it = poly.begin() ; it != poly.end() ; it++) {
        if (it->second == 0) {
            poly.erase(it);
            it = poly.begin();
        }
    }

    reduced_form(poly);
    polynomial_degree(poly);
    switch (poly.rbegin()->first) {
        case 0: solve_zero(poly);
                break;
        case 1: solve_one(poly);
                break;
        case 2: solve_two(poly);
                break;
        default: std::cout << "The polynomial degree is strictly greater than 2, I can't solve." << std::endl;
    }
}

int main (int ac, char **av)
{
    if (ac == 2) {
        try {
            computorv1(av[1]);
        }
        catch (std::exception & e) {
            std::cout << "Invalid input: " << e.what() << std::endl;
            return (1);
        }
    }
    else {
        std::cout << "Invalid number of arguments." << std::endl;
        return (1);
    }
    return (0);
}