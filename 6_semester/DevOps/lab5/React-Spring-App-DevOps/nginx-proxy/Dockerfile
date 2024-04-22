FROM alpine:3.19 as run

RUN apk add nginx --update --no-cache && \
    chown -R 1001:0 /var/lib/nginx && \
    chown -R 1001:0 /run/nginx

USER 1001

CMD ["nginx", "-g", "daemon off;"]
