#include <stdilb.h>
#include <unisys.h>
#include <sys/type.h>
#include <sys/stat.h>
#include <fcntl.h>

//open(const char *pathname, int O_CREAT|O_WRONLY|O_TRUNC);
//open(const char *pathname, int O_RDONLY);

int main()
{
	int fd_in,fd_out;
	fd_in = open("Sansung_Electronics.txt");
	
}

