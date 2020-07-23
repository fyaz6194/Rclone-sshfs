#include <bits/stdc++.h>
#include <pthread.h> 
#include <iostream>


using namespace std;
void *OneDrive(void *a){
system("umount ~/OneDrive");
system("fusermount -u ~/OneDrive");
system("mkdir ~/OneDrive");
system("chmod 777 ~/Documents/Rclone/onedrive.sh");
system("chmod +x ~/Documents/Rclone/onedrive.sh");
cout << "Executing onedrive.sh" << endl;    
system("sh -c ~/Documents/Rclone/onedrive.sh");
cout << "End of onedrive command: 01"<< endl;
return NULL;

}
void *GoogleDrive(void *a){
system("umount ~/'Google Drive'");
system("fusermount -u ~/'Google Drive'");
system("mkdir ~/'Google Drive'");
system("chmod 777 ~/Documents/Rclone/googledrive.sh");
system("chmod +x ~/Documents/Rclone/googledrive.sh");  
cout << "Executing googledrive.sh" << endl;  
system("sh -c ~/Documents/Rclone/googledrive.sh");
cout << "End of googledrive command: 02" << endl;
return NULL;

}
void *Hercules(void *a){
system("pkill -kill -f 'sshfs'");
system("umount ~/fmb925");
system("fusermount -u ~/fmb925");
system("mkdir ~/fmb925");
system("chmod 777 ~/Documents/Rclone/hercules_uofr.sh");
system("chmod +x ~/Documents/Rclone/hercules_uofr.sh"); 
cout << "Executing hercules_uofr.sh" << endl;   
system("sh -c ~/Documents/Rclone/hercules_uofr.sh");
cout << "End of hercules command: 03" << endl;
return NULL;

}

int main ()

{


cout << "---------------           Self Code Executation            ----------------" << endl;
system("pkill -kill -f 'sshfs'");
system("umount ~/fmb925");
system("fusermount -u ~/fmb925");
system("umount ~/'Google Drive'");
system("fusermount -u ~/'Google Drive'");
system("umount ~/OneDrive");
system("fusermount -u ~/OneDrive");
system("while ! wget -q -O /dev/null --no-cache http://www.google.com/; do sleep 5; done");
pthread_t onedrive, googledrive, hercules;
cout << "thread created" << endl;
pthread_create(&onedrive, NULL,OneDrive,NULL);
cout << "thread: onedrive has executed." << endl;
pthread_create(&googledrive, NULL,GoogleDrive,NULL);
cout << "thread: googledrive has executed." << endl;
pthread_create(&hercules, NULL,Hercules,NULL);
cout << "thread: hercules has executed." << endl;
pthread_join(onedrive , NULL);
pthread_join(googledrive , NULL);
pthread_join(hercules , NULL);

cout << "All Command completed..." << endl;

return 0;

}
