#include <chrono>
#include <iostream>

int main()
{
    std::chrono::system_clock::time_point start, end;                                            // 型は auto で可
    start = std::chrono::system_clock::now();                                                    // 計測開始時間
                                                                                                 // 処理
    end = std::chrono::system_clock::now();                                                      // 計測終了時間
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); //処理に要した時間をミリ秒に変換
    std::cout << elapsed << std::endl;
}