#include "Lab6Example.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
namespace SpaceExample3 {
    // MultipleiInherance.cpp 
// Ієрархія типів складається з сутностей: 
// машина, пасажирський транспорт і автобус.
//


    class File {
    protected:
        std::string filename;
    public:
        File(const std::string& filename) : filename(filename) {}
        virtual ~File() {}
        virtual void read() const = 0;
        virtual void write() const = 0;
        friend std::ostream& operator<<(std::ostream& os, const File& file);
    };

    std::ostream& operator<<(std::ostream& os, const File& file) {
        os << "Filename: " << file.filename << std::endl;
        return os;
    }

    class Readable {
    public:
        virtual void read() const = 0;
    };

    class Writable {
    public:
        virtual void write() const = 0;
    };

    class ReadWrite : public Readable, public Writable {
    public:
        virtual void read() const = 0;
        virtual void write() const = 0;
    };

    class ReadableFile : public File, public Readable {
    public:
        ReadableFile(const std::string& filename) : File(filename) {}
        virtual void read() const {
            std::ifstream file(filename);
            std::cout << "Content of " << filename << ":" << std::endl;
            std::string line;
            while (std::getline(file, line)) {
                std::cout << line << std::endl;
            }
        }
    };

    class WritableFile : public File, public Writable {
    public:
        WritableFile(const std::string& filename) : File(filename) {}
        virtual void write() const {
            std::ofstream file(filename);
            file << "Hello, world!" << std::endl;
        }
    };

    class ReadWriteFile : public File, public ReadWrite {
    public:
        ReadWriteFile(const std::string& filename) : File(filename) {}
        virtual void read() const {
            std::ifstream file(filename);
            std::cout << "Content of " << filename << ":" << std::endl;
            std::string line;
            while (std::getline(file, line)) {
                std::cout << line << std::endl;
            }
        }
        virtual void write() const {
            std::ofstream file(filename);
            file << "Some text" << std::endl;
        }
    };



    int mainExample3()
    {
        File* f3 = new ReadWriteFile("data.txt");
        std::cout << *f3;
        f3->read();
        f3->write();
        delete f3;


        return 0;
    }


}