
#include <iostream>
#include <exception>
#include <map>

int gcd(int a, int b)
{
    while (b > 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

class Fraction
{
private:
	int numerator;
	int denominator;

    void skorot()
    {
        int a = gcd(abs(numerator), denominator);
        if (a != 1)
        {
            numerator /= a;
            denominator /= a;
        }
    }

public:
    Fraction(int _numerator, int _denominator)
    {
        try
        {
            if (_denominator != 0 && _numerator != 0)
            {
                numerator = _numerator;
                denominator = _denominator;
            }
            else if (_numerator != 0)
            {
                numerator = _numerator;
                denominator = 1;
                throw std::invalid_argument(0);
            }
            else
            {
                numerator = 1;
                denominator = _denominator;
                throw std::invalid_argument(0);
            }
        }
        catch (std::invalid_argument)
        {
            std::cerr << "Invalid Argumet: " << 0 << '\n';
        }
    }

    void show() const
    {
        std::cout << "Numerator: " << this->numerator << " Denimonator: " << this->denominator << '\n';
    }

    Fraction operator * (Fraction& b)
    {
        this->numerator *= b.numerator;
        this->denominator *= b.denominator;
        skorot();
        return *this;
    }
    Fraction operator / (Fraction& b)
    {
        try
        {
            if (b.numerator != 0)
            {
                this->numerator *= b.denominator;
                this->denominator *= b.numerator;
                skorot();
                return *this;
            }
            else
            {
                throw std::logic_error(0);
            }
        }
        catch(std::logic_error)
        {
            std::cerr << "Logic Error: " << 0 << '\n';
        }
    }
    Fraction operator - (Fraction& b)
    {
        int unionDenom = lcm(this->denominator, b.denominator);
        if (this->denominator != b.denominator)
        {
            int relNumer = this->numerator * (unionDenom / this->denominator);
            int mulNumer = b.numerator * (unionDenom / b.denominator);
            this->numerator = relNumer - mulNumer;
        }
        else
        {
            this->numerator -= b.numerator;
        }
        this->denominator = unionDenom;
        skorot();
        return *this;
    }
    Fraction operator + (Fraction& b)
    {
        int unionDenom = lcm(this->denominator, b.denominator);
        if (this->denominator != b.denominator)
        {
            int relNumer = this->numerator * (unionDenom / this->denominator);
            int mulNumer = b.numerator * (unionDenom / b.denominator);
            this->numerator = relNumer + mulNumer;
        }
        else
        {
            this->numerator += b.numerator;
        }
        this->denominator = unionDenom;
        skorot();
        return *this;
    }
};

class CartItem
{
private:
    char* name = nullptr;
    int price;
    int stash;
public:
    CartItem(const char* _name, int _price, int _stash)
    {
        name = new char[strlen(_name) + 1];
        name[strlen(_name)] = '\0';
        for (int i = 0; i < strlen(_name); i++)
        {
            name[i] = _name[i];
        }
        try
        {
            if (_price != 0)
            {
                price = _price;
            }
            else
            {
                price = 1;
                throw std::invalid_argument(0);
            }
        }
        catch (std::invalid_argument)
        {
            std::cerr << "Price lower then 0!\n";
        }
        stash = _stash;
    }

    int getStash()
    {
        return stash;
    }
    int getPrice()
    {
        return price;
    }

    virtual ~CartItem()
    {
        if (name != nullptr)
        {
            delete[] name;
        }
    }
};
class Cart
{
private:
public:
    void add(CartItem &item, int many)
    {
        try
        {
            if (item.getStash() >= many)
            {
                std::cout << "Added succesfully!\n";
            }
            else
            {
                throw std::runtime_error(0);
            }
        }
        catch (std::runtime_error)
        {
            std::cerr << "ERROR: STASH LESS THEN ADD MUCH!\n";
        }
    }
};

int main()
{

}