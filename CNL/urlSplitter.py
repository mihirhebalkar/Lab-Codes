url = input("Enter a URL : ")

protocol = ""
host = ""
port = None
path = ""

if "://" in url:
    protocol, url = url.split("://", 1)

if "/" in url:
    host, path = url.split("/", 1)
else:
    host = url
    path = 'NULL'

if ":" in host:
    host, port = host.split(":", 1)

print("Protocol:", protocol)
print("Host:", host)
print("Port:", port if port else "None")
print("Path:", path)
