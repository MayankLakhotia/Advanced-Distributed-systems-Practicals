from xmlrpc.server import SimpleXMLRPCServer
from xmlrpc.server import SimpleXMLRPCRequestHandler

# Restrict to a particular path.
class RequestHandler(SimpleXMLRPCRequestHandler):
    rpc_paths = ('/RPC2',)

# Create server
with SimpleXMLRPCServer(('localhost', 8000),
                        requestHandler=RequestHandler) as server:
    server.register_introspection_functions()

    # Register a function under a different name
    def add(x, y):
        return x + y
    server.register_function(add, 'add')

    def subtract(x, y):
        return x - y
    server.register_function(subtract, 'subtract')

    def divide(x, y):
        return x // y
    server.register_function(divide, 'divide')

    # Register an instance; all the methods of the instance are
    # published as XML-RPC methods (in this case, just 'mul').
    class MyFuncs:
        def mul(self, x, y):
            return x * y

    server.register_instance(MyFuncs())

    # Run the server's main loop
    server.serve_forever()

    # Register pow() function; this will use the value of
    # pow.__name__ as the name, which is just 'pow'.
    # server.register_function(pow)