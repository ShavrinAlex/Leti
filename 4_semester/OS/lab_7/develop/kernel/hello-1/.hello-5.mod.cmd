cmd_/home/alex/develop/kernel/hello-1/hello-5.mod := printf '%s\n'   hello-5.o | awk '!x[$$0]++ { print("/home/alex/develop/kernel/hello-1/"$$0) }' > /home/alex/develop/kernel/hello-1/hello-5.mod
