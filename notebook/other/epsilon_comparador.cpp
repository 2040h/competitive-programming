inline bool epsilon_equal(double a, double b) {return fabs(a-b) < EPSILON;}
inline bool epsilon_bigger(double a, double b) {return a > b+EPSILON;}
inline bool epsilon_smaller(double a, double b) {return a+EPSILON < b;}
inline bool epsilon_smaller_equal(double a, double b) {return a <= b+EPSILON;}
inline bool epsilon_bigger_equal(double a, double b) {return a+EPSILON >= b;}
