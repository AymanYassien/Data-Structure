//
// Created by Ayman yassien on 16/02/2024.

#include "stack"
#include "iostream"

using namespace std;

// Undo/Redo Task

class clsMyString{

    stack <string> _Undo;
    stack <string> _Redo;

    string _string  = " ";

public:
    void setValue(string s1)
    {
        _Undo.push(_string);
        _string = s1;
    }
    string getValue()
    {
        return _string;
    }

    void undo()
    {
        if ( !_Undo.empty()){
            _Redo.push(_string);
            _string = _Undo.top();
            _Undo.pop();
        }


    }

    void redo()
    {
        if (!_Redo.empty())
        {
            _Undo.push(_string);
            _string = _Redo.top();
            _Redo.pop();

        }

    }

};

/*
 * #include "clsMyString.h"
using namespace std;

int main() {

    cout << "\n\n\t\t\t\t\t\t Undo/Redo Task\n\n";

    clsMyString string1;

    cout << "\nS1  = " << string1.getValue() << '\n';

    string1.setValue("Ayman1");

    cout << "\nS1  = " << string1.getValue() << '\n';

    string1.setValue("Ayman2");

    cout << "\nS1  = " << string1.getValue() << '\n';

    string1.setValue("Ayman3");

    cout << "\nS1  = " << string1.getValue() << '\n';

    string1.undo();
    cout << "\nS1  after undo = " << string1.getValue() << '\n';

    string1.undo();
    cout << "\nS1  after undo = " << string1.getValue() << '\n';

    string1.undo();
    cout << "\nS1  after undo = " << string1.getValue() << '\n';


    string1.redo();
    cout << "\n\n\nS1  after redo = " << string1.getValue() << '\n';

    string1.redo();
    cout << "\nS1  after redo = " << string1.getValue() << '\n';

    string1.redo();
    cout << "\nS1  after redo = " << string1.getValue() << '\n';







    return 0;

}*/
