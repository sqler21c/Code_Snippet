# setup.py
from distutils.core import setup

setup(name="spam",
        version="1.0",
        description="setup test",
        author="Lee, Gang Seong",
        author_email="gslee0115@gmail.com",
        url="http://pythonworld.net/",

        py_modules = ['A', 'B', 'mymath02'],
        packages = ['Speech', 
            'Speech/Recognition', 
            'Speech/SignalProcessing', 
            'Speech/Synthesis'],
        #package_dir={'Speech': 'Speech2'},
        package_data={'Speech': ['images/*.jpg']},
        data_files=[('data', ['Speech/images/a1.jpg'])],
)
