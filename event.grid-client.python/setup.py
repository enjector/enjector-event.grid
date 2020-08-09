from distutils.core import setup

import sys
if sys.version_info < (3,0):
  sys.exit('Sorry, Python < 3.0 is not supported')

setup(
  name        = 'event.grid-client.python',
  version     = '', # TODO: might want to use commit ID here
  packages    = [ 'eventgrid' ],
  package_dir = {
    '': 'event.grid-client.python/main/package'
  },
  package_data = {
    '': ['eventgrid.pyd']
  }
)
