# compose_hangul3.py
cho_list_eng = [ "r", "R", "s", "e", "E", "f", "a", "q", "Q", "t", "T", "d", "w", "W", "c", "z", "x", "v", "g"]
jung_list_eng = ["k", "o", "I", "O", "j", "p", "u", "P", "h", "hk", "hO", "hl", "y", "n", "nj", "np", "nl", "b", "m", "ml", "l"]
jong_list_eng = ["", "r", "R", "rt", "s", "sw", "sg", "e", "f", "fr", "fa", "fq", "ft", "fx", "fv", "fg", "a", "q", "qt", "t", "T", "d", "w", "C", "z", "x", "v", "g"]

def compose_hangul3(cho_e, jung_e, jong_e=''):
    cho = cho_list_eng.index(cho_e)
    jung = jung_list_eng.index(jung_e)
    jong = jong_list_eng.index(jong_e)
    code = 0xac00 + ((cho*21) + jung)*28 + jong
    return chr(code)

print (compose_hangul3('g', 'k', 's'), compose_hangul3('r', 'm', 'f'))
