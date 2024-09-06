#usage
docker pull curlimages/curl  
docker build -t serverimage .  
docker network create --driver overlay --attachable testNetwork  
docker service create --name cpp-server --network testNetwork -publish 8080:8080 serverimage  
cd ddos  
docker compose up  
