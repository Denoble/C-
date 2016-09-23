/* queue1.h -- The implementation of queue as a template class.
 * Note that we should avoid to put executable code
 * in the header file usually. As far as templates are considered,
 * we make an exception to this rule.
 */

#include <iostream>
using namespace std;

// Class definition. Titem is "type parameter". max_no_of_elements is "function style parameter"
// (could be replaced by: const int max_no_of_elements = 50;)
template <class Titem, int max_no_of_elements>
class Queue {
  private :
    Titem array[max_no_of_elements];
    int first;
    int last;
    int number_of_items;
  public:
    Queue();
    bool enqueue(Titem item);
    bool dequeue(Titem *Pitem);
    void print() const;
};

template <class Titem, int max_no_of_elements>
Queue<Titem, max_no_of_elements>::Queue() {
    first = 0;
    last = -1;
    number_of_items = 0;
}
template <class Titem, int max_no_of_elements>
bool Queue<Titem, max_no_of_elements>::enqueue(Titem item) {
    if (number_of_items >= max_no_of_elements)
        return(false);
    if (++last > max_no_of_elements - 1)
            last = 0;
    array[last] = item;
    number_of_items++;
    return (true);
}
template <class Titem, int max_no_of_elements>
bool Queue<Titem, max_no_of_elements>::dequeue(Titem *Pitem) {
    if (number_of_items == 0)
        return(false);
    *Pitem = array[first++];
    if (first > max_no_of_elements - 1)
        first = 0;
    number_of_items--;
    return (true);
}
template <class Titem, int max_no_of_elements>
void Queue<Titem, max_no_of_elements>::print() const {
    int i, n;
    cout << "Queue now: " << endl;
    for (n = 1, i=first ; n <= number_of_items ; n++) {
        cout << array[i++] << " ";
        if (i>max_no_of_elements-1)
            i = 0;
    }
    cout << endl;
}
