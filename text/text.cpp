//
// Created by Ales1098 on 08.06.2018.
//

#include "text.h"

text::text()
{
	this->ego_users_text = (char*)calloc(100, sizeof(char));
	this->ego_length_users_text = 0;
}

text::text(char *ego_write_text) 
{
    this->ego_users_text=ego_write_text;
    this->ego_length_users_text=ego_length(ego_write_text);
}

char *text::ego_get_users_text() 
{
    return this->ego_users_text;
}

int text::ego_length(char *ego_users_text) 
{
    int length=0;
    for(length; *(ego_users_text+length)!='\0'; ++length);
    return length;
}

std::ostream &operator<<(std::ostream &os, text & users_text)
{
    os<<users_text.ego_users_text;
    return os;
}

std::istream & operator>>(std::istream & is, text & users_text)
{
    is>>users_text.ego_users_text;
    return is;
}


