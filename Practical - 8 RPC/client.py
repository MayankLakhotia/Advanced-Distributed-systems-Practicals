import xmlrpc.client

server = xmlrpc.client.ServerProxy('http://localhost:8000')

x = input("Please enter x : ")
y = input("Enter y : ")

# print(s.pow(int(x),int(y)))  # Returns x*y = 8
print(x,"+",y,"=",server.add(int(x),int(y)))  # Returns x+y 
print(x,"-",y,"=",server.subtract(int(x),int(y))) # Return x-y
print(x,"*",y,"=",server.mul(int(x),int(y)))  # Returns x*y
print(x,"//",y,"=",server.divide(int(x),int(y))) #Return x // y


# Print list of available methods
# print(s.system.listMethods())