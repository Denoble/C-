/* Application, which uses a queue class template. The application
 * needs a character queue and an integer queue. Because the template
 * queue implementation is in the file queue1.h, the programmer can
 * ask the compiler to generate class instances needed in the
 * program.
 */

#include "queue1.h"

int main() {
    Queue<int, 20> intqueue;  //Compiler generates class instance
    Queue<char, 30> chrqueue; //-- " -
    int number;
    char chr;

    //using queue for integers
    intqueue.enqueue(500); intqueue.enqueue(600);
    intqueue.enqueue(700); intqueue.enqueue(800);
    intqueue.print();
    intqueue.dequeue(&number);
    intqueue.print();

    //using queue for characters
    chrqueue.enqueue('A'); chrqueue.enqueue('B');
    chrqueue.enqueue('C'); chrqueue.enqueue('D');
    chrqueue.print();
    chrqueue.dequeue(&chr);
    chrqueue.print();

    system("PAUSE");
    return 0;
}



