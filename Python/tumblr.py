"""
A Read Only Tumblr Python library for their version 2 API.

Requires a Tumblr API Key and httplib2.

Copyright (c) 2010, Myles Braithwaite <me@mylesbraithwaite.com>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

* Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in
  the documentation and/or other materials provided with the
  distribution.

* Neither the name of the Monkey in your Soul nor the names of its
  contributors may be used to endorse or promote products derived
  from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
"""

import json
import urllib
import httplib2

class Tumblr(object):
	
	API_SCHEME = 'http'
	API_HOST = 'api.tumblr.com'
	
	BLOG_URLS = {
		'info': '/v2/blog/%(hostname)s/info',
		'avatar': '/v2/blog/%(hostname)s/avatar',
		'posts': '/v2/blog/%(hostname)s/posts',
	}
	
	def __init__(self, api_key, blog_name):
		self.api_key = api_key
		self.blog_name = blog_name
		self.http = httplib2.Http()
	
	def client(self, path, query={}, method='GET'):
		path = path % { 'hostname': self.blog_name }
		query['api_key'] = self.api_key
		
		return self.http.request("%s://%s%s?%s" % (self.API_SCHEME, self.API_HOST, path, urllib.urlencode(query)), 'GET')
	
	def info(self):
		resq, content = self.client(self.BLOG_URLS['info'])
		return json.loads(content)
	
	def avatar(self):
		resq, content = self.client(self.BLOG_URLS['avatar'])
		return json.loads(content)
	
	def posts(self, limit=20, offset=0, post_type=None, post_id=None, tag=None,
		reblog_info=False, notes_info=False, format=None):
		
		query = {
			'limit': limit,
			'offset': offset,
		}
		
		if post_type:
			query['type'] = post_type
		
		if post_id:
			query['id'] = post_id
		
		if tag:
			query['tag'] = tag
		
		if reblog_info:
			query['reblog_info'] = reblog_info
		
		if notes_info:
			query['notes_info'] = notes_info
		
		if format:
			query['format'] = format
		
		resp, content = self.client(self.BLOG_URLS['posts'], query)
		return json.loads(content)