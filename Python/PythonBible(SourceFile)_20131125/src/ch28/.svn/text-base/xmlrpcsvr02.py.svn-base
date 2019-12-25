# xmlrpcsvr02.py
from xmlrpc.server import *

class MyRequestHandler(SimpleXMLRPCRequestHandler):
    def _dispatch(self, method, params):
        try:
            server_method = getattr(self, "do_"+method)
        except:
            raise AttributeError("No XML-RPC procedure do_%s" % method)
        return server_method(*params)

    def do_otherObj(self, datetime, bin):
        print(datetime, bin)
        print()
        print(datetime.value, bin.data)
        return datetime, bin

if __name__ == '__main__':
    server = SimpleXMLRPCServer(('', 8000), MyRequestHandler)
    server.serve_forever()
