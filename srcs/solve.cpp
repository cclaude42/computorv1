#include "computorv1.hpp"

void reduced_form (POLY poly)
{
    std::string rform = "Reduced form :";

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
        if (ss.str() != "1" || it->second == 0) {
            rform += " ";
            rform += ss.str();
        }
        if (ss.str() != "1" && it->first > 0) {
            rform += " *";
        }
        if (it->first > 0) {
            rform += " X";
        }
        if (it->first > 1) {
            rform += "^";
            rform += std::to_string(it->first);
        }
    }

    rform += " = 0";

    std::cout << rform << std::endl << std::endl;
}

void polynomial_degree (POLY poly)
{
    std::string pdegree = "Polynomial degree : ";

    pdegree += std::to_string(poly.rbegin()->first);

    std::cout << pdegree << std::endl;
}

void solve_zero (POLY poly)
{
    std::cout << "No variables, only constants !" << std::endl << std::endl;
    std::cout << "Statement evaluates to : " << poly[0] << " = 0" << std::endl;
    if (poly[0] == 0)
        std::cout << "Statement is... TRUE !" << std::endl;
    else
        std::cout << "Statement is... FALSE !" << std::endl;
}

void solve_one (POLY poly)
{
    float sol = -poly[0] / poly[1];
    if (sol == -0.0f)
        sol = 0;

    std::cout << "Solving linearly :" << std::endl << std::endl;

    std::cout << "    " << poly[0] << " " << (poly[1] > 0 ? "+" : "") << poly[1] << "x = 0" << std::endl;
    std::cout << "<=> " << poly[1] << "x = " << -poly[0] << std::endl;
    std::cout << "<=> " << poly[1] << "x / " << poly[1] << " = " << -poly[0] << " / " << poly[1] << std::endl;
    std::cout << "<=> x = " << sol << std::endl << std::endl;

    std::cout << "The unique solution is :" << std::endl;
    std::cout << sol << std::endl;
}

void solve_two (POLY poly)
{
    float a = poly[2];
    float b = poly[1];
    float c = poly[0];
    float discr = b * b - 4 * a * c;

    std::cout << "Computing discriminant :" << std::endl << std::endl;

    std::cout << "    Δ = b² - 4ac" << std::endl;
    std::cout << "<=> Δ = " << b << "² - 4 * " << a << " * " << c << std::endl;
    std::cout << "<=> Δ = " << b * b << " - " << 4 * a * c << std::endl;
    std::cout << "<=> Δ = " << discr << std::endl << std::endl;

    float discr_abs = discr > 0 ? discr : -discr;
    
    std::cout << "Roots can be found by solving :" << std::endl << std::endl;

    std::cout << "    x = ( -b ± √Δ ) / (2 * a)" << std::endl;
    std::cout << "<=> x = ( -(" << b << ") ± √" << discr << " ) / (2 * " << a << ")" << std::endl;
    std::cout << "<=> x = ( " << -b << " ± " << sqrt(discr_abs) << (discr < 0 ? "i" : "") << " ) / " << 2 * a << std::endl;
    std::cout << "<=> x = " << -b << " / " << 2 * a << " ± " << sqrt(discr_abs) << (discr < 0 ? "i" : "") << " / " << 2 * a << std::endl;
    std::cout << "<=> x = " << -b / (2 * a) << " ± " << sqrt(discr_abs) / (2 * a) << (discr < 0 ? "i" : "") << std::endl << std::endl;


    if (discr > 0) {
        float sol1 = (-b + sqrt(discr)) / (2 * a);
        float sol2 = (-b - sqrt(discr)) / (2 * a);

        std::cout << "Discriminant is strictly positive, the two (real) solutions are :" << std::endl;
        std::cout << sol1 << std::endl;
        std::cout << sol2 << std::endl;
    }
    else if (discr < 0) {
        float real = -b / (2 * a);
        float complex = sqrt(-discr) / (2 * a);
    
        std::cout << "Discriminant is strictly negative, the two (complex) solutions are :" << std::endl;
        std::cout << real << " + " << complex << "i" << std::endl;
        std::cout << real << " - " << complex << "i" << std::endl;
    }
    else {
        float sol = -b / (2 * a);

        std::cout << "Discriminant is strictly zero, the one solution is :" << std::endl;
        std::cout << sol << std::endl;
    }
}