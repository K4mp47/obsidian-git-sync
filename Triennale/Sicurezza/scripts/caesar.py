alphabet = "abcdefghijklmnopqrstuvwxyz"

input = """ Lq fubswrjudskb, d Fdhvdu flskhu, dovr nqrzq dv Fdhvdu'v flskhu, wkh vkliw flskhu, Fdhvdu'v frgh ru Fdhvdu \
vkliw, lv rqh ri wkh vlpsohvw dqg prvw zlghob nqrzq hqfubswlrq whfkqltxhv. Lw lv d wbsh ri vxevwlwxwlrq \
flskhu lq zklfk hdfk ohwwhu lq wkh sodlqwhaw lv uhsodfhg eb d ohwwhu vrph ilahg qxpehu ri srvlwlrqv grzq \
wkh doskdehw. Iru hadpsoh, zlwk d ohiw vkliw ri 3, G zrxog eh uhsodfhg eb D, H zrxog ehfrph E, dqg vr rq. Wkh \
phwkrg lv qdphg diwhu Mxolxv Fdhvdu, zkr xvhg lw lq klv sulydwh fruuhvsrqghqfh \
"""


output = ""

for i in range(26):
    for char in input:
        if char.lower() in alphabet:
            index = alphabet.find(char.lower())
            output += alphabet[(index + i) % 26]
        else:
            output += char
    print("Shift " + str(i))
    print(output)
    print()
    print()
    output = ""
