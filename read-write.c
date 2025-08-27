//wap to read data from the standard input output device and write it on the screen
#include <unistd.h>
int main()
{
    char buff[20];
    int n = read(0, buff, 10); //0 means stdin (keyboard) 
    write(1, buff, 10);       //1 means stdout (screen/terminal)
}