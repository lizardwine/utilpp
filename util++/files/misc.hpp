#include <dirent.h> 
#include <stdio.h> 
#include <fstream>
#include <vector>
#include <unistd.h>
#include <cstring>
#include <sys/stat.h>
#include <filesystem>

using namespace std;


namespace miscfiles{
    vector<string> listdir(string path = "."){
        vector<string> dirs;
        DIR *d;
        struct dirent *dir;
        d = opendir(path.c_str());
        if (d) {
            while ((dir = readdir(d)) != NULL) {
                if(!strcmp(dir->d_name,".") == 0 && !strcmp(dir->d_name,"..") == 0) {
                    dirs.push_back(dir->d_name);
                }
            }
            closedir(d);
        }
        return dirs;
    }


    bool exists(const char *filename){
        ifstream f(filename);
        return f.good();
    }

    string getdir(){
        char tmp[512];
        getcwd(tmp,512);
        string result = tmp;
        return result;
    }
    int makedir(string dirname){
    return mkdir(dirname.c_str(),0777);
    }

    int file_size(string filename){
        filesystem::path p{filename};
        return filesystem::file_size(p);
    }
    bool is_directory(string dirname){
        return filesystem::is_directory(dirname.c_str());
    }
    bool is_file(string filename){
        return !filesystem::is_directory(filename.c_str());
    }
    int dir_size(string dirname = "."){
        int size = 0;
        vector<string> dirs;
        vector<filesystem::path> files;
        dirs = listdir(dirname);
        for(int i = 0; i < dirs.size(); i++)
        {   
            if(is_file(dirname+"/"+dirs[i])){
                files.push_back(filesystem::path{dirname+"/"+dirs[i]});
                size += filesystem::file_size(files[i]);
            }
            else{
                size += dir_size(dirname+"/"+dirs[i]);
            }
        }       
        return size;
    }
    void chdir(string directory){
        filesystem::current_path(directory.c_str());
    }
    int rename(string name,string new_name){
        return rename(name.c_str(),new_name.c_str());
    }
}