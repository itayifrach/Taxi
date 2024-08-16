#ifndef PERSON_H
#define PERSON_H

const int ID_LEN = 9;

class Person {

protected:
    const char* name;
    char id[ID_LEN + 1];

public:
    // Constructors
    Person(const char* name, const char* id);
    Person(const Person& other);        // Copy Constructor
    Person(Person&& other);            // Move Constructor
    virtual ~Person();                // Destructor

    Person& operator=(const Person& other);
    Person& operator=( Person&& other);

    // Getters
    const char* getName() const;
    const char* getId() const;

    // Setters
    bool setName(const char* name);
    bool setId(const char* id);
};

#endif // PERSON_H
