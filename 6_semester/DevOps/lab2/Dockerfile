FROM alpine:3.17

WORKDIR /app

RUN apk update && \
    apk add libpq-dev gcc python3 py3-pip && \
    rm -rf /var/cache/** 

COPY ./src .

RUN pip install --upgrade pip && \
    pip install -r requirements.txt

RUN chown -R 1001:0 start.sh && \
    chmod u+x start.sh

USER 1001

CMD ./start.sh