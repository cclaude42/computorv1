#include "computorv1.hpp"

void reduced_form (POLY poly)
{
    std::string rform = "Reduced form:";

    for (auto it = poly.begin() ; it != poly.end() ; it++) {
        std::stringstream ss;
        if (it->second >= 0)
            ss << it->second;
        else
            ss << (it->second * -1);

        if (it != poly.begin() || it->second < 0) {
            rform += " ";
            rform += (it->second >= 0) ? "+" : "-";
        }
        rform += " ";
        rform += ss.str();
        rform += " * X^";
        rform += std::to_string(it->first);
    }

    rform += " = 0";

    std::cout << rform << std::endl;
}

void polynomial_degree (POLY poly)
{
    std::string pdegree = "Polynomial degree: ";

    pdegree += std::to_string(poly.rbegin()->first);

    std::cout << pdegree << std::endl;
}

void solve_zero (POLY poly)
{
    std::cout << "No variables, only constants !" << std::endl;
    std::cout << "Statement evaluates to: " << poly[0] << " = 0" << std::endl;
    if (poly[0] == 0)
        std::cout << "Statement is... TRUE !" << std::endl;
    else
        std::cout << "Statement is... FALSE !" << std::endl;
}

void solve_one (POLY poly)
{
    float sol = poly[0] * -1 / poly[1];
    std::cout << "The solution is :" << std::endl;
    std::cout << sol << std::endl;
}

void solve_two (POLY poly)
{
    float a = poly[2];
    float b = poly[1];
    float c = poly[0];
    float discr = b * b - 4 * a * c;
    if (discr > 0) {
        float sol1 = (-b + sqrt(discr)) / (2 * a);
        float sol2 = (-b - sqrt(discr)) / (2 * a);
        std::cout << "Discriminant is strictly positive, the two (real) solutions are:" << std::endl;
        std::cout << sol1 << std::endl;
        std::cout << sol2 << std::endl;
    }
    else if (discr < 0) {
        float real = -b / (2 * a);
        float complex = sqrt(-discr) / (2 * a);
        std::cout << "Discriminant is strictly negative, the two (complex) solutions are:" << std::endl;
        std::cout << real << " + " << complex << "i" << std::endl;
        std::cout << real << " - " << complex << "i" << std::endl;
    }
    else {
        std::cout << "Discriminant is strictly zero, the one solution is:" << std::endl;
    }
}