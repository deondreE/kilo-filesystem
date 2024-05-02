#
# setup;
#
setup:
	chmod +x ./scripts/setup.sh
	./scripts/setup.sh

#
# clean;
#
clean: 
  rm -rf build/*

# 
# builds will be platform specific.
#
mac:
	