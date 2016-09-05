#include <s2n.h>

int main(){
    struct s2n_connection *conn;
	conn = s2n_connection_new(S2N_SERVER);
	return 0;
}