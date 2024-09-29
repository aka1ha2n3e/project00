#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <mutex>
#include "common/common.hpp"
#include "common/commonType.hpp"
#include "logging/LogData.hpp"
#include "common/generalType.hpp"  

namespace loging {

    /**
     * @class Logger
     * @brief ロギング機能を提供するシングルトンクラス
     */
    class Logger {
    public:
        /**
         * @brief Loggerインスタンスを取得する
         * @return Loggerインスタンスへの参照
         */
        static auto getLogger() -> Logger &;

        /**
         * @brief ログファイルを設定する
         * @param logFilePath ログファイルのパス
         */
        auto setLogFile(const fileSystem::Path &logFilePath) -> void;

        static auto logUserAction(const String &message) -> void;
        static auto logInfo(const String &message) -> void;
        static auto logWarning(const String &message) -> void;
        static auto logError(const String &message) -> void;
        static auto logDebug(const String &message) -> void;

    private:
        Logger()
        {
            getLogger();
        };

        ~Logger() = default;

        Logger(const Logger &) = delete;
        Logger &operator=(const Logger &) = delete;

        /**
         * @brief ログを記録する内部メソッド
         * @param level ログレベル
         * @param message ログメッセージ
         */
        auto leaveLog(LogLevel level, const String &message) -> void;

        /**
         * @brief ログレベルに応じたタグを取得する
         * @param level ログレベル
         * @return ログレベルに対応するタグ
         */
        auto getTag(LogLevel level) const -> String;

        ContextPtr<UserAction> userActionLog; ///< ユーザーアクションログ
        ContextPtr<Info> infoLog; ///< 情報ログ
        ContextPtr<Warning> warningLog; ///< 警告ログ
        ContextPtr<Error> errorLog; ///< エラーログ
        ContextPtr<Debug> debugLog; ///< デバッグログ

        mutable std::mutex mut; ///< スレッドセーフ用ミューテックス
    };

} // namespace loging

#endif // LOGGER_HPP