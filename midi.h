#ifndef midi_H
#define midi_H
#include "QString"

class midi //главный класс
{
private:
    QString brand;
    QString model;
    float price;
    int number_of_keys;
    QString color;
    QString backlight;
    QString size_of_keys;
    int positionX;
    int positionY;

public:
    midi(); //конструктор по умолчанию

    midi( //конструктор с новыми параметрами
                               const QString _brand,
                               const QString _model,
                               const float _price,
                               const  int _number_of_keys,
                               const QString _color,
                               const QString _backlight,
                               const QString _size_of_keys,
                               const int _positionX,
                               const int _positionY
);
    midi(const midi& other); //конструктор копирования

    ~midi();  //деструктор

    midi operator = (const midi& other); //перегрузка присваивания

    //Методы, устанавливающие (сеттеры) и получающие (геттеры) значения переменных

    void SetBrand(const QString _brand);
    QString GetBrand() const;

    void SetModel(const QString _model);
    QString GetModel() const;

    void SetPrice(const float _price);
    float GetPrice() const;

    void SetColor(const QString _color);
    QString GetColor() const;

    void SetBacklight(const QString _backlight);
    QString GetBacklight() const;

    void SetSize_of_keys (const QString _size_of_keys);
    QString GetSize_of_keys() const;

    void SetNumber_of_keys(const int _number_of_keys);
    int GetNumber_of_keys() const;

};

#endif
