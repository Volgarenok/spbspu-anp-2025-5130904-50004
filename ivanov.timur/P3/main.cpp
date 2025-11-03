#include <fstream>
namespace ivanov {
    struct Dynamic {
        int rows, cols;
        int * matrix = reinterpret_cast< int * >(malloc(sizeof(int) * (rows * cols)));
    };
    struct Static {
        int rows, cols;
        int matrix[1000] = {};
    };

}
int main(int argc, char ** argv)
{

}
