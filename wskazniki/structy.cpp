#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
};


void print_info(Node node) // ta funkcja otrzymuje cały obiekt (przez wartość, czyli będzie sobie kopiowała i dopiero potem się wykona)
{
    /*
    - Creates a copy of the entire Node object
    - The parameter node is a completely separate object from the original
    - &node shows the address of this copy (on the stack)
    - Changes to node inside the function wouldn't affect the original
    - Performance cost: copying the entire struct
    */
    cout << endl << "Print info: " << endl;
    // cout << node << endl; //! błąd: nie można wypisać całego obiektu
    cout << "object's address: " << &node << endl; // wypisze adres jakiegoś tam obiektu utworzonego na stosie na bazie przekazanego obiektu
    cout << "object.value:     " << node.value << endl;
    cout << "object.next :     " << node.next << endl;
}

void print_ptr_info(Node *node) // ta funkcja otrzymuje wskaźnik do obiektu (przez referencję, obiekt nie jest kopiowany, pracujemy na oryginale)
{
    /*
    - Receives a pointer (memory address) to the original object
    - &node shows where the pointer variable itself is stored
    - node (without &) shows the address it points to (the original object's location)
    - Uses -> operator to access object members
    - No copying of the original object occurs
    - The pointer itself is copied, but it's just an address (8 bytes on 64-bit systems)
    */
    cout << endl << "Print pointer info: " << endl;
    cout << "pointer's address: " << &node << endl; // adres skopiowanego wskaźnika (stack)
    cout << "pointer's value: "<< node << endl; // zawartość wskaźnika
    cout << "object.value:    " << node->value << endl; // zawartość value obiektu
    cout << "object.next:     " << node->next << endl; // adres następnego obiektu
}

void print_ref_info(Node &node) // ta funkcja otrzymuje adres obiektu (przez referencję), bez kopiowania
{
    /*
    - Creates an alias to the original object
    - &node shows the address of the original object (same as caller would see)
    - Uses . operator like a regular object
    - No copying occurs - it's essentially the same object with a different name
    - Most efficient and cleanest syntax
    */
    cout << endl << "Print ref info: " << endl;
    cout << "object's address: " << &node << endl; //
    cout << "object.value:     " << node.value << endl;
    cout << "object.next:      " << node.next << endl;
}
/*
Method	Object Copied?	Extra Memory	Access Syntax
By Value	✅ Yes	Full object size	node.value
By Pointer	❌ No	Pointer size only	node->value
By Reference	❌ No	None	node.value
*/
int main()
{
    setlocale(LC_ALL, "pl_PL.UTF-8");
    // statycznie
    Node node1 = {15, nullptr};
    Node node2 = {12, nullptr};
    node1.next = &node2;
    cout << "adres node1: " << &node1 << endl;
    cout << "node1.value: " << node1.value << endl;
    cout << "node1.next: " << node1.next << endl;
    cout << "adres node1.value: " << &node1.value << endl;
    cout << "adres node1.next: " << &node1.next << endl << endl;

    // cout << "node2: " << node2 << endl; //! zwróci error, nie da się wypisać całego obiektu
    cout << "adres node2: " << &node2 << endl;
    cout << "adres node2.value: " << &(node2.value) << endl;
    cout << "sizeof node2.value: " << sizeof(node2.value) << endl;
    cout << "adres node2.next: " << &(node2.next) << endl << endl;
    // cout << node1->value << endl;
    // cout << node1->next << endl;
    cout << "node2.value: " << node2.value << endl;
    cout << "node2.next: " << node2.next << endl;
    // cout << node2->value << endl;
    // cout << node2->next << endl;

    // Node node;

    // std::cout << "Size of int: " << sizeof(int) << " bytes\n";
    // std::cout << "Size of pointer: " << sizeof(Node*) << " bytes\n";
    // std::cout << "Size of Node struct: " << sizeof(Node) << " bytes\n";
    
    // std::cout << "\nAddress of node: " << &node << "\n";
    // std::cout << "Address of node.value: " << &(node.value) << "\n";
    // std::cout << "Address of node.next: " << &(node.next) << "\n";
    
    // std::cout << "\nOffset of value: " << offsetof(Node, value) << "\n";
    // std::cout << "Offset of next: " << offsetof(Node, next) << "\n";

    cout << endl;
    print_info(node2);
    print_ptr_info(node1.next);
    print_ref_info(node2);


    // dynamicznie
    cout << endl << endl << endl << "Alokacja dynamiczna: " << endl << endl;
    Node *node3 = new Node({16, nullptr});
    Node *node4 = new Node({20, nullptr});

    (*node3).next = node4;
    cout << "node3: " << node3 << endl; //* wartość `wskaźnika (stack)` do `obiektu na stercie (heap)`
    cout << "node3->value: " << node3->value << endl; //* dereferencja wskaźnika i otrzymanie wartości kryjącej się pod value
    // cout << "node3.value: " << node3.value << endl; //! błąd, node3 to wskaźnik, a nie gotowy obiekt
    // cout << *node3 << endl; //! błąd, *node3 to dereferencja do obiektu, a nie można wypisać całego obiektu
    cout << "adres node3: " << &node3 << endl; //* adres wskaźnika na stosie
    cout << "adres node3->value: " << &node3->value << endl; //* adres (heap) właściwości value obiektu wskazywanego przez node3

    cout << endl << "node3->next: " << node3->next << endl;
    cout << "node4: " << node4 << endl;

    print_info(*node3); // tu musi być dereferencja do obiektu, po to by otrzymać cały obiekt, bo tak prosi funkcja
    print_ptr_info(node3);
    print_ref_info(*node3);
    delete node3, node4;
    return 0;
}