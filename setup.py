from setuptools import setup, find_packages

setup(
    name='gendefs',
    version='0.0.2',
    packages=find_packages() + find_packages('./scripts'),
    
    entry_points={
        'console_scripts': [
            'gendefs=gendefs:main'
        ]
    }
)

setup(
    name='genfproto',
    version='0.0.1',
    packages=find_packages() + find_packages('./scripts'),
    
    entry_points={
        'console_scripts': [
            'genfproto=genfproto:main'
        ]
    }
)