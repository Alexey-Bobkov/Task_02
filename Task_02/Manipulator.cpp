#include "Manipulator.h"

void generate(Manipulator& m)  
{
    // ��������� �������� double X � Y (�� -100 �� 100)
    int MIN = -100;
    int MAX = 100;

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(MIN, MAX);

    m.m_x = distr(eng);
    m.m_y = distr(eng);

    // ��������� �������� double ��� ������� (�� 5 �� 25)
    MIN = 5;
    MAX = 25;
    std::uniform_real_distribution<double> dis_radius(MIN, MAX);

    m.m_radius = dis_radius(eng);
};

void print_m(const Manipulator& m)
{
    std::cout << "X = " << m.m_x << " Y = " << m.m_y << " radius = " << m.m_radius << std::endl;
};

// ������ ���������� �� ����� �� ������� �������� ��� ��������� �������
double get_distance(const Manipulator& m, const std::pair<double, double> &p) 
{
    return sqrt(pow((m.m_x - p.first), 2) + pow((m.m_y - p.second), 2));
};
