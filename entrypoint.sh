sleep 10


APP_CONTAINER=$(docker ps -q -f name=testrepo_app)

if [ -n "$APP_CONTAINER" ]; then
    docker logs "$APP_CONTAINER" > /usr/share/nginx/html/index.html
else
    echo "Error: testrepo_app wasn't found" > /usr/share/nginx/html/index.html
fi

exec nginx -g 'daemon off;'