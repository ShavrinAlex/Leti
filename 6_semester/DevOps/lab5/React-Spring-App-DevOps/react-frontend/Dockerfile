FROM alpine:3.19.1 as build

WORKDIR /build

RUN apk update && \
    apk add nodejs npm --no-cache

COPY ./package.json ./package-lock.json ./

RUN npm install

COPY . .

RUN npm run build


FROM alpine:3.19.1

WORKDIR /run

RUN apk add nginx curl --update --no-cache && \
    chown -R 1001:0 /var/lib/nginx /run/nginx /var/log/nginx

COPY --from=build /build/build /var/www/html

USER 1001

CMD ["nginx", "-g", "daemon off;"]
