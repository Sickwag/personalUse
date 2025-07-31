// service_locator.h
#pragma once
#include <functional>
#include <memory>
#include <mutex>
#include <typeindex>
#include <unordered_map>
#include "utils.h"

class ServiceLocator {
   private:
    static std::mutex mtx_;
    static std::unordered_map<std::type_index, std::shared_ptr<void>> services_;

   public:
    // 手动注册服务
    template <typename T>
    static void provide(std::shared_ptr<T> service) {
        std::lock_guard<std::mutex> lock(mtx_);
        services_[std::type_index(typeid(T))] = std::static_pointer_cast<void>(service);
    }
    template <typename T>
    static T& get() {
        std::lock_guard<std::mutex> lock(mtx_);
        auto it = services_.find(std::type_index(typeid(T)));
        if (it == services_.end()) {
            throw std::runtime_error("Service not registered: " + std::string(typeid(T).name()));
        }
        return *std::static_pointer_cast<T>(it->second);
    }

    // // 检查是否已注册
    template <typename T>
    static bool has() {
        std::lock_guard<std::mutex> lock(mtx_);
        return services_.find(std::type_index(typeid(T))) != services_.end();
    }

    // // 清理（可选，用于测试）
    static void reset() {
        std::lock_guard<std::mutex> lock(mtx_);
        services_.clear();
    }
};

inline std::mutex ServiceLocator::mtx_;
inline std::unordered_map<std::type_index, std::shared_ptr<void>> ServiceLocator::services_;