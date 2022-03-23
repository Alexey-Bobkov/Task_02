#pragma once
#include <iostream>
#include <random>
#include <iomanip>
#include <tuple>

using vector_pair = std::vector <std::pair<double, double>>;
using vector_tuple = std::vector<std::tuple<double, double, std::string>>;

class Manipulator
{
private:
    double m_x, m_y;
    double m_radius;

public:
    Manipulator() : m_x{ 0 }, m_y{ 0 }, m_radius{ 0 } {}
    Manipulator(double x, double y, double rad) : m_x{ x }, m_y{ y }, m_radius{ rad } {}

    void change_center_point(double x, double y) // изменение координат манипулятора 
    {
        m_x = x;
        m_y = y;
    }

    friend void generate(Manipulator& m);
    friend void print_m(const Manipulator& m);
    friend double get_distance(const Manipulator& m, const std::pair<double, double> &p);
};
