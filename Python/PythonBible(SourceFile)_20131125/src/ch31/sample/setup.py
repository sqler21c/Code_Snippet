from distutils.core import setup, Extension

setup(name="_sample",
      version="0.1",
      description="sample extension module",
      author="Lee, Gang Seong",
      author_email="gslee0115@gmail.com",
      url="http://pythonworld.net/",
      ext_modules=[
        Extension("_sample", ["sample.c"]),
        Extension("_sample2", ["sample2.c"]),
        ]
)
