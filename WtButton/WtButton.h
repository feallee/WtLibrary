#ifndef __WTBUTTON_H_
#define __WTBUTTON_H_
/// <summary>
/// °´¼ü¿âº¯Êý°æ±¾ºÅ¡£
/// </summary>
#define WTBUTTON_VERSION	10

typedef void* WtButton_Type;

typedef void(*WtButton_Event)(char id, size_t count);

WtButton_Type WtButton_Create(char id, size_t repeatTicks, WtButton_Event holdEvent, WtButton_Event repeatEvent);

void WtButton_Scan(WtButton_Type button, unsigned char value);

void WtButton_Dispose(WtButton_Type button);


#endif //__WTBUTTON_H_
