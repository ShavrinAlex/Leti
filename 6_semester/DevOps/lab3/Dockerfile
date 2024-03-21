FROM alpine:3.19.1 AS Builder

WORKDIR /src

RUN apk add g++ make --no-cache

COPY ./src .
RUN make


FROM alpine:3.19.1 AS Launcher

WORKDIR /src

RUN apk add --no-cache libstdc++ && \
    chown -R 1001:0 /src

COPY --from=0 ./src .

USER 1001
CMD ./snake
