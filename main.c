#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define INPUT_BUFFER_SIZE 1024

int main() {
  const char *username = getenv("USER");
  char hostname[256];
  gethostname(hostname, sizeof(hostname));

  char *args[50];
  char input[INPUT_BUFFER_SIZE];

  while (1) {
    printf("%s@%s ~ $ ", username, hostname);

    if (fgets(input, sizeof(input), stdin) == NULL) {
      if (feof(stdin)) {
        // printf("\n Ctrl + D Encountered Exiting");
        return EXIT_SUCCESS;
      } else {
        continue;
      }
    }

    if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') {
      input[strlen(input) - 1] = '\0';
    }

    char delimiters[] = " ,;";
    char *token = strtok(input, delimiters);

    int i = 0;
    while (token != NULL) {
      args[i++] = token;
      token = strtok(NULL, delimiters);
    }
    args[i] = NULL;

    if (strcmp(args[0], "exit") == 0) {
      // printf("Exiting SHELL");
      return EXIT_SUCCESS;
    } else {
      pid_t p = fork();

      if (p < 0) {
        perror("Fork Failed \n");
        perror("EXITING SHELL \n");
        exit(EXIT_FAILURE);
      } else if (p == 0) {
        execvp(args[0], args);

        perror("execvp failed");
        return EXIT_FAILURE;
      } else {
        int status;
        waitpid(p, &status, 0);
      }
    }
  }
  return EXIT_SUCCESS;
}
