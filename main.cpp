#include "visitor.h"
#include "cor.h"
#include "flyweight.h"
#include "mediator.h"
#include "momento.h"
#include "interpreter.h"


int main()
{
    Visitor::test();
    COR::test();
    Flyweight::test();
    Mediator::test();
    Momento::test();
    Interpreter::test();
}
