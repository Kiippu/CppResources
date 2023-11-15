/**
 * HEADING: parallel algos
 * many STL algorithms by default execute serially
 * c++ 17 now overloads many of these algorithms
 * algorithms that can be parallelized take a template parameter
 * parameter is a execution policy
 * example: std::algorithm(execution_policy, // other args  //)
 * POLICIES:
 * sequenced_policy - seq
 *      no parallel done
 * parallel_policy - par
 *      algo should be executed parallally
 *      might use thread pool or main thread
 * parallel_unsequenced_policy - par_unseq
 *      indicates the execution may be parallelized, vectorized or migrated across threads
 * EXCEPTIONS:
 * all parallel algos call std::terminate on exception
 * also applies to seq policy
 * if you want exceptions use the standard algos
 * will throw bad_alloc on fail of memory allocation
 * WHEN:
 * they are backwards compatible
 * can be used for input and output iterators
 * syncronization is expensive
 * will give bad performance with small data sets
 *  
*/

