// Copyright (c) 2016, Baidu.com, Inc. All Rights Reserved
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

#ifndef  BFS_FILE_LOCK_H_
#define  BFS_FILE_LOCK_H_

#include "nameserver/file_lock_manager.h"

#include <vector>
#include <memory>

namespace baidu {
namespace bfs {

class FileLockManager;

class Lock {
public:
    virtual ~Lock() {}
};

class WriteLock : public Lock {
public:
    WriteLock(const std::string& file_path);
    WriteLock(const std::string& file_path_a,
              const std::string& file_path_b);
    ~WriteLock();
    static void SetFileLockManager(FileLockManager* file_lock_manager);
private:
    // will be initialized in NameServerImpl's constructor
    static FileLockManager* file_lock_manager_;
    std::vector<std::string> file_path_;
};

class ReadLock : public Lock {
public:
    ReadLock(const std::string& file_path);
    ~ReadLock();
    static void SetFileLockManager(FileLockManager* file_lock_manager);
private:
    // will be initialized in NameServerImpl's constructor
    static FileLockManager* file_lock_manager_;
    std::string file_path_;
};

typedef std::shared_ptr<Lock> FileLockGuard;

} // namespace bfs
} // namespace baidu

#endif //BFS_FILE_LOCK_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
