build container:
	docker build -f Dockerfile-devel -t test-blah --no-cache=true .

build binary within container:
	docker run -it -v <path to code>/dlopen-test/:/root/code/dlopen-test -w /root/code/dlopen-test test-blah fab build

