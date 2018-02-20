#ifndef VISITOR_H
#define VISITOR_H

#include "pch.h"


namespace Visitor
{
    class Round;
    class Quad;


    class Visitor
    {
    public:
        virtual ~Visitor() = default;
        virtual void visit(Round& round) = 0;
        virtual void visit(Quad& quad) = 0;
    };


    class Figure
    {
    public:
        virtual ~Figure() = default;
        virtual void accept(Visitor& visitor) = 0;
    };


    class Round : public Figure
    {
    public:
        Round(unsigned int radius)
            : radius{ radius }
        {
        }

        void accept(Visitor& visitor) override
        {
            visitor.visit(*this);
        }

        unsigned int getRadius() const
        {
            return radius;
        }

    private:
        unsigned int radius;
    };


    class Quad : public Figure
    {
    public:
        Quad(unsigned int side)
            : side{ side }
        {
        }

        void accept(Visitor& visitor) override
        {
            visitor.visit(*this);
        }

        unsigned int getSide() const
        {
            return side;
        }

    private:
        unsigned int side;
    };


    class SquareVisitor : public Visitor
    {
    public:
        void visit(Round& round) override
        {
            std::cout << "Round square = " << 2 * M_PI * round.getRadius() << std::endl;
        }

        void visit(Quad& quad) override
        {
            std::cout << "Quad square = " << quad.getSide() * quad.getSide() << std::endl;
        }
    };


    class Scene : public Figure
    {
    public:
        void accept(Visitor& visitor) override
        {
            for(auto& figure : scene)
                figure->accept(visitor);
        }

    private:
        std::array<std::unique_ptr<Figure>, 3> scene{{
            std::unique_ptr<Round>{ new Round{5} },
            std::unique_ptr<Quad>{ new Quad{3} },
            std::unique_ptr<Round>{ new Round{7} }
        }};
    };

    void test()
    {
        Scene scene;
        SquareVisitor visitor;
        scene.accept(visitor);
    }
}
#endif // VISITOR_H
