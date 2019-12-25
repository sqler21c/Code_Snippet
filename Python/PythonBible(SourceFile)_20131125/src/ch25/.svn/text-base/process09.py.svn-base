# process09.py
from multiprocessing.connection import Listener

address = ('localhost', 6000)

def server():
    listener = Listener(address, authkey=b'mypassword')
    print('listening..')
    from_client = True
    while from_client:
        conn = listener.accept()
        print ('connection accepted from', listener.last_accepted)

        conn.send([1,2,3,4])
        conn.send_bytes(b'hello')
        from_client = conn.recv()
        print(from_client)

        conn.close()
    listener.close()

if __name__ == '__main__':
    server()
