#ifndef INTERPRETER_H
#define INTERPRETER_H

namespace Interpreter
{
    class Expression
    {
    public:
        virtual ~Expression() = default;
        virtual double eval() = 0;
    };


    class Number : public Expression
    {
    public:
        Number(double value):
            value{value}
        {
        }

        double eval() override
        {
            return value;
        }

    private:
        const double value;
    };


    class Plus : public Expression
    {
    public:
        Plus(Expression& left, Expression& right)
            : left{left}
            , right{right}
        {
        }

        double eval() override
        {
            return left.eval() + right.eval();
        }

    private:
        Expression& left;
        Expression& right;
    };


    class Minus : public Expression
    {
    public:
        Minus(Expression& left, Expression& right)
            : left{left}
            , right{right}
        {
        }

        double eval() override
        {
            return left.eval() - right.eval();
        }

    private:
        Expression& left;
        Expression& right;
    };


    class Multiplication : public Expression
    {
    public:
        Multiplication(Expression& left, Expression& right)
            : left{left}
            , right{right}
        {
        }

        double eval() override
        {
            return left.eval() * right.eval();
        }

    private:
        Expression& left;
        Expression& right;
    };


    void test()
    {
        auto left = Number{4};
        auto right = Number{5};
        auto plus = Plus{left, right};
        auto minus = Minus{left, right};
        auto mult = Multiplication{plus, minus};
        std::cout << mult.eval() << std::endl;
    }
}
#endif // INTERPRETER_H
