#include <iostream>
#include <random>
#include <chrono>
#include <thread>
using namespace std;
// 定义时间槽的长度（毫秒）
const int SLOT_TIME_MS = 51; // 以太网标准时间槽为51.2微秒，这里为了方便使用毫秒

// 模拟时间槽的类
class SlotTime {
public:
    SlotTime(int ms) : duration(chrono::milliseconds(ms)) {}

    void wait() const {
        this_thread::sleep_for(duration);
    }

private:
    chrono::milliseconds duration;
};

// 阶段二进制退避算法类
class Backoff {
public:
    Backoff(int max_stage = 10, int max_retries = 16)
        : max_stage(max_stage), max_retries(max_retries), current_retries(0), current_stage(0) {}

    // 重置退避状态
    void reset() {
        current_retries = 0;
        current_stage = 0;
    }

    // 获取下一个退避时间（以时间槽为单位）
    int get_backoff_time() {
        if (current_retries >= max_retries) {
            // 超过最大重试次数，放弃
            return -1;
        }

        // 计算当前阶段k
        current_stage = min(current_retries, max_stage);

        // 生成一个0到(2^k - 1)之间的随机数
        int k = current_stage;
        int limit = (1 << k) - 1; // 2^k - 1

        // 使用随机数生成器生成退避时间
        uniform_int_distribution<int> dist(0, limit);
        int backoff_slots = dist(generator);

        // 增加重试次数
        current_retries++;

        return backoff_slots;
    }

    // 获取当前重试次数
    int get_current_retries() const {
        return current_retries;
    }

    // 获取当前阶段
    int get_current_stage() const {
        return current_stage;
    }

    mt19937 generator{ random_device{}() };
private:
    int max_stage;
    int max_retries;
    int current_retries;
    int current_stage;
};

// 示例使用
int main() {
    Backoff backoff_algorithm;

    int attempt = 0;
    while (attempt < 20) { // 最多尝试20次
        int backoff_slots = backoff_algorithm.get_backoff_time();
        if (backoff_slots == -1) {
            cout << "达到最大重试次数，放弃发送。\n";
            break;
        }

        cout << "尝试发送第 " << (attempt + 1) << " 次，退避时间: " << backoff_slots << " 个时间槽。\n";

        // 等待退避时间
        SlotTime slot(SLOT_TIME_MS);
        for (int i = 0; i < backoff_slots; ++i) {
            slot.wait();
            cout << "等待时间槽 " << (i + 1) << "...\n";
        }

        // 模拟发送结果：假设每次发送有30%的概率成功
        uniform_int_distribution<int> dist(1, 100);
        int random_value = dist(backoff_algorithm.generator);
        if (random_value <= 30) {
            cout << "发送成功！\n";
            break;
        } else {
            cout << "发送失败，冲突发生。\n";
        }

        attempt++;
    }

    if (attempt == 20) {
        cout << "尝试次数达到上限，发送失败。\n";
    }

    return 0;
}