#include <iostream>
#include <cmath>
#include <iomanip>

double norm_cdf(double x) {
    return 0.5 * std::erfc(-x / std::sqrt(2.0));
}

double black_scholes_call(double S, double K, double r, double sigma, double T) {
    if (S <= 0 || K <= 0 || sigma <= 0 || T <= 0) {
        throw std::invalid_argument("Inputs S, K, sigma, and T must be positive.");
    }
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);
    return S * norm_cdf(d1) - K * std::exp(-r * T) * norm_cdf(d2);
}

int main() {
    double S = 100.0; 
    double K = 100.0;
    double r = 0.05;
    double sigma = 0.2;
    double T = 1.0;
    try {
        double call_price = black_scholes_call(S, K, r, sigma, T);
        std::cout << std::fixed << std::setprecision(4);
        std::cout << "Black-Scholes Call Option Price: " << call_price << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}