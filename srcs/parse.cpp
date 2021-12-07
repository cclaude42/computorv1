#include "computorv1.hpp"

int is_float (std::string input)
{
    if (input.length() == 0)
        return (0);
    if (input.find_first_not_of("0123456789.-+") != std::string::npos)
        return (0);
    if (input.find("-") != std::string::npos && input.rfind("-") != 0)
        return (0);
    if (input.find("+") != std::string::npos && input.rfind("+") != 0)
        return (0);
    if (input.find(".") != input.rfind("."))
        return (0);
    return (1);
}

int is_power (std::string input)
{
    if (input.length() == 0)
        return (0);
    if (input.find_first_not_of("0123456789X^") != std::string::npos)
        return (0);
    if (input == "X")
        return (1);
    if (input[0] != 'X')
        return (0);
    if (input[1] != '^')
        return (0);
    if (input.substr(2).find_first_not_of("0123456789") != std::string::npos)
        return (0);
    return (1);
}

void check_input (std::string input)
{
    if (input.find_first_not_of("0123456789.-+*^X") != std::string::npos)
        throw std::invalid_argument("invalid character in input (" + input + ")");

    if (input.find("*") == std::string::npos) {
        if (!is_float(input) && !is_power(input.substr(1)))
            throw std::invalid_argument("missing * sign (" + input + ")");
        return ;
    }

    std::string coeff = input.substr(0, input.find("*"));
    std::string power = input.substr(input.find("*") + 1);

    if (!is_float(coeff))
        throw std::invalid_argument("invalid character in coeff part (" + coeff + ")");

    if (!is_power(power))
        throw std::invalid_argument("invalid character in X^n part (" + power + ")");
}

void parse_expr (std::map<size_t, float> & poly, std::string expr)
{
    check_input(expr);

    float coeff = 1;
    size_t power = 0;

    if (expr.find("*") != std::string::npos) {
        coeff = std::stof(expr);
        expr.erase(0, expr.find("*") + 1);
        if (expr == "X")
            power = 1;
        else {
            power = std::stoi(expr.substr(2));
        }
    }
    else if (expr.find("X") != std::string::npos) {
        if (expr[0] == '-')
            coeff = -1;
        expr.erase(0, 1);
        if (expr == "X")
            power = 1;
        else {
            power = std::stoi(expr.substr(2));
        }
    }
    else {
        coeff = std::stof(expr);
    }


    poly[power];
    poly[power] += coeff;
}

std::vector<std::string> split_expr (std::string poly)
{
    std::vector<std::string> segments;
    std::string sign;
    size_t idx;

    if (poly[0] != '-' && poly[0] != '+')
        poly = "+" + poly;

    while (poly.length()) {
        sign = poly.substr(0, 1);
        poly.erase(0, 1);
        idx = poly.find_first_of("-+");
        segments.push_back(sign + poly.substr(0, idx));
        poly.erase(0, idx);
    }

    return (segments);
}