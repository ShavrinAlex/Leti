FROM alpine:3.19.1

RUN apk add nginx --update --no-cache && \
    chown -R 1001:0 /var/lib/nginx && \
    chown -R 1001:0 /run/nginx

USER 1001

CMD ["nginx", "-g", "daemon off;"]