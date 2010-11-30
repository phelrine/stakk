#ifndef CONNECTION_H
#define CONNECTION_H

#include "common.h"
namespace stakk {
    struct Connection {
        vector<unsigned short> connection;
        static const int size = 3033;

        bool load(string filename, bool full = true) {
            wifstream ifs(filename.c_str());
            if (!ifs.is_open())
                return false;
            wstring line;
            getline(ifs, line);
            if (full)
                connection.resize(size * size);
            else
                connection.resize(size);
            while (getline(ifs, line)) {
                vector<wstring> splited = split_w(line, L' ');
                unsigned short lid, rid ,cost;
                wstringstream(splited[0]) >> lid;
                wstringstream(splited[1]) >> rid;
                wstringstream(splited[2]) >> cost;
                if (!full && lid != 0) break;
                connection[lid * size + rid] = cost;
            }
            ifs.close();
            return true;
        }
        unsigned short get(unsigned short lid, unsigned short rid) {
            return connection[lid * size + rid];
        }
    };

    struct Definition {
        static const int size = 3033;
        wstring definition[size];

        bool load(string filename) {
            wifstream ifs(filename.c_str());
            if (!ifs.is_open())
                return false;
            wstring line;
            while (getline(ifs, line)) {
                int index;
                wstring detail;
                wstringstream(line) >> index >> detail;
                definition[index] = detail;
            }
            ifs.close();
            return true;
        }
        wstring get(int index) {
            return definition[index];
        }
    };
}
#endif
