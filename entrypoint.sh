#!/bin/bash
until kubectl get pods -l app=test-app --field-selector=status.phase=Running -o name | grep -q "pod/"; do
    sleep 5
done

kubectl logs -l app=test-app --tail=100 > /usr/share/nginx/html/logs.txt
exec nginx -g 'daemon off;'