FROM alpine:3.19.1

ARG USER=1001

RUN apk add --update nginx --no-cache && \
    chown -R $USER:0 /var/lib/nginx && \
    chown -R $USER:0 /run/nginx

USER $USER

CMD ["nginx", "-g", "daemon off;"]
