from fabric.api import run, local
from fabric.context_managers import lcd

def wipe():
	local("rm -rf build")
        local("mkdir build")

def build():
	wipe()
	with lcd("build"):
		local("pwd")
		local("cmake ../")
		local("make")


