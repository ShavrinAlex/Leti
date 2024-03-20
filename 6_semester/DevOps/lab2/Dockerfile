FROM alpine:3.17

WORKDIR /app

RUN apk update && \
    apk add libpq-dev gcc python3 py3-pip && \
    rm -rf /var/cache/** 

COPY ./src/requirements.txt .

RUN pip install --upgrade pip && \
    pip install -r requirements.txt 

USER 1001

