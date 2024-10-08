// simple calculator project using a class
#include <iostream>
using namespace std;

class clsCalculator
{
private:
    double _Result = 0;
    double _PreviousResult = 0;
    double _Input = 0;
    string _Operation = "Clearing";

    bool isZero(double num)
    {
        return (num == 0);
    }

public:
    void Clear()
    {
        _Result = 0;
        _PreviousResult = 0;
        _Input = 0;
        _Operation = "Clearing";
    }
    void Add(double num)
    {
        _PreviousResult = _Result;
        _Input = num;
        _Operation = "Adding";
        _Result += num;
    }
    void Subtarct(double num)
    {
        _PreviousResult = _Result;
        _Input = num;
        _Operation = "Subtracting";
        _Result -= num;
    }
    void Multiply(double num)
    {
        _PreviousResult = _Result;
        _Input = num;
        _Operation = "Multipling";
        _Result *= num;
    }
    void Divide(double num)
    {
        _Input = num;
        
        if (isZero(num))
            num = 1;

        _PreviousResult = _Result;
        _Operation = "Dividing";
        _Result /= num;
    }
    void CancelLastOperation()
    {
        _Operation = "Cancelling Last Operation";
        _Result = _PreviousResult;
    }

    void PrintResult()
    {
        if (_Operation != "Clearing" && _Operation != "Cancelling Last Operation")
            cout << "Result After " << _Operation << " " << _Input << " is: " << _Result << endl;
        else
            cout << "Result After " << _Operation << " is: " << _Result << endl;
    }
    double GetFinalResult()
    {
        return _Result;
    }


};

int main()
{
    clsCalculator Calculator1;

    Calculator1.Clear();

    Calculator1.Add(10);
    Calculator1.PrintResult();

    Calculator1.Subtarct(5);
    Calculator1.PrintResult();

    Calculator1.Multiply(6);
    Calculator1.PrintResult();

    Calculator1.Divide(2);
    Calculator1.PrintResult();

    Calculator1.CancelLastOperation();
    Calculator1.PrintResult();

    Calculator1.Clear();
    Calculator1.PrintResult();

    system("pause>0");
    return 0;
}

