while True:
    try:s,a=input(),None
    except:break
    exec('a='+s.replace('F',"0").replace('V','1').replace('&',' and ').replace('|',' or ').replace('!',' not '))
    print('V'if a else 'F')
