FROM alpine:3.19 as build

WORKDIR /app

RUN apk add --update --no-cache openjdk11 maven 

COPY pom.xml ./
COPY mvnw ./

RUN mvn dependency:resolve

COPY src ./src

RUN mvn package

FROM alpine:3.19 as run

WORKDIR /app

RUN apk add --update --no-cache openjdk11 
COPY --from=build /app/target/*.jar ./my_app.jar

USER 1001

CMD ["java", "-jar", "my_app.jar"]
