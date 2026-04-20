/*

----- Momento Design Pattern -----

Memento Design Pattern is a behavioral design pattern that allows an object to capture its internal state and save it externally so
that it can be restored later without violating encapsulation. This pattern is particularly useful when you want to implement features
like undo / redo functionality in applications. 

For example, take an application where users can edit documents. By using the Momento Design Pattern, the application can save the state 
of the document at various points in time. If the user wants to undo their last action, the application can restore the document to its
previous state using the saved memento. This way, the internal state of the document is preserved without exposing its details to other 
parts of the application. 

--- Components of Memento Design ---

1) Originator - The main object you want to save and restore. It can make a memento and later use that momento to go back to how it was before. 

2) Memento - A special object that remembers the state of the Originator at a certain time. Once made, its contents cannot be changed, so you can
             always trust it to bring things back exactly as they were. (like a save point)

3) Caretaker - The helper that keeps track of all the mementos (saved states). It stores them safely and can ask the Originator to go back to a previous
               state when needed. The caretaker never looks inside the mementos or changes them; It just holds onto them and gives them back when you want to
               undo or redo something. 

--- Implementation of Memento Design Pattern --- 

We will use all three components of the Memento Design Pattern to implement a simple text editor that allows users to type test and under their last action. 

In this editor, the Originator will be the TextEditor class, which maintains the current text and creates mementos to saves its state. The Memento will be the
TextMemento class, which stores the text state. The Caretaker will be the EditorHistory class, which manages the mementos and allows undo functionality. 

*/

#include <iostream> 
#include <string> 
#include <vector>
using namespace std; 

class TextMomento { 
    private: 
         string currentText;
    public: 
        TextMomento(const string &state) : currentText(state) {}
        string getState() const { return currentText; }
};

class TextEditor { 
    private: 
        string text;
    public: 
        void type (const string &newText){
            text += newText;
        }
        string getText() const {
            return text;
        }
        TextMomento save() {
            return TextMomento(text);
        }
        void restore(const TextMomento &memento){
            text = memento.getState();
        }
};

class EditorHistory { 
    private: 
        vector<TextMomento> history;
    public: 
        void push(const TextMomento &memento) { 
            history.push_back(memento);
        }
        TextMomento pop(){
            if (!history.empty()) { 
                TextMomento memento = history.back();
                history.pop_back();
                return memento;
            }
            return TextMomento("");
        }
};

int main() { 
    TextEditor editor;
    EditorHistory history;

    editor.type("Hello, "); 
    history.push(editor.save());
    editor.type("World!");
    history.push(editor.save());

    cout << "Current Text: " << editor.getText() << endl;
    editor.restore(history.pop());

    return 0;
}