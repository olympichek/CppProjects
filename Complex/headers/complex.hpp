#ifndef MY_COMPLEX
#define MY_COMPLEX

namespace my {
    template<class type>
    class complex {
    private:
        type a; // real part
        type b; // imagine part
    public:
        complex(): a(0), b(0) {}
        complex(type a, type b): a(a), b(b) {}
        complex(const complex &other): a(other.a), b(other.b) {};
        type real() const {
            return a;
        }
        type imag() const {
            return b;
        }
        friend std::ostream& operator<<(std::ostream& os, const complex &number) {
            os << number.a;
            if(number.b >= 0)
                os << " + " << number.b;
            else
                os << " - " << -number.b;
            os << "i";
            return os;
        }
        complex& operator+=(const complex &other) {
            this->a += other.a;
            this->b += other.b;
            return *this;
        }
        complex& operator-=(const complex &other) {
            this->a -= other.a;
            this->b -= other.b;
            return *this;
        }
        complex& operator*=(const complex &other) {
            type res_a = (this->a * other.a) - (this->b * other.b);
            type res_b = (this->b * other.a) + (this->a * other.b);
            this->a = res_a, this->b = res_b;
            return *this;
        }
        complex& operator/=(const complex &other) {
            type t = (other.a * other.a) + (other.b * other.b);
            type res_a = ((this->a * other.a) + (this->b * other.b)) / t;
            type res_b = ((this->b * other.a) - (this->a * other.b)) / t;
            this->a = res_a, this->b = res_b;
            return *this;
        }
        complex operator+() const {
            return *this;
        }
        complex operator-() const {
            return complex(-a, -b);
        }
        complex operator+(const complex &other) const {
            complex res;
            res.a = this->a + other.a;
            res.b = this->b + other.b;
            return res;
        }
        complex operator-(const complex &other) const {
            complex res;
            res.a = this->a - other.a;
            res.b = this->b - other.b;
            return res;
        }
        complex operator*(const complex &other) const {
            complex res;
            res.a = (this->a * other.a) - (this->b * other.b);
            res.b = (this->b * other.a) + (this->a * other.b);
            return res;
        }
        complex operator/(const complex &other) const {
            complex res;
            type t = (other.a * other.a) + (other.b * other.b);
            res.a = ((this->a * other.a) + (this->b * other.b)) / t;
            res.b = ((this->b * other.a) - (this->a * other.b)) / t;
            return res;
        }
    };
}

#endif //MY_COMPLEX
