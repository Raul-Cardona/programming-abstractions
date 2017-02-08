//
// buffer.h
//
// This file defines the interface for the EditorBuffer class.
// It has been augmented to support operations (movement and deletion) on 
// word-boundaries.
//
// --------------------------------------------------------------------------
// Attribution: "Programming Abstractions in C++" by Eric Roberts
// Chapter 13, Exercise 6 (list-based)
// Stanford University, Autumn Quarter 2012
// http://web.stanford.edu/class/archive/cs/cs106b/cs106b.1136/materials/CS106BX-Reader.pdf
//
// This file extends code from Figures 13-2 and 13-8.
// --------------------------------------------------------------------------
//
// Created by Glenn Streiff on 7/25/16.
// Copyright © 2016 Glenn Streiff. All rights reserved. (derivative work)
//

#ifndef buffer_h
#define buffer_h


// Class: EditorBuffer
// -------------------
// This class represents an editor buffer, which maintains an ordered
// sequence of characters along with an insertion point called the cursor.

class EditorBuffer {
    
public:
    
    // Constructor: EditorBuffer
    // Usage: EditorBuffer buffer;
    // ---------------------------
    // Creates an empty editor buffer.
    
    EditorBuffer();
    
    // Destructor: ~EditorBuffer
    // Usage: (usually implicit)
    // -------------------------
    
    ~EditorBuffer();
    
    // Methods: moveCursorForward, moveCursorBackward
    // Usage: buffer.moveCursorForward();
    //        buffer.moveCursorBackward();
    // -----------------------------------
    // These functions move the cursor forward or backward one character,
    // respectively.  If the command would shift the cursor beyond either
    // end of the buffer, this method has no effect.
    
    void moveCursorForward();
    void moveCursorBackward();
    
    // Methods: moveCursorForwardWord, moveCursorBackwardWord
    // Usage: buffer.moveCursorForwardWord();
    //        buffer.moveCursorBackwardWord();
    // ---------------------------------------
    // These methods move the cursor forward or backward one word,
    // respectively.  If the command would shift the cursor beyond either
    // end of the buffer, this method has no effect.
    
    void moveCursorForwardWord();
    void moveCursorBackwardWord();
    
    // Methods: moveCursorToStart, moveCursorToEnd
    // Usage: buffer.moveCursorToStart();
    //        buffer.moveCursorToEnd();
    // --------------------------------
    // These methods move the cursor to the start or the end of this buffer.
    
    // Methods: moveCursorToStart, moveCursorToEnd
    // Usage: buffer.moveCursorToStart();
    //        buffer.moveCursorToEnd();
    // --------------------------------
    // These functions move the cursor to the start or the end of this buffer.
    
    void moveCursorToStart();
    void moveCursorToEnd();
    
    // Method: insertCharacter
    // Usage: buffer.insertCharacter(ch);
    // ----------------------------------
    // Inserts the character ch into this buffer at the cursor position,
    // leaving the cursor after the inserted character.
    
    void insertCharacter(char ch);
    
    // Method: deleteCharacter
    // Usage: buffer.deleteCharacter();
    // --------------------------------
    // Deletes the character immediately after the cursor, if any.
    
    void deleteCharacter();
    
    // Method: deleteWord
    // Usage: buffer.deleteWord();
    // --------------------------------
    // Deletes the word immediately after the cursor, if any.
    //
    // A word consists of a consecutive sequence of alphanumeric characters
    // (i.e., letters or digits) and includes any adjacent nonalphanumeric
    // characters between the cursor and the word (except for spaces).
    
    void deleteWord();
    
    // Method: insertString
    // Usage: buffer.insertString(str);
    // --------------------------------
    // Inserts the string into the buffer at the cursor position,
    // leaving the cursor after the inserted string.
    
    void insertString(const std::string str);
    
    // Method: getText
    // Usage: string str = buffer.getText();
    // -------------------------------------
    // Returns the contents of the buffer as a string.
    
    std::string getText() const;
    
    // Method: getCursor
    // Usage: int cursor = buffer.getCursor();
    // ---------------------------------------
    // Returns the index of the cursor.
    
    int getCursor() const;
    
private:
    
    // Implementation notes: Buffer data structure
    // -------------------------------------------
    // In the linked-list implementation of the buffer, the characters in which
    // the buffer are stored is a list of Cell structures, each of which
    // contains a character and a pointer to the next cell in the chain.  To
    // simplifiy the code used to maintain the cursor, this implementation adds
    // an extra "dummy" cell at the beginning of the list.  The character in
    // this cell is not used, but having it in the data structure provides a
    // cell for the cursor to point to when the cursor is at the beginning of
    // the buffer.
    //
    // The following diagram shows the structure of the list-based buffer
    // containing "ABC" with the cursor at the beginning:
    //
    //
    //        +-----+      +-----+      +-----+      +-----+      +-----+
    //  start |  o--+---==>|     |   -->|  A  |   -->|  B  |   -->|  C  |
    //        +-----+  /   +-----+  /   +-----+  /   +-----+  /   +-----+
    // cursor |  o--+--    |  o--+--    |  o--+--    |  o--+--    |  /  |
    //        +-----+      +-----+      +-----+      +-----+      +-----+
    
    //
    // Type: Cell
    // ----------
    // This structure type is used locally within the implementation to store
    // each cell in the linked-list representation.  Each cell contains one
    // character and a pointer to the next cell in the chain.
    
    struct Cell {
        char ch;
        Cell *link;
    };
    
    // Instance variables
    
    Cell *start;        // Pointer to the dummy cell
    Cell *cursor;       // Pointer to cell before cursor.
    
    // Make it illegal to copy editor buffers
    
    EditorBuffer(const EditorBuffer & value) {}
    const EditorBuffer & operator=(const EditorBuffer & rhs) { return *this; }
    
};

#endif // buffer_h
