#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/socket.h>   
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>  

int serial ()
{
   struct termios ops;
  printf("opening file...\n");
  int fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd == -1) {
    printf("open_port: UNable to open /dev/ttyUSB0");
    return -1;
  }
  printf("setting attr\n");
  tcgetattr(fd, &ops);
  cfsetispeed(&ops, B9600);
  cfsetospeed(&ops,B9600);
  ops.c_cflag |= (CLOCAL | CREAD);
  ops.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
  tcsetattr(fd, TCSANOW, &ops);

  return fd;
}

int open_socket()
{
  int serverSocket = 0,
    on = 0;
    port = 9500;
    status = 0;
    childPid = 0;
  struct hostent *hostPtr = NULL;
  char hostname[80] = "";
  struct sockaddr_in serverName = { 0 };

  serverSocket = socket(PF_INET, SOCK_SREAM, IPPROTO_TCP);
  if (serverSocket == -1)
  {
    printf("Error 1");
    exit(1);
  }

  on = 1;

  status = setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR,
    (const char *) &on, sizeof(on));

  if (status == -1) {
    printf("Error 2"); 
  }

}

int main () 
{
  fd = serial();

  int i = 0;
  int n;
  printf("testing lights\n");
  while (1) {
    write(fd,"000,000,000",11);
    sleep(2);
    write(fd,"255,255,255",11);
    sleep(2);
  }
  close(fd);
  return 0;
}
