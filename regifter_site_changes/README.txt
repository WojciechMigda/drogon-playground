Simple endpoint which sends back received attachment.

Example curl test:

curl -XPOST http://localhost:8080/upload -F "file1=@1.jpeg" --output out.jpeg

1.jpeg and out.jpeg should be identical.
