#######################
#	File: 
#		Vagrantfile
#	Description: 
#		Contains the test code for functions with the 'calc' prefix.
#		'calc' prefix functions perform calculations.
#	Author: 
#		(Original) 	Dave McPherson et al (VT ECE Department)		
#		(Modifed) 	Zander S. Ackerman
#	Date:
#		June 05 2019
#######################

# IMPORTANT NOTES:
# For best results use a VirualBox version that matches the guest
# lsmod | grep -io vboxguest | xargs modinfo | grep -iw version

# provision script
#-----------------------------------------------------------------------
$bootstrap = <<BOOTSTRAP
export DEBIAN_FRONTEND=noninteractive
apt-get update && apt-get upgrade

# label as reference environment
echo "export ECE3574_REFERENCE_ENV=Y" >> /etc/environment

# install base development tools
apt-get -y install build-essential
apt-get -y install cmake valgrind lcov graphviz doxygen
apt-get -y install python3-pip
apt-get -y install clang clang-tidy xvfb
apt-get -y install feh
pip3 install gcovr
pip3 install pexpect
pip3 install matplotlib

# install a lightweight graphical environment
apt-get -y install virtualbox-guest-dkms 
apt-get -y install virtualbox-guest-utils 
apt-get -y install virtualbox-guest-x11
apt-get -y install xorg sddm openbox
echo "[Autologin]" >> /etc/sddm.conf
echo "User=vagrant" >> /etc/sddm.conf
echo "Session=openbox.desktop" >> /etc/sddm.conf

# install a simple browser (for viewing coverage reports)
apt-get -y install hv3

# install Qt dev libs
#apt-get -y install qt5-default
BOOTSTRAP
#-----------------------------------------------------------------------

Vagrant.configure("2") do |config|
  config.vm.box = "ubuntu/bionic64"

  # get rid of annoying console.log file and start the GUI 
  config.vm.provider "virtualbox" do |vb|
    vb.customize [ "modifyvm", :id, "--uartmode1", "disconnected" ]
    vb.gui = true
  end

  # setup the VM
  config.vm.provision "shell", inline: $bootstrap
  
end

