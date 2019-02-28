* Download virtual box and any linux image(don't go for rc-x ). Set them up(also create a backup of vm cause you are going to mess up).
* Boot up the new vm.
* In the vm, wget kernel from http://www.kernel.org
* Untar it the archive and cd into it.
* Configure the system for your machine config by running "make menuconfig" - don't just use default as it will result in huge binaries when compiling. If errors are given install necessary dependencies. Finally you'll get a .config file.
* Do "make" to compile the kernel - will use the settings from .config. This will produce "vmlinuz" - the kernel image.
* Do "make modules" to compile the kernel modules - watch out for out of memory error in case your vm doesn't have enough memory.
* Do "make module_install" to install the modules into vmlinuz.
* Do "make install" to install the kernel.
* Reboot and check kernel version(in case this wasn't the same.).
