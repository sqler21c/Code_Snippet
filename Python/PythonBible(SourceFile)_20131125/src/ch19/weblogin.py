'''
daum.net login and reading page example

Gang Seong Lee
gslee0115@gmail.com
2013.2
'''

import urllib.request
import urllib.parse
from http import cookiejar            

cj = cookiejar.CookieJar()
cookie_handler = urllib.request.HTTPCookieProcessor(cj)
opener = urllib.request.build_opener(cookie_handler)
urllib.request.install_opener(opener)

def my_request(url, postfields):
    headers =  {'User-agent' : 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'}

    req = urllib.request.Request(url, postfields, headers)
    response = urllib.request.urlopen(req)
    return response


def login(username, password):
    login_url = 'https://logins.daum.net/accounts/login.do'
    form_values = {
          'id': username,
          'pw': password,
    }
    formdata = urllib.parse.urlencode(form_values)
    
    try:
        response = my_request(login_url, formdata.encode())
    except IOError as e:
        print ('We failed to open "%s".' % login_url)
        if hasattr(e, 'code'):
            print ('We failed with error code - %s.' % e.code)
        raise SystemExit
    else:
        #response.info()
        #html = response.read()
        pass

def getPage(url):
    response = my_request(url, None)
    return response.read()

def run():
    login('my_login_id', 'my_password')

    url = 'http://www.daum.net/'
    html = getPage(url).decode()
    # do someting with html
    print('내정보' in html)

    url = 'http://mail2.daum.net/hanmailex/simple/Top.daum'
    html = getPage(url).decode()
    # do someting with html
    print('내게쓴편지함' in html)

if __name__ == '__main__':
    run()
