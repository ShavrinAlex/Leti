FROM alpine:3.19.1 as system

RUN apk add --update --no-cache openjdk11 tzdata curl unzip bash



FROM system as build

WORKDIR /app

RUN apk add --update --no-cache maven

COPY pom.xml ./
COPY mvnw ./

RUN mvn dependency:resolve

COPY src ./src

RUN mvn package



FROM build as run

WORKDIR /app

RUN chown -R 1001:0 /app

COPY --from=build /app/target/*.jar ./my_app.jar

USER 1001

CMD ["java", "-jar", "my_app.jar"]
