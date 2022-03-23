#include "Manipulator.h"

double generate()
{
    int MIN = -100;
    int MAX = 100;

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(MIN, MAX);

    return distr(eng);
};

void generate_points(vector_pair& points, unsigned int length = 8)
{
    int MIN = -100;
    int MAX = 100;

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(MIN, MAX);

    for (int i = 0; i < length; ++i)
    {
        points.push_back(std::pair<double, double>(distr(eng), distr(eng)));
    }
};

void print_vec_points(const vector_pair& v)
{
    int i{ 0 };
    for (auto iter : v)
    {
        ++i;
        std::cout << std::setprecision(3) << "{" << iter.first << ", " << iter.second << "} ";
        if (i % 5 == 0)
            std::cout << std::endl;
    }
}

// нахождение оптимального манипулятора для каждой point(коордитаты точек) и добавление 
//в вектор(std::vector<std::tuple<double, double, std::string>>) оптимального манипулятора
void optimal_way(Manipulator& m1, Manipulator& m2, const vector_pair& point,
    vector_tuple& v)
{
    for (int i = 0; i < point.size(); ++i)
    {
        if (get_distance(m1, point[i]) < get_distance(m2, point[i]))
        {
            v.push_back(std::tuple<double, double, std::string>(point[i].first, point[i].second, "Manipulator 1"));
            m1.change_center_point(point[i].first, point[i].second);// смена координат после у манипулятора если у него оптимальная дистанция
        }
        else
        {
            v.push_back(std::tuple<double, double, std::string>(point[i].first, point[i].second, "Manipulator 2"));
            m2.change_center_point(point[i].first, point[i].second);// смена координат после у манипулятора если у него оптимальная дистанция
        }
    }
}
