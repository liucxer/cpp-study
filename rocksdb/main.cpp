#include <iostream>
#include <cassert>
#include "rocksdb/db.h"

using namespace std;

int main() {
    rocksdb::DB* db;
    rocksdb::Options options;
    options.create_if_missing = true;
    rocksdb::Status status = rocksdb::DB::Open(options, "./testdb", &db);
    assert(status.ok());
    cout << "Open rocksdb success." << endl;

    int i = 0;
        string key1 = std::to_string(i);
        string value1 = "aaaaa";
        for (i= 0; i< 100; i++) {
                key1 = std::to_string(i);
                status = db->Put(rocksdb::WriteOptions(), key1, value1);
                assert(status.ok());
                printf("Put[%s,%s] success.\n", key1.c_str(), value1.c_str());
        }

        delete db;

        return 0;
    string value;
    status = db->Get(rocksdb::ReadOptions(), key1, &value);
    assert(status.ok());
    printf("Put key[%s] = %s\n", key1.c_str(), value.c_str());

    status = db->Delete(rocksdb::WriteOptions(), key1);
    assert(status.ok());
    printf("Delete key[%s] success.\n", key1.c_str());

    delete db;

    return 0;
}

