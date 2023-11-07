
/**
 * HEADING: Folding / Fold Expression
 *  - process that applies binary operator to a list of values recursively
 *  - the results are combined recursively  to build up the final result
 *  - variadic templates can perform folding over a template pack
 * 
*/

template<class ...Args>
auto Sum(Args...args)
{
    // return (args + ...); // Unary right fold
    return (... + args);    // Unary Left fold
}
/**
 * Unary Right fold
 * (1+(2+(3+(4+5))))
 * 
 * Unary Left fold
 * ((((1+(2+(3+(4+5)
*/


void Folding_main()
{
    auto result =  Sum(1,2,3,4,5);
}