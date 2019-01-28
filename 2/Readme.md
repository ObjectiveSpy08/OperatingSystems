''''General steps for copy program:''''

- Create file i/o refereences/descriptors.
- Check for vali number of arguments- one soruce file and one destination file.
- Attempt to open src file, exit on fail.
- Attempt to open dest file. If it doesn't exist create it. Exit on fail
- Start reading src file and while that src file has contents to be read, keep wrinting those contents to dest file. Exit if write failed.
- Close both files.
