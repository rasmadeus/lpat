#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

namespace Flyweight
{
    enum class Color
    {
        Red,
        Green,
        Blue,
    };

    class Data
    {
    public:
        Data(const std::string& color)
            : color{color}
        {
        }

        const std::string getColor() const
        {
            return color;
        }

    private:
        std::string color;
    };


    class Figure
    {
    public:
        enum class Type
        {
            Round,
            Quad,
        };

    public:
        Figure(Data& data)
            : data{data}
        {
        }

        void setPos(int x, int y)
        {
            this->x = x;
            this->y = y;
        }

        int getX() const
        {
            return x;
        }

        int getY() const
        {
            return y;
        }

        virtual void draw() const = 0;

    protected:
        Data& data;
        int x = 0;
        int y = 0;
    };


    class Round : public Figure
    {
    public:
        Round(Data& data)
            : Figure{data}
        {
        }

        void draw() const override
        {
            std::cout << "Color: " << data.getColor() << ". Round." << std::endl;
        }
    };


    class Quad : public Figure
    {
    public:
        Quad(Data& data)
            : Figure{data}
        {
        }

        void draw() const override
        {
            std::cout << "Color: " << data.getColor() << ". Quad." << std::endl;
        }
    };


    class Factory
    {
    public:
        std::unique_ptr<Figure> get(Figure::Type type, Color color)
        {
            auto& data = datas.find(color)->second;
            switch (type)
            {
            case Figure::Type::Round: return std::unique_ptr<Figure>{ new Round{data} };
            case Figure::Type::Quad: return std::unique_ptr<Figure>{ new Quad{data} };
            default: return {};
            }
        }

    private:
        std::unordered_map<Color, Data, EnumClassHash> datas{
            { Color::Red, {"red"} },
            { Color::Green, {"green"} },
            { Color::Blue, {"blue"} },
        };
    };

    void test()
    {
        Factory factory;
        std::vector<std::unique_ptr<Figure>> figures;
        figures.emplace_back(factory.get(Figure::Type::Quad, Color::Blue));
        figures.emplace_back(factory.get(Figure::Type::Quad, Color::Red));
        figures.emplace_back(factory.get(Figure::Type::Round, Color::Blue));

        for(auto& figure : figures)
            figure->draw();
    }
}

#endif // FLYWEIGHT_H
