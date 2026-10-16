#include "usuario.h"
#include <cstring>


using namespace std;

usuario::usuario() {
    username[0] ='\0';
    email[0] = '\0';
    fechanacimiento[0]= '\0';
    fotoperfilruta[0] = '\0';
    ciudad[0] = '\0';
    pais[0] = '\0';

}

usuario::usuario(const char* user, const char* mail, const char* fotoruta) {
    strncpy(username, user, sizeof(username)-1);
    username[sizeof(username)-1] = '\0';

    strncpy(email,mail.sizeof(email) - 1);
    email[sizeof(email)-1]= '\0';

}