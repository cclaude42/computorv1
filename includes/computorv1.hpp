#ifndef COMPUTORV1_HPP
# define COMPUTORV1_HPP

# include <iostream>
# include <sstream>
# include <algorithm>
# include <math.h>
# include <vector>
# include <map>

# define POLY std::map<size_t, float>

// Parsing
std::vector<std::string> split_expr (std::string poly);
void parse_expr (std::map<size_t, float> & poly, std::string expr);

// Solving
void reduced_form (POLY poly);
void polynomial_degree (POLY poly);
void solve_zero (POLY poly);
void solve_one (POLY poly);
void solve_two (POLY poly);

#endif