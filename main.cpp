#include <iostream>                                                 // iostream contains std

static void banner()
{
    const char* banner = R"(
                  .__   __  .__  __                .__                           
  _____  __ __|  |_/  |_|__|/  |_  ____   ____ |  |      .__         .__     
 /     \|  |  \  |\   __\  \   __\/  _ \ /  _ \|  |    __|  |___   __|  |___ 
|  Y Y  \  |  /  |_|  | |  ||  | (  <_> |  <_> )  |__ /__    __/  /__    __/ 
|__|_|  /____/|____/__| |__||__|  \____/ \____/|____/    |__|        |__|    
      \/                                                                     

)";                                                                 // multiline raw string
    std::cout << banner << "\n";                                    // cout - character output
}

int main()
{
    std::cout << "Hello from Multitool++!\n";                       // cout - character output
    std::cout << "C++ is a great language!\n";                      // cout - character output

    banner();                                                       // calling banner function

    return 0;                                                       // exit code success
}