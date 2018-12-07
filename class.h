#ifndef CLASS_H
#define CLASS_H

#include <iostream>

using namespace std;

//CLASS

class Box {
   public:
      double length;   // Length of a box
      double breadth;  // Breadth of a box
      double height;   // Height of a box

      // Member functions declaration
      double getVolume(void);
      void setLength( double len );
      void setBreadth( double bre );
      void setHeight( double hei );

      void setWidth( double wid );
      double getWidth( void );

    private:
      double width;

    protected:
      double width2;
};

class SmallBox:Box { // SmallBox is the derived class. Protected
   public:
      void setSmallWidth( double wid );
      double getSmallWidth( void );
};

// Member functions definitions
double Box::getVolume(void) {
   return length * breadth * height;
}

void Box::setLength( double len ) {
   length = len;
}
void Box::setBreadth( double bre ) {
   breadth = bre;
}
void Box::setHeight( double hei ) {
   height = hei;
}

double Box::getWidth(void) {
   return width ;
}

void Box::setWidth( double wid ) {
   width = wid;
}

double SmallBox::getSmallWidth(void) {
   return width2 ;
}

void SmallBox::setSmallWidth( double wid ) {
   width2 = wid;
}

void print_class(){
    Box box;
    Box Box1;                // Declare Box1 of type Box
    Box Box2;                // Declare Box2 of type Box

    SmallBox box2;

    double volume = 0.0;     // Store the volume of a box here

    // box 1 specification
    Box1.setLength(6.0);
    Box1.setBreadth(7.0);
    Box1.setHeight(5.0);

    // box 2 specification
    Box2.setLength(12.0);
    Box2.setBreadth(13.0);
    Box2.setHeight(10.0);

    // volume of box 1
    volume = Box1.getVolume();
    cout << "Volume of Box1 : " << volume <<endl;

    // volume of box 2
    volume = Box2.getVolume();
    cout << "Volume of Box2 : " << volume <<endl;


    // set box length without member function
    box.length = 10.0; // OK: because length is public
    cout << "Length of box : " << box.length <<endl;

    // set box width without member function
    // box.width = 10.0; // Error: because width is private
    box.setWidth(10.0);  // Use member function to set it.
    cout << "Width of Small box : " << box.getWidth() <<endl;

    box2.setSmallWidth(5.0);
       cout << "Width of Small box : "<< box2.getSmallWidth() << endl;

}


//3. CONSTRUCTOR/DESTRUCTOR
class Line {
   public:
      void setLength( double len );
      double getLength( void );
      Line(double len);  // This is the constructor
      ~Line();  // This is the destructor: declaration

   private:
      double length;
};

// Member functions definitions including constructor
Line::Line( double len) {
   cout << "Object is being created, length = " << len << endl;
   length = len;
}
//Destrucotr func
Line::~Line(void) {
   cout << "Object is being deleted" << endl;
}
void Line::setLength( double len ) {
   length = len;
}
double Line::getLength( void ) {
   return length;
}

void constructor(){
   Line line(10.0);

   // get initially set length.
   cout << "Length of line : " << line.getLength() <<endl;

   // set line length again
   line.setLength(6.0);
   cout << "Length of line : " << line.getLength() <<endl;
}


//4. COPY CONSTRUCTOR

class NewLine {

   public:
      int getLength( void );
      NewLine( int len );             // simple constructor
      NewLine( const NewLine &obj);  // copy constructor
      ~NewLine();                     // destructor

   private:
      int *ptr;
};

// Member functions definitions including constructor
NewLine::NewLine(int len) {
   cout << "Normal constructor allocating ptr" << endl;

   // allocate memory for the pointer;
   ptr = new int;
   *ptr = len;
}

NewLine::NewLine(const NewLine &obj) {
   cout << "Copy constructor allocating ptr." << endl;
   ptr = new int;
   *ptr = *obj.ptr; // copy the value
}

NewLine::~NewLine(void) {
   cout << "Freeing memory!" << endl;
   delete ptr;
}

int NewLine::getLength( void ) {
   return *ptr;
}

void display(NewLine obj) {
   cout << "Length of line : " << obj.getLength() <<endl;
}

void copy_construct(){
    NewLine line1(10);

    NewLine line2 = line1; // This also calls copy constructor

    display(line1);
    display(line2);
}

//5. FRIEND FUNCTION

class FriendFuncClass {
   double width;

   public:
      friend void printWidth( FriendFuncClass box );
      void setWidth( double wid );
};

// Member function definition
void FriendFuncClass::setWidth( double wid ) {
   width = wid;
}

// Note: printWidth() is not a member function of any class.
void printWidth( FriendFuncClass box ) {
   /* Because printWidth() is a friend of Box, it can
   directly access any member of this class */
   cout << "Width of box : " << box.width <<endl;
}

void print_friend(){
    FriendFuncClass box;

    // set box width without member function
    box.setWidth(10.0);

    // Use friend function to print the wdith.
    printWidth( box );
}

//6. INLINE
//If a function is inline, the compiler places a copy of the code of that function at each point
//where the function is called at compile time.

inline int Max(int x, int y) {
   return (x > y)? x : y;
}

void ex_inline(){
    cout << "Max (20,10): " << Max(20,10) << endl;
    cout << "Max (0,200): " << Max(0,200) << endl;
    cout << "Max (100,1010): " << Max(100,1010) << endl;
}

//THIS POISNTER

class ThisPointerClass {
   public:
      // Constructor definition
      ThisPointerClass(double l = 2.0, double b = 2.0, double h = 2.0) {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
      }
      double Volume() {
         return length * breadth * height;
      }
      int compare(ThisPointerClass box) {
         return this->Volume() > box.Volume();
      }

   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

void this_pointer(){
    ThisPointerClass Box1(3.3, 1.2, 1.5);    // Declare box1
    ThisPointerClass Box2(8.5, 6.0, 2.0);    // Declare box2

    if(Box1.compare(Box2)) {
       cout << "Box2 is smaller than Box1" <<endl;
    } else {
       cout << "Box2 is equal to or larger than Box1" <<endl;
    }
}

//POINTER in CLASSES
//A pointer to a C++ class is done exactly the same way as a pointer to a structure
//and to access members of a pointer to a class you use the member access operator -> operator,
//just as you do with pointers to structures. Also as with all pointers,
//you must initialize the pointer before using it.

class PointerClass {
   public:
      // Constructor definition
      PointerClass(double l = 2.0, double b = 2.0, double h = 2.0) {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
      }
      double Volume() {
         return length * breadth * height;
      }

   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

void ex_pointer(){
   PointerClass Box1(3.3, 1.2, 1.5);    // Declare box1
   PointerClass Box2(8.5, 6.0, 2.0);    // Declare box2
   PointerClass *ptrBox;                // Declare pointer to a class.

   // Save the address of first object
   ptrBox = &Box1;

   // Now try to access a member using member access operator
   cout << "Volume of Box1: " << ptrBox->Volume() << endl;

   // Save the address of second object
   ptrBox = &Box2;

   // Now try to access a member using member access operator
   cout << "Volume of Box2: " << ptrBox->Volume() << endl;
}

//STATIC FUNCTIONS
//When we declare a member of a class as static it means no matter how many objects of the class are created,
//there is only one copy of the static member.

class StaticFuncClass {
   public:
      static int objectCount;

      // Constructor definition
      StaticFuncClass(double l = 2.0, double b = 2.0, double h = 2.0) {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;

         // Increase every time object is created
         objectCount++;
      }
      double Volume() {
        return length * breadth * height;
      }
      static int getCount() {
        return objectCount;
      }

   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

// Initialize static member of class Box
int StaticFuncClass::objectCount = 0;

void ex_static(){
    // Print total number of objects before creating object.
    cout << "Inital Stage Count: " << StaticFuncClass::getCount() << endl;

    StaticFuncClass Box1(3.3, 1.2, 1.5);    // Declare box1
    StaticFuncClass Box2(8.5, 6.0, 2.0);    // Declare box2

    // Print total number of objects after creating object.
    cout << "Final Stage Count: " << StaticFuncClass::getCount() << endl;
}
#endif // CLASS_H
