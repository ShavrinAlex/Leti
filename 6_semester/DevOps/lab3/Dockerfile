FROM alpine:3.19.1

WORKDIR /src

RUN apk add g++ make --no-cache

COPY ./src .
RUN make


FROM alpine:3.19.1

ARG USER=1001
WORKDIR /src

RUN apk add g++ make --no-cache \
    && chown -R $USER:0 /src

COPY --from=0 ./src .

USER $USER
CMD ./snake
