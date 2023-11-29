cmd_/home/alex/develop/kernel/hello-1/hello-4.mod := printf '%s\n'   hello-4.o | awk '!x[$$0]++ { print("/home/alex/develop/kernel/hello-1/"$$0) }' > /home/alex/develop/kernel/hello-1/hello-4.mod
