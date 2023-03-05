#include "Lab6Example.h"
#include <iostream>
namespace SpaceExample1 {
    ///Задача. Створити дві ієрархії класів без віртуального та з віртуальним спадкуванням, 
    // з елементами даних класів у кожному класі. Схема успадкування на рисунку за варіантами. 
    // Створити об’єкти похідних класів з віртуальним та без віртуального успадкуванням. 
    // Вивести розміри об’єктів даних класів.
    ///

    class Base1
    {
    protected:
        int dat;
        double a[5] = { 10,1,7,1,9 };
    public:
        Base1() : dat(1) {}
        Base1(int d) : dat(d) {}
    };

    class Base2
    {
    protected:
        int dat;
        double a[5] = { 10,1,7,1,9 };
    public:
        Base2() : dat(1) {}
        Base2(int d) : dat(d) {}
    };

    class DB12 : protected Base1, protected Base2
    {
    protected:
        int db12;
    public:
        DB12() : db12(1) {}
        DB12(int d) : db12(d) {}
        DB12(int a, int b, int c) : Base1(a), Base2(b), db12(c) {}
    };

    class DB1 : protected Base1
    {
    protected:
        double db1;
    public:
        DB1() : db1(1) {}
        DB1(double d) : db1(d) {}
        DB1(int d, double db1) : Base1(d), db1(db1) {}
    };

    class RDB12 : protected DB12
    {
    protected:
        double db12;
    public:
        RDB12() : db12(1) {}
        RDB12(double d) : db12(d) {}
        RDB12(int a, int b, int c, double d) : DB12(a, b, c), db12(d) {}
    };

    class R : protected DB1, protected DB12, protected RDB12
    {
    protected:
        double dt;
    public:
        R() : dt(1) {}
        R(double d) : dt(d) {}
        R(
            int a, double b, int c, int d, int e, int f, int g, int h, double i
        ) : DB1(a, b), RDB12::DB12(c, d, e), RDB12(f, g, h, i), dt(i) {}
        void showDat()
        {
            std::cout << "DB1::Base1::dat         =  " << DB1::Base1::dat << std::endl;
            std::cout << "DB12::Base2::dat        =  " << DB12::Base2::dat << std::endl;
            std::cout << "RDB12::DB12::Base1::dat =  " << RDB12::DB12::Base1::dat << std::endl;
            std::cout << "RDB12::DB12::Base2::dat =  " << RDB12::DB12::Base2::dat << std::endl;
        }
    };


    //
    //  virtual
    //


    class DB12V : virtual protected Base1, virtual protected Base2
    {
    protected:
        int db12;
    public:
        DB12V() : db12(1) {}
        DB12V(int d) : db12(d) {}
        DB12V(int a, int b, int c) : Base1(a), Base2(b), db12(c) {}
    };

    class DB1V : protected virtual Base1
    {
    protected:
        double db1;
    public:
        DB1V() : db1(1) {}
        DB1V(double d) : db1(d) {}
        DB1V(int d, double db1) : Base1(d), db1(db1) {}
    };

    class RDB12V : virtual public DB12V
    {
    protected:
        double db12;
    public:
        RDB12V() : db12(1) {}
        RDB12V(double d) : db12(d) {}
        RDB12V(int a, int b, int c, double d) : DB12V(a, b, c), db12(d) {}
    };

    class RV : virtual protected DB1V, virtual public DB12V, virtual public RDB12V
    {
    protected:
        double dt;
    public:
        RV() : dt(1) {}
        RV(double d) : dt(d) {}
        RV(
            int a, double b, int c, int d, int e, int f, int g, int h, double i
        ) : DB1V(a, b), RDB12V::DB12V(c, d, e), RDB12V(f, g, h, i), dt(i) {}
        void showDat()
        {
            std::cout << "DB1V::Base1::dat         =  " << DB1V::Base1::dat << std::endl;
            std::cout << "DB12V::Base2::dat        =  " << DB12V::Base2::dat << std::endl;
            std::cout << "RDB12V::DB12V::Base1::dat =  " << RDB12V::DB12V::Base1::dat << std::endl;
            std::cout << "RDB12V::DB12V::Base2::dat =  " << RDB12V::DB12V::Base2::dat << std::endl;
        }
    };


    int mainExample1()
    {
        std::cout << " Example 1  \n";
        R a, b(1, 2.2, 3, 4, 5, 10, 4, 2, 3.33);
        RV av, bv(1, 2.2, 3, 4, 5, 10, 4, 2, 3.33);

        std::cout << "Testing !\n";
        std::cout << "Size for Base1 " << sizeof(Base1) << std::endl;
        std::cout << "Size for Base2 " << sizeof(Base2) << std::endl;
        std::cout << "Size for DB12 " << sizeof(DB12) << std::endl;
        std::cout << "Size for DB1 " << sizeof(DB1) << std::endl;
        std::cout << "Size for RDB12 " << sizeof(RDB12) << std::endl;
        std::cout << "Size for R " << sizeof(R) << std::endl;

        std::cout << "Size for DB12V " << sizeof(DB12V) << std::endl;
        std::cout << "Size for DB1V " << sizeof(DB1V) << std::endl;
        std::cout << "Size for RDB12V " << sizeof(RDB12V) << std::endl;
        std::cout << "Size for RV " << sizeof(RV) << std::endl;

        std::cout << "Size for object class R " << sizeof(R) << " or  "
            << sizeof(a) << " or  " << sizeof(b) << std::endl;
        std::cout << "Size for object class RV " << sizeof(RV) << " or  "
            << sizeof(av) << " or  " << sizeof(bv) << std::endl;
        b.showDat();
        bv.showDat();
        return 0;
    }

}