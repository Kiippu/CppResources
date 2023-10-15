#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>



void STLContainers_main()
{

    ///////
    /// Sequence Containers
    //////

    /**
     * std::array
     *  - random access, 
     *  - can be used in C functions with .data() 
     *  - Cannot grow in size 
    */
   std::array<int,3> arr = {1,2,3};

   /**
    * std::vector
    *  - size is dynamic
    *  - provides random access
    *  - efficient for addition/remove at end
    *  - inefficient for insertion/deletion not at end
   */
    std::vector<int> vec = {1,2,3};
    vec.push_back(23);
   
    /**
     * Iterators
     *  - used in containers to access data by postion
     *  - pointer like objects
    */
    auto itrArr = arr.begin(); // is pointer
    std::vector<int>::iterator itrVec = vec.begin(); // is iterator obj

    /**
     * std::deque
     *  - efficient for addition/removal at BOTH ends
     *  - provides random access
     *  - not good at deletion/insertion mid deque
    */
    std::deque<int> deq = {1,2,3};
    deq.push_front(23); // add to front and push_back() to back 
    deq.pop_front();    // pops the front most element

    /**
     * std::list 
     * 2 way linked list
     * efficient for insertion/deletion anywhere, done in constant time
     * does NOT provide random access
    */
    std::list<int> list = {1,3,4,5};
    list.push_front(23); // add to front and push_back() to back 
    list.insert(++list.begin(), 40); // inserts in to list at font position + 1


    //////
    //  Associative Containers
    /////

    /**
     * std::forward_list
     *  - 1 way linked list - each node has only one pointer to next node
     *  - element added to front only 
     *  - no support for size
    */
    std::forward_list<int> fwdList = {2,3,4,65};
    fwdList.push_front(34);
    fwdList.insert_after(fwdList.begin(), 34);
    fwdList.erase_after(fwdList.begin());

    /**
     * std::set
     *  - implemented as a binary tree in sorted order
     *  - value acts as a key - one key will every exist
     *  - fast search
     *  - no random access
     *  - elements can not be modified directly
    */
    std::set<int> set = {1,2,3,4,5}; // by default is  is std::less
    std::set<int,std::greater<int>> setGreater = {1,2,3,4,5};
    set.insert(34);
    set.find(3); // will find 3 if not it will be iterator::end()

    /**
     * std::multiset
     *  - like set but can have multiple instances of a key
    */
    std::multiset<int> multiset = {1,1,3,4,1};
    auto iterMSet = multiset.equal_range(1);
    while(iterMSet.first != iterMSet.second){
        iterMSet.first++; // get each value that is equal to 1
    }

    /**
     * std::map
     *  - binary tree
     *  - stored in pares of key and value - no dups
     *  - element sorted in order og key
     *  - fast search
     *  - no random access
     *  - keys cannot be modified
    */
    std::map<int,char> map = {{1,'h'},{3,'f'}};
    map[45] = 's';
    map.insert(std::make_pair(23,'a'));
    for(auto const& itr : map )
        std::cout << itr.first << " - " << itr.second << std::endl;
    auto it = map.find(3);
    if(it != map.cend())
        std::cout << it->first << " - " << it->second << std::endl;


    /**
     * std::multimap
     *  - same as above but
     *  - stored in pares of key and value - no dups
    */
    std::multimap<int,char> multiMap = {{1,'h'},{3,'f'},{1,'h'}};
    auto iterMMap = multiMap.equal_range(1);
    while(iterMMap.first != iterMMap.second){
        std::cout << iterMMap.first->first << " - " << iterMMap.first->second << std::endl;
        iterMMap.first++; // get each value that is equal to 1
    }

    
    //////
    //  Unordered Containers
    /////
    /**
     *  - Associative containers implemented with hash tables
     *  - values are hashed and stored in undefined order 
     *  - fast search/insertion/deletion - may degrade over time
     *  - iterators are constant
     *  - uses buckets(lists) in hash locations for when multiple element have the same hash value
     *      - elements are added to buckets as collisions occur (same hash value)  
    */

    /**
     * std::unordered_set / std::unorded_multiset
    */
    std::cout << "std::unordered_set and std::unordered_multiset" << std::endl;
    std::unordered_set<int> uSet = {1,2,3,4,5};
    //std::unordered_multiset<int> uSet = {1,2,3,4,5};
    for(auto const& itr : uSet )
        std::cout<< "Bucket: " << uSet.bucket(itr) << " - " << itr << std::endl;
    // get buckets info
    std::cout << "Bucket count: " << uSet.bucket_count() << std::endl;  // bucketCount
    std::cout << "Number of elements: " << uSet.size() << std::endl;    // element count
    // measured as size / bucketCount at value of 1 it will indicate degrading
    std::cout << "Load factor: " << uSet.load_factor() << std::endl;

    /**
     * std::unordered_map
    */
    std::cout << "std::unordered_map and std::unordered_multimap" << std::endl;
    std::unordered_map<int,char> uMap = {{1,'h'},{3,'f'},{5,'h'},{3,'l'}};
    // std::unordered_multimap<int,char> uMap = {{1,'h'},{3,'f'},{5,'h'},{3,'l'}};
    for(auto const& itrMap : uMap )
        std::cout << "Bucket: " << uMap.bucket(itrMap.first) << " - "  << itrMap.first << " - " << itrMap.second << std::endl;
    std::cout << "Bucket count: " << uMap.bucket_count() << std::endl;  // bucketCount
    std::cout << "Number of elements: " << uMap.size() << std::endl;    // element count
    // measured as size / bucketCount at value of 1 it will indicate degrading
    std::cout << "Load factor: " << uMap.load_factor() << std::endl;

}