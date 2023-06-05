cmd_/home/alex/develop/kernel/timer/timer-1.mod := printf '%s\n'   timer-1.o | awk '!x[$$0]++ { print("/home/alex/develop/kernel/timer/"$$0) }' > /home/alex/develop/kernel/timer/timer-1.mod
