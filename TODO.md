# KAT  Roadmap

## 1. Project Setup

- [x] **Create a Project Directory**
  - Set up a directory for your shell project.
- [x] **Initialize Version Control**
  - Set up a Git repository to track your changes.

## 2. Basic Shell Structure

- [x] **Create a Basic Shell File**
  - Implement a basic `main()` function that starts an infinite loop.
- [x] **Display a Prompt**
  - Print a command prompt to the user.

## 3. Reading User Input

- [x] **Read Input from the User**
  - Use `fgets()` or `getline()` to read user input from the command line.
- [x] **Handle Input Length**
  - Ensure input is handled correctly even if it’s very long.
- [x] **Ctrl + c & Ctrl + d functionality**
  - Ensure input is handled correctly even if it’s very long.

## 4. Parsing Commands

- [x] **Tokenize Input**
  - Split the input into tokens using functions like `strtok()`.
- [x] **Handle Simple Commands**
  - Parse and execute simple commands (e.g., `ls`, `pwd`).

## 5. Executing Commands

- [ ] **Fork and Execute**
  - Use `fork()` to create a child process.
  - Use `execvp()` or `execv()` in the child process to execute the command.
- [ ] **Wait for Command Completion**
  - Use `wait()` or `waitpid()` to wait for the child process to complete.

## 6. Handling Built-in Commands

- [ ] **Implement Built-in Commands**
  - Handle commands like `cd` (change directory) and `exit` within the shell.
- [ ] **Implement Exit Command**
  - Exit the shell cleanly when the `exit` command is entered.

## 7. Redirection and Pipes

- [ ] **Implement Input/Output Redirection**
  - Handle commands with `<` (input redirection) and `>` (output redirection).
- [ ] **Implement Piping**
  - Handle commands with pipes `|` to connect the output of one command to the input of another.

## 8. Error Handling

- [ ] **Add Error Checking**
  - Check for errors in system calls and handle them gracefully.
- [ ] **Display Error Messages**
  - Provide meaningful error messages to the user when something goes wrong.

## 9. Command History (Optional)

- [ ] **Implement Command History**
  - Store and allow users to recall previous commands (e.g., using a linked list or file).

## 10. Testing and Debugging

- [ ] **Test Basic Functionality**
  - Test the shell with various commands to ensure they execute correctly.
- [ ] **Debug and Refine**
  - Debug any issues and refine the implementation for stability and usability.

## 11. Documentation

- [ ] **Document the Code**
  - Add comments and documentation to explain the code and its functionality.
- [ ] **Write a README**
  - Create a README file explaining how to build and use your shell.

## 12. Future Enhancements (Optional)

- [ ] **Implement Job Control**
  - Allow for job control features like background jobs and job listing.
- [x] **Add Signal Handling**
  - Handle signals like SIGINT (Ctrl+C) to interrupt commands.
- [ ] **Add Color, Background, Foreground, Style Formatting**
  - Prettify the shell output.
