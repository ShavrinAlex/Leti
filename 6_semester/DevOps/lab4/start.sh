docker build -f DockerfileSystem -t system:1.0.0 .

docker build -f DockerfileBuild -t build:1.0.0 .

docker build -f DockerfileRun -t app:1.0.0 .

docker run -it app:1.0.0