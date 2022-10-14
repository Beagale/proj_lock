// Manage lock functionalities

#ifndef LOCK_H_
#define LOCK_H_



void Lock_init(void);
// NOTE: maybe will take a bool as argument, which will tell if user has entered correct PIN number
void Lock_unlock(bool);
void Lock_lock(void);


#endif