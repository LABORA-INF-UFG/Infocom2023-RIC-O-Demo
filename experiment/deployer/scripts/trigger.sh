#!/bin/bash
curl -X POST http://10.233.60.24/alert -H "Content-Type: application/json" -d @scripts/alert-example.json
#curl -X POST http://127.0.0.1:5000/alert -H "Content-Type: application/json" -d @scripts/alert-example.json