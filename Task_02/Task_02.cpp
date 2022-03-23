#include "Manipulator.h"

double generate();
void generate_points(vector_pair& points, unsigned int length = 8);
void print_vec_points(const vector_pair& v);
void optimal_way(Manipulator& m1, Manipulator& m2, const vector_pair& point,
    vector_tuple& v);

using namespace std;

int main()
{
    vector_pair point; // дан массив точек, где лежат детали P1…Pn.
    vector_tuple v_motion;
    Manipulator first;
    Manipulator second;

    generate(first);
    generate(second);
    generate_points(point);

    print_vec_points(point);
    cout << endl;
    print_m(first);
    print_m(second);
    cout << endl;

    optimal_way(first, second, point, v_motion);
    cout << endl;

    for (const auto& [X, Y, M] : v_motion)
    {
        cout << setprecision(3) << M << "{" << X << ", " << Y << "} " << endl;
    }

    cout<< endl << "last position manipulators" << endl;
    print_m(first);
    print_m(second);
}
