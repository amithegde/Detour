#pragma once

#include <sstream>
#include <string>
#include <type_traits>

class Logger {
public:
	void Log(const std::wstring& message) {
		OutputDebugString(message.c_str());
	}

	void LogEnter(const std::wstring& functionName, const std::wstring& params) {
		Log(L"Enter: " + functionName + L"(" + params + L")");
	}

	void LogExit(const std::wstring& functionName, const std::wstring& result) {
		Log(L"Exit: " + functionName + L"() -> " + result);
	}
};

extern Logger logger;

class LogScope {
public:
	template<typename... Args>
	LogScope(const std::wstring& funcName, Args... args)
		: funcName_(funcName) {
		std::wstringstream ss;
		(logArgs(ss, args), ...);  // Fold expression to process all arguments
		logger.LogEnter(funcName_, ss.str());
	}

	~LogScope() {
		logger.LogExit(funcName_, result_);
	}

	void SetResult(const std::wstring& result) {
		result_ = result;
	}

private:
	std::wstring funcName_;
	std::wstring result_;

	template<typename T>
	void logArgs(std::wstringstream& ss, const T& arg) {
		if (!ss.str().empty()) {
			ss << L", ";
		}
		ss << to_wstring(arg);
	}

	template<typename T>
	std::wstring to_wstring(const T& value) {
		if constexpr (std::is_same_v<T, std::wstring>) {
			return value;
		}
		else if constexpr (std::is_same_v<T, std::string>) {
			return std::wstring(value.begin(), value.end());
		}
		else if constexpr (std::is_convertible_v<T, std::wstring>) {
			return std::wstring(value);
		}
		else if constexpr (std::is_convertible_v<T, std::string>) {
			std::string str = static_cast<std::string>(value);
			return std::wstring(str.begin(), str.end());
		}
		else if constexpr (std::is_pointer_v<T>) {
			std::wstringstream ss;
			ss << L"0x" << std::hex << reinterpret_cast<uintptr_t>(value);
			return ss.str();
		}
		else {
			std::wstringstream ss;
			ss << value;
			return ss.str();
		}
	}
};

extern Logger logger;
