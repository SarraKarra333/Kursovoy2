#include "midi.h"

midi::midi():
    brand(""),
    model(""),
    price(0.00),
    number_of_keys(0),
    color(""),
    backlight(""),
    size_of_keys(""),
    positionX(0),
    positionY(0) {}

midi::midi(const QString _brand,
           const QString _model,
           const float _price,
           const  int _number_of_keys,
           const QString _color,
           const QString _backlight,
           const QString _size_of_keys,
           const int _positionX,
           const int _positionY):
    brand(_brand),
    model(_model),
    price(_price),
    number_of_keys(_number_of_keys),
    color(_color),
    backlight(_backlight),
    size_of_keys(_size_of_keys),
    positionX(_positionX),
    positionY(_positionY)
{

}

midi::midi(const midi &other):
    brand(other.brand),
    model(other.model),
    price(other.price),
    number_of_keys(other.number_of_keys),
    color(other.color),
    backlight(other.backlight),
    size_of_keys(other.size_of_keys),
    positionX(other.positionX),
    positionY(other.positionY)
{

}

midi::~midi()
{

}

void midi::SetBrand(const QString _brand)
{
    brand=_brand;
}

QString midi::GetBrand() const
{
    return brand;
}

void midi::SetModel(const QString _model)
{
    model=_model;
}

QString midi::GetModel() const
{
    return model;
}

void midi::SetPrice(const float _price)
{
    price=_price;
}

float midi::GetPrice() const
{
    return price;
}

void midi::SetColor(const QString _color)
{
    color=_color;
}

QString midi::GetColor() const
{
    return color;
}

void midi::SetBacklight(const QString _backlight)
{

    backlight=_backlight;
}

QString midi::GetBacklight() const
{
    return backlight;
}

void midi::SetSize_of_keys(const QString _size_of_keys)
{
    size_of_keys=_size_of_keys;
}

QString midi::GetSize_of_keys() const
{
    return size_of_keys;
}

void midi::SetNumber_of_keys(const int _number_of_keys)
{
    number_of_keys=_number_of_keys;
}

int midi::GetNumber_of_keys() const
{
    return number_of_keys;
}

