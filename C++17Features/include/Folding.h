
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

template<class ...Args>
auto Sum2(Args...args)
{
    // return (args + ... + 0); // Binary right fold
    return (0 + ... + args);    // Binary Left fold
}
/**
 * Binary Right fold
 * (1+(2+(3+(4+(5+0)))))
 * 
 * Binary Left fold
 * ((((1+(2+(3+(4+(5+0))
*/

// use of other operators || OR operator
template<class ...Args>
auto AnyOf(Args...args)
{
    return (... || (args % 2 == 0));
}
// use of other operators && AND operator
template<class ...Args>
auto AllOf(Args...args)
{
    return (... && (args % 2 == 0));
}
// use of other operators && AND operator - with predicate
template<class ...Args, typename Predicate>
auto AnyOf2(Predicate p,Args...args)
{
    return (... || p(args));
}


void Folding_main()
{
    auto result =  Sum(1,2,3,4,5);
    auto result2 = AnyOf(1,2,3,4);  // true if any are even
    auto result3 = AllOf(1,2,3,4);  // true if all are even
    auto result4 = AnyOf2(
        [](int x){return x % 2 == 0;},
        1,2,3,4
        );                          // true it any are even
}