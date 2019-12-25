# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
import uiautomator2 as u2

d = u2.connect('10.100.0.25')
print(d.info)
# sess = d.session("com.android.settings")
d.screen_on()
# d.info.get('screenOn')

sess = d.session("com.android.settings")
#sess(text="Wi-Fi").click()

#sess(text="Apps").click()