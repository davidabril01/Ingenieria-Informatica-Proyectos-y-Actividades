#ifndef LINEA_H
#define LINEA_H

class Linea
{
public:
    Linea();

    int get_x_inicial() const;
    int get_y_inicial() const;
    int get_x_final() const;
    int get_y_final() const;

    void set_x_inicial(const int& nuevo_x_inicial);
    void set_y_inicial(const int& nuevo_y_inicial);
    void set_x_final(const int& nuevo_x_final);
    void set_y_final(const int& nuevo_y_final);

private:
    int x_inicial, y_inicial, x_final, y_final;
};

#endif // LINEA_H
