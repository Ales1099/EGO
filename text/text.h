//
// Created by Ales1098 on 08.06.2018.
//

#ifndef EGO_TEXT_H
#define EGO_TEXT_H

#include <iostream>

class text {
private:
    char* ego_users_text;
    int ego_length_users_text;
public:
    text();
    text(char * ego_write_text);
    char * ego_get_users_text();
    int ego_length(char * ego_users_text);

    friend std::ostream & operator<<(std::ostream & os, text & users_text);
    friend std::istream & operator>>(std::istream & is, text & users_text);

    friend text & operator+(const text & users_text_1, const text & users_text_2);
    text &operator+=(const text & users_text);
};


#endif //EGO_TEXT_H
