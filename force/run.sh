#!/system/bin/sh
# Checking ID shell
if [ "$(id -u)" -ne 2000 ]; then
    echo "[ Error |@UnixeID(Yeye)]"
    exit 1
fi
# Smart Notification
shell() {
    sor="$1"
    cmd notification post -S bigtext -t '♨️ VelocityHz' 'Tag' "$sor" > /dev/null 2>&1
}
# Style display Terminal
    echo
    echo "     ☆================================☆"
    echo
    echo "       ~ Description. VelocityHz.... "
    echo
    echo "       - Author                 :  @UnixeID"
    echo "       - Point                    : 1.0 [ SETTINGS SS ]"
    echo "       - Release               :  14 - Mar - 2025"
    echo "       - Name Shell         :  VelocityHz"
    echo
    echo "    |_______________________________________|"
    echo "    \______________________________________/"
    echo
    echo "   Priority VelocityHz. "
    sleep 2
    echo
    echo
     rm -rf /data/local/tmp/git
     cp /sdcard/force/git /data/local/tmp 
     chmod +x /data/local/tmp/git 
       if [ "$1" = "-E" ]; then
        shell "Wait To Set refresh rate to 60Hz Min 1-3"
        /data/local/tmp/git -E
    elif [ "$1" = "-F" ]; then
        shell "Wait To Set refresh rate to 120Hz Min 1-3"
        /data/local/tmp/git -F
    elif [ "$1" = "-l" ]; then
         shell "Wait To Set refresh rate to 90Hz Min 1-3"
        /data/local/tmp/git -l
    elif [ "$1" = "-d" ]; then
         shell "Wait To delete refres rate to settings Min 1-3"
         /data/local/tmp/git -d
    elif [ "$1" = "-h" ]; then
       /data/local/tmp/git -h
    else
        printf "Usage VelocityHz [-E|-F|-l|-h]\n"
    fi
    