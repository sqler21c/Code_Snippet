# debugging.py

def check_sum(line):
    import pdb
    pdb.set_trace()
    p1 = line.index('$')
    p2 = line.index('*')
    s = line[p1:p2]

    chk = 0
    for c in s:
        code = ord(c)
        chk = chk ^ code
    return chk

if __name__ == '__main__':    
    line = '$GPGGA,114455.532,3735.0079,N,12701.6446,E,,,,,,,,,0000*7e'
    print (hex(check_sum(line)))
