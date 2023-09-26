# Signals

A signal is a software generated interrupt that is sent to a process by the OS, which forces the process to handle something immediately. In short they are like notifications sent to a process to notify them about various important events. There are fix set of signals that can be sent to a process. Signals are identified by integers.

```man 7 signal```

To list all the signals supported by your system:
```
kill -l
```

## Signal handlers

Each signal may have a signal handler, which is a function that gets called when the process receives that signal. The function is called in "asynchronous mode", meaning that no where in your program you have code that calls this function directly. Instead, when the signal is sent to the process, the operating system stops the execution of the process, and "forces" it to call the signal handler function. When that signal handler function returns, the process continues execution from wherever it happened to be before the signal was received, as if this interruption never occurred. 


