#ifndef VISITOR_H
#define VISITOR_H

#include "pch.h"


namespace Visitor
{
    class Engine;
    class Wheel;


    class CarPartVisitor
    {
    public:
        virtual ~CarPartVisitor() = default;
        virtual void visit(Engine& engine) = 0;
        virtual void visit(Wheel& wheel) = 0;
    };


    class CarPart
    {
    public:
        virtual ~CarPart() = default;
        virtual void accept(CarPartVisitor& visitor) = 0;
    };


    class Engine : public CarPart
    {
    public:
        void accept(CarPartVisitor& visitor) override
        {
            visitor.visit(*this);
        }
    };


    class Wheel : public CarPart
    {
    public:
        void accept(CarPartVisitor& visitor) override
        {
            visitor.visit(*this);
        }
    };


    class Car : public CarPart
    {
    public:
        void accept(CarPartVisitor& visitor) override
        {
            for(auto& part : parts)
               part->accept(visitor);
        }

    private:
        std::array<std::unique_ptr<CarPart>, 2> parts{{
            std::unique_ptr<Engine>{ new Engine{} },
            std::unique_ptr<Wheel>{ new Wheel{} }
        }};
    };


    class WhoIsVisitor : public CarPartVisitor
    {
    public:
        void visit(Engine& engine) override
        {
            std::ignore = engine;
            std::cout << "WhoIsVisitor visits Engine" << std::endl;
        }

        void visit(Wheel& wheel) override
        {
            std::ignore = wheel;
            std::cout << "WhoIsVisitor visits wheel" << std::endl;
        }
    };


    void test()
    {
        WhoIsVisitor visitor;
        Car car;
        car.accept(visitor);
    }
}
#endif // VISITOR_H
