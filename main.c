#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define INPUT_BUFFER_SIZE 1024

void handle_sigint(int sig) {
  printf("\n SIGINT (Ctrl + c ) Encountered");
  exit(EXIT_SUCCESS);
}

int main() {
  const char *username = getenv("USER");
  char hostname[256];
  gethostname(hostname, sizeof(hostname));

  char input[INPUT_BUFFER_SIZE];

  signal(SIGINT, handle_sigint);

  while (1) {
    printf("%s@%s ~ $ ", username, hostname);

    if (fgets(input, sizeof(input), stdin) == NULL) {
      if (feof(stdin)) {
        printf("\n Ctrl + D Encountered Exiting");
        return EXIT_SUCCESS;
      } else {
        printf("\n Something else encountered");
      }
    }

    if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') {
      input[strlen(input) - 1] = '\0';
    }

    if (strcmp(input, "exit") == 0) {
      return EXIT_SUCCESS;
    }
  }
  return EXIT_SUCCESS;
}
