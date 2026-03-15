#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class CubicSpline {
public:
    void build(const std::vector<double>& x, const std::vector<double>& y) {
        int n = static_cast<int>(x.size());
        if (n < 2 || y.size() != x.size()) {
            throw std::invalid_argument("x and y must have the same size >= 2");
        }
        x_ = x;
        a_ = y;
        b_.assign(n - 1, 0.0);
        c_.assign(n, 0.0);
        d_.assign(n - 1, 0.0);

        for (int i = 1; i < n; ++i) {
            if (x_[i] <= x_[i - 1]) {
                throw std::invalid_argument("x values must be strictly increasing");
            }
        }

        std::vector<double> h(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            h[i] = x_[i + 1] - x_[i];
        }

        // Solve tridiagonal system for c_ using Thomas algorithm
        std::vector<double> alpha(n, 0.0);
        for (int i = 1; i < n - 1; ++i) {
            alpha[i] = (3.0 / h[i]) * (a_[i + 1] - a_[i])
                     - (3.0 / h[i - 1]) * (a_[i] - a_[i - 1]);
        }

        std::vector<double> l(n), mu(n), z(n);
        l[0] = 1.0;
        mu[0] = 0.0;
        z[0] = 0.0;

        for (int i = 1; i < n - 1; ++i) {
            l[i] = 2.0 * (x_[i + 1] - x_[i - 1]) - h[i - 1] * mu[i - 1];
            mu[i] = h[i] / l[i];
            z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
        }

        l[n - 1] = 1.0;
        z[n - 1] = 0.0;
        c_[n - 1] = 0.0;

        for (int j = n - 2; j >= 0; --j) {
            c_[j] = z[j] - mu[j] * c_[j + 1];
            b_[j] = (a_[j + 1] - a_[j]) / h[j] - h[j] * (c_[j + 1] + 2.0 * c_[j]) / 3.0;
            d_[j] = (c_[j + 1] - c_[j]) / (3.0 * h[j]);
        }
    }

    // Evaluate spline at query point xq
    double eval(double xq) const {
        if (x_.empty()) {
            throw std::runtime_error("Spline has not been built");
        }
        int n = static_cast<int>(x_.size());
        // Clamp to range endpoints
        if (xq <= x_.front()) return evalSegment(0, xq);
        if (xq >= x_.back())  return evalSegment(n - 2, xq);

        // Binary search for interval
        auto it = std::upper_bound(x_.begin(), x_.end(), xq);
        int i = static_cast<int>(it - x_.begin()) - 1;
        return evalSegment(i, xq);
    }

private:
    double evalSegment(int i, double xq) const {
        double dx = xq - x_[i];
        return a_[i] + b_[i] * dx + c_[i] * dx * dx + d_[i] * dx * dx * dx;
    }
    std::vector<double> x_;
    std::vector<double> a_;
    std::vector<double> b_, c_, d_;
};

int main() {
    std::vector<double> x = {0.0, 1.0, 2.0, 3.0, 4.0};
    std::vector<double> y = {0.0, 0.8, 0.9, 0.1, -0.8};
    CubicSpline spline;
    spline.build(x, y);
    for (double q = 0.0; q <= 4.0; q += 0.25) {
        std::cout << "x = " << q << ", spline(x) = " << spline.eval(q) << '\n';
    }

    return 0;
}