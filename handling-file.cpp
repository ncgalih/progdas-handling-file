#include <stdio.h>
#include <string>

int main(){
    FILE *infile, *outfile, *info_file, *warn_file, *error_file;
    infile     = fopen("event_log_windows_1000.txt", "r");
    info_file  = fopen("information.txt", "w");
    warn_file  = fopen("warning.txt", "w");
    error_file = fopen("error.txt", "w");
    char c, head[100];
    std::string str;
    fgets(head, 100, infile); 

    while((c = fgetc(infile)) != EOF){      
        if (c==','){
            if (str.compare("Information")==0){
                outfile = info_file;
            } else if (str.compare("Warning")==0){
                outfile = warn_file;
            } else if (str.compare("Error")==0){
                outfile = error_file;
            } 
            fprintf(outfile, "%s,", str.c_str() );
            str.clear(); continue;
        } else if (c=='\n') {
            fprintf(outfile, "%s\n", str.c_str() );
            str.clear(); continue;
        } 
        str.push_back(c);
    };
    fclose(infile);
    fclose(info_file);
    fclose(warn_file);
    fclose(error_file);

    return 0;
}

